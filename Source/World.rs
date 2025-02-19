use bevy::prelude::*;
use bevy_voxels::{prelude::*, voxel::*};
use noise::{NoiseFn, Perlin};

use crate::block::BlockType;
use crate::biome::BiomeType;

pub struct WorldPlugin;

impl Plugin for WorldPlugin {
    fn build(&self, app: &mut App) {
        app.add_startup_system(setup_world);
    }
}

fn setup_world(mut commands: Commands) {
    let perlin = Perlin::new(0);
    let mut voxels = VoxelBuffer::new([32, 32, 32]); // Chunk size

    for x in 0..32 {
        for z in 0..32 {
            let height = (perlin.get([x as f64 * 0.1, z as f64 * 0.1]) * 8.0 + 16.0) as usize;

            // Determine biome based on coordinates
            let biome = match (x / 8, z / 8) {
                (0, 0) => BiomeType::Grassland,
                (1, 0) => BiomeType::Desert,
                (0, 1) => BiomeType::Forest,
                (1, 1) => BiomeType::Mountain,
                _ => BiomeType::Water, // Bro it's called an Ocean
            };

            for y in 0..32 {
                let block = if y > height {
                    BlockType::Air
                } else {
                    biome.get_block_type(y)
                };

                voxels.set([x, y, z], block as u8);
            }
        }
    }

    commands.spawn((
        VoxelChunk { voxels },
        Transform::default(),
    ));
}


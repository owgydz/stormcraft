#[derive(Clone, Copy, PartialEq, Eq, Debug)]
pub enum BiomeType {
    Plains,
    Desert,
    Forest,
    Mountain,
    Water, // What?
}

impl BiomeType {
    pub fn get_block_type(&self, y: usize) -> BlockType {
        match self {
            BiomeType::Grassland => if y == 0 { BlockType::Grass } else { BlockType::Dirt },
            BiomeType::Desert => if y == 0 { BlockType::Sand } else { BlockType::Dirt },
            BiomeType::Forest => if y == 0 { BlockType::Grass } else { BlockType::Dirt },
            BiomeType::Mountain => if y == 0 { BlockType::Stone } else { BlockType::Dirt },
            BiomeType::Water => if y == 0 { BlockType::Water } else { BlockType::Air },
        }
    }
}

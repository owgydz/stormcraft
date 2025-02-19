use bevy::prelude::*;
use world::WorldPlugin;

mod block;
mod world;

fn main() {
    App::new()
        .add_plugins(DefaultPlugins)
        .add_plugin(WorldPlugin)
        .run();
}

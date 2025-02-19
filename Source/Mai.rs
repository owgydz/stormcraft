use bevy::prelude::*;
use world::WorldPlugin;

mod block;
mod world;
mod Crafting;
mod Sal;
mod DayAndNight;

fn main() {
    App::new()
        .add_plugins(DefaultPlugins)
        .add_plugin(WorldPlugin)
        .add_startup_system(DayAndNight::setup_day_night)
        .run();
}

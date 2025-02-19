use bevy::prelude::*;

pub struct DayNightCycle {
    time_of_day: f32, // 0.0 - 1.0 representing day cycle
}

impl Default for DayNightCycle {
    fn default() -> Self {
        DayNightCycle { time_of_day: 0.0 }
    }
}

fn update_day_night_cycle(time: Res<Time>, mut query: Query<&mut DayNightCycle>) {
    for mut cycle in query.iter_mut() {
        cycle.time_of_day += time.delta_seconds() / 60.0; // Speed up for testing
        if cycle.time_of_day >= 1.0 {
            cycle.time_of_day = 0.0; // Reset at the end of the day
        }
        
        let light_intensity = if cycle.time_of_day < 0.5 {
            1.0 - (cycle.time_of_day * 2.0) // Morning to noon
        } else {
            (cycle.time_of_day - 0.5) * 2.0 // Noon to evening
        };

        let mut light_query = query.iter_mut();
        if let Some(mut light) = light_query.next() {
            light.intensity = light_intensity;
        }
        for mut light in query.iter_mut() {
            light.intensity = light_intensity;
        }
    }
}

pub fn setup_day_night(app: &mut App) {
    app.insert_resource(DayNightCycle::default())
       .add_system(update_day_night_cycle);
}

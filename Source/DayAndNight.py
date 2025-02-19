class DayNightCycle:
    def __init__(self):
        self.time_of_day = 0.0  # 0.0 - 1.0 representing day cycle

def update_day_night_cycle(delta_seconds, cycles):
    for cycle in cycles:
        cycle.time_of_day += delta_seconds / 60.0  # Speed up for testing
        if cycle.time_of_day >= 1.0:
            cycle.time_of_day = 0.0  # Reset at the end of the day

        if cycle.time_of_day < 0.5:
            light_intensity = 1.0 - (cycle.time_of_day * 2.0)  # Morning to noon
        else:
            light_intensity = (cycle.time_of_day - 0.5) * 2.0  # Noon to evening

        cycle.light_intensity = light_intensity  # Assuming each cycle has a light_intensity attribute

def setup_day_night():
    day_night_cycle = DayNightCycle()
    return day_night_cycle

# Example usage:
day_night_cycle = setup_day_night()
cycles = [day_night_cycle]  # List of cycles

# Simulate passing time
for i in range(10):
    update_day_night_cycle(1.0, cycles)  # Assuming delta_seconds = 1.0 for simplicity
    print(f"Time of Day: {day_night_cycle.time_of_day}, Light Intensity: {day_night_cycle.light_intensity}")

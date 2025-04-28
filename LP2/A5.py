def prompt_question(query: str) -> bool:
    response = input(query + " (yes/no): ").lower()
    return response == "yes"


def check_peak_travel_time() -> bool:
    return prompt_question("Is it a peak travel season? (e.g., holidays, summer?)")


def check_weather_conditions() -> bool:
    return prompt_question("Are the weather conditions favorable for flying?")


def check_aircraft_availability() -> bool:
    return prompt_question("Is the aircraft available for the flight?")


def check_passenger_demand() -> bool:
    return prompt_question("Is there high demand for flights to this destination?")


def check_destination_restrictions() -> bool:
    return prompt_question("Are there any restrictions or limitations at the destination airport?")


def check_runway_availability() -> bool:
    return prompt_question("Is the runway available at the desired time?")


print("Expert System for Airline Scheduling")

if check_peak_travel_time():
    print("Consider additional flights due to high travel demand.")
if check_weather_conditions():
    print("Weather conditions are favorable. Proceed with scheduling flights.")
else:
    print("Weather conditions are unfavorable. Delay flights or cancel as necessary.")

if check_aircraft_availability():
    print("Aircraft is available for the flight.")
else:
    print("Aircraft is not available. Check for alternate aircraft.")

if check_passenger_demand():
    print("High passenger demand. Prioritize this route or consider adding more flights.")
else:
    print("Low passenger demand. Consider reducing the number of flights.")

if check_destination_restrictions():
    print("Destination restrictions are clear. Proceed with scheduling.")
else:
    print("There are restrictions at the destination. Consider adjusting schedules or delays.")

if check_runway_availability():
    print("Runway is available at the desired time.")
else:
    print("Runway is not available. Check for alternate time slots.")

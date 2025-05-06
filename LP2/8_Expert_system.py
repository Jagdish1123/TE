def prompt_question(query: str) -> bool:
    response = input(query + " (yes/no): ").strip().lower()
    return response == "yes"

def check_peak_travel_time() -> bool:
    return prompt_question("1. Is it a peak travel season (e.g., holidays, summer)?")

def check_weather_conditions() -> bool:
    return prompt_question("2. Are the weather conditions favorable for flying?")

def check_aircraft_availability() -> bool:
    return prompt_question("3. Is the aircraft available for the flight?")

def check_passenger_demand() -> bool:
    return prompt_question("4. Is there high demand for flights to this destination?")

def check_destination_restrictions() -> bool:
    return prompt_question("5. Are there any restrictions or limitations at the destination airport?")

def check_runway_availability() -> bool:
    return prompt_question("6. Is the runway available at the desired time?")

def check_crew_availability() -> bool:
    return prompt_question("7. Is a qualified flight crew available?")

def check_air_traffic_congestion() -> bool:
    return prompt_question("8. Is the air traffic at the departure and destination airports manageable?")

def check_fuel_availability() -> bool:
    return prompt_question("9. Is sufficient fuel available for the flight?")

def check_maintenance_status() -> bool:
    return prompt_question("10. Has the aircraft cleared all required maintenance checks?")

print("Expert System for Airline Scheduling\n")

if check_peak_travel_time():
    print("1. Consider adding more flights due to high seasonal demand.")

if check_weather_conditions():
    print("2. Weather is favorable. Proceed with scheduling.")
else:
    print("2. Unfavorable weather. Delay or cancel flights if necessary.")

if check_aircraft_availability():
    print("3. Aircraft is available for scheduling.")
else:
    print("3. No aircraft available. Check alternate options.")

if check_passenger_demand():
    print("4. High demand. Prioritize this route.")
else:
    print("4. Low demand. Evaluate necessity of the flight.")

if check_destination_restrictions():
    print("5. No destination restrictions. Continue planning.")
else:
    print("5. Destination restrictions detected. Reassess scheduling.")

if check_runway_availability():
    print("6. Runway is available at the desired time.")
else:
    print("6. Runway not available. Consider rescheduling.")

if check_crew_availability():
    print("7. Qualified crew is available.")
else:
    print("7. No crew available. Delay or reassign flight.")

if check_air_traffic_congestion():
    print("8. Air traffic is manageable.")
else:
    print("8. Heavy air traffic. Adjust flight timing.")

if check_fuel_availability():
    print("9. Sufficient fuel available for the flight.")
else:
    print("9. Fuel unavailable. Delay until resolved.")

if check_maintenance_status():
    print("10. Aircraft has passed all maintenance checks.")
else:
    print("10. Aircraft pending maintenance. Flight not recommended.")

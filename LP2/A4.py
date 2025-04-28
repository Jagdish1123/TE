import random

class HotelBot:

    def __init__(self):
        # Dictionary of intents mapped with keywords
        self.intents = {
            "welcome": ["hello", "hi", "hey"],
            "book_room": ["book", "reservation", "reserve", "room", "accommodation"],
            "menu": ["menu", "dishes", "food", "meal", "items", "breakfast", "lunch", "dinner"],
            "hours": ["hours", "time", "open", "close", "timing", "schedule"],
            "location": ["location", "address", "where are you", "direction", "map"],
            "contact": ["contact", "phone", "email", "reach out", "contact us", "get in touch"],
            "exit": ["exit", "bye", "quit", "goodbye"],
            "ok": ["ok", "okay", "alright"],
            "thanks": ["thanks", "thank", "appreciate", "thank you"]
        }

        # Dictionary of intents mapped with responses
        self.responses = {
            "menu": ["Our menu includes continental breakfast, sandwiches, soups, and salads. What would you like to order?",
                     "We offer a variety of meals including breakfast, lunch, and dinner. How can I assist you with your choice?"],
            "book_room": ["To book a room, you can visit our website or call us at 123-456-7890. How can I assist you further?",
                     "You can make a reservation online through our website or give us a call at 123-456-7890. What else would you like to know?"],
            "hours": ["We are open 24/7 to serve you. How can I assist you further?",
                     "Our hotel is open 24/7. What else would you like to know?"],
            "location": ["We are located at 123 Main Street, City, State, ZIP. How can I help you further?",
                        "Our hotel is situated at 123 Main Street. What else would you like to know?"],
            "contact": ["You can contact us at 123-456-7890 or email us at info@hotel.com. How can I assist you further?",
                        "Feel free to reach out to us at 123-456-7890 or via email at info@hotel.com. What else would you like to know?"],
            "default": ["I'm sorry, I didn't quite get that. Can you please rephrase your question?",
                        "I'm not sure I understand. Could you ask again in a different way?"],
            "welcome": ["Hello! Welcome to HotelBot. How can I assist you today?",
                        "Hi there! Welcome to HotelBot. How can I help you today?",
                        "Hey! Welcome to HotelBot. What can I do for you today?"],
            "exit": ["Goodbye! Thank you for visiting HotelBot. Have a great day!",
                     "Goodbye! Hope to see you again soon. Have a wonderful day!",
                     "Bye! Thanks for chatting with HotelBot. Take care!"],
            "thanks": ["You're welcome! If you need any further assistance, feel free to ask.",
                       "No problem! Let me know if there's anything else I can help you with.",
                       "Glad I could assist you! If you have any more questions, just ask."],
            "ok": ["Alright! Let me know if there's anything else I can do for you.",
                   "Got it! Feel free to ask if you need any further information.",
                   "Sure thing! If you have any other questions, don't hesitate to ask."],
        }

    def check_for_keywords(self, keywords: list, user_query: str) -> bool:
     
        for word in keywords:
            if word in user_query:
                return True
        return False

    def generate_response(self, user_query: str) -> str:
       
        user_query = user_query.lower()
        for intent, keywords in self.intents.items():
            if self.check_for_keywords(keywords=keywords, user_query=user_query):
                return random.choice(self.responses[intent])
        return random.choice(self.responses["default"])
    
    def start_chat(self) -> None:
      
        print(random.choice(self.responses["welcome"]))
        while True:
            user_query = input("You: ")
            if self.check_for_keywords(self.intents["exit"], user_query):
                print(random.choice(self.responses["exit"]))
                break
            response = self.generate_response(user_query)
            print("HotelBot: ", response)

def main():
    hotel_bot = HotelBot()
    hotel_bot.start_chat()

main()

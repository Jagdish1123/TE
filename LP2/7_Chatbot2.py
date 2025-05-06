import nltk
import re
from nltk.chat.util import Chat, reflections

products = {
    "Wireless Earbuds": {
        "info": "Compact wireless earbuds with noise cancellation, 24-hour battery life, and IPX5 water resistance.",
        "stock": True
    },
    "Gaming Mouse": {
        "info": "High-precision gaming mouse with 16000 DPI, RGB lighting, and 8 programmable buttons.",
        "stock": False
    },
    "4K Monitor": {
        "info": "27-inch 4K UHD monitor with HDR10, 144Hz refresh rate, and built-in speakers.",
        "stock": True
    },
    "Bluetooth Speaker": {
        "info": "Portable Bluetooth speaker with 12 hours playtime and deep bass.",
        "stock": True
    },
    "Laptop Stand": {
        "info": "Adjustable aluminum laptop stand suitable for all screen sizes, with cooling support.",
        "stock": False
    }
}

class AdvancedEcomChat(Chat):
    def __init__(self, pairs, reflections):
        super().__init__(pairs, reflections)
        self.context = None
        self.last_product_query = None

    def respond(self, str_):
        str_ = str_.lower().strip()

        if self.context=="complaint":
            with open("logs.txt", 'a') as f:
                f.write(str_ + "\n\n")
            self.context=None
            return "Complaint logged. You will be contacted soon regarding it"

        order_id_match = re.match(r"ord\d{5}", str_)
        if order_id_match:
            oid = str_.upper()
            if self.context == "order_status":
                return f"{oid} is out for delivery and should reach you by tomorrow."
            elif self.context == "refund":
                return f"A refund for {oid} has been approved and will be credited within 3-5 business days."
            elif self.context == "return":
                return f"Return initiated for {oid}. Pickup scheduled within 48 hours."
            else:
                return f"Thanks for providing {oid}. What would you like help with?"

        if self.context in ["product_info", "product_stock"]:
            product_name = str_.title()
            self.last_product_query = product_name
            product = products.get(product_name)
    
            if product:
                if self.context == "product_info":
                    return product["info"]
                elif self.context == "product_stock":
                    return f"Yes, {product_name} is in stock!" if product["stock"] else f"Sorry, {product_name} is currently out of stock."
        
        if "complaint" in str_:
            self.context="complaint"
        elif "order status" in str_ or "track my order" in str_:
            self.context = "order_status"
        elif "refund" in str_:
            self.context = "refund"
        elif "return" in str_:
            self.context = "return"
        elif "product info" in str_ or "product details" in str_:
            self.context = "product_info"
        elif "in stock" in str_:
            self.context = "product_stock"
       
        else:
            self.context = None

        return super().respond(str_)

pairs = [
    # Greetings
    [r"hi|hello|hey", ["Hello! How can I assist you today?"]],
    [r"how are you", ["Doing great! Here to help you with any shopping issue."]],

    # Orders
    [r"(.*)order status(.*)", ["Sure! Please provide your order ID (e.g., ORD12345)."]],
    [r"(.*)track(.*)", ["Sure! Please provide your order ID (e.g., ORD12345)."]],
    [r"i want to know my order status", ["Absolutely, just share your order ID."]],

    # Refunds & Returns
    [r"(.*)refund(.*)", ["Refunds take 3–5 days. Please provide your order ID for more details."]],
    [r"(.*)return(.*)", ["Returns accepted within 30 days. Share your order ID to continue."]],

    # Product
    [r"(.*)product (info|details)(.*)", ["What product are you referring to?"]],
    [r"(.*)in stock(.*)", ["Let me check that for you. Which product are you interested in?"]],
    
    # Account
    [r"(.*)forgot password(.*)", ["You can reset your password via the 'Forgot Password' link."]],
    [r"(.*)login problem(.*)", ["Try resetting your password or contact support if it persists."]],

    # Shipping
    [r"(.*)shipping charges(.*)", ["Shipping is free on orders above $50."]],
    [r"(.*)delivery time(.*)", ["Delivery usually takes 3–5 business days."]],

    # Store info
    [r"(.*)store hours(.*)", ["Our stores are open from 9 AM to 9 PM, Mon–Sat."]],
    [r"(.*)nearest store(.*)", ["Tell me your city, and I’ll find the nearest store."]],

    # Complaints
    [r"(.*)complaint(.*)", ["Please describe your issue, and I’ll log your complaint."]],

    # Goodbye
    [r"bye|exit|quit", ["Thanks for visiting E-Shop! Have a great day!"]],

    # Fallback
    [r"(.*)", ["I didn’t get that. Can you rephrase or ask about orders, refunds, shipping, etc.?"]],
]

# Run the bot
def run_chatbot():
    print(" Welcome to E-Shop Support Bot! Type 'bye' to exit.")
    chat = AdvancedEcomChat(pairs, reflections)
    chat.converse()

if __name__ == "__main__":
    run_chatbot()
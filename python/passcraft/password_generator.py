import random
import string
import sys

def generate_password():
    """Generate a random password based on user preferences"""
    print("\n=== Password Options ===")
    
    # Get password length
    while True:
        try:
            length = int(input("Enter password length (min 8): "))
            if length >= 8:
                break
            print("Password must be at least 8 characters")
        except ValueError:
            print("Please enter a valid number")
    
    # Get character types
    char_sets = {
        'lowercase': string.ascii_lowercase,
        'uppercase': string.ascii_uppercase,
        'numbers': string.digits,
        'symbols': string.punctuation
    }
    
    selected_chars = []
    for name, chars in char_sets.items():
        while True:
            answer = input(f"Include {name}? (y/n): ").lower()
            if answer in ('y', 'n'):
                if answer == 'y':
                    selected_chars.extend(list(chars))
                break
            print("Please enter 'y' or 'n'")
    
    if not selected_chars:
        print("You must select at least one character type!")
        return
    
    # Generate password
    password = ''.join(random.choices(selected_chars, k=length))
    
    print("\n=== Generated Password ===")
    print(password)
    print("========================")
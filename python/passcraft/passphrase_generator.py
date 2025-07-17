import random

def generate_passphrase(word_list):
    """Generate a random passphrase from the word list"""
    print("\n=== Passphrase Options ===")
    
    # Get word count
    while True:
        try:
            count = int(input("Enter number of words (min 4): "))
            if count >= 4:
                break
            print("Passphrase must have at least 4 words")
        except ValueError:
            print("Please enter a valid number")
    
    # Generate passphrase
    passphrase = ' '.join(random.choices(word_list, k=count))
    
    print("\n=== Generated Passphrase ===")
    print(passphrase)
    print("=========================")
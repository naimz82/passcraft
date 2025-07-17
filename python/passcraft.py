#!/usr/bin/env python3
from passcraft.password_generator import generate_password
from passcraft.passphrase_generator import generate_passphrase
import os
import sys

def load_word_list():
    """Load the word list from the text file"""
    word_list_path = os.path.join(os.path.dirname(__file__), '../enpass-word-list.txt')
    try:
        with open(word_list_path, 'r') as f:
            return [word.strip() for word in f.readlines() if word.strip()]
    except FileNotFoundError:
        print(f"Error: Word list file not found at {word_list_path}")
        sys.exit(1)

def main():
    word_list = load_word_list()
    print(f"Loaded {len(word_list)} words")
    
    while True:
        print("\n=== PassCraft Generator ===")
        print("1. Generate Password")
        print("2. Generate Passphrase")
        print("3. Exit")
        
        choice = input("Choose an option (1-3): ").strip()
        
        if choice == '1':
            generate_password()
        elif choice == '2':
            generate_passphrase(word_list)
        elif choice == '3':
            print("Goodbye!")
            sys.exit(0)
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
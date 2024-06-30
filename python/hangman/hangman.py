"""
File: hangman.py
Author: Patrick Robbins
Date: 30/06/2024
Description: Hangman Game in Python.
"""

# Import modules.
import random


class hangman:
    def __init__(self, word):
        self.word = word
        self.state = "inprogress" #Options are 'inprogress', 'won', 'lost'
        self.max_tries = 8
        self.wrong_tries = 0
        self.guessed_letters = []
        self.board = ["_" for chararacter in word]
    
    def display(self):
        print("Word to guess: ", ''.join(self.board))
        print("Guessed Letters: ", ', '.join(self.guessed_letters))
        print("Wrong Tries Remaining: ", (self.max_tries - self.wrong_tries))
    
    def get_input(self):
        print("Enter a single letter to guess a letter,")
        print("Enter a word to guess the word,")
        print("Enter 'exit' to exit the game.")

        user_input = input(">>> ").lower()#force input to be lowercase.

        return user_input
    
    def update(self, user_input):
        if len(user_input) == 1:
            #check if the letter has already been guessed
            if user_input in self.guessed_letters:
                print("You have already guessed that letter.")
                return None
            elif user_input in self.word:#Guess is correct
                print("Correct Guess!")

                self.guessed_letters.append(user_input)

                #update the guessed letters
                index = 0
                for letter in self.word:
                    if letter == user_input:
                        self.board[index] = user_input
                    index += 1
            else:
                print("Incorrect Guess!")
                self.wrong_tries += 1
                self.guessed_letters.append(user_input)
            
            #check if the word has been solved/game won
            if not "_" in self.board:
                self.state = "won"
        else:
            if user_input == self.word:
                self.state = "won"
            else:
                print("Incorrect Guess!")
                self.wrong_tries += 1

        if self.wrong_tries >= self.max_tries:
            self.state = "lost"



# Define the main game loop
def main():
    
    # Load the word list from the file 'words.txt'
    with open("words.txt", "r") as file:
        # Read the file, and strip the whitespace from the words.
        words = [word.strip() for word in file.readlines()]
    
    # Select a random word
    word = random.choice(words)

    #initate the game
    game = hangman(word)
    print("Welcome to Hangman!")
    print("I have selected a random word for you to try and guess.\n")
    print("The theme is: Names of Countries.")


    #main game loop
    while True:
        game.display()
        user_input = game.get_input()

        if user_input == "exit":#exit the game
            print("Exiting...")
            break

        game.update(user_input)

        if game.state == "won":
            print("You Won!!!")
            break
        elif game.state == "lost":
            print("You Lost!!!")
            break


    return None


# Run the main function for the game, if the script is executed directly.
if __name__ == "__main__":
    main()

# End of File.

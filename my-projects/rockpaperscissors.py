import random
import sys
from random import choice

#rock paper scissors game

print("Let's play Rock Paper Scissors!")

options = ["rock", "paper", "scissors"]


while True:
  comp_options = random.choice(options) #generates random computer choice

  while True:
    choice = input("Choose rock - 1 , paper - 2 or scissors - 3: ")
    if choice.isdigit():
      choice = int(choice)
      if (choice == 1 or choice == 2 or choice == 3):
        break #valid input, code continues
    print('Please enter a valid option: ')

  if (choice == 1):  #changes number input to an option
      choice = "rock"
  elif (choice == 2):
      choice = "paper"
  elif (choice == 3):
      choice = "scissors"

  #user and computer choices
  print(f"You chose {choice}")
  print(f"Computer chose {comp_options}")

  #determine the winner
  if (choice == comp_options):
      print(f"Both players chose {choice}. It's a tie!")
  elif ((choice == 'paper' and comp_options == 'rock') or (choice == 'rock' and comp_options == 'scissors') or {choice == 'scissors' and comp_options == 'paper'}):
      print("You win!")
  else:
      print("Computer wins!")


  while True:
      ans = input("Would you like to play again? (Y/N): ")

      if ans in ['y', 'Y', 'n', 'N']:
          break
      print("Invalid input, please try again: ")


  if (ans == 'n' or ans == 'N'):
      print("Thanks for playing!")
      break





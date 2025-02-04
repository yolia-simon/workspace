import random
import sys
from random import choice

#rock paper scissors game

print("Let's play Rock Paper Scissors!")

options = ["rock", "paper", "scissors"]


while True:
  comp_options = random.choice(options) #generates random computer choice

  while True:
    user = input("Choose rock - 1 , paper - 2 or scissors - 3: ")
    if user.isdigit():
      user = int(user)
      if (user == 1 or user == 2 or user == 3):
        break #valid input, code continues
    print('Please enter a valid option: ')

  if (user == 1):  #changes number input to an option
      user = "rock"
  elif (user == 2):
      user = "paper"
  elif (user == 3):
      user = "scissors"

  #user and computer choices
  print(f"You chose {user}")
  print(f"Computer chose {comp_options}")

  #determine the winner
  if (user == comp_options):
      print(f"Both players chose {user}. It's a tie!")
  elif ((user == 'paper' and comp_options == 'rock') or (user == 'rock' and comp_options == 'scissors') or (user == 'scissors' and comp_options == 'paper')):
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





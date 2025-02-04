#practise automating decision making

#code will ask how much time the user has, what mood
#the user is in, then selects the activity they should do

import random
import csv
import sys
from random import choice

def main():
    menu()

def menu():
    print('Welcome to the Decision Maker!')
    print()

    #things to do
    activity = ['games', 'drawing', 'study', 'cook', 'watch anime', 'youtube', 'coding', 'walking', 'reading']

    #time input
    time = int(input("""First, how much time in mins do you have to spend?
                        Please enter your choice: """))

    if time > 0 or time < 15:
        print('you have 0-60 mins')
        #elif time >
    elif option == "2":
        print('This is the activity you should do:',choice(activity))
    elif option == "5" or 'five':
        print('Exiting application...')
        sys.exit
    else:     #makes sure that you can only choose from the options avaliable
        print("You must select an option from the menu")
        print("Please try again")
        menu()

    #mood input
    #option = input("""'What kinda mood are you in? ')
                        #1. Tired
                        #2. Sad
                        #3. Happy
                        #4. Stressed
                        #5. Exit the application
                        #Please enter your choice: """)

def tired():
    pass

menu() #program is initiated here

#for item in activity:
    #if mood == 'tired':
        #print('This is the activity you should do: ',choice(item[1,2]))
    #else:
        #print('This is the activity you should do:',choice(activity))

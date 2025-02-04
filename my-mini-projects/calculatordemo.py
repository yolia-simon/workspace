#Calculator python project by Yolia S

import random
import csv
import sys

def main():
    menu()

def menu():
    print('---- Welcome to Yolia\'s Calculator App ----')
    print()

    answer = input("""What would you like to do today?
                        1. Addition 
                        2. Subtraction 
                        3. Multiplication 
                        4. Division
                        5. Exit
                        Please enter your choice: """)

    if answer == "1":
        add()
    elif answer == "2":
        sub()
    elif answer == "3":
        multiply()
    elif answer == "4":
        divide()
    elif answer=="5":
        print('Exiting application...')
        sys.exit
    else:     #makes sure that you can only choose from the options avaliable
        print("You must select an option from the menu")
        print("Please try again")
        menu()


def add(): #addition function
    num1 = int(input('Enter the first number: '))
    num2 = int(input('Enter the second number: '))
    print('Here is your result: ', num1 + num2)
    
def sub(): #subtration function
    num1 = int(input('Enter the first number: '))
    num2 = int(input('Enter the second number: '))
    print('Here is your result: ', num1 - num2)

def multiply(): #multiply function
    num1 = int(input('Enter the first number: '))
    num2 = int(input('Enter the second number: '))
    print('Here is your result: ', num1 * num2)

def divide(): #division function
    num1 = int(input('Enter the first number: '))
    num2 = int(input('Enter the second number: '))
    print('Here is your result: ', num1 / num2)

#the program is initiated here
main()

#Personal Finance Dashboard
#used to track how much you're spending, what categories you are spending in, total weekly spend and total monthly spend
#learn how to use streamlit later

import sys
import csv
import numpy as np
import pandas as pd
import streamlit as st
import matplotlib
 
df = pd.read_csv('sample_finance_data.csv', index_col='Date') #reads the transactional data

df.drop('Description',inplace=True, axis=1) #these 2 lines delete the columns with the corresponding labels
df.pop('Account Name')

#column_names = ['Date', 'Description', 'Amount', 'Transaction Type', 'Category', 'Account Name']

with open('sample_finance_data.csv') as f: #tells me the number of columns and rows in data
    data = list(csv.reader(f))

tot_rows = len(data) - 1
#tot_columns = len(data[0])


def categoryspending(): #this function cycles thru list of categories and tells me how many times each category shows up in data
    categories = ['Entertainment', 'Utilities', 'Salary','Shopping', 'Rent', 'Investment',
                  'Food', 'Transportation', 'Healthcare']
    category_column = 'Category'
    cat_counts = df[category_column].value_counts()
    for category in categories:
        count = cat_counts.get(category, 0)
        percentage = (count/tot_rows) *100  #calculates the percentage for each spending category
        print(f'{category}: {percentage:.2f}%')
#need to display this in a pie chart
#maybe specify for each year? so far this would be a pie chart for the entire account...

def totalweekly():
    #ask1 = input('Would you like to view your deposit or withdrawal information')

    #if ask1 == 'deposit' or 'Deposit':

    for i in range(0, tot_rows, 7):
        weekly = df.iloc[i:i + 7]
        print(f"Week {i // 7 + 1}:")
        print(weekly)
        print("-" * 50)  # Separator between weeks

        # Optionally, wait for user input to go to the next week
        input("Press Enter to see the next week's data...")


totalweekly()

def totalmonthly():
    column_name = 'Amount'
    neg_values = df[df[column_name] < 0][column_name]
    sum = neg_values.abs().sum()
    print('Total Spent', sum)  # need to specify total spent in each month


def totalyearly():
    amount = np.sum(df['Amount'].tolist()) #sums the entire column
    

totalweekly()

#categories = df['Category'].tolist()
#print('Utilities transactions:',categories.count('Utilities'))

#def main():
    #menu()

def menu():
    print('---- Welcome to your Personal Finance Dashboard ----')
    print()

    option = input("""What would you like to do today?
                        1. What Categories I am spending in?
                        2. Total Weekly expenses
                        3. Total Monthly expenses 
                        4. Total Yearly expenses
                        5. Exit
                        Please enter your choice: """)
    if option == '1':
        categoryspending()
    elif option == '2':
        pass #totalweekly()  
    elif option == '3':
        pass #totalmonthly()
    elif option == '4':
        pass #totalyearly()
    elif option =="5":
        print('Exiting application...')
        sys.exit
    else:     #makes sure that you can only choose from the options avaliable
        print("You must select an option from the menu")
        print("Please try again")
        #menu()

#menu() #program is initiated here
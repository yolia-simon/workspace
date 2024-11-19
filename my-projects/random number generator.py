import random

print('Welcome to the Random Number Generator')

number = input('How many numbers?')
number = int(number)
length = input('How many digits?')
length = int(length)

chars = '0123456789'

print('Here are your numbers:')

for rnum in range(number):
    rnum = ''
    for c in range(length):
        rnum += random.choice(chars)
    print(rnum)
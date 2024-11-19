#https://www.youtube.com/watch?v=SqvVm3QiQVk&t=2531s
#Password generator project

import random

print('Welcome to the Password Generator')

number = input('Number of passwords?')
number = int(number)
length = input('Password length required?')
length = int(length)

chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ£$%&@!0123456789'

print('Here are your passwords:')

for password in range(number):
    passwords = ''
    for c in range(length):
        passwords += random.choice(chars)
    print(passwords)
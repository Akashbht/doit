import random
import math

up = int(input('Enter the lower limit :'))
low = int(input('Enter the upper limit :'))
x = random.randint(up, low)
count= 0
print('You only get 10 tries for guessing the correct number.')
'''b = round(math.log(upper - lower + 1, 2))
print("\n\tYou've only ", round(math.log(upper - lower + 1, 2))," chances to guess the integer!\n")
while count < math.log(upper - lower + 1, 2):
    count +=1
    g = int(input('Enter your guess :'))

    if g == guess:
        print('Hurray, you got it right.')
    elif g > x :
        print('Its too big, think small')
    elif g < x :
        print('Thats too small. think big')'''
while count < 10:
    count += 1

    # taking guessing number as input
    guess = int(input("Guess a number:- "))

    # Condition testing
    if x == guess:
        print("Congratulations you did it in ", count, " try")
        # Once guessed, loop will break
        break
    elif x > guess:
        print("You guessed too small!")
    elif x < guess:
        print("You Guessed too high!")

# If Guessing is more than required guesses,
# shows this output.
if count >= 10:
    print("\nThe number is %d" % x)
    print("\tBetter Luck Next time!")


if count == 10:
    print('Opps you exceeded the no. of trails.')
    print('Better luck next time.')


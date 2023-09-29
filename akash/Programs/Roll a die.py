import random
import time

min = 1
max = 6

roll_again = True

while roll_again:
    print("Rolling dice .... ")
    time.sleep(random.randint(1, 4))
    result = random.randint(min, max)
    print(result)
    roll_again = False
    repeater = input("Do you want to roll again :(yes or no) ? : ").lower()
    while repeater not in ["yes", "no"]: repeater = input("Invalid Input. Please try again : ").lower()
    if repeater == "yes":
        roll_again = True
    elif repeater == "no":
        roll_again = False

        print("Have a good day.")
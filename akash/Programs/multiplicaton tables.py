again = True
while again:
    num = int(input("Display multiplication table of? "))
    for i in range(1,11):
        print(num,'x',i,'=',num*i)
    again = False
    repeater = input("Do you want to run the program again :(yes or no) ? : ").lower()
    while repeater not in ["yes", "no"]:repeater = input("Invalid Input. Please try again : ").lower()
    if repeater == "yes":
        again = True
    elif repeater == "no":
        again = False
print("Understandable! Have a good day.")
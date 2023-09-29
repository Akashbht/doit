a = int(input("Enter number of classes held"))
b = int(input("Enter number of classes attended"))
c = (b / a) * 100
print("The percentage of your attendance is", c)
if c >= 75:
    print("Your are allowed to sit in exams")
else:
    print("Your are not allowed to sit in exams")
print("Are you mentally or physically disabled?")
k = input("Y or N").lower()
if k == 'y':
    print("You are allowed to sit in exams")
else:
    print("You are not allowed to sit in exams")




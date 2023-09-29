l = eval(input('Enter your list :'))
n = int(input('enter the element to be searched :'))
for i in range(len(l)):
    if type(l[i]) == int and l[i] == n:
        print('Exists at position ',i+1)
        break
else:
    print('Not Exists')
with open('D:\\test.txt', mode= 'a') as file:

    file.write('Hello world \n akash bhatt \n Good morning')


file = open('D:\\test.txt', mode= 'r')
print(file.read())
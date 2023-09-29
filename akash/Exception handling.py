def func(a, b):
    try:
        div = a + b

    except:
        print('exception caught')

    else:
        # when no exception
        print('All is well')

    finally:
        # this runs no matter what
        print('I always run')


a = int(input('enter '))
b = int(input('Enter  '))
div = func(a, b)

try:
    file = open('D:\\sample.txt', mode='r')
    print(file.read)

except FileNotFoundError:
    print('File not found')
else:
    print('No exception')


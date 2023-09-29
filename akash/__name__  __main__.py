def func():
    print("func() is called.")

if __name__ == '__main__':
    func()


print('Top level of sample.py')

if __name__ == '__main__':
    print('sample.py run directly')
else:
    print('Test.py not run directly')
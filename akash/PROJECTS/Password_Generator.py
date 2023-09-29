from Random_password_generator import Password
print('''u - for uppercase letters
l - for lowercase letters 
d - for digits
s - for special characters
''')
charset = input('Enter the charset for the password(u,l,d,s)(do not put commas and spaces): ')
digits = int(input('Enter the number of digits in the password: '))
password = Password(charset, digits)
password.set_charset()
password.generate_password()
print("The random password generated is :", password.get_password())
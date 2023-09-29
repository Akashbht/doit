from Mygeometry import my_geometry
# import  Mygeometry

aksh = True
print("Let's Begin")
while aksh:
    # Mygeometry.my_geometry()
    my_geometry()
    con = input('Do you want to run again?(y/n):').lower()
    if con == 'n':
        aksh = False
        print('Understandable. Have a good day!')
    else:
        aksh = True

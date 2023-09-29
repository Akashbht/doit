def my_geometry():

    print('Enter 2. For 3D shapes')
    print('Enter 1. For 2D shapes')
    a = int(input('Enter:'))
    if a == 1:
        print('Enter 1. For circle')
        print('Enter 2. For square ')
        print('Enter 3. for rectangle')
        print('Enter 4. for triangle')
        ch = int(input('Enter :'))
        if ch == 1:
            print('You choose Circle')
            r = int(input('Enter the radius of the circle :'))
            print('Enter 1. For area')
            print('Enter 2. For circumference')
            a = int(input('Enter :'))
            if a == 1:
                area = 3.14159265 * r * r
                print('The area of the circle is ', area)
            elif a == 2:
                cir = 2 * 3.14159265 * r
                print('The circumference of the circle is ', cir)
        elif ch == 2:
            print('You choose square')
            s = int(input('Enter the side of the square :'))
            print('Enter 1. For area')
            print('Enter 2. For perimeter')
            b = int(input('Enter :'))
            if b == 1:
                area = s * s
                print('The area of the square is ', area)
            elif b == 2:
                peri = 4 * s
                print('The perimeter of the square is ', peri)
        elif ch == 3:
            print('You choose rectangle')
            y = int(input('Enter the length :'))
            z = int(input('Enter the breadth :'))
            print('Enter 1. For area')
            print('Enter 2. For perimeter')
            c = int(input('Enter :'))
            if c == 2:
                peri = 2 * (y + z)
                print('The perimeter of the rectangle is ', peri)
            else:
                area = y * z
                print('The area of the rectangle is ', area)
        else:
            print('You choose triangle')
            base = int(input('Enter the base of the triangle :'))
            hei = int(input('Enter the height of the triangle :'))
            print('Enter 1. For area')
            print('Enter 2. For hypotneuse')
            d = int(input('Enter:'))
            if d == 1:
                area = 1 / 2 * base * hei
                print('The area of the triangle is ', area)
            else:
                hypo = (base ** 2 + hei ** 2) ** (1 / 2)
                print('The hypotneuse of the triangle is ', hypo)

    else:
        print('Enter 1. For cube')
        print('Enter 2. For cuboid ')
        print('Enter 3. for cylinder')
        print('Enter 4. for cone')
        print('Enter 5. For sphere')
        print('Enter 6. For hemisphere ')
        i = int(input('Enter:'))
        if i == 1:
            print('''Cube is created''')
            side = int(input('Enter the side of the cube:'))
            ope = int(input('''Enter 1. for Volume
Enter 2. for total surface area
Enter 3. for curved surface area
Enter: '''))
            if ope == 1:
                volume = side**3
                print('The volume of the cube is', volume)
            elif ope == 2:
                tsa = 6 * side**2
                print('The total surface area of the cube is', tsa)
            elif ope == 3:
                csa = 4 * side**2
                print('The curved surface area of the cube is', csa)

        elif i == 2:
            print('''Cuboid is created''')
            length = int(input('Enter the length of the cuboid:'))
            breadth = int(input('Enter the breadth of the cuboid:'))
            h = int(input('Enter the h of the cuboid:'))
            ope = int(input('''Enter 1. for Volume
Enter 2. for total surface area
Enter 3. for curved surface area
Enter: '''))
            if ope == 1:
                volume = length * breadth * h
                print('The volume of the cuboid is', volume)
            elif ope == 2:
                tsa = 2*(length*breadth + breadth*h + length*h)
                print('The total surface area of the cube is', tsa)
            elif ope == 3:
                csa = 2*(length*breadth)*h
                print('The curved surface area of the cuboid is', csa)

        elif i == 3:
            print('''Cylinder is created''')
            r = int(input('Enter the radius of the cylinder:'))
            h = int(input('Enter the height of the cylinder:'))
            ope = int(input('''Enter 1. for Volume
Enter 2. for total surface area
Enter 3. for curved surface area
Enter: '''))
            if ope == 1:
                volume = 3.141 * r**2 * h
                print('The volume of the cylinder is', volume)
            elif ope == 2:
                tsa = 2*3.141*r*h + 2*3.141*r**2
                print('The total surface area of the cylinder is', tsa)
            elif ope == 3:
                csa = 2*3.141*r*h
                print('The curved surface area of the cylinder is', csa)

        elif i == 4:
            print('Cone is created')
            r = int(input('Enter the radius of the cone:'))
            h = int(input('Enter the height of the cone:'))
            l = int(input('Enter the slant height of the cone:'))
            ope = int(input('''Enter 1. for Volume
Enter 2. for total surface area
Enter 3. for curved surface area
Enter: '''))
            if ope == 1:
                volume = 3.141 * r ** 2 * h * 1/3
                print('The volume of the cone is', volume)
            elif ope == 2:
                tsa = 3.141*r*l + 3.141*r**2
                print('The total surface area of the cone is', tsa)
            elif ope == 3:
                csa = 3.141*r*l
                print('The curved surface area of the cone is', csa)

        elif i == 5:
            print('''Sphere is created''')
            r = int(input('Enter the radius of the sphere:'))
            ope = int(input('''Enter 1. for Volume
Enter 2. for total surface area
Enter: '''))
            if ope == 1:
                volume = 4/3 * 3.141*r**3
                print('The volume of the sphere is', volume)
            elif ope == 2:
                tsa = 6 * 3.141*r**2
                print('The total surface area of the sphere is', tsa)

        elif i == 6:
            print('''Hemisphere is created''')
            r = int(input('Enter the radius of the hemisphere:'))
            ope = int(input('''Enter 1. for Volume
Enter 2. for total surface area
Enter 3. for curved surface area
Enter: '''))
            if ope == 1:
                volume = 2 / 3 * 3.141 * r ** 3
                print('The volume of the hemisphere is', volume)
            elif ope == 2:
                tsa = 3 * 3.141 * r**2 + 3.141*r**2
                print('The total surface area of the hemisphere is', tsa)
            elif ope == 3:
                csa = 3* 3.141*r**2
                print('The curved surface area of the cone is', csa)





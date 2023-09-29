class Quadrilateral:

    def __init__ (self, length, breadth):

        self.length = length
        self.breadth = breadth
        print('Quadrilateral is created.')

    def get_type(self):

        return 'Quadrilateral'


class Rectangle(Quadrilateral):

    def __init__(self,length, breadth):

        Quadrilateral.__init__(self, length , breadth)
        print('Rectangle is created.')

    def get_area(self) :
        return self.length * self.breadth

    def get_perimeter(self):
        return 2*(self.length+self.breadth)

    def get_type(self):
        return 'Rectangle'


class Square:

    def __init__(self, length):
        self.length = length

        print('Square is created.')

    def get_area(self):
        return self.length **2

    def get_perimeter(self):
        return 4*self.length

    def get_type(self):
        return 'Square'


class Rhombus:

    def __init__(self, length):
        self.length = length

        print('Rhombus is created.')

    def get_area(self):
        return self.length **2

    def get_perimeter(self):
        return 4*self.length

    def get_type(self):
        return 'Rhombus'

#
# sq = Square(34)
# print(sq.get_perimeter())
# print(sq.get_area())
# print(sq.get_type())


shape = input('Enter your shape(square/rectangle/rhombus) :')
if shape == 'square':
    side = int(input('Enter the side of the square:'))
    shape = Square(side)
    operation = int(input('Enter 1 for area and 2 for perimeter :'))
    if operation == 1:
        print('the area of the square is ', shape.get_area())
    else:
        print('The perimeter of the square is ', shape.get_perimeter())

elif shape == 'rectangle':
    length = int(input('Enter the length of the rectangle: '))
    breadth = int(input('Enter the breadth of the rectangle:'))
    shape = Rectangle(length,breadth)
    operation = int(input('Enter 1 for area and enter 2 for perimeter :'))
    if operation == 1:
        print('The area of the rectangle is', shape.get_area())
    else:
        print('The perimeter of the rectangle is', shape.get_perimeter())
elif shape == 'rhombus':
    side = int(input('Enter the side of the rhombus :'))
    shape = Rhombus(side)
    operation = int(input('Enter 1 for area or 2 for perimeter :'))
    if operation == 1:
        print('The area of the Rhombus is', shape.get_area())
    else:
        print('The perimeter of the Rhombus is', shape.get_perimeter())


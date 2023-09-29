class Student:
    def __init__(self, rollno, name):

        self.rollno = rollno
        self.name = name

    def __str__(self):

        return 'Class str is called.'

    def __len__(self):
        return len(self.name)

    def __del__(self):
        print('Student is destroyed')

student = Student(12,'Atul')
print(len(student))
del student
print(student)
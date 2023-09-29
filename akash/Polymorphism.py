






class kali:
    def advantage(self):
        print('Powerful')

    def disadvantage(self):
        print('Resourse inensive')

class Parrot:

    def advantage(self):
        print('Light weight')

    def disadvantage(self):
        print('Small community')

kali = kali()
parrot = Parrot()

kali.disadvantage()
parrot.disadvantage()


for object in (kali,parrot):
    print(type(object))
    object.advantage()
    object.disadvantage()


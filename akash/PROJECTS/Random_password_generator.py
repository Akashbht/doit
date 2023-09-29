import random
import string


class Password:
    def __init__(self,charset,length):

        self.charset = charset
        self.char_array = []
        self.length = length
        self.password = []

    def set_charset(self):

        if ('u' in self.charset):
            self.char_array.append(string.ascii_uppercase)

        if ('l' in self.charset):
            self.char_array.append(string.ascii_lowercase)

        if ('d' in self.charset):
            self.char_array.append(string.digits)

        if ('s' in self.charset):
            self.char_array.append(string.punctuation)

    def get_char_array(self):

        return self.char_array

    def generate_password(self):


        for i in range(self.length):

            outer_index = random.randrange(0,len(self.char_array))
            inner_index = random.randrange(0,len(self.char_array[outer_index]))
            self.password.append(self.char_array[outer_index][inner_index])

    def get_password(self):
        return ''.join(self.password)








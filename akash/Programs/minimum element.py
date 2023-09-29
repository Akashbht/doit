l1 = eval(input('Enter the list elements :'))
print(l1)
length = len(l1)
min_element=l1[0]
min_index = 0
for i in range (1,length):
    if l1[i] < min_element:
        min_element = l1[i]
        min_index = i
print('Inputted list is :',l1)
print('the minimun element in the given list is :')
print(min_element,' at index ', min_index)


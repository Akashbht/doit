A = []
B = []
C = []
i = 1
a = int(input('Enter the number of elements in the list'))
while i <= a:
    b = int(input('Enter the element :'))
    A.append(b)
    i = i + 1
for n in A:
    B.append(n)
for j in range(0, len(B)):
    c = B.pop()
    C.append(c)

print('Original list')
print(A)
print('Reversed list')
print(C)

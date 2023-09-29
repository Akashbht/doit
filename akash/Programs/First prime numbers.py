n = int(input('Enter the limit :'))
num = 1
condition = True
ctr = 2
# while ctr <= n:
#     i = 2
#     flag = 0
#     while i < num:
#         if num % i == 0:
#             break
#         i = i + 1
#     else:
#         print(num, end=" ")
#         ctr = ctr + 1
#     num += 1
while ctr <= n:
    for i in range(2,n):
        if n/i == 0:
            condition = False
else:
    condition = True
if condition == False:
    print()
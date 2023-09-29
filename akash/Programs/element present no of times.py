L1 = [10,20,30,40,10,50,10]
c= 0
a = int(input("Enter you number. :"))
for i in L1:
    if a == i:
        c += 1
print(a," is present ",c," times in L1")

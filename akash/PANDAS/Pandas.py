import numpy as np
import pandas as pd
'''s = pd.Series([1,2,3,4,5],index=['a','b','c','d','e'])
print(s['a'])
dict1 = dict([
    ('first',1),
    ('second',2),
    ('Third',3)
])
print(dict)
vls = pd.Series([11,23,31,61,87,93], index=['a','b','c','d','e','f'])
print(vls[-2:])
print(vls[['b','e','f']])


list1 = [{
          'Delhi':[12,32,523,23,],
          'Beng':[223,35,34,32]}]
df = pd.DataFrame(list1,columns=['City','axtemp'])
print(df)
l =[1,2,34,54]
s = {}
df2 = pd.DataFrame(s)
print(df2)
df2['class']=l
print(df2)

column1 = {62.893165,94.734483,49.090140,38.487265}
column2 = {100,100,100,85.4}
column3 ={60,59.22,46.84,58.62}
res = {'T1':'True','T2':'True','T3':'False','T4':'False'}
list1 = [column1,column2,column3,res]
df = pd.DataFrame(, columns=['Column1','Column2','Column3','Res'])
print(df)
s = {"Column1":[62.893165,94.734483,49.090140,38.487265],
     "Column2":[100,100,100,85.4],
     "Column3":[60,59.22,46.84,58.62],
     "Res":["True",'True','False','False']}
df = pd.DataFrame(s,index=["T1",'T2','T3','T4'])
df['Eligible'] = "Yes"
#print(df)

a = {"Age":[20,19,22,21],
     "favourite_color":['Blue','red','yellow','green'],
     'marks':[95,88,92,70]}
names = ['Riya sen','Asma Tauhid','GUrkirat Kaur','Daniel Thasmes']
df2 = pd.DataFrame(a,index=names)
df2['Eligible']='Yes'


print(df2)

D1 = {"Riya Sen":20,"Asma Tauhid":19,"Gurkirat Kaur":22,"Daniel Thames":21}
S1 = {"Riya Sen":"Blue","Asma Tauhid":"Red","Gurkirat Kaur":"Yellow","Daniel Thames":"Green"}
A1 = {"Riya Sen":88,"Asma Tauhid":92,"Gurkirat Kaur":89,"Daniel Thames":70}
X1 = {"Age":D1,"Favourite_Color":S1,"Marks":A1}
L1 = pd.DataFrame(X1)
print(L1)

# DataFrames
  X  Y  Z
0 78 84 86
1 85 94 97
2 96 89 96
3 80 83 72
4 86 86 83

data = {'X':[78,54,34,45,54],
        'Y':[67,56,67,87,76],
        'Z':[78,87,56,67,86]}
df = pd.DataFrame(data)
print(df)


exam_data = {'name': ['Anastasia', 'Dima', 'Katherine', 'James', 'Emily', 'Michael', 'Matthew', 'Laura', 'Kevin', 'Jonas'],
             'score': [12.5, 9, 16.5, np.nan, 9, 20, 14.5, np.nan, 8, 19],
             'attempts': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
             'qualify': ['yes', 'no', 'yes', 'no', 'no', 'yes', 'yes', 'no', 'no', 'yes']}
labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
fd = pd.DataFrame(data=exam_data,index=labels)
#print(fd)
#2nd part, print the iformation of the table
#print(fd.info())
#3rd part,print first 3 rows of the data
#print(fd.iloc[:3])
#print specific columns
#print(fd[['name','score']])
#print(fd.iloc[[1,2,3],[1,2]])
df = pd.DataFrame({'a1':[1,2,3],'b1':[4,5,6],'c1':[7,8,9]})

b =[{'Name' :'Akash','Class':'XI A'},{'Name':'Ankush','Class':'XI B'},{'Name':'Nikhil','Class':'XI A'}]
df = pd.DataFrame(b, index=['a','b','c'])
#print(df[['Class','marks','Name']])
df['marks'] =[10, 20, 30]
df['mark2'] = df['marks'] + 5

print(df)

d1 = {'ankita':20,'rahul':45,'dev':54}
d2 = {'ankita':45,'rahul':76,'dev':53}
d3 = {'ankita':70,'rahul':55,'dev':34}
df1 = pd.DataFrame({'maths':d1,'eng':d2,'hindi':d3})
#Deleting columns
#del df1['hindi']
#df1.pop('maths')
#print(df1.loc['ankita':'dev','maths':'eng'])
# for printing all rows and columns
#print(df1.loc[ : , :])
# use iloc for printing specific columns and rows
#print(df1.iloc[0:2])
# adding columns using loc
#df1.loc[:,'science']=[10,20,30]
#adding rows using loc
#df1.loc['akash',:] = [46,67,54]
#print(df1)

grade = {'Name':['Rashmi','Harsh','Ganesh','Priya','Vivel','Anita','Kartik'],

         'Grade':['A1','A2','B1','A1','B2','A2','A1']}
Gr = pd.DataFrame(grade)
#print(Gr)

data1 = {'Color':['Red','Green','Red','Green','Green'],
         'Count':[3,9,25,26,99],
         'Price':[120,110,125,150,70]}
data = pd.DataFrame(data1,index=['Apple','Apple','Pear','Pear','Lime'])
#print(data)

#for printing the count more than 25

#print(data[data1['Count']> 25])

# for getting only the coulmns count and price usng loc with all rows

#print(data.loc[:,['Color','Price']])

# list only columns 0 nad 2 using iloc

#print(data.iloc[:,[0,2]])

#for printing rows

#print(data.iloc[[1,3,4]])

# for deleting rows 'Apple' and 'Lime'

#data.drop(['Apple','Lime'])

# for deleting the columns named 'count' and 'Color'
# there are 3 ways pop, del , drop

#drop
data.drop(['Color','Count'],axis=1)
#print(data)
'''

s = {"Column1":[62.893165,94.734483,49.090140,38.487265],
     "Column2":[100,100,100,85.4],
     "Column3":[60,59.22,46.84,58.62],
     "Res":["True",'True','False','False']}
df = pd.DataFrame(s,index=["T1",'T2','T3','T4'])

# print(df.iloc[1:3,2:3])
df.loc['Column5']=[ 70.0, 89.34, 76.43, 67.81]

print(df)
print(df['T1':'T4'])






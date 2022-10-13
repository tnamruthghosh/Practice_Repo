n = 12

sum=1 

for i in range(2,n):
  if(n%i==0):   
   sum=sum+i

if(sum>n):
  print(n,'is Abundant Number')

else:
  print(n,'is not Abundant Number')

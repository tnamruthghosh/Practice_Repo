def bubblesort(list1):
   for num in range(len(list1)-1,0,-1):
      for i in range(num):
         if list1[i]>list1[i+1]:
            temp = list1[i]
            list1[i] = list1[i+1]
            list1[i+1] = temp
list1 = list(map(int,input().split(',')))
bubblesort(list1)
print(list1)

a=0
b=1
c=0
n=0
print("enter the no till which you want a fibonacci")
n=int(input())
print("the fibonacci sequence is as follows")
print(a)
print(b)
for i in range(n):
  c=a+b
  a=b
  b=c
  print(c)
 

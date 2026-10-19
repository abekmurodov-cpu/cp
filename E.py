arr = []
counter = 0
n,k=map(int,input().split())
m=n
while (n-1)<k:
    flag = 1
    print(n,end=" ")
    counter+=1
    n-=1
    k-=n
for i in range(n-1):
    if i==(n-1-k):
        print(n,end=" ")
        counter+=1
    print(i+1,end=" ")
    counter+=1

if counter!=m:
    print(m,end=" ")
    

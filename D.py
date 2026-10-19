ans =[[1,1]]

for i in range(1,123457):
    s= str(i)
    flag = 0
    flag2 = 0
    for j in s:
        if j == '4' or j == '2' or j == '6' or j == '9':
            flag2 = 1
            break
        elif j == '3' or j == '7':
            flag = 1
    if flag2 !=0:
        ans.append([ans[i-1][0],ans[i-1][1]])
    else:
        if flag == 0:
            ans.append([ans[i-1][0]+1,ans[i-1][1]+1])
        else:
            ans.append([ans[i-1][0],ans[i-1][1]+1])

N = int(input())

print(ans[N][0], ans[N][1])





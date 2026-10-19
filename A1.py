n,q=map(int,input().split())
words=[]
orgs=[]

y_words=[]
y_copy=[]

for i in range(n):
    w=input()
    orgs.append(w)
    w=w.replace("e","a")
    w=w.replace("i","a")
    w=w.replace("o","a")
    w=w.replace("u","a")

    y_loc=[]
    for j in range(len(w)):
        if w[j]=="y":
            y_loc.append(j)

        
    if len(y_loc)>0:
        y_words.append([w, y_loc, i])
        

    words.append(w)



def y_combination(w, y_loc, index):
    y_count = len(y_loc)
    bits = []
    new_words =[]
    for i in range(2**y_count):
        bits.append(bin(i)[2:])
    for i in range(len(bits)):
        new_w = list(w)
        for c in range(len(bits[i])):
            if bits[i][c]=="1":
                new_w[y_loc[c]]="a"

        new_words.append(str.join("", new_w))
    return new_words

for words in y_words:
    y_copy.extend(y_combination(words[0],words[1]))

print(y_copy)


        
for i in range(q):
    flag=2
    s=""
    m=list(input().split())
    for m1 in m[1:]:
        if words.count(m1)==0 :
            flag=0
            break
        elif words.count(m1)==1  and flag==2:
            s+=orgs[words.index(m1)]+" "
        else:
            flag=1
    if flag==0:
        print("impossible")
    elif flag==1:
        print("ambiguous")
    else:
        print("possible",s)
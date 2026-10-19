for i in range(int(input())):
    a, b = map(int, input().split())
    print((a//b+1)*a-((b+a//b*b)*(a//b)//2))
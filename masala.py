t = int(input())
print(type(t))
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    c = [0] * (n + 1)
    for val in a:
        c[val] += 1
        
    last_false = float('inf')
    
    for x in range(n, 0, -1):
        if c[x] > 0:
            if last_false <= x + k:
                # Dabir can move to a state that guarantees Egor loses, 
                # so Dabir has a winning strategy from here (L = True)
                W = True
            else:
                # Dabir has no good type 2 moves, forced to drain current value.
                # Outcome depends on count parity.
                W = (c[x] % 2 == 0)
                
            if not W:
                last_false = x
    
    if last_false <= n:
        print("YES")
    else:
        print("NO")

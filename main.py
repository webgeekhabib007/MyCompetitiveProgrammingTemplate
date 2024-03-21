for _ in range(int(input())):
    n,m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    
    ans = 1e18
    now = 0
    
    for i in range(n-1,-1,-1):
        if i<m :
            ans = min(ans,now+a[i])
            
        now+= min(a[i],b[i])
            
    print(ans)
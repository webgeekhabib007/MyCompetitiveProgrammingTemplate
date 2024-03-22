for _ in range(int(input())):
    n,m,a = [int(x) for x in input().split()]
    q = []
    q.append(set())
    q.append(set())
    ix = 0
    q[ix].add(a)
    
    while m>0:
        x,ch = [x for x in input.split()]
        x = int(x)
        
        m-=1
        print(dir(q[ix]))
            
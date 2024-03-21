x,n =  map(int,input().split())

primes_fact = []

i=2
while i*i<= x:
    if x%i==0:
        primes_fact.append(i)
        while x%i==0:
            x//=i    
    i+=1
    
if x>1:
    primes_fact.append(x)
mod = 10**9+7
ans = 1
for primes in primes_fact:
    power = 0
    fact = primes
    while fact <= n:
        power+=n//fact
        fact*=primes
    
    ans*= pow(primes,power,mod)
    ans%=mod
    
print(ans)
import math
primes = []
def Sieve(n):
    half = n//2
    nNew = int(math.sqrt(n))
    marked = [0]*(n)
    for i in range(1, (nNew-1)//2 + 1):
        for j in range(i*(i+1) << 1,half+1, 2*i+1):
            marked[j] = 1
    primes.append(2)
    for i in range(1, half + 1):
        if (marked[i] == 0):
            primes.append(2*i+1)
Sieve(int(input()))
print(*primes)

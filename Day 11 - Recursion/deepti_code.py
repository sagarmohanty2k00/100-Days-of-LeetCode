def prime(n):
    pass

n = int(input())
ans = 1
for i in range(1, (n//2)+1):
    if n%i == 0:
        prime = True

        for j in range(2, i):
            if (n % j) == 0:
                prime = False
                break

        if prime:
            ans = max(ans, i)

print(ans)
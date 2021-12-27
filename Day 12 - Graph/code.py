k = int(input())
n = int(input())
s = input()

i = 0
j = 0

count = 0
ans = 0

while (count < k):
    if s[j] == '1':
        count += 1
    
    j += 1

if (j < len(s)):
    ans += 1

while (j < len(s)):
    

print(ans)
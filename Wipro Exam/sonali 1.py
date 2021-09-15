def fun(a):
    l = []
    for i in range(4):
        l.append(a%10)
        a //= 10
    
    l.sort()

    return l[3] - l[0]
    

inp1, inp2, inp3 = map(int, raw_input().split())

l = [inp1, inp2, inp3]

key = 0
for i in range(3):
    key += fun(l[i])

print key
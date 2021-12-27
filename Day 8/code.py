s1 = s[d:] + s[:d]
s2 = s[-1*d:] + s[:-1*d]

ans = []

ans.append(s1)
ans.append(s2)

return ans
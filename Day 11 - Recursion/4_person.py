def decide_path(l1, l2, pathCost, island):
    # check for any False
    complete = True
    for x in l2:
        complete = x and complete

    if complete:
        # print (f"min path cost : {pathCost}")
        return pathCost

    if island == 1:
        ans = 32
        for i in  range(4):
            if l2[i] == True:
                l2[i] = False

                op = decide_path(l1, l2, pathCost+l1[i], 0)
                ans = min(ans, op)
                
                # print (f"{l1[i]} returns and ans would be : {op}")
                l2[i] = True

        return ans

    ans = 32
    for i in  range(3):
        for j in range(i+1, 4):
            if l2[i] == False and l2[j] == False:
                l2[i] = True
                l2[j] = True

                pathCost += max(l1[i], l1[j])
                op = decide_path(l1, l2, pathCost, 1)
                ans = min(ans, op)
                pathCost -= max(l1[i], l1[j])
                # print (f"{l1[i]} and {l1[j]} goes and ans would be : {op}")

                l2[i] = False
                l2[j] = False

    return ans

l1 = [1, 2, 4, 5]
l2 = [False, False, False, False]

print(f"min traversal cost = {decide_path(l1, l2, 0, 0)}")
def lcsStr(l,i,j,returnList = None):
    if returnList is None:
        returnList = []
    if l[i][j][0] == 0:
        return returnList[::-1]
    up = l[i-1][j]
    left = l[i][j-1]    

    if up[0] == l[i][j][0]:
        
        return lcsStr(l,i-1,j,returnList)
    elif left[0] == l[i][j][0]:
        return lcsStr(l,i,j-1,returnList)
    else:
        returnList.append(l[i][j][1])
        return lcsStr(l,i-1,j-1,returnList)
dp = []
def lcs(x,y):
    global dp
    xn,yn = len(x),len(y)
    dp = [[0 for i in range(yn+1)] for j in range(xn+1)]
    for i in range(xn+1):
        for j in range(yn+1):
            if i == 0 or j == 0:
                dp[i][j] = [0,'\0']
            elif x[i-1] == y[j-1]:
                dp[i][j] = [dp[i-1][j-1][0]+1,y[j-1]]
            else:
                dp[i][j] = [max(dp[i-1][j][0],dp[i][j-1][0]),'\0']
    return lcsStr(dp,xn,yn)
l = input()
a = input().split()
b = input().split()
print(*lcs(a,b))

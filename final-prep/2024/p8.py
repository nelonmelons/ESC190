

def canBeSegmented(s, wordDict):
    n = len(s) + 1
    dp = [False] * n
    dp[0] = True
    
    for i in range(1, n):
        for j in range(0, i):
            if dp[j] is True and s[j:i] in wordDict:
                dp[i] = True
                break
    return dp[n-1]


s = "penapplepen"
wordDict = ["pen", "apple"]
print(canBeSegmented(s, wordDict))    

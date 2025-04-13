class Solution:
    def minCost(self, costs):
        res = [0, 0, 0]
        for i in range(len(costs)):
            res1 = costs[i][0] + min(res[2], res[1])
            res2 = costs[i][1] + min(res[0], res[2])
            res3 = costs[i][2] + min(res[1], res[3])
            res = [res1, res2, res3]
        return min(res)
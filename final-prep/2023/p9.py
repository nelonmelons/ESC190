def mincost(cost: list[int]) -> list[int]:
    n = len(cost)
    dp = [0, 0, 0]
    for i in range(n):
        dp1 = len
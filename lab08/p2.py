#part A
#OPT(n) = 1 + min(OPT(n-1), OPT(n-4), OPT(n-5))

#PART B

def OPT(target, denominations):
    res = [float("inf")] * (target + 1)
    res[0] = 0
    for i in range(1, target+1):
        for d in denominations:
            if d <= i:
                res[i] = min(res[i], 1 + res[i-d])
    return res


#Part (c)

def coin_change_coins(denominations, target):
    # DP array for storing minimum coins needed for each amount
    OPT = [float('inf')] * (target + 1)
    # choice[i] will store which coin was chosen to reach the optimal solution for i
    choice = [-1] * (target + 1)

    # Base case
    OPT[0] = 0
    choice[0] = 0  # No coin needed for 0

    # Build up the OPT array
    for i in range(1, target + 1):
        for d in denominations:
            if d <= i:
                # If using coin d leads to a better b(fewer coins) solution:
                if OPT[i - d] + 1 < OPT[i]:
                    OPT[i] = OPT[i - d] + 1
                    choice[i] = d  # record that we used coin d for the best solution at i

    # Reconstruct which coins were used
    coins_used = []
    i = target
    while i > 0:
        d = choice[i]        # the coin that was used for amount i
        coins_used.append(d) # add it to the solution list
        i = i - d            # move to the remaining amount

    # The coins_used list will be in reverse order (from target down to 0),
    # so you might want to reverse it if you want them from first coin to last:
    coins_used.reverse()

    # Return both the table (if needed) and the actual coins used
    return coins_used

    
# Write code that returns a list of the coins you need to make up a target amount, when the least possible
# number of coins is used. (For example, the function would return [4, 4], if the denominations are
# [1c, 4c, 5c] and the target is 8).
# Follow the example from houses.py. The first coin used, denom, should be such that 1 + OPT(n-denom)
# is as small as possible. To determine the next coin, denom2, make 1 + 1 + OPT(n-denom-denom2) as
# small as possible.
# (Note: it is possible to keep track of the coins used when computing OPT, but here we are asking for
# you to do something analogous to houses.py).
    
    


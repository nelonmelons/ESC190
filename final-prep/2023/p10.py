def friendshipchain(d):
    #use DFS -> stack
    longest = 1
    for person in d:
        visited = []
        stack = [person]
        while len(stack) > 0:
            p = stack.pop()
            if p not in visited:
                visited.append(p)
                for friend in d[p]:
                    if friend not in visited:
                        stack.append(friend)
        longest = max(len(visited), longest)
    return longest

friends = {"Carl Gauss": ["Isaac Newton", "Gottfried Leibniz", "Charles Babbage"],
"Gottfried Leibniz": ["Carl Gauss"],
"Isaac Newton": ["Carl Gauss", "Charles Babbage"],
"Ada Lovelace": ["Charles Babbage", "Michael Faraday"],
"Charles Babbage": ["Isaac Newton", "Carl Gauss", "Ada Lovelace"],
"Michael Faraday": ["Ada Lovelace"] }

print(friendshipchain(friends))
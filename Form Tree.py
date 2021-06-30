d = []
for i in range(n+1):
    d.append([])
for _ in range(n-1):
    p,c = map(int,input().split())
    d[c].append(p)
    d[p].append(c)
t = 0
tree = [1]
pc = []
for i in range(n+1):
    pc.append([])
vi = set()
while len(tree):
    for i in tree:
        vi.add(i)
        if len(set(d[i])-vi)!= 0:
            pc[i] = []
        else:
            pc[i] = [-1]
        for j in set(d[i])-vi:
            tree.append(j)
            pc[i].append(j)
        tree.remove(i)

import sys 

def Ask(y):
    res = int(input())
    return res

y, q, seed = input().split()
y = int(y)
q = int(q)
seed = int(seed)

while True:
    print(str((y + 1) // 2))
    print('')
    sys.stdout.flush()
    t = Ask(y)
    if t == 0:
        y += (y + 1) // 2
    elif t == 1:
        y -= y
    else:
        break
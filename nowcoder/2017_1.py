import sys

for line in sys.stdin:
    a = line.split(' ')
    n,m = int(a[0]), int(a[1])

    print(m*n//2)


import sys
data = sys.stdin.readlines()
n = int(data.pop(0))

for i in range(n):
    l = int(data[2*i].strip())
    num = data[2*i+1].strip()

    if l<11 or (l==11 and int(num[0])!=8): sys.stdout.write("NO\n")
    elif l==11 and int(num[0])==8: sys.stdout.write("YES\n")
    else:
        found = 0
        c = l-10
        for i in range(c):
            if int(num[i])==8:
                found = 1
                break
        if found: sys.stdout.write("YES\n")
        else: sys.stdout.write("NO\n")
        
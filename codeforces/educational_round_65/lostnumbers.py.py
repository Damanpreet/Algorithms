import sys

nums = [4, 8, 15, 16, 23, 42]
product = {i*j: (i,j) for i in nums for j in nums}
queries = ["? 1 2", "? 2 3", "? 4 5", "? 5 6"]
answers = []

for query in queries:
    sys.stdout.write(query+"\n")
    sys.stdout.flush()
    number = int(input())
    answers.append(product[number])

out = [0] * 6
out[1] = set(answers[0]).intersection(set(answers[1])).pop()
out[4] = set(answers[2]).intersection(set(answers[3])).pop()

output="! "
i=0
for answer in answers:
    for e in answer:
        if e!=out[1] and e!=out[4]:
            out[i] = e
            if i==0 or i==3: i+=2
            else: i+=1

output += ' '.join(str(x) for x in out)
sys.stdout.write(output+"\n")
sys.stdout.flush()

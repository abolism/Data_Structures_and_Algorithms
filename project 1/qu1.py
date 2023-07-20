
n, k = input().split()
n, k = int(n) , int(k)
# print(n , k)
elements = []
# for i in range(0,int(n)) :
elements = input().split()
for i in range (0, len(elements)) :
    elements[i] = int(elements[i])
# print(elements)

counter = 0
for i in range (0 , len(elements)):
    for j in range(i , len(elements)):
        toCheck = 0
        for l in range (i,j+1) :
            toCheck += elements[l]
        if toCheck <= k :
            counter += 1

print(counter)
arr = [5, 1, 4, 2, 8]

def bubbleSort():
    for i in range(len(arr)-1):
        flag = True
        print("Pass ", i+1)
        for j in range(len(arr)-i-1):
            if arr[j] > arr[j+1]:
                # swap
                flag = False
                arr[j] += arr[j+1]
                arr[j+1] = arr[j] - arr[j+1]
                arr[j] -= arr[j+1]
        
        for elem in arr:
            print(elem, end="\t")
        print()
        
        if flag:
            break

if __name__ == '__main__':
    bubbleSort()
    # Print sorted array
    print("Sorted array: ")
    for elem in arr:
        print(elem)
        
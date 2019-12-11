class Solution:
    '''
        1. Brute force solution
    '''
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if k>=n: k%=n
        
        if k < int(n/2):
            while k:
                temp=nums[n-1]
                for i in range(n-1, 0, -1):
                    nums[i] = nums[i-1]
                nums[0]=temp
                k-=1
        else:
            k = n-k
            while k:
                temp=nums[0]
                for i in range(n-1):
                    nums[i] = nums[i+1]
                nums[n-1]=temp
                k-=1

    
    '''
        Cyclic rotation
    '''
    def cyclic_rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if k>=n: k%=n
        
        visited = list(range(k))
        
        for j in range(k):
            if j in visited:
                visited.remove(j)
                
                elem = nums[j]
                i = j+k
                while i!=j:
                    temp = nums[i]
                    if i in visited:
                        visited.remove(i)
                    nums[i] = elem 
                    elem = temp
                    i+=k
                    if i>=n: i=i-n

                nums[j] = elem   

    '''
        Cyclic rotate constant space O(1)
    '''
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if k>=n: k%=n
        
        count = 0
        start = 0
        while count != n:
            curr = (start+k)%n
            prev = nums[start]
            while start!=curr:
                temp = nums[curr]
                nums[curr] = prev
                prev = temp
                count += 1
                curr = (curr+k)%n
            nums[start] = prev
            count+=1
            start += 1
        
    '''
        By Reversing the lists.
    '''
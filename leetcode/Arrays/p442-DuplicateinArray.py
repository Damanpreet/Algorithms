class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result=[]
        n = len(nums)
        
        for i in range(n):
            if nums[abs(nums[i])-1] < 0:
                result.append(abs(nums[i]))
            nums[abs(nums[i])-1]=nums[abs(nums[i])-1] * -1
        
        return result
# by converting to string
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        evenc=0
        for num in nums:
            count=len(str(num))
            if count%2==0: evenc+=1
        return evenc

# dividing by 10 
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        evenc=0
        for num in nums:
            count = 0
            while num:
                count+=1
                num//=10
            if count%2==0: evenc+=1
        return evenc
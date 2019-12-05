from collections import defaultdict

class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        dp = defaultdict(lambda: 0)
        
        for i in range(K):
            dp[i] = (i+1)*max(A[:(i+1)])
            
        for i in range(K, len(A)):
            dp[i] = max(dp[i], max([dp[i-j]+(j*max(A[i-j+1:i+1])) for j in range(1, K+1) if i-j>=-1]))
                
        
        return dp[len(A)-1]
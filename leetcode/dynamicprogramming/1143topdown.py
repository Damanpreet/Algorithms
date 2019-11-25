# Problem 1143 (Longest common subsequence) - iterative approach

from collections import defaultdict

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:        
        n = len(text1)
        m = len(text2)
        lcs = defaultdict(lambda: defaultdict(lambda: 0))
        
        for i in range(1, n+1):
            for j in range(1, m+1):
                if text1[i-1] == text2[j-1]: 
                    lcs[i][j] = lcs[i-1][j-1]+1
                else:
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1])
        
        return lcs[n][m]
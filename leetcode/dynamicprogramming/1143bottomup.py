# Problem 1143 (Longest common subsequence) - bottom up approach with memoization

from collections import defaultdict

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:        
        n = len(text1)
        m = len(text2)
        lcs = defaultdict(lambda: defaultdict(lambda: 0))
        
        def rec(n, m):
            if n<0 or m<0:
                return 0
            else:
                if text1[n]==text2[m]:
                    if (n-1) in lcs and (m-1) in lcs[n-1]:
                        lcs[n][m]=(1+lcs[n-1][m-1])
                    else:
                        lcs[n][m]=(1+rec(n-1, m-1))
                else:
                    if (n-1) in lcs and m in lcs[n-1]:
                        left = lcs[n-1][m]
                    else:
                        left = rec(n-1, m)
                    
                    if n in lcs and (m-1) in lcs[n]:
                        right = lcs[n][m-1]
                    else:
                        right = rec(n, m-1)
                        
                    lcs[n][m] = max(left, right)
                return lcs[n][m]
            
        return rec(n-1, m-1)
from collections import defaultdict
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        x = list(range(1, N+1))
        inedge = dict.fromkeys(x, 0)
        outedge = dict.fromkeys(x, 0)
        for i in range(len(trust)):
            inedge[trust[i][1]]+=1
            outedge[trust[i][0]]+=1
        cands=[]
        for k in outedge:
            if outedge[k]==0:
                cands.append(k)
        if len(cands)!=1 or (len(cands)==1 and inedge[cands[0]]!=N-1):
            return -1
        return cands[0]
class Solution:
    def longestDecomposition(self, text: str) -> int:
        b=len(text)-1
        f=0
        count=0
        fval, bval=0, 0
        
        while(f<b):
            fval += (7**ord(text[f]))
            bval += (7**ord(text[b]))
            if fval == bval:
                count+=2
                fval=0
                bval=0
            f+=1
            b-=1
                
        if fval!=0 or bval!=0 or f==b: count+=1
        return count
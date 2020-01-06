class Solution:
    def judgeCircle(self, moves: str) -> bool:
        side = 0
        up = 0
        
        for move in moves:
            if move=='L': side-=1
            elif move=='R': side+=1
            elif move=='U': up+=1
            else: up-=1
        
        if side==0 and up==0: return True
        else: return False
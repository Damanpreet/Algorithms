from collections import defaultdict, deque

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        rooms_set = set(range(len(rooms)))
        accessed_set = set()
        curr_access = deque([0])
        
        corr_rooms = dict()
        for i, room in enumerate(rooms):
            corr_rooms[i] = room
        
        # using Deque
        while curr_access:
            elem=curr_access.popleft()
            accessed_set.add(elem) # only if visited add it to the set
            curr_access.extend([r for r in corr_rooms[elem] if r not in accessed_set])
        
        if len(rooms_set-accessed_set)!=0:
            return False
        return True
            
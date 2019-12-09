# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if k==0: return head
        prevnode = {}        
        node=head
        prev=None
        l=0
        while node:
            l+=1
            prevnode[node] = prev
            prev=node
            node=node.next
        node=prev
        
        if l==0 or l==1: return head
        if k>=l:
            k=k%l
        if k==0: return head
        
        l=1
        while l<k:
            l+=1
            node=prevnode[node]
    
        nhead=node
        while node.next:
            node = node.next
        node.next=head
        prevnode[nhead].next=None
        
        return nhead
            
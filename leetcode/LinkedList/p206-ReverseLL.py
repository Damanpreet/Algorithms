# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# recursive solution
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        def rec(node, prev):
            if node:
                nextnode=node.next
                node.next=prev
                return rec(nextnode, node)
            else:   return prev
            
        head=rec(head, None)
        return head

# iterative solution
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        
        while head:
            nextnode = head.next
            head.next = prev
            prev = head
            head = nextnode            
        return prev  
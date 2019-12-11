# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
    
        if root==None: return False
    
        def search_path(node, running_sum):
            if node:
                running_sum += node.val
                if not node.left and not node.right and running_sum == sum: return True
                return search_path(node.left, running_sum) or search_path(node.right, running_sum)
        
        return search_path(root, 0)
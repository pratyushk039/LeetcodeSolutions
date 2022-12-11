# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def max_path_sum(self, root: Optional[TreeNode]) -> int:
        max_path = -float('inf')

        # post order traversal of subtree rooted at `node`
        def gain_from_subtree(node: Optional[TreeNode]) -> int:
            nonlocal max_path

            if not node:
                return 0

            # add the gain from the left subtree. Note that if the
            # gain is negative, we can ignore it, or count it as 0.
            # This is the reason we use `max` here.
            gain_from_left = max(gain_from_subtree(node.left), 0)

            # add the gain / path sum from right subtree. 0 if negative
            gain_from_right = max(gain_from_subtree(node.right), 0)

            # if left or right gain are negative, they are counted
            # as 0, so this statement takes care of all four scenarios
            max_path = max(max_path, gain_from_left + gain_from_right + node.val)

            # return the max sum for a path starting at the root of subtree
            return max(
                gain_from_left + node.val,
                gain_from_right + node.val
            )

        gain_from_subtree(root)
        return max_path
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return self.max_path_sum(root)
        
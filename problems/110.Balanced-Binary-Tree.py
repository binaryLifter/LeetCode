class Solution:
	balanced = True

	def isBalanced(self, root: TreeNode) -> bool:
		self.traverse(root)
		return self.balanced

	def traverse(self, root):
		if root is None:
			return 0
		left = self.traverse(root.left)
		right = self.traverse(root.right)
		if abs(left - right) > 1:
			self.balanced = False
		return max(left,right) + 1
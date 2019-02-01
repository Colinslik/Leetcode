class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if t1 and t2:
            root = TreeNode(t1.val + t2.val)
#           print("t1: ",t1.val," t2: ",t2.val," root: ",root.val)
            root.left = self.mergeTrees(t1.left, t2.left)
            root.right = self.mergeTrees(t1.right, t2.right)
            return root
        elif t1:
            root = TreeNode(t1.val)
#           print("t1: ",t1.val," t2: None"," root: ",root.val)
            root.left = self.mergeTrees(t1.left, None)
            root.right = self.mergeTrees(t1.right, None)
            return root
        elif t2:
            root = TreeNode(t2.val)
#           print("t1: None"," t2: ",t2.val," root: ",root.val)
            root.left = self.mergeTrees(None, t2.left)
            root.right = self.mergeTrees(None, t2.right)
            return root

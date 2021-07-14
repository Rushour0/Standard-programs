class TreeNode:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key
        self.root = None
    def insert(self,key):
        if not self.key:
            self.key = key
            return
        if self.key == key:
            return
        if key<self.key:
            if self.left:
                self.left.insert(key)            
                return
            self.left = TreeNode(key)
            return
        if self.right:
            self.right.insert(key)
            return
        self.right = TreeNode(key)
        return
    def find(self,key):
        if self.key == key:
            return True
        if key<self.key:
            if self.left == None:
                return False
            return self.left.find(key)
        if self.right == None:
            return False
        return self.right.find(key)
    def inorder(self):
        if self.left != None:
            self.left.inorder()
        if self.key != None:
            print(self.key)
        if self.right != None:
            self.right.inorder()

class BinarySearchTree:
    def __init__(self,root):
        self.root = TreeNode(root)
    def insert(self,key):
        self.root.insert(key)
    def find_min(self):
        current = self.root
        while current.left != None:
            current = current.left
        return current.key
    def find_max(self):
        current = self.root
        while current.right != None:
            current = current.right
        return current.key
    def find(self,key):
        return self.root.find(key)
            
    def is_empty(self):
        if self.root.left == None and self.root.right == None:
            return True
        return False

    def print_tree(self):
        self.root.inorder()
    def subtree(self):
        self.root.left.inorder()
        self.root.right.inorder()
        

BST = BinarySearchTree(50)
for i in [20,30,40,50,60,70,80]:
    BST.insert(i)
BST.subtree()
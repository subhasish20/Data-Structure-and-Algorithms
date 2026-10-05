
class Node:
    def __init__ (self,key) -> None:

        # left will connect to the left child ( left tree )
        self.left = None

        # data will store the key ( vlaue of the node )
        self.data = key

        # left will connect to the right child ( right tree )
        self.right = None



class BinaryTree:


    def create_node(self, key) -> Node:

        self.newNode = Node(key)

        return self.newNode

    def insert_at_left(self, key : int , root : Node) -> Node:
        """
         we will take the key that will insert in the left.
         if the root is not created then we will make that as root node else we will insert it in the left side.
        """
        if root is None:
            root = self.create_node(key)
        else:
            root.left = self.create_node(key)

        return root

    def insert_at_right(self, key : int ,root : Node ) -> Node:
        """
         we will take the key that will insert in the right.
         if the root is not created then we will make that as root node else we will insert it in the right side.
        """
        if root is None:
            root = self.create_node(key)
        else:
            root.right = self.create_node(key)

        return root

    def preorder(self, root : Node):
        if root is None:
            return

        print(root.data)
        self.preorder(root.left)
        self.preorder(root.right)

    def inoroder(self, root : Node):
        if root is None:
            return

        self.inoroder(root.left)
        print(root.data)
        self.inoroder(root.right)

    def postorder(self, root : Node):
        if root is None :
            return

        self.postorder(root.left)
        self.postorder(root.right)
        print(root.data)


tree = BinaryTree()


root = tree.create_node(20)

tree.insert_at_left(15, root)
tree.insert_at_right(25,root)

print("Inorder :")
tree.inoroder(root)
print("Preorder :")
tree.preorder(root)
print("Postorder :  ")
tree.postorder(root)

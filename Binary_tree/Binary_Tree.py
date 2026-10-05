
class LLNode:
    def __init__ (self, key: int) -> None:
        """
        Represents a node in the binary tree.
        """
        self.left_node = None
        self.data = key
        self.right_node = None


class BinaryTree:

    def create_node(self, key: int) -> LLNode:
        """
        Create and return a new binary tree node.
        """
        return LLNode(key)

    def insert_at_left(self, key: int, root_node: LLNode) -> LLNode:
        """
        Insert a new node as the left child of root_node.

        If root_node is None, create a new root node.
        """
        if root_node is None:
            root_node = self.create_node(key)
        else:
            root_node.left_node = self.create_node(key)

        return root_node

    def insert_at_right(self, key: int, root_node: LLNode) -> LLNode:
        """
        Insert a new node as the right child of root_node.

        If root_node is None, create a new root node.
        """
        if root_node is None:
            root_node = self.create_node(key)
        else:
            root_node.right_node = self.create_node(key)

        return root_node

    def preorder(self, root_node: LLNode) -> None:
        """
        Preorder traversal:
        Root -> Left -> Right
        """
        if root_node is None:
            return

        print(root_node.data)
        self.preorder(root_node.left_node)
        self.preorder(root_node.right_node)

    def inorder(self, root_node: LLNode) -> None:
        """
        Inorder traversal:
        Left -> Root -> Right
        """
        if root_node is None:
            return

        self.inorder(root_node.left_node)
        print(root_node.data)
        self.inorder(root_node.right_node)

    def postorder(self, root_node: LLNode) -> None:
        """
        Postorder traversal:
        Left -> Right -> Root
        """
        if root_node is None:
            return

        self.postorder(root_node.left_node)
        self.postorder(root_node.right_node)
        print(root_node.data)


# Create binary tree
tree = BinaryTree()

# Create root node
root_node = tree.create_node(20)

# Add left and right children
tree.insert_at_left(15, root_node)
tree.insert_at_right(25, root_node)

# Traversals
print("Inorder:")
tree.inorder(root_node)

print("Preorder:")
tree.preorder(root_node)

print("Postorder:")
tree.postorder(root_node)

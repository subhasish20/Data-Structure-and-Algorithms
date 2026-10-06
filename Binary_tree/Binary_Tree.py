
class TreeNode:
    """
    Represent a single node of a binary tree.

    Attributes:
        left_node: References the left child, or None if no left child exists.
        data: Stores the value of the node.
        right_node: References the right child, or None if no right child exists.
    """

    def __init__(self, key: int) -> None:
        """Initialize a node with the given value and no children."""
        self.left_node: TreeNode | None = None
        self.data: int = key
        self.right_node: TreeNode | None = None


class BinaryTree:

    def create_node(self, key: int) -> TreeNode:
        """
        Create and return a new binary tree node.
        """
        return TreeNode(key)

    def insert_at_left(self, key: int, root_node: TreeNode) -> TreeNode:
        """
        Insert a new node as the left child of root_node.

        If root_node is None, create a new root node.
        """
        if root_node is None:
            root_node = self.create_node(key)
        else:
            root_node.left_node = self.create_node(key)

        return root_node

    def insert_at_right(self, key: int, root_node: TreeNode) -> TreeNode:
        """
        Insert a new node as the right child of root_node.

        If root_node is None, create a new root node.
        """
        if root_node is None:
            root_node = self.create_node(key)
        else:
            root_node.right_node = self.create_node(key)

        return root_node

    def delete_node(self, key : int, root_node : TreeNode) -> TreeNode:
        pass

    def preorder(self, root_node: TreeNode) -> None:
        """
        Preorder traversal:
        Root -> Left -> Right
        """
        if root_node is None:
            return

        print(root_node.data)
        self.preorder(root_node.left_node)
        self.preorder(root_node.right_node)

    def inorder(self, root_node: TreeNode) -> None:
        """
        Inorder traversal:
        Left -> Root -> Right
        """
        if root_node is None:
            return

        self.inorder(root_node.left_node)
        print(root_node.data)
        self.inorder(root_node.right_node)

    def postorder(self, root_node: TreeNode) -> None:
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


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

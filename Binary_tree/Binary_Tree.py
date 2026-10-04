

class Node:
    def __init__ (self,key) -> None:

        # left will connect to the left child ( left tree )
        self.left = None

        # data will store the key ( vlaue of the node )
        self.data = key

        # left will connect to the right child ( right tree )
        self.right = None



def Create_Node(key)-> Node:
    node = Node(key)

    return node






root = Create_Node(10)

root.left = Create_Node(5)

print(root.data, "\n", root.left.data)

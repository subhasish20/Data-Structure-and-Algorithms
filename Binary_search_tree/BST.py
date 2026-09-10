class Node:
    def __init__(self, key):
        self.lchild = None
        self.data = key
        self.rchild = None


def CreateNode(key):
    node = Node(key)

    node.lchild = None
    node.data = key
    node.rchild = None

    return node


def main():
    root = CreateNode(50)

    if root is not None:
        print("Node Created Successfully")
    else:
        print("Node not created")

    # Python automatically manages memory,
    # so we don't need free(root)


if __name__ == "__main__":
    main()

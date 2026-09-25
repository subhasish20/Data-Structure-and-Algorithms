
# making the node using constructor
class Node:
    def __init__(self, data):
        self.key = data
        self.next = None

# SLL class
class SingleLinkedList:
    def __init__(self):
        self.head = None


    def creat_node(self, key):
        new_node = Node(key)

        return new_node

    def insert_at_beginning(self, key):
        new_node = Node(key)
        new_node.next = self.head
        self.head = new_node


ll = SingleLinkedList()

ll.insert_at_beginning(10)
ll.insert_at_beginning(20)

current = ll.head

while current:
    print(current.key, " ")
    current = current.next

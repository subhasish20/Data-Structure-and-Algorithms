
class Stack:
    """
    Representatin of a fixed-capacity Stack data structure using python list.
    Attributes :
        stack (list): store the key user want to store in the stack
        top (int): index of the recentely inserted element ( i.e. top element in the stack)
        stack_size (int) : define the size of the stack
    """
    def __init__ (self, stack_size : int) -> None:
        self.stack = []
        self.top = -1
        self.stack_size = stack_size

        if self.stack_size < 0:
            raise ValueError("The stack size can not be negative !!")

    def push(self, key: int)->None:

        """
            func :insertion of a key into the stack

            args:
                key : the elemtent that will insert in the stack
            increamenting the top pointer by one insertion is complete to keep the peek correct
        """
        # if already stack is full then insertion can not be done
        if self.top == self.stack_size:
            raise OverflowError("Stack Overflow")
            return

        else:
            self.stack.append(key)
            self.top += 1
            print(f"{key} inserted successfully !!")

    def pop(self)-> None:
        """
            fun: deletion of a key from the stack

            top pointer will decrease by one and one top element will be poped
        """
        if self.top == -1:
            raise IndexError("Stack underflow")
        else:
            print(f"{self.stack[-1]} poped successfully !!")
            self.stack.pop()
            self.top -=1

    def peek(self):
        """

        Return the top element without removing it.

        Raises:
            IndexError: If the stack is empty.
        """
        if not self.stack:
            print("Stack is Empty")
            return None

        return self.stack[-1]

    def display_stack(self):
        """
            fun : display the stack data structure
        """
        if  self.top == -1:
            raise IndexError("Stack is empty")
        else:
            print("The stack is :")
            for i in reversed(self.stack):
                print(f"| {i} |")






stack = Stack(4)

stack.push(10)
stack.push(20)
stack.push(30)
stack.pop()
stack.push(40)
stack.push(85)


stack.display_stack()

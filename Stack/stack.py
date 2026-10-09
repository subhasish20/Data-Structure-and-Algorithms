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

    def push(self, key: int)->None:

        """
            Comment
        """
        if self.top == self.stack_size:
            print("Stack Overflow")
            return

        else:
            self.stack.append(key)
            self.top += 1

    def pop(self)-> None:
        if self.top == -1:
            print("Stack underflow")
        else:

            self.stack.pop()
            self.top -=1

    def peek(self):
        if not self.stack:
            print("Stack is Empty")
            return None

        return self.stack[-1]






stack = Stack(3)



stack.push(10 )

stack.push(20)
stack.push(30 )

stack.push(40)




print(stack.top)
print(stack.peek())

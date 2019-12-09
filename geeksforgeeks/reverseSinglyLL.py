class Node:
    def __init__(self, n):
        '''
            Create a node
        '''
        self.val = n
        self.next = None

class LinkedList:
    def __init__(self):
        '''
            Initialize the linked list.
        '''
        self.head = None

    def addNode(self, n):
        '''
            Add node in the linked list.
        '''
        new_node = Node(n)
        new_node.next = self.head 
        self.head = new_node

    def reverse(self):
        '''
            Function to reverse the linked list nodes.
        '''
        prev = None
        while self.head:
            next = self.head.next
            self.head.next = prev
            prev = self.head
            self.head = next
        self.head = prev

    def printLL(self):
        '''
            Print the linked list.
        '''
        node = self.head
        while node:
            print(node.val)
            node = node.next


l = LinkedList()
l.addNode(1)
l.addNode(2)
l.addNode(10)
l.addNode(7)
l.addNode(17)
l.printLL()

print("Reverse Linked list")
l.reverse()
l.printLL()
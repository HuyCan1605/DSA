class Node:
    """An object for sotring a single node of a linked list"""
    data = None
    next_node = None

    def __init__(self, data):
        self.data = data

    def __repr__(self):
        return "<Node data: %s>" %self.data

class LinkedList:
    """singly linked list"""
    def __init__(self):
        self.head = None
    
    def is_empty(self):
        return self.head == None

    def size(self):
        current = self.head
        count = 0

        while current != None:
            count +=1
            current = current.next_node

        return count

    def add(self, data):
        """Adds new Node containing data at head of the list"""
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node

    def search(self, key):
        """
        SEarch for the first node contraining data that matches the key
        return the node or 'None' if not found
        """
        current = self.head

        while current:
            if current.data == key:
                return current
            else:
                current = current.next_node
        
        return None

    def insert(self, data, index):
        if index == 0:
            self.add(data)
        
        if index > 0:
            new = Node(data)

            position = index
            current = self.head

            while position > 1:
                current = current.next_node
                position -= 1

            prev = current
            next_node = current.next_node

            prev.next_node = new 
            new.next_node = next_node

    def remove(self, key):
        """
        Removes node containing data that matches the key 
        Returns the node or none if key doesn't exist
        Takes O(n) time
        """
        
        current = self.head
        previous = None
        found = False

        while current and not found:
            if current.data == key and current == self.head:
                found = True
                self.head = current.next_node
            elif current.data == key:
                found = True
                previous.next_node = current.next_node
            else:
                previous = current
                current = current.next_node

    def __repr__(self):
        """Return a string representation of the list take 0(n) time"""
        nodes = []
        current = self.head

        while current:
            if current is self.head:
                nodes.append("[Head: %s]" %current.data)
            elif current.next_node is None:
                nodes.append("[Tail: %s]" %current.data)
            else:
                nodes.append("[%s]" %current.data)

            current = current.next_node
        return '-> '.join(nodes)
    
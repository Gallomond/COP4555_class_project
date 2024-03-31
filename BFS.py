class Node:
    def __init__(self,value): #node constructor
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self,value): #helper function to create trees
        new_node = Node(value) #create new node instance
        if self.root is None: #if not root
            self.root = new_node
            return True
        temp = self.root #temp used to traverse treee
        while(True):
            if new_node.value == temp.value:
                return False
            if new_node.value < temp.value:
                if temp.left is None:
                    temp.left = new_node
                    return True
                temp = temp.left
            else:
                if temp.right is None:
                    temp.right = new_node
                    return True
                temp = temp.right

    def contains(self,value): # function to find a node
        if self.root is None: # if tree is empty 
            return False
        temp = self.root #temp used to traverse tree
        while temp is not None:
            if value < temp.value: #if value being searched is less than current
                temp = temp.left #go left
            elif value > temp.value: #if value being searched is more than current
                temp = temp.right #go right
            else: #value is equal to temp
                return True
        return False #value is not in tree


    def BFS(self): #self because it is a method in binary search tree class
        current_node = self.root #assigned top node on tree
        queue = []
        results = []
        queue.append(current_node) #putting current_node into queue
        while len(queue) > 0: #run until queue is empty
            current_node = queue.pop(0) # set current node equal to first item in queue
            results.append(current_node.value)
            if current_node.left is not None: #if there is a node to the left of current node
                queue.append(current_node.left) # adds node to the left to queue
            if current_node.right is not None: #if there is a node to the right of current node
                queue.append(current_node.right) #adds node to the right to queue
        return results

my_tree = BinarySearchTree() ##instance of BST to test methods
my_tree.insert(47)
my_tree.insert(21)
my_tree.insert(76)
my_tree.insert(18)
my_tree.insert(27)
my_tree.insert(52)
my_tree.insert(82)

print(my_tree.BFS())

#should return [47, 21, 76, 18, 27, 52, 82]

print(my_tree.contains(27)) #test for contains method

print(my_tree.contains(17)) #test fo contains method



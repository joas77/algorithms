# https://www.python.org/dev/peps/pep-0255/

class Node:
    def __init__(self, key, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right
        self.parent = None

    def __repr__(self, level=0, indent="    "):
        s = level * indent + str(self.key)
        if self.left:
            s = s + "\n" + self.left.__repr__(level+1, indent)
        if self.right:
            s = s + "\n" + self.right.__repr__(level+1, indent)
        return s    

class BinaryTree:
    def __init__(self, key):
        self.root = Node(key)

    def insert(self, key):
        y = None
        x = self.root
        z = Node(key)
        while x:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.parent = y
        if y is None:
            self.root = z  # tree was empty
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z

    def __repr__(self, level=0, indent="    "):
        return self.root.__repr__(level, indent)


if __name__ == "__main__":
    tree = BinaryTree(2)
    l = [3,4,6,7,13,9,15,18,17,20]
    for n in l:
        tree.insert(n)
    print(tree)
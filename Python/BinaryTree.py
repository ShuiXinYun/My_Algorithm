"""
二叉树的实现
author: 云水心
@ 2018.10
"""


class Node:
    def __init__(self, elem=None):
        self._elem = elem
        self._lchild = None
        self._rchild = None

    def __repr__(self):
        return str(self._elem)


class BinaryTree:
    def __init__(self):
        self._root = None
        self._height = 0

    def add(self, elem):
        node = Node(elem)
        if self._root == None:
            self._root = node
            # self._height += 1
        else:
            queue = list()
            queue.append(self._root)
            while queue:
                t = queue.pop(0)
                if t._lchild == None:
                    t._lchild = node
                    return
                elif t._rchild == None:
                    t._rchild = node
                    return
                else:
                    queue.append(t._lchild)
                    queue.append(t._rchild)


if __name__ == "__main__":
    btree = BinaryTree()
    for i in range(8):
        btree.add(i)
    print(btree._root._lchild._lchild._lchild)

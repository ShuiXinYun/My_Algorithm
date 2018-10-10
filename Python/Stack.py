# 使用列表实现栈, 支持扩容


class Stack:
    def __init__(self, capacity: int):
        self._count = 0
        self._data = [None] * capacity
        self._capacity = capacity

    def __getitem__(self, index: int):
        if index >= self._count:
            return False
        else:
            return self._data[index]

    def capacity_expansion(self):
        self._data += [None] * self._capacity
        self._capacity *= 2

    def push(self, value):
        if self._count >= self._capacity:
            self.capacity_expansion()
            self._data[self._count] = value
            self._count += 1
        else:
            self._data[self._count] = value
            self._count += 1

    def pop(self):
		# if self._count == 0:
        if not self._data:  # 空, 无元素
            return False
        else:
            t = self._data[self._count - 1]
            self._count -= 1
            return t

    def __repr__(self):
        return str(self._data[:self._count])


if __name__ == "__main__":
    s = Stack(3)
    for i in range(3):
        s.push(i)
    print(s)  # [0, 1, 2]
    print(s._capacity)  # 3
    s.push('push1')
    print(s)  # [0, 1, 2, 'push1']
    print(s._capacity)  # 6
    t = s.pop()
    print(t)  # push1
    print(s)  # [0, 1, 2]
    s.push('push after pop')
    print(s)  # [0, 1, 2, 'push after pop']

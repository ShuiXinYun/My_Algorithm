# 使用列表实现队列, 支持扩容
# 列表实现的环形队列, 不支持扩容


class ArrayQueue:
    def __init__(self, capacity: int):
        self._capacity = capacity
        self._head = 0
        self._tail = 0
        self._count = 0
        self._data = [None] * capacity

    # 入队
    def enqueue(self, value):
        if self._count >= self._capacity:
            print("queue full, capacity expansion")
            self._data += [None] * self._capacity
            self._capacity *= 2

        if self._tail >= self._capacity:
            # 队列未满但数据达到队尾, 数据搬移
            for i in range(self._count):
                self._data[i] = self._data[self._head + i]
            self._head = 0
            self._tail = self._count
        self._data[self._tail] = value
        self._tail += 1
        self._count += 1

    # 出队
    def dequeue(self):
        if self._head == self._tail:
            print("queue empty")
            return False
        else:
            t = self._data[self._head]
            self._head += 1
            self._count -= 1
            return t

    def __repr__(self):
        return str(self._data[self._head:self._tail])


class CircularQueue:
    def __init__(self, capacity: int):
        self._capacity = capacity
        self._head = 0
        self._tail = 0
        self._count = 0
        self._data = [None] * capacity

    # 入队
    def enqueue(self, value):
        # if (self._tail + 1) % self._capacity == self._head:
        if self._count == self._capacity:
            print("queue full")
        self._data[self._tail] = value
        self._tail = (self._tail + 1) % self._capacity
        self._count += 1

    # 出队
    def dequeue(self):
        # if self._head == self._tail:
        if self._count == 0:
            print("queue empty")
            return False
        else:
            t = self._data[self._head]
            self._data[self._head] = None
            self._head = (self._head + 1) % self._capacity
            self._count -= 1
            return t


if __name__ == "__main__":
    print("---------Array Queue---------")
    q = ArrayQueue(5)
    q.dequeue()  # queue empty
    for i in range(5):
        q.enqueue(i)
    print(q)  # [0, 1, 2, 3, 4]
    print(q.dequeue())  # 0
    print(q._head)  # 1
    print(q._count)  # 4
    q.enqueue(5)
    print(q)  # [1, 2, 3, 4, 5]
    q.enqueue(6)  # queue full, capacity expansion
    print(q, ", queue capacity: %d" % q._capacity)  # [1, 2, 3, 4, 5, 6] , queue capacity: 10

    print("---------Circular Queue---------")
    qc = CircularQueue(5)
    for i in range(5):
        qc.enqueue(i)
    print(qc._data, "head: %d" % qc._head, "tail: %d" % qc._tail,
          "count: %d" % qc._count)  # [0, 1, 2, 3, 4] head: 0 tail: 0 count: 5
    qc.dequeue()
    print(qc._data, "head: %d" % qc._head, "tail: %d" % qc._tail,
          "count: %d" % qc._count)  # [None, 1, 2, 3, 4] head: 1 tail: 0 count: 4
    qc.enqueue(5)
    print(qc._data, "head: %d" % qc._head, "tail: %d" % qc._tail)  # [5, 1, 2, 3, 4] head: 1 tail: 1
    qc.dequeue()
    qc.dequeue()
    print(qc._data, "head: %d" % qc._head, "tail: %d" % qc._tail)  # [5, None, None, 3, 4] head: 3 tail: 1
    qc.enqueue(6)
    print(qc._data, "head: %d" % qc._head, "tail: %d" % qc._tail)  # [5, 6, None, 3, 4] head: 3 tail: 2
    qc.enqueue(7)
    print(qc._data, "head: %d" % qc._head, "tail: %d" % qc._tail)  # [5, 6, 7, 3, 4] head: 3 tail: 3

# 使用列表实现数组的insert, delete, insert_to_head, insert_to_tail, find, print_all, 支持负数下标访问


class MyArray:
    def __init__(self, capacity: int):
        self._data = [None] * capacity
        self._count = 0
        self._capacity = capacity

    def __getitem__(self, index: int):  # 支持P[key]取值
        if index < 0:
            if index < -self._capacity:
                return False
            else:
                return self._data[self._capacity + index]
        else:
            if index > self._count:
                return False
            else:
                return self._data[index]

    def insert(self, index: int, value):
        if index >= self._count or self._count >= self._capacity:
            return False
        else:
            i = self._count - index  # 移动元素的个数
            while i > 0:
                self._data[index + i] = self._data[index + i - 1]
                i -= 1
            self._data[index] = value
            self._count += 1
            return True

    def insert_to_head(self, value):
        if self._count + 1 > self._capacity:
            return False
        else:
            for i in range(self._count):  # 移动元素
                self._data[self._count - i] = self._data[self._count - i - 1]
            self._data[0] = value
            self._count += 1
            return True

    def insert_to_tail(self, value):
        if self._count >= self._capacity:
            return False
        else:
            self._data[self._count] = value
            self._count += 1
            return True

    def delete(self, index: int):
        if index > self._count - 1 or index > self._capacity - 1:
            return False
        else:
            i = self._count - index - 1  # 移动元素个数
            for j in range(i):
                self._data[index + j] = self._data[index + j + 1]
            self._data[self._count - 1] = None
            self._count -= 1
            return True

    def find(self, value):
        result = []
        j = 0
        for i in range(self._count):
            if self._data[i] == value:
                result.append(i)
                j += 1
        if j == 0:
            return None
        else:
            return result

    def __repr__(self):
        return str(self._data[:self._count])


if __name__ == "__main__":
    a = MyArray(8)
    for i in range(5):
        a.insert_to_tail(i)
    a.insert_to_tail('tail')
    print(a)  # [0, 1, 2, 3, 4, 'tail']
    a.insert(2, 'mid')
    print(a)  # [0, 1, 'mid', 2, 3, 4, 'tail']
    a.insert_to_head('head')
    print(a)  # ['head', 0, 1, 'mid', 2, 3, 4, 'tail']
    a.delete(3)
    print(a)  # ['head', 0, 1, 2, 3, 4, 'tail']
    print(a[-7])  # 0
    a.insert(5, 1)
    print(a)  # ['head', 0, 1, 2, 3, 1, 4, 'tail']
    print(a.find(1))  # [2, 5]

"""
递归的实现
author: 云水心
@ 2018.10
"""
import time


class myRecursion:
    def __init__(self, n):
        self._n = n
        self._dict = dict()

    def f_1(self, n):
        """
        假如这里有 n 个台阶，每次你可以跨 1 个台阶或者 2 个,请问走这 n 个台阶有多少种走法？
        使用字典避免重复计算
        :param n:台阶数
        :return:走的方法数
        f(n) = f(n-1) + f(n-2)
        f(1) = 1
        f(2) = 2
        """
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n in self._dict:
            return self._dict[n]
        fn = self.f_1(n - 1) + self.f_1(n - 2)
        self._dict.update({n: fn})
        return fn

    def f_2(self, n):
        """
        有重复计算
        """
        if n == 1:
            return 1
        if n == 2:
            return 2
        fn = self.f_2(n - 1) + self.f_2(n - 2)
        return fn

    def __repr__(self):
        t = time.clock()
        n_1 = self.f_1(self._n)
        duration_1 = time.clock() - t
        t = time.clock()
        n_2 = self.f_2(self._n)
        duration_2 = time.clock() - t
        return 'f_1 result: {0}, f_1 duration: {1}; f_2 result: {2}, f_2 duration: {3};'.format(n_1, duration_1, n_2,
                                                                                                duration_2)


if __name__ == '__main__':
    re = myRecursion(40)
    print(re)  # f_1 result: 165580141, f_1 duration: 3.01511196874296e-05; f_2 result: 165580141, f_2 duration: 30.017064395964983;

from typing import Callable
from typing import List
from typing import Optional

import numpy as np


class LazyArray:
    def __init__(self, arr: List):
        self.arr: List = arr
        self.udfs: List[Callable] = []

    def arrmap(self, fn: Callable) -> 'LazyArray':
        self.udfs.append(fn)
        return self

    def indexOf(self, x) -> Optional[int]:
        arr_evaluated = self.evaluate()
        return arr_evaluated.index(x)

    def evaluate(self) -> List:
        ret = []
        for a in self.arr:
            for fn in self.udfs:
                a = fn(a)
            ret.append(a)
        return ret


def test1():
    arr = LazyArray([10, 20, 30, 40, 50])
    assert arr.arrmap(lambda x: x * 2).indexOf(40) == 1


def test2():
    # Test the laziness
    num_calls = 0

    def fn(x):
        nonlocal num_calls
        num_calls += 1
        return x * 2

    arr = LazyArray([10, 20, 30, 40, 50])
    arr = arr.arrmap(fn)
    assert num_calls == 0
    assert arr.indexOf(40) == 1
    assert num_calls > 0


def test3():
    arr = LazyArray([10, 20, 30, 40, 50])
    arr = arr.arrmap(lambda x: x * 2)
    assert np.allclose(arr.evaluate(), [20, 40, 60, 80, 100])


if __name__ == '__main__':
    test1()
    test2()
    test3()

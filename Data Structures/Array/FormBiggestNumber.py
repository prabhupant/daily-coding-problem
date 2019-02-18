def comparator(a, b):
    ab = str(a) + str(b)
    bs = str(b) + str(a)
    return ((int(ba) > int(ab)) - (int(ba) < int(ab)))

def my_compare(mycmp):
    class K:
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0

a = [54,546,548,60]
a.sort(key=my_compare(comparator))
print(a)

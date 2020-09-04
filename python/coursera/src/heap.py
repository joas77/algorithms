
class HeapMin:
    def __init__(self):
        self._heap = []

    # def heapify(self, listx, key=None):
    #     if key:
    #         for x in listx:
    #             self._heap_keys.append(key(x))
        
    #     else:
    #         self._elems = listx
    #         heapq.heapify(self._heap_keys)

    def parent(self, i):
        return self._heap[i//2]

    def left(self, i):
        return 2*i

    def right(self, i):
        return 2*i + 1
    
    def insert(self, x, key=None):
        pass


if __name__ == "__main__":
    pass
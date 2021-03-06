from heapq import heappush, heappop, heapify

class MinHeap:

    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i-1)/2

    def insertKey(self, k):
        heappush(self.heap, k)

    def decreaseKey(self, i, new_val):
        self.heap[i] = new_val
        while(i != 0 and self.heap[self.parent(i)] > self.heap[i]):
            self.heap[i], self.heap[self.parent(i)] = (self.heap[self.parent(i), self.heap[i])


    def extractMin(self):

class CircularQueue:
    def __init__(self, capacity=6):
        self.capacity = capacity
        self.data = [None] * capacity
        self.size = 0
        self.front = 0  
        self.rear = 0  

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

    def enqueue(self, item):
        if self.is_full():
            raise Exception("Queue is full")
        self.data[self.rear] = item
        self.rear = (self.rear + 1) % self.capacity
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        item = self.data[self.front]
        self.data[self.front] = None  # Optional: help garbage collection
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return item

    def __str__(self):
        """Return a string representation of the queue's contents from front to rear."""
        items = []
        index = self.front
        for i in range(self.size):
            items.append(str(self.data[index]))
            index = (index + 1) % self.capacity
        return "Queue contents: " + " ".join(items)


# Testing our CircularQueue class:
if __name__ == "__main__":
    # Create a CircularQueue with capacity 6
    cq = CircularQueue(6)

    # To mimic the sample diagram, we simulate operations that lead to a "wrapped"
    # queue. We begin by enqueueing two elements (10, 12) but then adjust the front.
    # First, fill the queue with two elements.
    cq.enqueue(10)  # front=0, rear=1, size=1
    cq.enqueue(12)  # front=0, rear=2, size=2

    # Dequeue twice so that front moves to index 2 (simulating a starting state
    # where the queue data begins at index 2). (The dequeued values are discarded.)
    cq.dequeue()    # front becomes 1, size=1
    cq.dequeue()    # front becomes 2, size=0

    # Now enqueue 10 and 12 again.
    cq.enqueue(10)  # front=2, rear=3, size=1
    cq.enqueue(12)  # front=2, rear=4, size=2

    print("After enqueueing 10 and 12:")
    print("Array state:", cq.data)
    print("Begin at index:", cq.front)
    print("End at index:", cq.rear)
    print(cq)
    print("-" * 40)

    # Enqueue 7:
    cq.enqueue(7)   # front=2, rear=5, size=3
    print("After enqueueing 7:")
    print("Array state:", cq.data)
    print("Begin at index:", cq.front)
    print("End at index:", cq.rear)
    print(cq)
    print("-" * 40)

    # Dequeue one element:
    removed = cq.dequeue()  # removes 10 from index 2; front becomes 3
    print(f"After dequeue (removed {removed}):")
    print("Array state:", cq.data)
    print("Begin at index:", cq.front)
    print("End at index:", cq.rear)
    print(cq)
    print("-" * 40)

    # Continue operations to demonstrate the wrap-around:
    cq.enqueue(1)  # current rear=5, so new element goes to index 5, then rear wraps to 0
    print("After enqueueing 1:")
    print("Array state:", cq.data)
    print("Begin at index:", cq.front)
    print("End at index:", cq.rear)
    print(cq)
    print("-" * 40)

    cq.enqueue(6)  # rear moves from 0 to 1
    print("After enqueueing 6:")
    print("Array state:", cq.data)
    print("Begin at index:", cq.front)
    print("End at index:", cq.rear)
    print(cq)
    print("-" * 40)

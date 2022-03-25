# CSCI-340 Homework 7: Blake Mitrick
---

## 1. Broken Code
### a. The first problem is that in the Queue_Enqueue function, the lock is locked sooner than it needs to be. It would be more efficient to only lock for the critical section of adding the data to the queue and leave the queue unlocked when just generating the new node but not yet putting it in the queue.
### b. The second problem is that the lock in the Queue_Dequeue function occurs after the information is already pulled from the queue. This means that it could be outdated or written over in the time it takes the function to lock the queue.
### c. To fix the first problem, I would move the lock to later in the function. To fix the second problem, I would move the lock to slightly earlier in the function. See code for the fixes.


## 2. Doubly Linked List

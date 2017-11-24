# Data Structures
See [GeeksforGeeks](http://www.geeksforgeeks.org/data-structures/)

## Linear Data Structures

### Array
Used to store homogeneous elements (all of the same type) at contiguous locations.

```
Accessing Time: O(1)
Search Time: O(n) for sequential; O(log n) for binary if sorted
Insertion Time: O(n)
Deletion Time: O(n)
```

### Linked List
Each element is a separate object, and each element of a list consists of the data and the pointer to the next node. Elements are linked using pointers.

Types:
- Singly Linked List: every node stores pointer to next node, last node is null
- Double Linked List: every node has a pointer to the next node and the previous node, advantage is that you can traverse in both directions and don't need to have access to previous node for deletion
- Circular Linked List: no null at the end, advantage is that any node can be made as the starting node (good for circular queue implementation using linked list)

Advantages over arrays:
- dynamic size
- ease of insertion/deletion

Disadvantages over arrays:
- random access not allowed
- extra memory space for pointer required

```
Accessing Time: O(n)
Search Time: O(n)
Insertion Time: O(1)
Deletion Time: O(1)
```

### Stack
LIFO, serves as a collection of elements with two principle operations: push and pop (same end)
Can be implemented using both an array and an linked list.

```
Insertion: O(1)
Deletion: O(1)
Access Time: O(n) worst case
Insertion and Deletion are allowed on one end.
```

### Queue
FIFO, has two principal operations: enqueue (add to back end) and dequeue (remove from front end)

Circular Queue: An advantage is that it reduces wastage of space in the case of an array implementation.

```
Insertion: O(1)
Deletion: O(1)
Access Time: O(n) worst case
```

## Other

### Binary Tree
A binary tree is a tree data structure in which each node has at most two children. Binary trees are generally implemented using links.

A tree is represented by a pointer to the topmost node in the tree. A binary tree node contains data, a pointer to the left child, and a pointer to the right child.

```
Time Complexity of Tree Traversal: O(n)
```

### Binary Search Tree
A binary search tree is a binary tree with the following additional invariants:
1. The left subtree of a node contains only nodes with keys less than the node’s key.
2. The right subtree of a node contains only nodes with keys greater than the node’s key.
3. The left and right subtree each must also be a binary search tree.

```
Search :  O(h)
Insertion : O(h)
Deletion : O(h)
Extra Space : O(n) for pointers

h: Height of BST
n: Number of nodes in BST

If Binary Search Tree is Height Balanced,
then h = O(Log n)
```

### Binary Heap
A binary heap is a binary tree with the following properties:
1. A binary heap is a complete tree, making it suitable to be stored in an array.
2. A binary heap is either min heap or max heap. In a minimum binary heap, the key at the root must be the minimum among all the keys in the binary heap.

```
Get Minimum in Min Heap: O(1) [Or Get Max in Max Heap]
Extract Minimum Min Heap: O(Log n) [Or Extract Max in Max Heap]
Decrease Key in Min Heap: O(Log n)  [Or Extract Max in Max Heap]
Insert: O(Log n)
Delete: O(Log n)
```

### Hashing
A hash function is a function that converts a given large input key into a smaller, more practical integer value. This integer is then used as an index in a hash table.

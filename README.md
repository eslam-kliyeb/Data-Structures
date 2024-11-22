# Data Structures Implementation

This repository contains C++ implementations of common data structures, designed for educational and practical use. Each data structure is implemented with a focus on simplicity, efficiency, and adherence to standard coding practices.

---

## Data Structures Included

### 1. Stack
**Header File:** `Stack.h`  
A simple stack implementation using singly linked nodes.  

#### Features:
- **push(value):** Adds an element to the top of the stack.
- **pop():** Removes the top element.
- **top():** Retrieves the top element without removing it.
- **size():** Returns the current size of the stack.
- **empty():** Checks if the stack is empty.

---

### 2. Queue
**Header File:** `Queue.h`  
A standard queue implementation using doubly linked nodes.  

#### Features:
- **push(value):** Adds an element to the back of the queue.
- **pop():** Removes the front element.
- **front():** Retrieves the front element.
- **back():** Retrieves the back element.
- **size():** Returns the size of the queue.
- **empty():** Checks if the queue is empty.

---

### 3. Binary Search Tree (BST)
**Header File:** `BST.h`  
A binary search tree implementation for storing ordered data.  

#### Features:
- **insert(value):** Adds a value to the tree.
- **find(value):** Checks if a value exists in the tree.
- **erase(value):** Removes a value from the tree.
- **size():** Returns the number of elements in the tree.
- **empty():** Checks if the tree is empty.

---

### 4. Singly Linked List (SLL)
**Header File:** `SLL.h`  
A basic singly linked list implementation.  

#### Features:
- **push_front(value):** Adds a node to the front.
- **push_back(value):** Adds a node to the back.
- **pop_front():** Removes the first node.
- **pop_back():** Removes the last node.
- **push_after(position, value):** Inserts a node after a given position.
- **push_at(position, value):** Inserts a node at a specific position.
- **pop_at(position):** Removes a node at a specific position.
- **size():** Returns the number of nodes.
- **empty():** Checks if the list is empty.

---

### 5. Doubly Linked List (DLL)
**Header File:** `DLL.h`  
A doubly linked list implementation.  

#### Features:
- **push_front(value):** Adds a node to the front.
- **push_back(value):** Adds a node to the back.
- **pop_front():** Removes the front node.
- **pop_back():** Removes the back node.
- **push_inner(rank, value):** Inserts a node at a specific position.
- **pop_inner(rank):** Removes a node from a specific position.
- **size():** Returns the number of nodes.
- **empty():** Checks if the list is empty.

---

### 6. Hash Table
**Header File:** `HashTable.h`  
A hash table with linked list chaining for collision resolution.

#### Features:
- **put(key, value):** Inserts or updates a key-value pair.
- **find(key):** Retrieves a value by key.
- **remove(key):** Deletes a key-value pair.

---

### 7. Vector
**Header File:** `Vector.h`  
A dynamic array implementation with automatic resizing.  

#### Features:
- **push_front(value):** Adds a value at the front.
- **push_back(value):** Adds a value at the back.
- **pop_front():** Removes the front element.
- **pop_back():** Removes the back element.
- **resize(new_size, value):** Adjusts the size of the vector.
- **clear():** Clears all elements.
- **size():** Returns the current size.
- **capacity():** Returns the current capacity.

---

## Requirements
- C++17 or later
- A compatible C++ compiler (e.g., GCC, Clang, MSVC)

## How to Use
1. Clone this repository.
   ```bash
    git clone https://github.com/eslam-kliyeb/Data-Structures.git

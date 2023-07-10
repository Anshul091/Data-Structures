# Data-Structures
 Data Structures in C++
 
 <img width="517" alt="Screenshot 2023-07-11 at 4 22 34 AM" src="https://github.com/Anshul091/Data-Structures/assets/112956069/10c21eda-5a68-4fa2-844f-3c32750b2fad">


This project contains implementations of various data structures in C++. The data structures currently implemented are:

- Treap
- Trie
- Segment Tree
- Sparse Table
- DSU

I'll be adding certain algorithms too. Later on.

## Getting Started
<img width="521" alt="Screenshot 2023-07-11 at 4 23 15 AM" src="https://github.com/Anshul091/Data-Structures/assets/112956069/9d2e3a46-13ed-4cb1-a439-d88c4b8a5abe">

To use these data structures in your own projects, simply include the appropriate header file(s) in your code. For example, to use the Treap data structure, include the `treap.h` header file:

```cpp
#include "treap.h"

// Your code here
```

## Data Structures

### Treap

The Treap data structure is a combination of a binary search tree and a heap. It maintains the following properties:

- The binary search tree property: For any node `x`, the left subtree of `x` contains nodes with keys less than `x`, and the right subtree of `x` contains nodes with keys greater than `x`.
- The heap property: For any node `x`, the priority of `x` is greater than or equal to the priorities of its children.

The Treap data structure supports the following operations:

- Insertion of a key-value pair
- Deletion of a key-value pair
- Search for a key

### Trie

The Trie data structure is a tree-like data structure that is used to store a collection of strings. It maintains the following properties:

- Each node represents a prefix of one or more strings.
- The root represents the empty string.
- Each edge is labeled with a character.

The Trie data structure supports the following operations:

- Insertion of a string
- Deletion of a string
- Search for a string

### Segment Tree

The Segment Tree data structure is used to perform range queries on an array. It maintains the following properties:

- Each node represents a segment of the array.
- The root represents the entire array.
- Each non-leaf node represents the union of its two children.

The Segment Tree data structure supports the following operations:

- Query for the minimum/maximum/sum/etc. value in a range
- Update the value of an element in the array

### Sparse Table

The Sparse Table data structure is used to perform range queries on an array. It maintains the following properties:

- Each cell of the table represents the minimum/maximum/sum/etc. value over a range of length 2^k.
- The table has O(n log n) space complexity and O(1) query time complexity.

The Sparse Table data structure supports the following operation:

- Query for the minimum/maximum/sum/etc. value in a range

### DSU

The DSU (Disjoint Set Union) data structure is used to maintain a collection of disjoint sets. It maintains the following properties:

- Each set is represented by a tree.
- Each tree has a root.
- Each element has a parent pointer pointing to its parent in the tree.

The DSU data structure supports the following operations:

- Union two sets
- Find the root of a set

<img width="518" alt="Screenshot 2023-07-11 at 4 23 51 AM" src="https://github.com/Anshul091/Data-Structures/assets/112956069/de13b536-4de7-46ec-9549-5f54992b6e70">



## Contributing

If you would like to contribute to this project, please feel free to submit a pull request!

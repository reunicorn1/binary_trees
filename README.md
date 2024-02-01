# binary_trees
Binary tree is a type of data structure in computer science that has at most two children for each parent node

Data structures can be linear or non linear. In linear data structures, data elements are arranged sequentially, and each element is connected to its previous and next element. Examples include arrays, linked lists, stacks, and queues.

Non Linear data structures on the other hand, re those in which data elements are not arranged in a sequential manner. They are connected in such a way that each element is connected to two or more other elements. Examples include trees and graphs.

> Trees can be defined as a collection of entities (nodes) linked together to stimulate a hierarchy.
> 

> Binary trees: are trees where each node it contain have at most 2 children.
> 

## Properties of a Binary Tree

![new-binary-tree.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/00b4f86f-821f-4104-ae8d-6482c282f4f9/new-binary-tree.png)

In the above example, the root of the trees is the value 2, a node is considered any value in the hierarchy of the tree.

the value 2 is the parent node of the values 7 and 5 which are the children nodes, and 6 is the parent node of the values 5 and 11. 

`A leaf node` **is considered a node which has no children**, in the above example, 2, 5, 11, 4 are all considered leaf nodes. And therefore a non leaf node is every other node except these as thers have their own respective children.

`Path:` **the path is the sequence of consecutive edges from source node to destination node.**

`Ancestor:` **is any predecessor node on the path from root to that node.**

6 = 7, 2

`Descendent:` **any successor node on the path from that node to leaf node**

7 = 2, 6, 5, 11

Common ancestors between 6 and 9 are only the value 2.

`Sibling:` children of the same parent

`Degree:` **degree of node is n.o of children of that node.** In a binary tree ****the maximum degree of a node is 2, and leaf nodes have the degree of zero.

`Depth of node:` **the length of the path from root to that node.** The depth of 6 is 2, and the depth of the root 2 is zero always. 

<aside>
🌳 Level of a node is equal to the height of a tree, and level of a node is equal to the depth of a node.

</aside>

`Height of node:` **is the number of edges in the longest path from that node to a leaf.** the height of 9 is 1, and the height of 7 is two.

<aside>
🌳 nodes of a tree equals n - 1 edges

</aside>

<aside>
🌳 The number of nodes possible at any level i equals 2 ^ i. And the maximum number of nodes in a binary of height h equals 2 ^ (h + 1)  -1, and the minimum number of nodes is h + 1

</aside>

### `Full Binary Tree`

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/13d1f073-57f4-4f74-9327-80baa54d1343/Untitled.png)

Each node contains two children or zero (all or none), or this can be defined as all nodes having two children except the leaf nodes having none.

<aside>
🌳 Number of leaf nodes equals the number of internal nodes + 1

</aside>

### `Complete Binary Tree`

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/0b381006-ba96-4ec6-9dc5-708c6f0c0c2e/Untitled.png)

All levels are completely filled (except possibly the last level) and the last level had nodes as left as possible  

### `Perfect Binary Tree`

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/f863e3cd-57c0-4e5e-943d-efe9613178ab/Untitled.png)

All internal nodes have 2 children and all leaves are at the same level

<aside>
🌳 Every perfect binary tree is also a complete and a full binary tree.

</aside>

### `Degenerate Binary Tree`

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/3da06667-36ae-4ca0-b580-635708bd9b19/Untitled.png)

All nodes have only one child, if it includes children on the left it’s called **left-skewed binary tree**, and if they’re all on the right it’s called **right skewed binary tree**.

|  | Max Nodes | Min Nodes | Max Height | Min Height |
| --- | --- | --- | --- | --- |
| Binary Tree | 2^{(h+1)}-1 | h + 1 | [log _{2}(n+1)]-1 | n -1  |
| Full Binary Tree | 2^{(h+1)}-1 | 2h + 1 | [log _{2}(n+1)]-1 | (n-1) / 2 |
| Perfect Binary Tree | 2^{(h+1)}-1 | 2^h  | [log _{2}(n+1)]-1 | log n |

## Traversal

### **`Inorder Traversal`**

left → root → right

### `Preorder Traversal`

root → left → right

### `Postorder Traversal`

left → right → root

A binary search tree (BST) is also called an ordered or sorted binary tree, where all internal nodes are greater than their respective node’s left subtree and less than the the ones in its right subtree.  

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/ebc24417-d066-4b87-859f-205d219f2dea/Untitled.png)

## AVL Tree

In AVL trees, the difference between the heights of left and right subtrees, known as the **Balance Factor**, must be at most one. Once the difference exceeds one, the tree automatically executes the balancing algorithm until the difference becomes one again.

when you do an insertion or deletion and need to do tree rotations, those rotations won't appear in random spots in the tree. They'll always appear along the access path you took when inserting or deleting the node.

let's see what happens when we insert 3. This places the 3 here:

![Screenshot 2024-02-01 at 7.51.00 PM.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/83482825-0340-44e5-bc88-fb658a679dda/Screenshot_2024-02-01_at_7.51.00_PM.png)

Notice that I've marked all nodes on the access path with a ?, since we're no longer sure what their balance factors are.

![Screenshot 2024-02-01 at 7.53.42 PM.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/e5e55dde-df8b-4011-9757-5e9a90ad78d1/Screenshot_2024-02-01_at_7.53.42_PM.png)

we can see that we're in the case where we have a balance factor of +2 where the left child has a balance factor of +1. This means that we do a right rotation and pull the 7 above the 9, as shown here:

![Screenshot 2024-02-01 at 7.54.05 PM.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/8d7a3c9c-fc2d-4793-8749-a5df6f848872/db2ca49b-9b3f-4cad-b4e5-16b18acbbd10/Screenshot_2024-02-01_at_7.54.05_PM.png)

Notice that when we did this fixup procedure, we didn't have to look over the entire tree. Instead, all we needed to do was look along the access path and check each node there. Typically, when implementing an AVL tree, your insertion procedure will do the following:

- **If the tree is null:**
    - Insert the node with balance factor 0.
    - Return that the tree height has increased by 1.
- **Otherwise:**
    - If the value to insert matches the current node, do nothing.
    - Otherwise, recursively insert the node into the proper subtree and get the amount that the tree height has changed by.
    - Update the balance factor of this node based on the amount that the subtree height changed.
    - If this mandates a series of rotations, perform them.
    - Return the resulting change in the height of this tree.

Since all these operations are local, the total work done is based purely on the length of the access path, which in this case is O(log n) because AVL trees are always balanced.

In an AVL tree, **the rotation is performed at the first unbalanced node that you encounter when moving up from the newly inserted or removed node towards the root.** The direction of rotation depends on whether the imbalance is left-heavy or right-heavy.

| Left-Left case | If the balance factor of the unbalanced node is positive and the balance factor of its left child is also positive (or zero), a right rotation on the unbalanced node is needed. |
| --- | --- |
| Right-Right case | If the balance factor of the unbalanced node is negative and the balance factor of its right child is also negative (or zero), a left rotation on the unbalanced node is needed. |
| Left-Right case | If the balance factor of the unbalanced node is positive and the balance factor of its left child is negative, a left rotation on the left child followed by a right rotation on the unbalanced node is needed. |
| Right-Left case | If the balance factor of the unbalanced node is negative and the balance factor of its right child is positive, a right rotation on the right child followed by a left rotation on the unbalanced node is needed. |

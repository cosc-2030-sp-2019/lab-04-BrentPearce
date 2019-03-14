# cosc-2030-lab04-binarytrees

I couldn't figure out what int was supposed to be returned in the traversal functions(the
signatures called for an int to be returned). This combined with the fact that the supplied infix 
traversal function didn't return an int, lead me to simply remove them from the function signitures.

Binary search is an algorithm that finds an element in a list or array by successively dividing
the search area in half. In each iteration the middle element of the current searh area is 
compared to the desired value and the search boudary is updated to the first or second half.

Binary trees are a data structure where each node is connencted to no more than two(however
any node may be connected to fewer than 2 other nodes) other nodes(called desendants).

Binary Search trees are a data structure where items are stored and sorted in a binary tree 
acording to a key value. In a binary search tree for any node the decendants are grouped such
that all key values less than the parent key are stored in the left-subtree. Similarly, any 
key values greater than the parent nodes key value are stored in the right subtree. 

The prefixes in post and pre describe when the parent node is traversed compared to and decendant
nodes

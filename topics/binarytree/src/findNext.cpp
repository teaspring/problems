/*
 * find the "next" node(e.g, in-order successor) of a given node in a binary search tree where each node has a link to its parent
 * */

//it seems the binary search tree is not necessary here

/*
 * in-order,left-root-right,for a subtree,first is its most left leaf 
 * for a given node x, its parent is p
 * 1.if x has right child, the "next" should be in its right subtree. specially, it is the left most node
 * 2.else, x is leaf
 * 2.a if x is left child, "next" is p
 * 2.b else,x is right child. go upstream if its ancestor is right child, return the parent of the ancestor which is left child
 * */



/*
 * pre-order,root-left-right,for a subtree,first is root 
 * for a given node x, its parent is p
 * 1.if x has left child, next is its left child; else if it has right child, next is its right child;
 * 2.else, x is leaf
 * 2.a if x is left leaf, next is its brother(p's right child) if it has;if no brother, go to 2.b
 * 2.b if x is right leaf, go upstream; if p is left child, next is p's right brother; else if p is right child, go upstream, recurse.
 * */


/*
 * post-order,left-right-root,for a subtree,first is its most left leaf
 * given x, with parent p
 * 1.if x is left leaf, next is x's brother(p's right child);else if x is right leaf, next is p
 * 2.else, x is not leaf. go upstream, if p is left child, next is first of p's right brother - most left leaf; else, next is p
 * */

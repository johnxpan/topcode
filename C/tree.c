#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *left;
   struct right *right;
}

typedef struct node TN;

/* 
 Given a binary tree, return true if a node 
 with the target data is found in the tree. Recurs 
 down the tree, chooses the left or right 
 branch by comparing the target to each node. 
*/
static int lookup(struct node* node, int target) {
  // 1. Base case == empty tree 
  if (node == NULL) {
    return(false);
  }
  else {
    // 2. see if found here 
    if (target == node->data) return(true);
    else {
      // 3. otherwise recur down the correct subtree 
      if (target < node->data)
         return(lookup(node->left, target));
      else
         return(lookup(node->right, target));
    }
  }
}

TN *NewNode( int data) {
   TN * new = malloc(sizeof(TN));
   if(new == NULL)
        return NULL;
   else{
        new->data = data;
        new->left =NULL;
        new->right =NULL;
   }
   return new;
}

// call newNode() three times 
struct node* build123a() {
  struct node* root = newNode(2);
  struct node* lChild = newNode(1);
  struct node* rChild = newNode(3);
  root->left = lChild;
  root->right= rChild;

  return(root);
}

// call newNode() three times, and use only one local variable 
struct node* build123b() {
  struct node* root = newNode(2);
  root->left = newNode(1);
  root->right = newNode(3);

  return(root);
}

/* 
 Build 123 by calling insert() three times. 
 Note that the '2' must be inserted first. 
*/
struct node* build123c() {
  struct node* root = NULL;
  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 3);
  return(root);
}

/* compute the number of nodes in a tree */
int size(struct node* node) {
  if (node==NULL) {
    return(0);
  } else {
    return(size(node->left) + 1 + size(node->right));
  }
}
/* 
 Compute the "maxDepth" of a tree -- the number of nodes along 
 the longest path from the root node down to the farthest leaf node. 
*/
int maxDepth(struct node* node) {
  if (node==NULL) {
    return(0);
  }
  else {
    // compute the depth of each subtree 
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    // use the larger one 
    if (lDepth > rDepth) return(lDepth+1);
    else return(rDepth+1);
  }
}

/* 
 Given a non-empty binary search tree, 
 return the minimum data value found in that tree. 
 Note that the entire tree does not need to be searched. 
*/
int minValue(struct node* node) {
  struct node* current = node;
  // loop down to find the leftmost leaf 
  while (current->left != NULL) {
    current = current->left;
  }

  return(current->data);
}

void printTree(TN *root) {
    if(root == NULL)
        return;

    // adjust the sequence you can get other order
    printTree( root->left);
    print("%d", root->data);
    printTree( root->right);
}
/* 
 Given a tree and a sum, return true if there is a path from the root 
 down to a leaf, such that adding up all the values along the path 
 equals the given sum.
 Strategy: subtract the node value from the sum when recurring down, 
 and check to see if the sum is 0 when you run out of tree. 
*/
int hasPathSum(struct node* node, int sum) {
  // return true if we run out of tree and sum==0 
  if (node == NULL) {
    return(sum == 0);
  }
  else {
  // otherwise check both subtrees 
    int subSum = sum - node->data;
    return(hasPathSum(node->left, subSum) ||
           hasPathSum(node->right, subSum));
  }
}

/* 
 Given a binary tree, print out all of its root-to-leaf 
 paths, one per line. Uses a recursive helper to do the work. 
*/
void printPaths(struct node* node) {
  int path[1000];
  printPathsRecur(node, path, 0);
}

/* 
 Recursive helper function -- given a node, and an array containing 
 the path from the root node up to but not including this node, 
 print out all the root-leaf paths. 
*/
void printPathsRecur(struct node* node, int path[], int pathLen) {
  if (node==NULL) return;

  // append this node to the path array 
  path[pathLen] = node->data;
  pathLen++;

  // it's a leaf, so print the path that led to here 
  if (node->left==NULL && node->right==NULL) {
    printArray(path, pathLen);
  }
  else {
  // otherwise try both subtrees 
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

// Utility that prints out an array on a line. 
void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
}


/* 
 Change a tree so that the roles of the 
 left and right pointers are swapped at every node.
 So the tree... 
       4 
      / \ 
     2   5 
    / \ 
   1   3

 is changed to... 
     4 
      / \ 
     5   2 
        / \ 
       3   1 
*/
void mirror(struct node* node) {
  if (node==NULL) {
    return;
  }
  else {
    struct node* temp;

    // do the subtrees 
    mirror(node->left);
    mirror(node->right);

    // swap the pointers in this node 
    temp = node->left;
    node->left = node->right;
    node->right = temp;
  }
}

/* 
 For each node in a binary search tree, 
 create a new duplicate node, and insert 
 the duplicate as the left child of the original node. 
 The resulting tree should still be a binary search tree.
 So the tree... 
    2 
   / \ 
  1   3

 Is changed to... 
       2 
      / \ 
     2   3 
    /   / 
   1   3 
  / 
 1

*/
void doubleTree(struct node* node) {
  struct node* oldLeft;

  if (node==NULL) return;

  // do the subtrees 
  doubleTree(node->left);
  doubleTree(node->right);

  // duplicate this node to its left 
  oldLeft = node->left;
  node->left = newNode(node->data);
  node->left->left = oldLeft;
}

/* 
 * return true if a binary tree is a binary search tree.
*/
int isBST(struct node* node) {
  if (node==NULL) return(true);
  // false if the max of the left is > than us

  // (bug -- an earlier version had min/max backwards here) 
  if (node->left!=NULL && maxValue(node->left) > node->data)
    return(false);

  // false if the min of the right is <= than us 
  if (node->right!=NULL && minValue(node->right) <= node->data)
    return(false);

  // false if, recursively, the left or right is not a BST 
  if (!isBST(node->left) || !isBST(node->right))
    return(false);

  // passing all that, it's a BST 
  return(true);
}

/* 
 Returns true if the given tree is a binary search tree 
 (efficient version). 
*/
int isBST2(struct node* node) {
  return(isBSTUtil(node, INT_MIN, INT_MAX));
}
/* 
 Returns true if the given tree is a BST and its 
 values are >= min and <= max. 
*/
int isBSTUtil(struct node* node, int min, int max) {
  if (node==NULL) return(true);

  // false if this node violates the min/max constraint 
  if (node->data<min || node->data>max) return(false);

  // otherwise check the subtrees recursively, 
  // tightening the min or max constraint 
  return
    isBSTUtil(node->left, min, node->data) &&
    isBSTUtil(node->right, node->data+1, max)
  );
}





//bst succsor and predecsor

Node* pred = NULL, *succ = NULL;
Node* cur = root;

// 1) First, walk down the tree to locate where x would be.
//    Along the way, keep track of potential preds and succs.
while (cur != NULL) {
  if (cur->data == x) {
    // Found the node: we can refine both pred & succ
    break;
  }
  else if (x < cur->data) {
    // Current node is a candidate for successor
    succ = cur;        
    // Go left to find x (or something even closer)
    cur = cur->Lchild;
  }
  else { // x > cur->data
    // Current node is a candidate for predecessor
    pred = cur;
    // Go right
    cur = cur->Rchild;
  }
}

// 2) If we actually found the node (cur->data == x), 
//    we can look in its subtrees for tighter bounds:

if (cur != NULL && cur->Lchild != NULL) {
  // predecessor is max in left subtree
  Node* t = cur->Lchild;
  while (t->Rchild != NULL) t = t->Rchild;
  pred = t;
}

if (cur != NULL && cur->Rchild != NULL) {
  // successor is min in right subtree
  Node* t = cur->Rchild;
  while (t->Lchild != NULL) t = t->Lchild;
  succ = t;
}

// At this point, `pred` points to the in-order predecessor (or NULL if none),
// and `succ` points to the in-order successor (or NULL if none).


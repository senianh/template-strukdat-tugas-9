#include "problem_a.hpp"
#include <queue>  // Include the queue header

template <typename T>
void BFSTraversal(Tree<T> &Root, vector<T> &traversedData) {
  if (Root == nullptr) return;

  std::queue<Tree<T>> q; 
  q.push(Root);

  while (!q.empty()) {
    Tree<T> current = q.front();
    q.pop();
    traversedData.push_back(current->data);

    if (current->left != nullptr)
      q.push(current->left);

    if (current->right != nullptr)
      q.push(current->right);
  }
}

template <typename T>
Tree<T> lowestCommonAncestor(Tree<T>& Root, pointer<T> a, pointer<T> b) {
  if (Root == nullptr) return nullptr;

  if (a->data < Root->data && b->data < Root->data)
    return lowestCommonAncestor(Root->left, a, b);

  if (a->data > Root->data && b->data > Root->data)
    return lowestCommonAncestor(Root->right, a, b);

  return Root;
}

template <typename T>
Tree<T> invertBST(Tree<T>& Root) {
  if (Root == nullptr) return Root;
  
  Tree<T> temp = Root->left;
  Root->left = Root->right;
  Root->right = temp;

  if (Root->left != nullptr)
    invertBST(Root->left);
  if (Root->right != nullptr)
    invertBST(Root->right);

  return Root;
}

// Explicit template instantiation
template void BFSTraversal<int>(Tree<int>&, vector<int>&);
template Tree<int> lowestCommonAncestor<int>(Tree<int>&, pointer<int>, pointer<int>);
template Tree<int> invertBST<int>(Tree<int>&);

#include "problem_a.hpp"

template <typename T>
void BFSTraversal(Tree<T> &Root, vector<T> &traversedData)
{
  if (Root == nullptr){
    return;
  }
  
  vector<pointer<T>> temp;
  temp.push_back(Root);
  
  while(!temp.empty()){

    pointer<T> pHelp = temp.front();

    traversedData.push_back(pHelp->data);
    temp.erase(temp.begin());

    if(pHelp->left != nullptr){
      temp.push_back(pHelp->left);
    }

    if(pHelp -> right != nullptr){
      temp.push_back(pHelp->right);
    }
  }
}

template <typename T>
Tree<T> lowestCommonAncestor(Tree<T>& Root, pointer<T> a, pointer<T> b)
{
  if (Root == nullptr){
    return Root;
  }
  if (Root->data > a->data && Root->data > b->data){
    return lowestCommonAncestor(Root->left, a, b);
  } 
  else if (Root->data < a->data && Root->data < b->data){
    return lowestCommonAncestor(Root->right, a, b);
  }

  return Root;
}

template <typename T>
Tree<T> invertBST(Tree<T>& Root)
{
  if (Root == nullptr){
    return Root;
  }

  invertBST(Root->left);
  invertBST(Root->right);

  pointer<T> temp = Root->left;

  Root->left = Root->right;
  Root->right = temp;
  
  return Root;
}
#pragma once

#include <vector>
using std::vector;

namespace strukdat {

namespace bst {

/**
 * @brief   Node tree berisi nilai bertipe `T` yang disimpan pada `data`
 */
template <typename T> struct Node {
  T data;
  Node *left;
  Node *right;
};

/**
 * @brief   Tipe pointer dari node
 */
template <typename T> using pointer = Node<T> *;

/**
 * @brief   Alias untuk pointer
 */
template <typename T> using Tree = pointer<T>;

template <typename T> Tree<T> Root;

/**
 * @brief    Fungsi untuk membuat tree baru
 *
 * @return   simply nullptr:)
 */
template <typename T> Tree<T> createTree() { return nullptr; }

/**
 * @brief   Membuat dan menginisialisasi element baru untuk dimasukkan ke tree
 * @param data   data yang akan dimasukkan
 *
 * @return       pointer ke elemen baru
 */
template <typename T> pointer<T> createElement(T data) {
  pointer<T> newElement = new Node<T>;

  newElement->data = data;
  newElement->left = nullptr;
  newElement->right = nullptr;

  return newElement;
}

/**
 * @brief   Mengecek apakah elemen yang dipass memiliki data yang lebih besar
 * dibanding root tree
 * @param Root           pointer ke element parent/ root
 * @param checkElement   pointer ke element yang di cek
 *
 * @return              'true' jika data pada checkElement lebih besar dari data
 * root, 'false' jika sebaliknya
 */
template <typename T>
bool isHigherThanRoot(Tree<T> &Root, pointer<T> &checkElement) {
  if (Root->data<checkElement->data) 
  {
    return true;
  }
  return false;
}

/**
 * @brief   Memasukkan element ke dalam tree
 * @note    Implementasikan secara rekursif
 * @param Root         pointer ke element parent/ root
 * @param newElement   pointer ke element baru
 */
template <typename T> void insertBST(Tree<T> &Root, pointer<T> newElement) {
  if (Root == nullptr){
    Root = newElement;
  } 
  else if (isHigherThanRoot(Root, newElement)){
    insertBST(Root->right, newElement);
  }
  else{
    insertBST(Root->left, newElement);
  }
}

/**
 * @brief   Mencari element dalam tree
 * @note    Implementasikan secara rekursif
 * @param Root   pointer ke element parent/ root
 * @param data   data yang ingin dicari
 *
 * @return       pointer element yang dicari
 */
template <typename T> pointer<T> search(Tree<T> &Root, T data) {
  if (Root != nullptr){
    if (Root->data == data) return Root;
    if (Root->data>data){
      return search (Root->left,data);
    }
    else{
      return search (Root->right,data);
    }
  }
  return nullptr;
}

/**
 * @brief   Melakukan traversal tree secara preOrder (P->L->R)
 * @note    Lakukan push_back data dari Root ke traversedData
 * @param Root            pointer ke element parent/ root
 * @param traversedData   vector yang menyimpan data traversal
 */
template <typename T> void preOrder(Tree<T> &Root, vector<T> &traversedData) {
  if (Root != nullptr){

    traversedData.push_back(Root->data);
    
    preOrder(Root->left, traversedData);
    preOrder(Root->right, traversedData);
  }
}

/**
 * @brief   Melakukan traversal tree secara inOrder (L->P->R)
 * @note    Lakukan push_back data dari Root ke traversedData
 * @param Root            pointer ke element parent/ root
 * @param traversedData   vector yang menyimpan data traversal
 */
template <typename T> void inOrder(Tree<T> &Root, vector<T> &traversedData) {
  if(Root != nullptr){

    inOrder(Root->left, traversedData);

    traversedData.push_back(Root->data);

    inOrder(Root->right, traversedData);
  }
}

/**
 * @brief   Melakukan traversal tree secara postOrder (L->R->P)
 * @note    Lakukan push_back data dari Root ke traversedData
 * @param Root            pointer ke element parent/ root
 * @param traversedData   vector yang menyimpan data traversal
 */
template <typename T> void postOrder(Tree<T> &Root, vector<T> &traversedData) {
  if (Root != nullptr){

    postOrder(Root->left, traversedData);
    postOrder(Root->right, traversedData);
    
    traversedData.push_back(Root->data);
  }
}

} // namespace bst

} // namespace strukdat
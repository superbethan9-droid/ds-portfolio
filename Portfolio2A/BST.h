#ifndef BST_H
#define BST_H

template <typename T>
class BST {
private:
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
  };
  Node* root;
  Node* insertHelper(Node* node, const T& value) {
    if (node==nullptr)
      return new Node(value);
    if (value < node->value)
      node->left = insertHelper(node->left, value);
    else if (value > node->value)
      node->right = insertHelper(node->right, value);
    return node;
  }
  bool searchHelper(const Node*node, const T& value) const {
    if (node == nullptr)
      return false;
    if (value ==node->value)
      return true;
    if (value < node->value)
      return searchHelper(node->left, value);
    return searchHelper(node->right, value);
  }
public:
  BST() : root(nullptr) {}
  void insert(const T& value) {
    root = insertHelper(root, value);
  }
  bool search(const T& value) const {
    return searchHelper(root, value);
  }
};

#endif
  

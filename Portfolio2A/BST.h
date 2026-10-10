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
  Node* findMin(Node* node) const {
    if (node->left == nullptr)
      return node;
    return findMin(node->left);
  }
  Node* removeHelper(Node* node, const T& value) {
    if (node==nullptr)
      return nullptr;
    if (value < node->value)
      node->left = removeHelper(node->left, value);
    else if (value > node->value)
      node->right = removeHelper(node->right, value);
    else {
      if (node->left == nullptr && node->right == nullptr) {
	delete node;
	return nullptr;
      }
      if (node->left == nullptr) {
	Node* temp = node->right;
	delete node;
	return temp;
      }
      if (node->right==nullptr) {
	Node* temp = node->left;
	delete node;
	return temp;
      }
      Node* successor = findMin(node->right);
      node->value = successor->value;
      node->right=removeHelper(node->right, successor->value);
    }
    return node;
  }
      
public:
  BST() : root(nullptr) {}
  void insert(const T& value) {
    root = insertHelper(root, value);
  }
  bool search(const T& value) const {
    return searchHelper(root, value);
  }
  void remove(const T& value) {
    root=removeHelper(root, value);
  }
  
};

#endif
  

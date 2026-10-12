#ifndef BST_H
#define BST_H
#include <vector>


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

  int heightHelper(const Node* node) const {
    if (node==nullptr)
      return -1;
    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);
    return 1+ (leftHeight>rightHeight? leftHeight: rightHeight);
  }
  int sizeHelper(const Node* node) const {
    if (node == nullptr)
      return 0;
    return 1+ sizeHelper(node->left) + sizeHelper(node->right);
  }
  void inorderHelper(const Node* node, std::vector<T>& result) const {
    if (node==nullptr)
      return;

    inorderHelper(node->left, result);
    result.push_back(node->value);
    inorderHelper(node->right, result);
  }
  void preorderHelper(const Node* node, std::vector<T>& result) const {
    if (node == nullptr)
      return;
    result.push_back(node->value);
    preorderHelper(node->left, result);
    preorderHelper(node->right, result);
  }
  void postorderHelper(const Node* node, std::vector<T>& result) const {
    if (node==nullptr)
      return;
    postorderHelper(node->left, result);
    postorderHelper(node->right, result);
    result.push_back(node->value);
  }
  void levelorderHelper(const Node* node, int level, std::vector<T>& result) const {
    if (node==nullptr)
      return;
    if (level==0) {
      result.push_back(node->value);
    } else {
      levelorderHelper(node->left, level -1, result);
      levelorderHelper(node->right, level -1, result);
    }
  }
  void destroyHelper(Node*node) {
    if (node==nullptr)
      return;
    destroyHelper(node->left);
    destroyHelper(node->right);
    delete node;
  }

  Node* copyHelper(const Node* node) const {
    if (node ==nullptr)
      return nullptr;
    Node* newNode = new Node(node->value);
    newNode->left = copyHelper(node->left);
    newNode->right=copyHelper(node->right);
    return newNode;
  }
  
      
public:
  BST() : root(nullptr) {}
  BST(const BST& other) : root(nullptr) {
    root = copyHelper(other.root);
  }
  ~BST() {
    destroyHelper(root);
  }
  BST& operator=(const BST& other) {
    if (this != &other) {
      Node* newRoot = copyHelper(other.root);
      destroyHelper(root);
      root=newRoot;
    }
    return *this;
  }
  void insert(const T& value) {
    root = insertHelper(root, value);
  }
  bool search(const T& value) const {
    return searchHelper(root, value);
  }
  void remove(const T& value) {
    root=removeHelper(root, value);
  }
  int height() const {
    return heightHelper(root);
  }
  int size() const {
    return sizeHelper(root);
  }
  std::vector<T> inorder() const {
    std::vector<T> result;
    inorderHelper(root, result);
    return result;
  }
  std::vector<T> preorder() const {
    std::vector<T> result;
    preorderHelper(root, result);
    return result;
  }
  std::vector<T> postorder() const {
    std::vector<T> result;
    postorderHelper(root, result);
    return result;
  }
  std::vector<T> levelorder() const {
    std::vector<T> result;
    for(int level=0; level <=height(); level++)
      levelorderHelper(root, level, result);
    return result;
  }
  
};

#endif
  

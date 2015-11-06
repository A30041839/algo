#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctype.h>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <tuple>


//data structures
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct UndirectedGraphNode {
  int label;
  std::vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


//public functions
void inorder(TreeNode* root){
  if (root){
    inorder(root->left);
    std::cout << root->val << ",";
    inorder(root->right);
  }
}

void postorder(TreeNode* root){
  if (root){
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << ",";
  }
}

void preorder(TreeNode* root){
  if (root){
    std::cout << root->val << ",";
    preorder(root->left);
    preorder(root->right);
  }
}

void print_array(int nums[], int n){
  for (int i = 0; i < n; ++i){
    std::cout << nums[i] << ",";
  }
  std::cout << std::endl;
}

void print_list(ListNode* head) {
  while (head) {
    std::cout << head->val << ",";
    head = head->next;
  }
  std::cout << std::endl;
}

template <class T>
void print_matrix(std::vector<std::vector<T>>& matrix) {
  int m = (int)matrix.size(), n = (int)matrix[0].size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << ",";
    }
    std::cout << std::endl;
  }
}

template <class T>
void print_vec(std::vector<T>& v) {
  for (T& elem : v) {
    std::cout << elem << ",";
  }
  std::cout << std::endl;
}

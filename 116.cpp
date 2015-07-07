#include "leetcode.h"

using namespace std;

class Solution {
public:
  void connect(TreeLinkNode *root) {
    return connect4(root);
  }

  void connect1(TreeLinkNode *root) {
    queue<TreeLinkNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      TreeLinkNode* prev = nullptr;
      while (n--) {
        TreeLinkNode* cur = q.front();
        q.pop();
        if (cur) {
          if (prev) {
            prev->next = cur;
          }
          prev = cur;
          q.push(cur->left);
          q.push(cur->right);
        }
      }
    }
  }

  void connect2(TreeLinkNode *root) {
    queue<pair<TreeLinkNode*, int>> q;
    q.push({root, 0});
    TreeLinkNode* prev = root;
    int dep = -1;
    while (!q.empty()) {
      TreeLinkNode* cur = q.front().first;
      int curDep = q.front().second;
      q.pop();
      if (cur) {
        if (curDep != dep) {
          dep = curDep;
        }else {
          prev->next = cur;
        }
        prev = cur;
        q.push({cur->left, dep + 1});
        q.push({cur->right, dep + 1});
      }
    }
  }

  void connect3(TreeLinkNode *root) {
    TreeLinkNode* p = root;
    while (p and p->left) {
      TreeLinkNode* q = p;
      while (q and q->left) {
        q->left->next = q->right;
        if (q->next) {
          q->right->next = q->next->left;
        }
        q = q->next;
      }
      p = p->left;
    }
  }

  void connect4(TreeLinkNode *root) {
    if (!root) {
      return;
    }
    if (!root->left) {
      return;
    }
    root->left->next = root->right;
    if (root->next) {
      root->right->next = root->next->left;
    }
    connect4(root->left);
    connect4(root->right);
  }
};

void print_level(TreeLinkNode* first){
  while (first){
    cout << first->val << ",";
    first = first->next;
  }
  cout << endl;
}

int main(){
  Solution s;
  TreeLinkNode* node1 = new TreeLinkNode(1);
  TreeLinkNode* node2 = new TreeLinkNode(2);
  TreeLinkNode* node3 = new TreeLinkNode(3);
  TreeLinkNode* node4 = new TreeLinkNode(4);
  TreeLinkNode* node5 = new TreeLinkNode(5);
  TreeLinkNode* node6 = new TreeLinkNode(6);
  TreeLinkNode* node7 = new TreeLinkNode(7);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;
  node3->right = node7;

  s.connect(node1);
  while (node1){
    print_level(node1);
    node1 = node1->left;
  }
  return 0;
}

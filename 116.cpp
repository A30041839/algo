#include "leetcode.h"

using namespace std;

class Solution {
public:
  void connect(TreeLinkNode *root) {
  }

  void connect1(TreeLinkNode *root) {
    if (!root){
      return;
    }
    queue<TreeLinkNode*> q;
    q.push(root);
    while (!q.empty()){
      TreeLinkNode* prev = nullptr;
      int last = q.size();
      for (int i = 0; i < last; ++i){
        TreeLinkNode* cur = q.front();
        q.pop();
        if (cur->left){
          q.push(cur->left);
        }
        if (cur->right){
          q.push(cur->right);
        }
        if (prev != nullptr){
          prev->next = cur;
        }
        prev = cur;
      }
    }
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

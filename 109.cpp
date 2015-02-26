#include "leetcode.h"

using namespace std;

void inorder(TreeNode* root){
  if (root){
    inorder(root->left);
    cout << root->val << ",";
    inorder(root->right);
  }
}

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    return sortedListToBST1(head, nullptr);
  }

  TreeNode* sortedListToBST1(ListNode* begin, ListNode* end){
    if (begin == end){
      return nullptr;
    }
    ListNode* slow = begin, *fast = begin;
    while (fast != end and fast->next != end){
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode* subroot = new TreeNode(slow->val);
    subroot->left = sortedListToBST1(begin, slow);
    subroot->right = sortedListToBST1(slow->next, end);
    return subroot;
  }
};

int main(){
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(5);
  //head->next = node1;
  //node1->next = node2;
  //node2->next = node3;
  //node3->next = node4;

  Solution s;
  TreeNode* root = s.sortedListToBST(head);
  inorder(root);
  cout << endl;
  return 0;
}

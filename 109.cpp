#include "leetcode.h"

using namespace std;

class Solution {
private:
  ListNode* findMid(ListNode* beg, ListNode* end) {
    ListNode *p1 = beg, *p2 = beg;
    while (p2 != end and p2->next != end) { //!!
      p1 = p1->next;
      p2 = p2->next->next;
    }
    return p1;
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    int len = 0;
    ListNode* ptr = head;
    while (ptr) {
      len++;
      ptr = ptr->next;
    }
    return sortedListToBST2(head, 0, len - 1);
  }

  //here end is the next position of last element
  TreeNode *sortedListToBST1(ListNode *beg, ListNode *end) {
    if (beg == end) {
      return nullptr;
    }
    ListNode* mid = findMid(beg, end);
    TreeNode* subroot = new TreeNode(mid->val);
    subroot->left = sortedListToBST1(beg, mid);
    subroot->right = sortedListToBST1(mid->next, end);
    return subroot;
  }

  //better solution!
  //no need to find the middle element everytime!
  TreeNode *sortedListToBST2(ListNode*& cur, int beg, int end) {
    if (beg > end) {
      return nullptr;
    }
    int mid = (beg + end) >> 1;
    TreeNode* left = sortedListToBST2(cur, beg, mid - 1);
    TreeNode* subroot = new TreeNode(cur->val);
    cur = cur->next;
    subroot->left = left;
    subroot->right = sortedListToBST2(cur, mid + 1, end);
    return subroot;
  }
};

int main(){
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  Solution s;
  TreeNode* root = s.sortedListToBST(head);
  inorder(root);
  cout << endl;
  return 0;
}

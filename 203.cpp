#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0), *prev = &dummy, *ptr = head;
    while (ptr) {
      ListNode* next = ptr->next;
      if (ptr->val == val) {
        delete ptr;
      }else {
        prev->next = ptr;
        ptr->next = nullptr;
        prev = ptr;
      }
      ptr = next;
    }
    return dummy.next;
  }
};

int main() {
  Solution s;
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(6);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  ListNode *node6 = new ListNode(6);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  head = s.removeElements(head, 6);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

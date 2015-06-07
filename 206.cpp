#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    return reverseList2(head);
  }

  //iterative
  ListNode* reverseList1(ListNode* head) {
    ListNode dummy(0), *ptr = head;
    while (ptr) {
      auto tmp = ptr->next;
      ptr->next = dummy.next;
      dummy.next = ptr;
      ptr = tmp;
    }
    return dummy.next;
  }

  //recursive !!
  ListNode* reverseList2(ListNode* head) {
    if (!head or !head->next) {
      return head;
    }
    auto new_head = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }
};

int main() {
  Solution s;
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  head = s.reverseList(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

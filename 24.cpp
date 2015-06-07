#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    return swapPairs1(head);
  }

  //recursive
  ListNode *swapPairs1(ListNode *ptr) {
    if (!ptr or !ptr->next) {
      return ptr;
    }
    auto tmp = ptr->next;
    ptr->next = swapPairs1(tmp->next);
    tmp->next = ptr;
    return tmp;
  }

  //iterative
  ListNode *swapPairs2(ListNode *head) {
    ListNode dummy(0), *ptr = head, *prev = &dummy;
    dummy.next = head;
    while (ptr and ptr->next) {
      prev->next = ptr->next;
      ptr->next= ptr->next->next;
      prev->next->next = ptr;
      prev = ptr;
      ptr = ptr->next;
    }
    return dummy.next;
  }
};

int main(){
  Solution s;
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  head = s.swapPairs(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

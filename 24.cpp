#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode dummy(0), *ptr, *prev = &dummy;
    dummy.next = head;
    ptr = dummy.next;
    while (ptr and ptr->next){
      prev->next = ptr->next;
      ListNode* tmp = ptr->next->next;
      ptr->next->next = ptr;
      ptr->next = tmp;
      prev = ptr;
      ptr = tmp;
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

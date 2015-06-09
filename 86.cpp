#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    return partition1(head, x);
  }

  ListNode *partition1(ListNode *head, int x) {
    ListNode dummy1(0), dummy2(0), *ptr1 = &dummy1, *ptr2 = &dummy2, *ptr = head;
    while (ptr) {
      ListNode*& pInsert = ptr->val < x ? ptr1 : ptr2;
      pInsert->next = ptr;
      pInsert = ptr;
      ptr = ptr->next;
    }
    ptr1->next = dummy2.next;
    ptr2->next = nullptr;
    return dummy1.next;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(4);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(2);
  ListNode* node4 = new ListNode(5);
  ListNode* node5 = new ListNode(2);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  ListNode* res = s.partition(head, 3);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

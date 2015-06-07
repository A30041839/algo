#include "leetcode.h"

using namespace std;

class Solution {
public:
  void reorderList(ListNode *head) {
    reorderList1(head);
  }

  void reorderList1(ListNode *head) {
    //find the middle node
    ListNode dummy(0), *p1 = head, *p2 = head, *tmp;
    if (!head or !head->next) {
      return;
    }
    while (p1 and p1->next) {
      tmp = p2;
      p2 = p2->next;
      p1 = p1->next->next;
    }
    tmp->next = nullptr;
    //reverse the second half
    while (p2) {
      tmp = p2->next;
      p2->next = dummy.next;
      dummy.next = p2;
      p2 = tmp;
    }
    //interveave the two halves
    p1 = head;
    while (p1) {
      p2 = dummy.next;
      dummy.next = p2->next;
      tmp = p1->next;
      p1->next = p2;
      p2->next = tmp;
      p1 = tmp;
    }
    p2->next = dummy.next;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  s.reorderList(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

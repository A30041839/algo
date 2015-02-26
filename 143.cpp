#include "leetcode.h"

using namespace std;

class Solution {
public:
  void reorderList(ListNode *head) {
    ListNode dummy(0), *p1 = &dummy, *p2 = &dummy;
    dummy.next = head;
    while (p2 and p2->next){
      p1 = p1->next;
      p2 = p2->next->next;
    }
    ListNode* p3 = nullptr, *p4 = p1->next;
    p1->next = nullptr;
    while (p4){
      ListNode* tmp = p4->next;
      p4->next = p3;
      p3 = p4;
      p4 = tmp;
    }
    p1 = dummy.next;
    p2 = p3;
    p3 = &dummy;
    int k = 0;
    while (p1 and p2){
      ListNode*& p = k == 0 ? p1 : p2;
      p3->next = p;
      p = p->next;
      p3 = p3->next;
      k = 1 - k;
    }
    p3->next = p1 ? p1 : p2;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(5);
  //head->next = node1;
  //node1->next = node2;
  //node2->next = node3;
  //node3->next = node4;
  s.reorderList(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

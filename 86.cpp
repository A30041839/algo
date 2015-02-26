#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    if (head == 0){
      return head;
    }
    ListNode dummy1(0), dummy2(0), *p1 = &dummy1, *p2 = &dummy2;
    while (head){
      ListNode*& p = head->val < x ? p1 : p2;
      p->next = head;
      p = p->next;
      head = head->next;
    }
    p2->next = 0;
    p1->next = dummy2.next;
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
  ListNode* res = s.partition(head, -6);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

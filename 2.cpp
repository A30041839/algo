#include "leetcode.h"
using namespace std;

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == NULL){
      return l2;
    }
    if (l2 == NULL){
      return l1;
    }
    ListNode dummy(0), *p = &dummy;
    int carry = 0;
    while (l1 or l2){
      int c1 = l1 ? l1->val : 0;
      int c2 = l2 ? l2->val : 0;
      int k = c1 + c2 + carry;
      carry = k >= 10 ? 1 : 0;
      k %= 10;
      p->next = new ListNode(k);
      p = p->next;
      l1 = l1 ? l1->next : 0;
      l2 = l2 ? l2->next : 0;
    }
    if (carry){
      p->next = new ListNode(1);
    }
    return dummy.next;
  }
};

int main(){
  Solution s;
  ListNode *head1 = new ListNode(3);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(1);
  ListNode *head2 = new ListNode(7);
  ListNode *node3 = new ListNode(7);
  head1->next = node1;
  node1->next = node2;
  head2->next = node3;
  ListNode* sum = s.addTwoNumbers(head1, head2);
  while (sum){
    cout << sum->val << ",";
    sum = sum->next;
  }
  cout << endl;
  return 0;
}

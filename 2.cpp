#include "leetcode.h"
using namespace std;

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0), *p = &dummy;
    int carry = 0, c1, c2, sum;
    while (l1 or l2 or carry){
      c1 = l1 ? l1->val : 0;
      c2 = l2 ? l2->val : 0;
      sum = c1 + c2 + carry;
      carry = sum / 10;
      sum %= 10;
      p->next = new ListNode(sum);
      p = p->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
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

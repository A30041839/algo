#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0), *cur = &dummy;
    while (l1 and l2){
      ListNode*& pMin = l1->val < l2->val ? l1 : l2;
      cur->next = pMin;
      pMin = pMin->next;
      cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
  }
};

int main(){
  ListNode* head1 = new ListNode(1);
  ListNode* head2 = new ListNode(-1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(5);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(7);
  head1->next = node1;
  node1->next = node2;
  head2->next = node3;
  node3->next = node4;
  Solution s;
  ListNode* res = s.mergeTwoLists(head1, head2);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

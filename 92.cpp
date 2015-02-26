#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(0), *p1, *p2 = head, *p3 = &dummy, *s;
    dummy.next = head;
    for (int i = 1; i <= n; ++i){
      if (i <= m){
        if (i == m){
          s = p2;
          p1 = p3;
        }
        p3 = p2;
        p2 = p2->next;
      }else if (i > m){
        ListNode* tmp = p2->next;
        p2->next = p3;
        p3 = p2;
        p2 = tmp;
      }
    }
    p1->next = p3;
    s->next = p2;
    return dummy.next;
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
  ListNode* res = s.reverseBetween(head, 1, 5);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

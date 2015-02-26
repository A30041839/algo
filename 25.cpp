#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummy(0), *p1 = head, *p2 = nullptr, *p3 = &dummy;
    dummy.next = head;
    while (true){
      ListNode* s = p3->next;
      int i;
      for (i = 0; i < k && p1; ++i){
        ListNode* tmp = p1->next;
        p1->next = p2;
        p2 = p1;
        p1 = tmp;
      }
      if (i != k){
        while (p2 != s) {
          ListNode* tmp = p2->next;
          p2->next = p1;
          p1 = p2;
          p2 = tmp;
        }
        if (s){
          s->next = p1;
        }
        break;
      }else{
        p3->next = p2;
        s->next = p1;
        p3 = s;
        p2 = nullptr;
      }
    }
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
  ListNode* res = s.reverseKGroup(head, 5);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

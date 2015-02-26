#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head){
      return NULL;
    }
    ListNode dummy(0), *p_fast = &dummy, *p_slow = &dummy;
    dummy.next = head;
    bool f = false;
    while (p_fast and p_fast->next){
      p_fast = f ? p_fast->next : p_fast->next->next;
      p_slow = p_slow->next;
      if (p_fast == p_slow){
        if (f){
          return p_fast;
        }else{
          f = true;
          p_slow = &dummy;
        }
      }
    }
    return NULL;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(5);
  ListNode* node3 = new ListNode(7);
  ListNode* node4 = new ListNode(2);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node1;
  ListNode* res = s.detectCycle(head);
  if (res){
    cout << res->val << endl;
  }else{
    cout << "no cycle" << endl;
  }
  return 0;
}

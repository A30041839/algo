#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    bool f = false;
    while (fast and fast->next) {
      if (slow == fast and f) {
        return slow;
      }
      fast = f ? fast->next : fast->next->next;
      slow = slow->next;
      if (slow == fast and !f) {
        f = true;
        fast = head;
      }
    }
    return nullptr;
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

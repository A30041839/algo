#include "leetcode.h"

using namespace std;

class Solution {
public:
  //one pass
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(0), *slow = &dummy, *fast = head;
    dummy.next = head;
    while (fast) {
      if (n > 0) {
        n--;
      }else {
        slow = slow->next;
      }
      fast = fast->next;
    }
    auto tmp = slow->next;
    slow->next = tmp->next;
    delete tmp;
    return dummy.next;
  }
};

int main(){
  ListNode* head = new ListNode(0);
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  Solution s;
  head = s.removeNthFromEnd(head, 1);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }

  return 0;
}

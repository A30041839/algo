#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != NULL){
      if (n != 0){
        fast = fast->next;
        n--;
      }else{
        fast = fast->next;
        slow = slow->next;
      }
    }
    if (n > 0){
      ListNode* tmp = head;
      head = head->next;
      delete tmp;
    }else{
      ListNode* tmp = slow->next;
      slow->next = tmp->next;
      delete tmp;
    }
    return head;
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
  head = s.removeNthFromEnd(head, 2);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }

  return 0;
}

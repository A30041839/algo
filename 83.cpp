#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode* p = head;
    while (p != NULL and p->next != NULL){
      if (p->val == p->next->val){
        ListNode* tmp = p->next;
        p->next = tmp->next;
        delete tmp;
      }else{
        p = p->next;
      }
    }
    return head;
  }
};

int main(){
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  //node2->next = node3;
  //node3->next = node4;
  Solution s;
  head = s.deleteDuplicates(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

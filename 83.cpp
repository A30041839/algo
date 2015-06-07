#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode* ptr = head, *tmp;
    while (ptr and ptr->next){
      if (ptr->val == ptr->next->val){
        tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
      }else{
        ptr = ptr->next;
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

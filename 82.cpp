#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head){
      return NULL;
    }else if (!head->next){
      return head;
    }
    ListNode dummy(0), *p = head, *prev = &dummy;
    dummy.next = head;
    while (p and p->next){
      if (p->val == p->next->val){
        ListNode* ptr = p->next;
        while (ptr and ptr->val == p->val){
          ListNode* tmp = ptr->next;
          delete ptr;
          ptr = tmp;
        }
        delete p;
        prev->next = ptr;
        p = ptr;
      }else{
        prev = p;
        p = p->next;
      }
    }
    return dummy.next;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(1);
  ListNode* node3 = new ListNode(2);
  ListNode* node4 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  ListNode *res = s.deleteDuplicates(head);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

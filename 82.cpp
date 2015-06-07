#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    return deleteDuplicates1(head);
  }

  //recursive
  ListNode *deleteDuplicates1(ListNode *head) {
    if (!head or !head->next) {
      return head;
    }
    if (head->val != head->next->val) {
      head->next = deleteDuplicates1(head->next);
      return head;
    }else {
      int val = head->val;
      while (head and head->val == val) {
        auto tmp = head->next;
        delete head;
        head = tmp;
      }
      return deleteDuplicates1(head);
    }
  }

  //iterative
  ListNode *deleteDuplicates2(ListNode *head) {
    ListNode dummy(0), *ptr = head, *prev = &dummy, *tmp;
    dummy.next = head;
    bool f;
    while (ptr and ptr->next) {
      f = false;
      while (ptr->next and ptr->val == ptr->next->val) {
        f = true;
        tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
      }
      if (f) {
        prev->next = ptr->next;
        delete ptr;
      }else {
        prev = prev->next;
      }
      ptr = prev->next;
    }
    return dummy.next;
  }

  //iterative
  ListNode *deleteDuplicates3(ListNode *head) {
    ListNode dummy(0), *prev = &dummy, *ptr;
    dummy.next = head;
    while (prev->next) {
      ptr = prev->next;
      if (!ptr->next or ptr->val != ptr->next->val) {
        prev = ptr;
        continue;
      }
      int val = ptr->val;
      while (ptr and ptr->val == val) {
        auto tmp = ptr->next;
        delete ptr;
        ptr = tmp;
      }
      prev->next = ptr;
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

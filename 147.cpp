#include "leetcode.h"

using namespace std;

class Solution {
private:
  void insert(ListNode* head, ListNode* ptr) {
    while (head->next and head->next->val < ptr->val) {
      head = head->next;
    }
    ptr->next = head->next;
    head->next = ptr;
  }

public:
  ListNode *insertionSortList(ListNode *head) {
    return insertionSortList1(head);
  }

  ListNode *insertionSortList1(ListNode *head) {
    ListNode dummy(0), *cur = head, *tmp;
    while (cur) {
      tmp = cur->next;
      insert(&dummy, cur);
      cur = tmp;
    }
    return dummy.next;
  }

  ListNode *insertionSortList2(ListNode *head) {
    if (!head or !head->next) {
      return head;
    }
    ListNode dummy(0), *cur = head, *ptr, *prev, *tmp;
    dummy.next = head;
    while (cur->next) {
      prev = &dummy;
      ptr = dummy.next;
      while (ptr != cur->next) {
        if (ptr->val > cur->next->val) {
          break;
        }
        prev = ptr;
        ptr = ptr->next;
      }
      if (ptr != cur->next) {
        prev->next = cur->next;
        tmp = cur->next->next;
        cur->next->next = ptr;
        cur->next = tmp;
      }else {
        cur = cur->next;
      }
    }
    return dummy.next;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(5);
  ListNode* node1 = new ListNode(4);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(2);
  ListNode* node4 = new ListNode(1);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  ListNode* res = s.insertionSortList(head);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

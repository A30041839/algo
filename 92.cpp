#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head) {
      return nullptr;
    }
    return reverseBetween2(head, m, n);
  }

  ListNode *reverseBetween1(ListNode *head, int m, int n) {
    ListNode dummy(0), *prev = &dummy, *begin, *ptr = head, *tmp;
    dummy.next = head;
    int k = 1;
    while (k <= n) {
      if (k > m) {
        tmp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = tmp;
      }else {
        begin = k == m ? prev : begin;
        prev = ptr;
        ptr = ptr->next;
      }
      k++;
    }
    begin->next->next = ptr;
    begin->next = prev;
    return dummy.next;
  }

  ListNode *reverseBetween2(ListNode *head, int m, int n) {
    if (m == n) {
      return head;
    }
    ListNode dummy(0), *ptr = &dummy;
    dummy.next = head;
    //move to m - 1 position
    for (int i = 0; i < m - 1; ++i) {
      ptr = ptr->next;
    }
    ListNode* p = ptr->next;
    for (int i = 0; i < n - m; ++i) {
      ListNode* q = p->next;
      p->next = q->next;
      q->next = ptr->next;
      ptr->next = q;
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
  ListNode* res = s.reverseBetween(head, 2, 3);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

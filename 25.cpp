#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head or k <= 1) {
      return head;
    }else {
      return reverseKGroup1(head, k);
    }
  }

  ListNode *reverseKGroup1(ListNode *head, int k) {
    ListNode dummy(0), *ptr = &dummy, *next;
    dummy.next = head;
    int res;
    while (true) {
      next = ptr->next;
      res = reverseHelper(ptr, k);
      if (res == 0) {
        break;
      }else if (res < k - 1) {
        reverseHelper(ptr, res + 1);
        break;
      }
      ptr = next;
    }
    return dummy.next;
  }

private:
  int reverseHelper(ListNode* head, int k) {
    if (!head->next) {
      return 0;
    }
    ListNode *ptr = head->next, *move;
    int i = 0;
    while (i < k - 1 and ptr->next) {
      move = ptr->next;
      ptr->next = move->next;
      move->next = head->next;
      head->next = move;
      i++;
    }
    return i;
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
  ListNode* res = s.reverseKGroup(head, 3);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

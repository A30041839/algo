#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    return isPalindrome1(head);
  }

  bool isPalindrome1(ListNode* head) {
    ListNode dummy(0), *slow = &dummy, *fast = &dummy;
    dummy.next = head;
    while (fast and fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* mid = slow;
    slow = slow->next;
    //reverse latter part
    while (slow and slow->next) {
      ListNode* tmp = slow->next;
      slow->next = tmp->next;
      tmp->next = mid->next;
      mid->next = tmp;
    }
    mid = mid->next;
    while (mid) {
      if (head->val != mid->val) {
        return false;
      }
      head = head->next;
      mid = mid->next;
    }
    return true;
  }
};

int main() {
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(1);
  ListNode* node4 = new ListNode(1);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  //node3->next = node4;
  if (s.isPalindrome(head)) {
    cout << "yes" << endl;
  }
  return 0;
}

#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    return rotateRight1(head, k);
  }

  ListNode *rotateRight1(ListNode *head, int k) {
    if (!head) {
      return nullptr;
    }
    ListNode* ptr = head;
    int len = 1;
    while (ptr->next) {
      len++;
      ptr = ptr->next;
    }
    k %= len;
    if (!k) {
      return head;
    }
    //connect the tail node with the head node
    ptr->next = head;
    while (len - k > 0) {
      ptr = ptr->next;
      k++;
    }
    head = ptr->next;
    ptr->next = nullptr;
    return head;
  }

  ListNode *rotateRight2(ListNode *head, int k) {
    if (!head) {
      return nullptr;
    }
    ListNode* ptr = head, *tail;
    int len = 0;
    while (ptr) {
      len++;
      tail = ptr;
      ptr = ptr->next;
    }
    k %= len;
    if (!k) {
      return head;
    }
    ptr = head;
    k = len - k;
    while (k > 1) {
      ptr = ptr->next;
      k--;
    }
    auto tmp = head;
    head = ptr->next;
    ptr->next = nullptr;
    tail->next = tmp;
    return head;
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
  ListNode* res = s.rotateRight(head, 2);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

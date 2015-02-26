#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA or !headB){
      return NULL;
    }
    ListNode dummy1(0), dummy2(0), *p1 = &dummy1, *p2 = &dummy2;
    dummy1.next = headA;
    dummy2.next = headB;
    int len1 = 0, len2 = 0;
    while (p1->next or p2->next){
      if (p1->next){
        len1++;
        p1 = p1->next;
      }
      if (p2->next){
        len2++;
        p2 = p2->next;
      }
    }
    p1 = len1 > len2 ? &dummy1 : &dummy2;
    p2 = len1 > len2 ? &dummy2 : &dummy1;
    int diff_len = abs(len1 - len2);
    while (p1->next and p2->next){
      p1 = p1->next;
      if (diff_len > 0){
        diff_len--;
      }else{
        p2 = p2->next;
      }
      if (p1 == p2){
        return p1;
      }
    }
    return NULL;
  }
};

int main(){
  ListNode* head1 = new ListNode(1);
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(5);
  ListNode* node3 = new ListNode(7);
  ListNode* head2 = new ListNode(2);
  head1->next = node1;
  node1->next = node2;
  node2->next = node3;

  Solution s;
  ListNode* res = s.getIntersectionNode(head1, head1);
  if (res != NULL){
    cout << res->val << endl;
  }else{
    cout << "No intersect!" << endl;
  }
  return 0;
}

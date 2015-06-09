#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head or !head->next) {
      return head;
    }
    /*int n = 0;
    ListNode* ptr = head;
    while (ptr) {
      n++;
      ptr = ptr->next;
    }
    return merge_sort(head, 0, n - 1);*/
    return bottom_up_merge_sort(head);
  }

  //average and bad case time complexity is always O(nlogn)
  //recursive function not constant space
  ListNode* merge_sort(ListNode*& cur, int beg, int end){
    if (beg == end) {
      ListNode* ret = cur;
      cur = cur->next;
      ret->next = nullptr;
      return ret;
    }
    int med = (beg + end) / 2;
    ListNode* l = merge_sort(cur, beg, med);
    ListNode* r = merge_sort(cur, med + 1, end);
    return merge(l, r);
  }

  ListNode* merge(ListNode* p1, ListNode* p2){
    ListNode dummy(0), *cur = &dummy;
    while (p1 and p2) {
      ListNode*& pMin = p1->val < p2->val ? p1 : p2;
      cur->next = pMin;
      cur = pMin;
      pMin = pMin->next;
    }
    cur->next = p1 ? p1 : p2;
    return dummy.next;
  }


  //bottom-up merge sort, iterative process, constant space complexity
  ListNode* bottom_up_merge_sort(ListNode* head) {
  }

  //quick sort will cause TLE, O(n^2) bad case complexity
  //the last pointer is the next position of the last element!!
  //recursive function not constant space
  void quick_sort(ListNode* first, ListNode* last){
    if (first == last or first->next == last) {
      return;
    }
    ListNode* pos = partition(first, last);
    quick_sort(first, pos);
    quick_sort(pos->next, last);
  }

  ListNode* partition(ListNode* first, ListNode* last){
    ListNode *p = first, *q = first->next;
    while (q != last) {
      if (q->val < first->val) {
        p = p->next;
        swap(p->val, q->val);
      }
      q = q->next;
    }
    swap(p->val, first->val);
    return p;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(3);
  ListNode* node1 = new ListNode(4);
  ListNode* node2 = new ListNode(1);
  ListNode* node3 = new ListNode(2);
  ListNode* node4 = new ListNode(-1);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  head = s.sortList(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

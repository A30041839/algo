#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head){
      return nullptr;
    }
    ListNode* last = head;
    while (last and last->next){
      last = last->next;
    }
    return merge_sort(head, last);
  }

  ListNode* merge_sort(ListNode* first, ListNode* last){
    if (first == nullptr){
      return nullptr;
    }
    if (first == last){
      first->next = nullptr;
      return first;
    }
    ListNode* mid = findMid(first, last);
    ListNode* tmp = mid->next;
    ListNode* l = merge_sort(first, mid);
    ListNode* r = merge_sort(tmp, last);
    return merge(l, r);
  }

  ListNode* merge(ListNode* p1, ListNode* p2){
    ListNode dummy(0), *cur = &dummy;
    while (p1 and p2){
      ListNode*& pMin = p1->val < p2->val ? p1 : p2;
      cur->next = pMin;
      pMin = pMin->next;
      cur = cur->next;
    }
    cur->next = p1 ? p1 : p2;
    return dummy.next;
  }

  ListNode* findMid(ListNode* first, ListNode* last){
    ListNode *slow = first, *fast = first;
    while (fast != last and fast->next != last){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  void quick_sort(ListNode* first, ListNode* last){
    /*quick sort will cause TLE, O(n2) bad case complexity*/
    if (first != last){
      ListNode* pos = partition(first, last);
      quick_sort(first, pos);
      quick_sort(pos->next, last);
    }
  }

  ListNode* partition(ListNode* first, ListNode* last){
    ListNode *i = first, *j = first->next;
    while (j != last){
      if (j->val <= first->val){
        i = i->next;
        swap(i->val, j->val);
      }
      j = j->next;
    }
    swap(i->val, first->val);
    return i;
  }
};

int main(){
  ListNode* head = new ListNode(3);
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(6);
  ListNode* node3 = new ListNode(2);
  ListNode* node4 = new ListNode(7);
  //head->next = node1;
  //node1->next = node2;
  //node2->next = node3;
  //node3->next = node4;

  Solution s;
  head = s.sortList(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

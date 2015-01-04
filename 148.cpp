#include <iostream>
#include <algorithm>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head or !head->next){
      return head;
    }
    ListNode dummy(0), *first = &dummy, *last = head;
    dummy.next = head;
    while (last->next != NULL){
      last = last->next;
    }
    quick_sort(first, last);
    return dummy.next;
  }

  void quick_sort(ListNode* first, ListNode* last){
    if (first == last or first->next == last){
      return;
    }
    ListNode* pos = partition(first, last);
    quick_sort(first, pos);
    quick_sort(pos->next, last);
  }

  ListNode* partition(ListNode* first, ListNode* last){
    ListNode *i = first, *j = first;
    while (j and j->next and j != last and j->next != last){
      i = i->next;
      j = j->next->next;
    }
    swap(i->val, last->val);
    i = first;
    j = first->next;
    while (j != last){
      if (j->val <= last->val){
        i = i->next;
        swap(i->val, j->val);
      }
      j = j->next;
    }
    swap(i->next->val, last->val);
    return i;
  }
};

int main(){
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  Solution s;
  head = s.sortList(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

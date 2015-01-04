#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (!head){
      return NULL;
    }
    ListNode dummy(0), *p = head, *prev = &dummy;
    dummy.next = head;
    ListNode* last = 0;
    while (p){
      ListNode *max_node = p, *max_prev = prev;
      while (p){
        if (p->val > max_node->val){
          max_node = p;
          max_prev = prev;
        }
        prev = p;
        p = p->next;
      }
      if (!last){
        last = max_node;
      }
      max_prev->next = max_node->next;
      max_node->next = dummy.next;
      p = last->next;
      dummy.next = max_node;
      prev = last;
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
  //head->next = node1;
  //node1->next = node2;
  //node2->next = node3;
  //node3->next = node4;
  ListNode* res = s.insertionSortList(head);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

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
  void reorderList(ListNode *head) {
    if (!head){
      return;
    }
    ListNode* p1 = head, *p2 = head, *prev;
    while (p1->next and p2->next){
      p2 = p1;
      while (p2->next){
        prev = p2;
        p2 = p2->next;
      }
      if (p1->next != p2){
        ListNode* tmp = p1->next;
        p1->next = p2;
        p2->next = tmp;
        p1 = p2 = tmp;
        prev->next = NULL;
      }else{
        p2->next = NULL;
      }
    }
    return;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(5);
  //head->next = node1;
  //node1->next = node2;
  //node2->next = node3;
  //node3->next = node4;
  s.reorderList(head);
  while (head){
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
  return 0;
}

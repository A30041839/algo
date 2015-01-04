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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (head == 0 or m == n){
      return head;
    }
    ListNode dummy(0), *p1 = &dummy, *p2 = &dummy, *start;
    dummy.next = head;
    while (n > 0){
      if (m == 0){
        ListNode* tmp = p2->next;
        cout << tmp->val << endl;
        p2->next = p1;
        p1 = p2;
        p2 = tmp;
      }else{
        m--;
        p1 = p1->next;
        p2 = p2->next;
        if (m == 1){
          start = p1;
        }
      }
      n--;
    }
    start->next->next = p2;
    start->next = p1;
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
  ListNode* res = s.reverseBetween(head, 2, 4);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

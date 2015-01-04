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
  ListNode *rotateRight(ListNode *head, int k) {
    ListNode dummy(0), *p1 = &dummy, *p2 = &dummy;
    dummy.next = head;
    if (head == 0){
      return 0;
    }
    int len = 0;
    while (p1->next){
      len++;
      p1 = p1->next;
    }
    k %= len;
    if (k == 0){
      return head;
    }
    p1 = &dummy;
    while (p2->next){
      p1 = k == 0 ? p1->next : p1;
      k = k > 0 ? k - 1 : 0;
      p2 = p2->next;
    }
    dummy.next = p1->next;
    p2->next = head;
    p1->next = 0;
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
  ListNode* res = s.rotateRight(head, 5);
  while (res){
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

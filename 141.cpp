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
  bool hasCycle(ListNode *head) {
    if (!head){
      return false;
    }
    ListNode* p_fast = head, *p_slow = head;
    while (p_fast and p_fast->next){
      p_fast = p_fast->next->next;
      p_slow = p_slow->next;
      if (p_fast == p_slow){
        return true;
      }
    }
    return false;
  }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(5);
  ListNode* node3 = new ListNode(7);
  ListNode* node4 = new ListNode(2);
  head->next = head;
 // node1->next = node2;
 // node2->next = node3;
 // node3->next = node4;
  //node4->next = node1;
  if (s.hasCycle(head)){
    cout << "has cycle" << endl;
  }else{
    cout << "no cycle" << endl;
  }
  return 0;
}

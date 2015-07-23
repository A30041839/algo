#include "leetcode.h"

using namespace std;

class Solution {
public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* tmp = node->next;
    node->next = tmp->next;
    delete tmp;
  }
};

int main(){
  Solution s;
  return 0;
}

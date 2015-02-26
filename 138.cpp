#include "leetcode.h"

using namespace std;

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    return copyRandomList1(head);
  }

  RandomListNode *copyRandomList1(RandomListNode *head) {
    unordered_map<RandomListNode*, int> mp1;
    unordered_map<int, RandomListNode*> mp2;
    
    RandomListNode dummy(0), *p1 = head, *p2 = &dummy;
    int k = 0;
    while (p1){
      RandomListNode* node_copy = new RandomListNode(p1->label);
      mp1[p1] = k;
      mp2[k] = node_copy;
      p1 = p1->next;
      p2->next = node_copy;
      p2 = node_copy;
      k++;
    }
    p1 = head;
    p2 = dummy.next;
    while (p1){
      p2->random = p1->random ? mp2[mp1[p1->random]] : nullptr;
      p1 = p1->next;
      p2 = p2->next;
    }
    return dummy.next;
  }
};

int main(){
  Solution s;
  RandomListNode* head = new RandomListNode(1);
  RandomListNode* node1 = new RandomListNode(2);
  RandomListNode* node2 = new RandomListNode(3);
  head->next = node1;
  node1->next = node2;
  node1->random = head;
  RandomListNode* cpy = s.copyRandomList(head);
  while (cpy){
    cout << cpy->label << "," << cpy->random << " ";
    cpy = cpy->next;
  }
  cout << endl;
  return 0;
}

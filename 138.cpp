#include "leetcode.h"

using namespace std;

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    return copyRandomList3(head);
  }

  RandomListNode *copyRandomList1(RandomListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode dummy(0), *ptr = head, *cpy = &dummy;
    while (ptr) {
      RandomListNode* cpyNode = new RandomListNode(ptr->label);
      mp[ptr] = cpyNode;
      cpy->next = cpyNode;
      ptr = ptr->next;
      cpy = cpyNode;
    }
    ptr = head;
    while (ptr) {
      if (ptr->random) {
        mp[ptr]->random = mp[ptr->random];
      }
      ptr = ptr->next;
    }
    return dummy.next;
  }

  //one-pass
  RandomListNode *copyRandomList2(RandomListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode dummy(0), *ptr = head, *cpy = &dummy;
    while (ptr) {
      if (mp.find(ptr) == mp.end()) {
        mp[ptr] = new RandomListNode(ptr->label);
      }
      cpy->next = mp[ptr];
      cpy = mp[ptr];
      if (ptr->random) {
        if (mp.find(ptr->random) == mp.end()) {
          mp[ptr->random] = new RandomListNode(ptr->random->label);
        }
        cpy->random = mp[ptr->random];
      }
      ptr = ptr->next;
    }
    return dummy.next;
  }

  //no extra space used
  RandomListNode *copyRandomList3(RandomListNode *head) {
    RandomListNode dummy(0), *ptr = head, *cpy = &dummy;
    //insert nodes
    while (ptr) {
      RandomListNode* new_node = new RandomListNode(ptr->label);
      new_node->next = ptr->next;
      ptr->next = new_node;
      ptr = new_node->next;
    }
    //copy random pointers
    ptr = head;
    while (ptr) {
      if (ptr->random) {
        ptr->next->random = ptr->random->next;
      }
      ptr = ptr->next->next;
    }
    //decouple two linked lists
    ptr = head;
    while (ptr) {
      cpy->next = ptr->next;
      cpy = cpy->next;
      ptr->next = cpy->next;
      ptr = ptr->next;
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

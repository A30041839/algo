#include "leetcode.h"

using namespace std;

class Solution {
public:
  struct cmp{
    bool operator()(const ListNode* node1, const ListNode* node2) const{
      return node1->val > node2->val;
    }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return NULL;
    }
    return mergeKLists2(lists, 0, lists.size() - 1);
  }

  ListNode* mergeKLists1(vector<ListNode*>& lists) {
    priority_queue<ListNode*,  vector<ListNode*>, cmp> p_q;
    ListNode dummy(0), *p = &dummy;
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i] != NULL) {
        p_q.push(lists[i]);
      }
    }
    while (!p_q.empty()) {
      ListNode* top = p_q.top();
      p_q.pop();
      p->next = new ListNode(top->val);
      p = p->next;
      if (top->next) {
        p_q.push(top->next);
      }
    }
    return dummy.next;
  }

  ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0), *cur = &dummy;
    while (l1 and l2) {
      ListNode*& min_ptr = l1->val < l2->val ? l1 : l2;
      cur->next = min_ptr;
      cur = min_ptr;
      min_ptr = min_ptr->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
  }

  ListNode *mergeKLists2(vector<ListNode *> &lists, int low, int high) {
    if (low == high) {
      return lists[low];
    }
    int mid = (low + high) / 2;
    ListNode* l1 = mergeKLists2(lists, low, mid);
    ListNode* l2 = mergeKLists2(lists, mid + 1, high);
    return merge2Lists(l1, l2);
  }
};

int main(){
  Solution s;
  ListNode* l1 = new ListNode(1);
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(5);
  ListNode* l2 = new ListNode(-1);
  ListNode* node3 = new ListNode(6);
  l1->next = node1;
  node1->next = node2;
  l2->next = node3;
  vector<ListNode*> lists;
  lists.push_back(l1);
  lists.push_back(l2);

  ListNode* res = s.mergeKLists(lists);

  while (res) {
    cout << res->val << ",";
    res = res->next;
  }
  cout << endl;
  return 0;
}

#include "leetcode.h"

using namespace std;

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    //return mergeKLists2(lists, 0, lists.size() - 1);
    return mergeKLists1(lists);
  }

  //k is number of lists, m is average list size, then time complexity is:
  //O(log(k)*km)
  ListNode* mergeKLists1(vector<ListNode*>& lists) {
    auto cmp = [](const ListNode * p, const ListNode * q) { return p->val > q->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    ListNode dummy(0), *p = &dummy;
    for (auto ptr : lists) {
      if (ptr) {
        pq.push(ptr);
      }
    }
    while (!pq.empty()) {
      ListNode* curmin = pq.top();
      pq.pop();
      if (curmin->next) {
        pq.push(curmin->next);
      }
      p->next = curmin;
      p = curmin;
    }
    return dummy.next;
  }

  ListNode* merge(ListNode* l1, ListNode* l2) {
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

  //k is number of lists, m is average list size, then time complexity is
  //O(log(k)*km)
  ListNode *mergeKLists2(vector<ListNode *> &lists, int low, int high) {
    if (low == high) {
      return lists[low];
    }
    int mid = (low + high) >> 1;
    ListNode* l1 = mergeKLists2(lists, low, mid);
    ListNode* l2 = mergeKLists2(lists, mid + 1, high);
    return merge(l1, l2);
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

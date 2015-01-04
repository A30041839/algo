#include <iostream>
#include <vector>
#include <limits.h>

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int k = lists.size();
    if (k == 0){
        return NULL;
    }
    if (k == 1){
        return lists[0];
    }
    ListNode dummy(0), *p = &dummy, dummy_max(INT_MAX);
    while (1){
      ListNode* p_min = &dummy_max;
      int pos = -1;
      for (int i = 0; i < lists.size(); ++i){
        if (lists[i] and p_min->val > lists[i]->val){
          p_min = lists[i];
          pos = i;
        }
      }
      if (pos != -1){
        p->next = p_min;
        p = p_min;
        lists[pos] = lists[pos]->next;
      }else{
        break;
      }
    }
    return dummy.next;
  }
};

int main(){
    Solution s;
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(5);
    ListNode* p4 = new ListNode(-1);
    ListNode* p5 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p4->next = p5;
    
    vector<ListNode*> vec;
    vec.push_back(p1);
    vec.push_back(p4);
    ListNode* res = s.mergeKLists(vec);
    while (res){
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
    return 0;
}


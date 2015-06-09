#include "leetcode.h"

using namespace std;

class Solution {
private:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    bool f = false;
    while (fast and fast->next) {
      if (slow == fast and f) {
        return slow;
      }
      fast = f ? fast->next : fast->next->next;
      slow = slow->next;
      if (slow == fast and !f) {
        f = true;
        fast = head;
      }
    }
    return nullptr;
  }

public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA or !headB) {
      return nullptr;
    }else {
      return getIntersectionNode1(headA, headB);
    }
  }

  //convert it to a cycle and then find the intersection
  ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    ListNode* la = headA;
    while (la and la->next) {
      la = la->next;
    }
    la->next = headA;
    ListNode* res = detectCycle(headB);
    //recover the original list structure
    la->next = nullptr;
    return res;
  }

  ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    int len1 = 0, len2 = 0;
    ListNode *l1 = headA, *l2 = headB;
    while (l1 or l2) {
      if (l1) {
        l1 = l1->next;
        len1++;
      }
      if (l2) {
        l2 = l2->next;
        len2++;
      }
    }
    int diff = abs(len1 - len2);
    ListNode* longer = len1 > len2 ? headA : headB;
    ListNode* shorter = longer == headA ? headB : headA;
    while (longer and shorter) {
      if (longer == shorter) {
        return longer;
      }
      if (diff > 0) {
        diff--;
      }else {
        shorter = shorter->next;
      }
      longer = longer->next;
    }
    return nullptr;
  }

  //when pA/pB reaches end, set to headB/headA. the meeting point must be the
  //intersection
  ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
    ListNode* la = headA, *lb = headB, *tailA = nullptr, *tailB = nullptr;
    while (la != lb) {
      if (la->next) {
        la = la->next;
      }else {
        tailA = la;
        la = headB;
        //no cycle
        if (tailB and tailA != tailB) {
          return nullptr;
        }
      }
      if (lb->next) {
        lb = lb->next;
      }else {
        tailB = lb;
        lb = headA;
        if (tailA and tailA != tailB) {
          return nullptr;
        }
      }
    }
    return la;
  }
};

int main() {
  ListNode* head1 = new ListNode(1);
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(5);
  ListNode* node3 = new ListNode(7);
  ListNode* head2 = new ListNode(2);
  head1->next = node1;
  node1->next = node2;
  node2->next = node3;
  head2->next = node1;

  Solution s;
  ListNode* res = s.getIntersectionNode(head1, head2);
  if (res != NULL){
    cout << res->val << endl;
  }else{
    cout << "No intersect!" << endl;
  }
  return 0;
}

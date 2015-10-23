#include "leetcode.h"

class MedianFinder {
private:
  priority_queue<int, vector<int>, less<int>> maxpq;
  priority_queue<int, vector<int>, greater<int>> minpq;

public:
  // Adds a number into the data structure.
  void addNum(int num) {
    maxpq.push(num);
    if (maxpq.size() - minpq.size() == 2) {
      int tmp = maxpq.top();
      maxpq.pop();
      minpq.push(tmp);
    }else if (!minpq.empty() and maxpq.top() > minpq.top()) {
      int tmp = maxpq.top();
      maxpq.pop();
      maxpq.push(minpq.top());
      minpq.pop();
      minpq.push(tmp);
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    return (maxpq.size() + minpq.size()) & 1 ? (double)maxpq.top() : (double)(maxpq.top() + minpq.top()) / 2.0;
  }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

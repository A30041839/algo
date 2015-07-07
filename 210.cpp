#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    return findOrder1(numCourses, prerequisites);
  }

  vector<int> findOrder1(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indgree(numCourses, 0), res;
    queue<int> q;
    for (auto& edge : prerequisites) {
      graph[edge.second].push_back(edge.first);
      indgree[edge.first]++;
    }
    for (int i = 0; i < numCourses; ++i) {
      if (indgree[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      res.push_back(cur);
      q.pop();
      numCourses--;
      for (auto& next : graph[cur]) {
        if (--indgree[next] == 0) {
          q.push(next);
        }
      }
    }
    return numCourses == 0 ? res : vector<int>();
  }
};

int main() {
  return 0;
}

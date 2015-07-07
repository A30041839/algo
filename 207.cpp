#include "leetcode.h"

using namespace std;

class Solution {
private:
  vector<vector<int>> directedGph;
  unordered_map<int, int> visit;

  void buildGph(int n, vector<pair<int, int>>& edges) {
    directedGph.clear();
    visit.clear();
    directedGph.resize(n);
    for (auto& edge : edges) {
      directedGph[edge.second].push_back(edge.first);
      visit[edge.first] = 0;
      visit[edge.second] = 0;
    }
  }

public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    return canFinish2(numCourses, prerequisites);
  }

  bool dfs(int st) {
    if (visit[st] == 1) { //st is on the dfs route, there is a cycle
      return true;
    }
    visit[st] = 1;
    for (auto& i : directedGph[st]) {
      if (visit[i] != -1) {
        if (dfs(i)) {
          return true;
        }
      }
    }
    visit[st] = -1;
    return false;
  }

  bool canFinish1(int numCourses, vector<pair<int, int>>& prerequisites) {
    buildGph(numCourses, prerequisites);
    unordered_map<int, int>::iterator iter = visit.begin();
    while (iter != visit.end()) {
      if (iter->second == 0) {
        if (dfs(iter->first)) {
          return false;
        }
      }
      iter++;
    }
    return true;
  }

  //topological sort
  bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
      indegree[p.first]++;
    }
    buildGph(numCourses, prerequisites);
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      numCourses--;
      for (auto& i : directedGph[cur]) {
        if (--indegree[i] == 0) {
          q.push(i);
        }
      }
    }
    return numCourses == 0;
  }
};

int main(){
  Solution s;
  vector<pair<int, int>> prerequisites;
  prerequisites.push_back({1,0});
  prerequisites.push_back({0,1});
  if (s.canFinish(3, prerequisites)) {
    cout << "can finish" << endl;
  }
  return 0;
}

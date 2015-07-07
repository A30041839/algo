#include "leetcode.h"

using namespace std;

class Solution {
private:
  vector<int> dirx;
  vector<int> diry;
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() or board[0].empty() or words.empty()) {
      return {};
    }else {
      return findWords1(board, words);
    }
  }

  //TLE
  vector<string> findWords1(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    dirx = {0, 1, 0, -1};
    diry = {1, 0, -1, 0};
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (auto& word : words) {
      if (word.empty()) {
        continue;
      }
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (board[i][j] == word[0]) {
            visited[i][j] = true;
            if (dfs1(board, visited, word, m, n, i, j, 1)) {
              res.push_back(word);
            }
            visited[i][j] = false;
          }
        }
      }
    }
    return res;
  }

  bool isValid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
  }

  bool dfs1(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word,
    int m, int n, int curx, int cury, int pos) {
    if (pos == word.size()) {
      return true;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = curx + dirx[i];
      int ny = cury + diry[i];
      if (isValid(nx, ny, m, n) and !visited[nx][ny] and board[nx][ny] == word[pos]) {
        visited[nx][ny] = true;
        if (dfs1(board, visited, word, m, n, nx, ny, pos + 1)) {
          visited[nx][ny] = false;
          return true;
        }
        visited[nx][ny] = false;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<string> words = {"oath","pea","eat","rain"};
  vector<vector<char>> board;
  board.push_back({'o','a','a','n'});
  board.push_back({'e','t','a','e'});
  board.push_back({'i','h','k','r'});
  board.push_back({'i','f','l','v'});
  auto res = s.findWords(board, words);
  for (auto str : res) {
    cout << str << ",";
  }
  cout << endl;
  return 0;
}

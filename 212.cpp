#include "leetcode.h"

using namespace std;

class TrieNode {
public:
  bool terminate;
  TrieNode* next[26];

public:
    // Initialize your data structure here.
  TrieNode() {
    terminate = false;
    memset(next, 0, sizeof(next));
  }
};

class Trie {
public:
  Trie() {
      root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string s) {
    int n = s.size();
    TrieNode* ptr = root;
    for (int i = 0; i < n; ++i) {
      if (!ptr->next[s[i] - 'a']) {
        ptr->next[s[i] - 'a'] = new TrieNode();
      }
      ptr = ptr->next[s[i] - 'a'];
    }
    ptr->terminate = true;
  }

  TrieNode* root;
};

class Solution {
private:
  vector<int> dirx = {1, -1, 0, 0};
  vector<int> diry = {0, 0, 1, -1};
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() or board[0].empty() or words.empty()) {
      return {};
    }else {
      return findWords1(board, words);
    }
  }

  //using trie
  vector<string> findWords1(vector<vector<char>>& board, vector<string>& words) {
    Trie tri;
    for (auto word : words) {
      tri.insert(word);
    }
    vector<string> res;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(board, res, tri.root, "", i, j, m, n);
      }
    }
    return res;
  }

  void dfs(vector<vector<char>>& board, vector<string>& res, TrieNode* node, string str,
    int curx, int cury, int m, int n) {
    char c = board[curx][cury];
    node = node->next[c - 'a'];
    if (!node) {
      return;
    }
    str.push_back(c);
    if (node->terminate) {
      node->terminate = false;
      res.push_back(str);
    }
    board[curx][cury] = '.';
    for (int dir = 0; dir < 4; ++dir) {
      int nx = curx + dirx[dir];
      int ny = cury + diry[dir];
      if (isValid(nx, ny, m, n) and board[nx][ny] != '.') {
        dfs(board, res, node, str, nx, ny, m, n);
      }
    }
    str.pop_back();
    board[curx][cury] = c;
  }

  bool isValid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
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

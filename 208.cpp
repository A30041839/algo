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

  // Returns if the word is in the trie.
  bool search(string key) {
    int n = key.size();
    TrieNode* ptr = root;
    for (int i = 0; i < n; ++i) {
      if (ptr->next[key[i] - 'a']) {
        ptr = ptr->next[key[i] - 'a'];
      }else {
        return false;
      }
    }
    return ptr->terminate;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    int n = prefix.size();
    TrieNode* ptr = root;
    for (int i = 0; i < n; ++i) {
      if (ptr->next[prefix[i] - 'a']) {
        ptr = ptr->next[prefix[i] - 'a'];
      }else {
        return false;
      }
    }
    return true;
  }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
  Trie trie;
  vector<string> vec = {"hello", "good", "hell", "goodday", "love", "lovely"};
  for (auto str : vec) {
    trie.insert(str);
  }
  for (auto str : vec) {
    if (trie.search(str)) {
      cout << "trie has string " << str << endl;
    }
    if (trie.startsWith(str.substr(0, 2))) {
      cout << "trie contains prefix " << str.substr(0, 2) << endl;
    }
  }
  return 0;
}

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

  bool regexSearch(string key) {
    return _regexSearch(root, key, 0);
  }

  bool _regexSearch(TrieNode* ptr, string& key, int pos) {
    if (key.size() == pos) {
      return ptr->terminate;
    }
    if (key[pos] == '.') {
      for (int i = 0; i < 26; ++i) {
        if (ptr->next[i] and _regexSearch(ptr->next[i], key, pos + 1)) {
          return true;
        }
      }
    }else {
      if (ptr->next[key[pos] - 'a']) {
        return _regexSearch(ptr->next[key[pos] - 'a'], key, pos + 1);
      }
    }
    return false;
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

class WordDictionary {
public:
  //constructer
  WordDictionary() {
    m_trie = new Trie();
  }
  // Adds a word into the data structure.
  void addWord(string word) {
    m_trie->insert(word);
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return m_trie->regexSearch(word);
  }

private:
  Trie* m_trie;
};

int main() {
  WordDictionary dic;
  vector<string> words = {"bad", "mad", "dad"};
  vector<string> query = {"pad", "bad", ".ad", "b..", "...", ".",
                          "badd", "b.", "...."};
  for (auto w : words) {
    dic.addWord(w);
  }
  for (auto w : query) {
    if (dic.search(w)) {
      cout << "Word dictionary contains " << w << endl;
    }else {
      cout << "Word dictionary doesn't contain " << w << endl;
    }
  }
  return 0;
}

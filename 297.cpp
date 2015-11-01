class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) {
      return "*";
    }
    return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream iss(data);
    return helper(iss);
  }

  TreeNode* helper(istringstream& iss) {
    if (iss.eof()) {
      return nullptr;
    }
    string cur;
    iss >> cur;
    if (cur == "*") {
      return nullptr;
    }
    TreeNode* new_node = new TreeNode(atoi(cur.c_str()));
    new_node->left = helper(iss);
    new_node->right = helper(iss);
    return new_node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

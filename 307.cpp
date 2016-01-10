struct segTreeNode {
  segTreeNode* left;
  segTreeNode* right;
  int low;
  int high;
  int sum;

  segTreeNode() {
    left = right = nullptr;
  }
};

class NumArray {
  segTreeNode* segTree;
  vector<int> num;
public:
  NumArray(vector<int> &nums) {
    if (nums.empty()) {
      return;
    }
    int n = nums.size();
    segTree = buildTree(nums, 0, n - 1);
    num = nums;
  }

  segTreeNode* buildTree(vector<int>& nums, int l, int h) {
    if (l > h) {
      return nullptr;
    }
    if (l == h) {
      segTreeNode* node = new segTreeNode();
      node->low = node->high = l;
      node->sum = nums[l];
      return node;
    }
    int mid = l + (h - l) / 2;
    segTreeNode* node = new segTreeNode();
    node->low = l;
    node->high = h;
    node->left = buildTree(nums, l, mid);
    node->right = buildTree(nums, mid + 1, h);
    node->sum = node->left->sum + node->right->sum;
    return node;
  }

  void update(int i, int val) {
    _update(segTree, i, val - num[i]);
    num[i] = val;
  }

  int sumRange(int i, int j) {
    return _sumRange(segTree, i, j);
  }

  int _sumRange(segTreeNode* node, int i, int j) {
    if (!node) {
      return 0;
    }
    if (node->low >= i and node->high <= j) {
      return node->sum;
    }
    if (node->low > j or node->high < i) {
      return 0;
    }
    return _sumRange(node->left, i, j) + _sumRange(node->right, i, j);
  }

  void _update(segTreeNode* node, int i, int diff) {
    if (!node) {
      return;
    }
    if (node->low > i or node->high < i) {
      return;
    }
    node->sum += diff;
    _update(node->left, i, diff);
    _update(node->right, i, diff);
  }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

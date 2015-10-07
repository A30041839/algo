#include "leetcode.h"

using namespace std;

//直接对中缀表达式求值，需要判定当前运算符和栈顶运算符的优先级，若当前运算符优先级
//低于栈顶运算符优先级，则从运算符栈和操作数栈分别取出运算符和操作数，把计算结果
//压入运算数栈，否则直接把当前运算符压入运算符栈。
//若对后缀表达式(逆波兰式)求值，过程则简单很多，不需要考虑括号或运算符的优先级，
//读到运算符，直接取出操作数计算结果压栈即可。

//below implements a more general calculator that supports +,-,*,/,(,).
class Solution {
public:
  static vector<vector<char>> precedence;
  static unordered_map<char, int> mp;

  int calculate(string s) {
    return calculate4(s);
  }

private:
  stack<int> operands;
  stack<char> operators;

  struct ExpressionTreeNode {
    char op;
    int val;
    bool isOp;
    ExpressionTreeNode* left;
    ExpressionTreeNode* right;

    explicit ExpressionTreeNode(char op, int val, bool isOp):
      op(op), val(val), isOp(isOp) {}
  };

  int compute(int a, int b, char op) {
    int res = 0;
    switch (op) {
    case '+': res = a + b; break;
    case '-': res = a - b; break;
    case '*': res = a * b; break;
    case '/': res = a / b; break;
    default:break;
    }
    return res;
  }

  void eval() {
    int b = operands.top();
    operands.pop();
    int a = operands.top();
    operands.pop();
    char op = operators.top();
    operators.pop();
    int res = compute(a, b, op);
    operands.push(res);
  }

  char getPrecedence(char op1, char op2) {
    return precedence[mp[op1]][mp[op2]];
  }
  //直接对中缀表达式求值
  int calculate1(string s) {
    s.push_back('#');
    operators.push('#');
    int k = s.size(), res = 0;
    string tmp;
    for (int i = 0; i < k; ++i) {
      //operand
      if (s[i] >= '0' and s[i] <= '9') {
        tmp.push_back(s[i]);
      }else if (mp.find(s[i]) != mp.end()) { //operator
        if (!tmp.empty()) {
          operands.push(atoi(tmp.c_str()));
          tmp.clear();
        }
        char pred = getPrecedence(operators.top(), s[i]);
        switch (pred) {
        //栈顶运算符优先级高
        case '>':
          eval();
          --i;
          break;
        //栈顶运算符优先级低
        case '<':
          operators.push(s[i]);
          break;
        //运算符优先级相同
        case '=':
          //去括号,#结束符号
          operators.pop();
        default: break;
        }
      }
    }
    if (!operands.empty()) {
      res = operands.top();
      operands.pop();
    }
    return res;
  }

  //基本思想类似于中缀表达式求值，只不过遇到操作数直接输出
  string convert2post(string s) {
    string res;
    operators.push('#');
    s.push_back('#');
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        res.push_back(s[i]);
      }else if (mp.find(s[i]) != mp.end()) {
        if (res.back() != ' ') {
          //use space to delimit numbers
          res.push_back(' ');
        }
        char pred = getPrecedence(operators.top(), s[i]);
        switch (pred) {
        case '<': operators.push(s[i]); break;
        case '>': res.push_back(operators.top()); operators.pop(); --i; break;
        case '=': operators.pop(); break;
        default: break;
        }
      }
    }
    return res;
  }

  //先转换成后缀式，再求值
  int calculate2(string s) {
    s = convert2post(s);
    int n = s.size(), res = 0;
    string tmp;
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        tmp.push_back(s[i]);
      }else if (s[i] == ' ') {
        if (!tmp.empty()) {
          operands.push(atoi(tmp.c_str()));
          tmp.clear();
        }
      }else {
        operators.push(s[i]);
        eval();
      }
    }
    if (!operands.empty()) {
      res = operands.top();
      operands.pop();
    }
    return res;
  }

  //build an expression tree from inorder sequence
  ExpressionTreeNode* buildExpressionTree(string s) {
    stack<ExpressionTreeNode*> operators;
    stack<ExpressionTreeNode*> operands;
    operators.push(new ExpressionTreeNode('#', 0, true));
    s.push_back('#');
    int n = s.size();
    string tmp;
    ExpressionTreeNode *res = nullptr, *op_node, *right, *left, *new_operand, *new_operator;
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        tmp.push_back(s[i]);
      }else if (mp.find(s[i]) != mp.end()) {
        if (!tmp.empty()) {
          new_operand = new ExpressionTreeNode(' ', atoi(tmp.c_str()), false);
          operands.push(new_operand);
          tmp.clear();
        }
        char pred = getPrecedence(operators.top()->op, s[i]);
        switch (pred) {
        case '>':
          op_node = operators.top();
          operators.pop();
          right = operands.top();
          operands.pop();
          left = operands.top();
          operands.pop();
          op_node->left = left;
          op_node->right = right;
          operands.push(op_node);
          --i;
          break;
        case '<':
          new_operator = new ExpressionTreeNode(s[i], 0, true);
          operators.push(new_operator);
          break;
        case '=':
          operators.pop();
          break;
        default:
          break;
        }
      }
    }
    if (!operands.empty()) {
      res = operands.top();
      operands.pop();
    }
    return res;
  }

  int _calculateExptree(ExpressionTreeNode* node) {
    if (!node) {
      return 0;
    }
    if (node->isOp) {
      int leftRes = _calculateExptree(node->left);
      int rightRes = _calculateExptree(node->right);
      return compute(leftRes, rightRes, node->op);
    }else {
      return node->val;
    }
  }

  //建立表达式树后求值
  int calculate3(string s) {
    ExpressionTreeNode* expTree = buildExpressionTree(s);
    return _calculateExptree(expTree);
  }

  //只能求解包含+,-算数运算符的表达式
  int calculate4(string s) {
    vector<int> v = {1, 1};
    int res = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        int num = s[i] - '0';
        int j = i + 1;
        while (j < n and isdigit(s[j])) {
          num = num * 10 + s[j] - '0';
          j++;
        }
        i = j - 1;
        res += v.back() * num;
        v.pop_back();
      }else if (s[i] == '+' or s[i] == '(') {
        v.push_back(v.back());
      }else if (s[i] == '-') {
        v.push_back(-1 * v.back());
      }else if (s[i] == ')') {
        v.pop_back();
      }
    }
    return res;
  }
};

vector<vector<char>> Solution::precedence = {
{'>','>','<','<','<','>','>'},
{'>','>','<','<','<','>','>'},
{'>','>','>','>','<','>','>'},
{'>','>','>','>','<','>','>'},
{'<','<','<','<','<','=',' '},
{'>','>','>','>',' ','>','>'},
{'<','<','<','<','<',' ','='}
};

unordered_map<char, int> Solution::mp = {
{'+',0}, {'-',1}, {'*',2}, {'/',3}, {'(',4}, {')',5}, {'#',6}};

int main() {
  Solution s;
  vector<string> exps = {
    "1 + 1",
    " 2-1 + 2 ",
    "(1+(4+5+2)-3)+(6+8)",
    //"(1+2)*(3-5)+2*(3+(4/2))",
    "2147483647"
  };
  for (string exp : exps) {
    cout << s.calculate(exp) << endl;
  }
  return 0;
}

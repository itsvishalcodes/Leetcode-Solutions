class Solution {
public:
  bool isValid(string s) {
    stack<char> bracStack;
    unordered_map<char, char> bracOpp = { { ')','(' }, { '}','{' }, { ']','[' } };
    
    for ( auto ch : s ) {
      if( ch == '(' || ch == '{' || ch == '[' ) {
        bracStack.push(ch);
      }
      else {
        if( bracStack.empty() || ( bracStack.top() != bracOpp[ch] ) ) {
          return false;
        }
        else {
          bracStack.pop();
        }
      }
    }
    if (bracStack.empty())
      return true;
    return false;
  }
};
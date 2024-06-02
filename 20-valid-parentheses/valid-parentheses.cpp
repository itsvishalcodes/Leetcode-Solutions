class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    map<char, char> correspondingOpen = {
      { '}', '{' },
      { ')', '(' },
      { ']', '[' },
    };
    for(auto c:s) {
      if(c == '{' || c == '(' || c=='[') {
        st.push(c);
      } 
      else {
        if(st.size() == 0) {
          return false;
        }
        
        if(st.top() != correspondingOpen[c]) {
          return false;
        } else {
          st.pop();
        }
      }
    }

    if(st.size() == 0) return true;
    return false;
  }
};
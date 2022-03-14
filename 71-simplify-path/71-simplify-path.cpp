class Solution {
public:
  string simplifyPath(string path) {
    path += "/";
    
    vector<string> st;
    string soln = "";
    
    for(int i=0; i<path.size(); i++) {
      if(path[i] == '.') {
        // if((i+1) < path.size() and path[i+1] == '.') {
        //   if(st.size()) st.pop_back();
        // }
        string dotString = "";
        while(i<path.size() and path[i]!='/') {
          dotString += path[i];
          i++;
        }
        cout<<"Dot String - "<<dotString<<endl;
        if(dotString.compare(".") == 0) {
          continue;
        }
        else if(dotString.compare("..") == 0) {
          if(st.size()) {
            st.pop_back();
          }
        }
        else {
          st.push_back(dotString);
        }
        // i--;
      }
      else if(path[i] == '/') {
        continue;
      }
      else {
        string s = "";
        while(path[i] != '/') {
          s += path[i];
          i++;
        }
        st.push_back(s);
      }
    }
    
    cout<<"Size - "<<st.size();
    
    if(!st.size()) return "/";
    for(auto i:st) {
      soln += ("/" + i);
    }
    return soln;
  }
};
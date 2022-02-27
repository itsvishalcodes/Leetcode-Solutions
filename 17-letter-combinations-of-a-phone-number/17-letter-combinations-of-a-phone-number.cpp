class Solution {
public:
  unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
  };
  
  vector<string> soln;
  
  void util(string prevStr, int i, string& queryStr, int& n) {
     // Base Case
    if(i==n) {
      if(prevStr.size())
        soln.push_back(prevStr);
      return;
    }
    
    // Recursive Case
    string letters = mp[queryStr[i]];
    for(int j=0; j<letters.size(); j++) {
      util(prevStr+letters[j], i+1, queryStr, n);
      
    }
  }
  
  vector<string> letterCombinations(string digits) {
    int n = digits.size();
    util("", 0, digits, n);
    
    return soln;
  }
};
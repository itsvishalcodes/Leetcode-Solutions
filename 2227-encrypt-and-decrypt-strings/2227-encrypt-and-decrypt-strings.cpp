class Encrypter {
public:
  unordered_map<char, string> encDict;
  unordered_map<string, int> decDict;
  // unordered_set<string> isPresent;
  
//   void dfs(string& s, int idx, int& soln, string curr) {
//     if(idx >= s.size()) {
//       if(isPresent.find(curr) != isPresent.end()) soln++;  
//       return;
//     }
//     // cout<<s[idx]<<s[idx+1]<<endl;
//     string toCheck = "";
//     toCheck += s[idx];
//     toCheck += s[idx+1];
//     vector<char> temp = decDict[toCheck];
    
//     for(int i=0; i<temp.size(); i++) {
//       if(i>0) curr.pop_back();
//       curr+=temp[i];
//       dfs(s, idx+2, soln, curr);
//     }
//   }
  
  Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
    for(int i=0; i<keys.size(); i++) {
      encDict[keys[i]] = values[i];
      // decDict[values[i]].push_back(keys[i]);
    }
    for(auto i:dictionary) {
      // isPresent.insert(i);
      string tmp = encrypt(i);
      // cout<<tmp<<endl;
      if(tmp.size())
        decDict[tmp]++;
    }
    
    // debug
    for(auto i:decDict) {
      cout<<i.first<<endl;
    }
  }

  string encrypt(string word1) {
    string encrypted = "";
    for(auto i:word1) {
      if(encDict[i]=="") return "";
      encrypted += encDict[i];
    }
    return encrypted;
  }

  int decrypt(string word2) {
    // vector<string> possDec;
    // int soln = 0;
    // dfs(word2, 0, soln, "");
    
    return decDict[word2];
  }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
class Solution {
public:
  int countOnes(vector<int> v) {
    int c = 0, i=0;
    while(i<v.size() and v[i] == 1) {
      c++; i++;
    }
    return c;
  }
  
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    vector<pair<int, int>> preComp(n);
    vector<int> soln(k);
    
    for(int i=0; i<n; i++) {
      preComp[i] = {countOnes(mat[i]), i};
    }
    
    sort(preComp.begin(), preComp.end());
    
    for(int i=0; i<k; i++) {
      soln[i] = preComp[i].second;
    }
    
    return soln;
  }
};
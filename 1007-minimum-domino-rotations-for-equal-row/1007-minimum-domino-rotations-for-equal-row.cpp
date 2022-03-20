class Solution {
public:
  // bool isAllEqual(int e, vector<int>& v) {
  //   for(int i=1; i<v.size(); i++) if(v[i] != e) return false;
  //   return true;
  // }
  
  
  
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    vector<int> countA(7), countB(7), same(7);
    int n = A.size();
    for (int i = 0; i < n; ++i) {
      countA[A[i]]++;
      countB[B[i]]++;
      if (A[i] == B[i])
        same[A[i]]++;
    }
    for (int i  = 1; i < 7; ++i)
      if (countA[i] + countB[i] - same[i] == n)
        return n - max(countA[i], countB[i]);
    return -1;
  }
};
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int start = 0, end = arr.size()-1;
    int totalIt = arr.size()-k;
    vector<int> soln;
    
    while(totalIt--) {
      if(abs(x-arr[start]) <= abs(x-arr[end])) {
        end--;
      }
      else {
        start++;
      }
    }
    
    for(int i=start; i<=end; i++) {
      soln.push_back(arr[i]);
    }
    
    return soln;
  }
};
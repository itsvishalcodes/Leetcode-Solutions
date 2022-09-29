class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> diff(arr.size()), soln;
    deque<int> solndeque;
    int start, end, nearest=INT_MAX, zeroLoc = -1;
    for(int i=0; i<arr.size(); i++) {
      diff[i] = arr[i]-x;
      if(diff[i] == 0) zeroLoc = i;
    }
    
    for(int i=0; i<diff.size(); i++) {
      if(min(nearest, abs(0-diff[i])) < nearest){
        zeroLoc = i;
        nearest = abs(0 - diff[i]);
      }
      
    }
    
    k = k-1;
    solndeque.push_back(arr[zeroLoc]);
    start = zeroLoc-1;
    end = zeroLoc+1;
    while(k>0) {
      if(start >=0 and end < arr.size()) {
        if(abs(diff[start]) <= abs(diff[end])) {
          solndeque.push_front(arr[start]);
          start--;
        }
        else {
          solndeque.push_back(arr[end]);
          end++;
        }
      }
      else if(start >= 0) {
        solndeque.push_front(arr[start]);
        start--;
      }
      else {
        solndeque.push_back(arr[end]);
        end++;
      }
      k--;
    }
    
    for(auto i:solndeque) {
      soln.push_back(i);
    }
    
    return soln;
  }
};
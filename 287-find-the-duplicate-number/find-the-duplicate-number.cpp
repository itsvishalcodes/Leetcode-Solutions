class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int low=0, high=nums.size()-1, mid;
    sort(nums.begin(), nums.end());

    while(low <= high) {
      mid = (low + high)/2;
      cout<<mid<<endl;
      if(low == high) return nums[mid];
      if(nums[mid] < mid+1) {
        high = mid-1;
        cout<<"New High "<<high<<endl;
      } else {
        low = mid+1;
        cout<<"New Low "<<low<<endl;
      }
    }
    return nums[low];
  }
};
class Solution {
public:
  int search(vector<int>& nums, int target) {
    // Corner case handling
    if(nums.size() == 1) {
      return nums[0] == target ? 0 : -1;
    }

    // Find the pivot element
    int rightMost = nums[nums.size()-1];
    int left = 0, right = nums.size()-1, mid = 0, pivot = -1;
    if(nums[0] > rightMost) {
      while(left <= right) {
        mid = (left + right)/2;
        if(mid == nums.size()-1) break;
        if(nums[mid+1] < nums[mid]) {
          pivot = mid;
          break;
        } else if(nums[mid] > rightMost) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      left = 0; right = nums.size()-1;
      if(pivot > -1) {
        if (target == nums[pivot]) return pivot;
        else if(target <= nums[pivot] && target <= rightMost) left = pivot+1;
        else right = pivot;
      }
    }

    cout<<pivot<<endl<<left<<endl<<right;

    // Find the element
    while(left <= right) {
      mid = (left + right)/2;
      if (nums[mid] == target) return mid;
      else if (nums[mid] < target) left = mid+1;
      else right = mid-1;
    }

    return -1;
  }
};
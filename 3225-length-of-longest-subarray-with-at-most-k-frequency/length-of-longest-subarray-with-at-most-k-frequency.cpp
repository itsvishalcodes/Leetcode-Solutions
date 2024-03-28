class Solution {
public:
  int maxSubarrayLength(vector<int>& nums, int k) {
    int largest = 0, left = 0, right = 0;
    unordered_map<int, int> freq;

    while(right < nums.size()) {
      freq[nums[right]]++;
      while(freq[nums[right]] > k) {
        freq[nums[left]]--;
        left++;
      }
      largest = max(largest, right-left+1);
      right++;
    }

    return largest;
  }
};
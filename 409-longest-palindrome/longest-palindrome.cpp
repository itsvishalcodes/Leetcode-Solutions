class Solution {
public:
  int longestPalindrome(string s) {
    map<int, int> freq;
    int ans = 0;
    bool hasOdd = false;

    for(auto i:s) {
      freq[i-'a']++;
    }

    for(auto i:freq) {
      int val = i.second;
      if(val%2) {
        hasOdd = true;
        ans += val-1;
      } else {
        ans += val;
      }
    }

    if(hasOdd) {
      ans++;
    }

    return ans;
  }
};
class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    int ans = 0;
    for(int i=0; i<tasks.size(); i++) {
      freq[tasks[i]-'A']++;
    }
    int mx = *max_element(freq.begin(), freq.end());
    int i = count(freq.begin(), freq.end(), mx);

    return max((int)tasks.size(), ((mx-1)*(n+1)+i));
  }
};
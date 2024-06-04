class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int boughtAt = prices[0];
    int maxProfit = 0;

    for(int i=1; i<prices.size(); i++) {
      if(boughtAt > prices[i]) {
        boughtAt = prices[i];
      } else {
        maxProfit = max(maxProfit, prices[i]-boughtAt);
      }
    }

    return maxProfit;
  }
};
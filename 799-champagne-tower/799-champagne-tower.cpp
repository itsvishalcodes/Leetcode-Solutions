class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> fractionFilled(100, vector<double>(100, 0.0));
    fractionFilled[0][0] = (double)poured;
    
    double flow;    
    for(int i=0; i< query_row; i++) {
      for(int it=0; it <= i; it++) {
        flow = (fractionFilled[i][it] - 1.0) / 2.0;
        if(flow > 0) {
          fractionFilled[i+1][it] += flow;
          fractionFilled[i+1][it+1] += flow;
        }
      }
    }
    
    
    return min(1.0, fractionFilled[query_row][query_glass]);    
    
  }
};
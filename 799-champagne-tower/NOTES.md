Instead of thinking about how will the glasses fill, think of it like how much champagne was poured through that glass. Like for the glass in first row and first col, the champagne poured would be max, but that glass would only be able to afford 1, so the rest, that is (A[0][0] -1), would be divided in 2 parts and be added to the below two glasses.
Keep doing it until the query row.
​
```
class Solution {
public:
double champagneTower(int poured, int query_row, int query_glass) {
vector<vector<double>> fractionFilled(100, vector<double>(100, 0.0));
fractionFilled[0][0] = (double)poured;
double flow;
for(int i=0; i< query_row; i++) {
for(int it=0; it <= i; it++) {
flow = (fractionFilled[i][it] - 1.0) / 2.0;
fractionFilled[i][it] = 1;
if(flow > 0) {
fractionFilled[i+1][it] += flow;
fractionFilled[i+1][it+1] += flow;
}
}
}
return min(1.0, fractionFilled[query_row][query_glass]);
}
};
```
​
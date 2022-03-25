class Solution {
public:
  double calc(double x, int n) {
    if(n==0) return 1;
    if(n==1) return x;
    if(n==2) return x*x;
    
    double soln = calc(calc(x, n/2), 2);
    if(n%2) return soln*x;
    return soln;
  }
  
  double myPow(double x, int n) {    
    if(n == 0) return 1;
    
    if(n>0) return calc(x, n);
    return 1/calc(x, abs(n));
  }
};
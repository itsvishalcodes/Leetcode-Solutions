class Solution {
public:
  int brokenCalc(int startValue, int target) {
    int ops = 0;
    while(startValue < target) {
      if(target%2)
        target++;
      else
        target = target/2;
      ops++;
    }
    
    return ops + (startValue-target);
  }
};
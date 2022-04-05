class Solution {
public:
  int maxArea(vector<int>& height) {
    int mxWater = INT_MIN;
    int leftPtr=0, rightPtr=height.size()-1;
    
    while(leftPtr < rightPtr) {
      mxWater = max(mxWater, min(height[leftPtr], height[rightPtr])*(rightPtr-leftPtr));
      if(height[leftPtr] <= height[rightPtr]) leftPtr++;
      else rightPtr--;
    }
    
    return mxWater;
  }
};
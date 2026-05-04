class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int leftPtr = 0, rightPtr = height.length -1;
        
        while(leftPtr < rightPtr) {
            maxArea = Math.max(
                maxArea, 
                (rightPtr - leftPtr)*Math.min(
                    height[leftPtr], height[rightPtr]
            ));
            if(height[leftPtr] <= height[rightPtr]) leftPtr++;
            else rightPtr--;
        }

        return maxArea;
    }
}

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

/*
 * @lc app=leetcode id=239 lang=java
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int leftPtr = 0, rightPtr = k-1;
        int[] ans = new int[nums.length - k + 1];
        Map<Integer, Integer> freqCount = new HashMap<>();
        Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        // in a loop, 3 conditions, 2 main conditions
        // if currElem (rightPtr) == mxElem, increase freq count,
        // if elem leaving (leftPtr) == mxElem, decrease freq count,
        // if after decrease, freqcount becomes 0, get next max elem
        // from the window (priority queue?)
        // if currElem (rightPtr) > mxElem, assignmxElem, put freq count 1
        
        // Initial Calculation
        for(int i=leftPtr; i<=rightPtr; i++) {
            pq.add(nums[i]);
            if (!freqCount.containsKey(nums[i])) {
                freqCount.put(nums[i], 0);
            }
            freqCount.put(nums[i], freqCount.get(nums[i]) + 1);
        }

        while(rightPtr < nums.length) {
            while(pq.peek() != null && freqCount.getOrDefault(pq.peek(), 0) == 0) {
                pq.remove();
            }
            Integer maxElemInWindow = pq.peek();
            ans[leftPtr] = maxElemInWindow == null ? 0 : maxElemInWindow;
            freqCount.put(nums[leftPtr], freqCount.get(nums[leftPtr]) - 1);
            leftPtr++; rightPtr++;
            if (rightPtr == nums.length) break;
            if (!freqCount.containsKey(nums[rightPtr])) {
                freqCount.put(nums[rightPtr], 0);
            }
            pq.add(nums[rightPtr]);
            freqCount.put(nums[rightPtr], freqCount.get(nums[rightPtr]) + 1);
        }

        return ans;
    }
}
// @lc code=end


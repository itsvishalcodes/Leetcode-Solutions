class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numToIdx = new HashMap<Integer, Integer>();
        numToIdx.put(nums[0], 0);

        for (int i=1; i<nums.length; i++) {
            int neededNum = target - nums[i];
            if (numToIdx.containsKey(neededNum)) {
                return new int[] { numToIdx.get(neededNum), i };
            }
            numToIdx.put(nums[i], i);
        }

        return new int[] { -1, -1 };
    }
}
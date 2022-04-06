class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long MOD = pow(10, 9) + 7;
        long long ans = 0;
        unordered_map<int, int> counter1, counter2; // Counters for single number and pair sum.
        for (int val : arr) {
            // If there are previous paired sums equal to "target - val", those previous pairs and "val" sum to "target".
            ans = (ans + counter2[target - val]) % MOD;
            for (auto v_c : counter1) {
                // All single numbers have seen can be used with "val" to form a paired sum.
                counter2[v_c.first + val] += v_c.second;
            }
            counter1[val]++;
        }
        return ans;
    }
};
// https://leetcode.com/problems/majority-element/
#define sz(x) ((int)x.size())

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
private:
    int random(int l, int r) {
        return uniform_int_distribution<int>(l, r)(rng);
    }

public:
    int majorityElement(vector<int>& nums) {
        int T = 20;
        while (T--) {
            int idx = random(0, nums.size() - 1), cnt = 0;
            for (int i = 0; i < sz(nums); i++)
                cnt += nums[i] == nums[idx];
            
            if (cnt > sz(nums) / 2) return nums[idx];
        }

        return 0;
    }
};
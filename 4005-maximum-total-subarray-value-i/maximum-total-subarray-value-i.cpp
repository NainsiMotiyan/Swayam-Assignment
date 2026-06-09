class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int maxi = nums[0];
        int mini = nums[0];

        for(int num : nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        return 1LL * (maxi - mini) * k;
    }
};
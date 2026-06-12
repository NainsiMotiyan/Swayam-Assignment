class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        int prefixsum=0;
        for(int num:nums){
            prefixsum+=num;
            if(mp.find(prefixsum-k)!=mp.end()){
                cnt+=mp[prefixsum-k];
            }
            mp[prefixsum]++;

        }
        return cnt;

    }
};
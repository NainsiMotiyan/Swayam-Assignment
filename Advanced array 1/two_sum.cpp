#include <iostream>
#include <vector>
using namespace std;

// Return indices of two numbers adding up to target
vector<int> twoSum(vector<int>& nums, int target){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target) return {i,j};
        }
    }
    return {};
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    for(int i: res) cout << i << " "; // Output: 0 1
}

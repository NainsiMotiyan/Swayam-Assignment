#include <iostream>
#include <vector>
using namespace std;

// Calculate total trapped rain water
int trap(vector<int>& height){
    int n=height.size(), left=0, right=n-1;
    int leftMax=0, rightMax=0, res=0;
    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>=leftMax) leftMax=height[left];
            else res+=leftMax-height[left];
            left++;
        } else {
            if(height[right]>=rightMax) rightMax=height[right];
            else res+=rightMax-height[right];
            right--;
        }
    }
    return res;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height); // Output: 6
}

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to find Next Greater Element for each element in array
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> result(nums.size(), -1); // Initialize result with -1
    stack<int> st; // Stack to store indices

    for (int i = 0; i < nums.size(); i++) {
        // Pop elements smaller than current number and update result
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i); // Push current index
    }

    return result;
}

// Main function
int main() {
    vector<int> nums = {4, 5, 2, 25};

    vector<int> nge = nextGreaterElement(nums);

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " -> " << nge[i] << endl;

    return 0;
}

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;

        for (int num : arr1) {
            string s = to_string(num);
            string temp = "";

            for (char c : s) {
                temp += c;
                prefixes.insert(temp);
            }
        }

        int ans = 0;

        for (int num : arr2) {
            string s = to_string(num);
            string temp = "";

            for (char c : s) {
                temp += c;

                if (prefixes.count(temp)) {
                    ans = max(ans, (int)temp.size());
                }
            }
        }

        return ans;
    }
};
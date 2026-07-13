class Solution {
public:
    int maxDistinct(string s) {

        if (s.empty())
            return 0;

        unordered_set<char> seen;

        int ans = 1;
        seen.insert(s[0]);

        for (int i = 1; i < s.size(); i++) {

            if (seen.find(s[i]) == seen.end()) {
                ans++;
                seen.insert(s[i]);
            }
        }

        return ans;
    }
};
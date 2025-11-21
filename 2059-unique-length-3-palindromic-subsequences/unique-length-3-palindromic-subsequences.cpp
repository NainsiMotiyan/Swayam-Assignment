class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Record first and last occurrences
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }

        int ans = 0;

        // For each character 'a' to 'z'
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue; // not present
            if (first[c] == last[c]) continue; // occurs only once

            unordered_set<char> mid;

            // Collect unique characters in between
            for (int j = first[c] + 1; j < last[c]; j++) {
                mid.insert(s[j]);
            }

            ans += mid.size();
        }

        return ans;
    }
};

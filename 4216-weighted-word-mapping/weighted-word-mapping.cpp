class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result ="";
        for (string &word:words){
            int sum=0;
            for(char c: word){
                sum+=weights[c-'a'];
            }
            int mod =sum% 26;
            char mappedchar='z'-mod;
            result.push_back(mappedchar);
        }
        return result;
    }
};
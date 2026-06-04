class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for(int i = num1; i <= num2; i++){
            string s = to_string(i);
            if(s.size() < 3) continue;
            for(int i = 1; i < s.size() - 1; i++){
                int a = s[i-1] + '0';
                int b = s[i] + '0';
                int c = s[i+1] + '0';
                if(b > a && b > c) cnt++;
                else if(b < a && b < c) cnt++;
            }
        }
        return cnt;
    }
};
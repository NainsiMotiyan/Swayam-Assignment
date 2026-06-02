class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int minLandFinish = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish = min(minLandFinish,
                                landStartTime[i] + landDuration[i]);
        }

        int minWaterFinish = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            minWaterFinish = min(minWaterFinish,
                                 waterStartTime[j] + waterDuration[j]);
        }

        int ans = INT_MAX;

        // Land ride first, then water ride
        for (int j = 0; j < waterStartTime.size(); j++) {
            ans = min(ans,
                      max(minLandFinish, waterStartTime[j]) +
                      waterDuration[j]);
        }

        // Water ride first, then land ride
        for (int i = 0; i < landStartTime.size(); i++) {
            ans = min(ans,
                      max(minWaterFinish, landStartTime[i]) +
                      landDuration[i]);
        }

        return ans;
    }
};
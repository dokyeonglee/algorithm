class Solution {
public:
    int earliestFinishTime(vector<int>& land_start_time, vector<int>& land_duration, vector<int>& water_start_time, vector<int>& water_duration) {
        int answer = INT_MAX;

        int land_min_end_time = INT_MAX;
        for (int i = 0; i < land_start_time.size(); ++i) {
            land_min_end_time = min(land_min_end_time, land_start_time[i] + land_duration[i]);
        }
        for (int i = 0; i < water_start_time.size(); ++i) {
            answer = min(answer, max(land_min_end_time, water_start_time[i]) + water_duration[i]);
        }

        int water_min_end_time = INT_MAX;
        for (int i = 0; i < water_start_time.size(); ++i) {
            water_min_end_time = min(water_min_end_time, water_start_time[i] + water_duration[i]);
        }
        for (int i = 0; i < land_start_time.size(); ++i) {
            answer = min(answer, max(water_min_end_time, land_start_time[i]) + land_duration[i]);
        }

        return answer;
    }
};
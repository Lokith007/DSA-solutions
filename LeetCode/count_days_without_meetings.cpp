// Count Days Without Meetings [Medium]
// https://leetcode.com/problems/count-days-without-meetings/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int current_day=0;
        sort(meetings.begin(),meetings.end());
        for(const auto& m:meetings){
            int i=m[0],j=m[1];
            if(j<=current_day){
                continue;
            }else if(i>current_day){
                days-=j-i+1;
            }else{
                days-=j-current_day;
            }
            current_day=j;
        }
        return days;
    }
};
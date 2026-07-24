// Count Days Without Meetings [Medium]
// https://leetcode.com/problems/count-days-without-meetings/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int curr_day=0;
        sort(meetings.begin(),meetings.end());
        for(auto &m:meetings){
            int i=m[0],j=m[1];
            if(j<=curr_day){
                continue;
            }else if(i>curr_day){
                days-=j-i+1;
            }else{
                days-=j-curr_day;
            }
            curr_day=j;
        }
        return days;
    }
};

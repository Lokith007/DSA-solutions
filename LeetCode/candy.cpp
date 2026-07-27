// Candy [Hard]
// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& rating) {
        int n=size(rating);
            int candies=n;
            int i=1;
            while(i<n){
                if(rating[i]==rating[i-1]){
                    i++;
                    continue;
                }
                int peak=0;
                while(i<n && rating[i]>rating[i-1]){
                    peak++;
                    candies+=peak;
                    i++;
                }
                int down=0;
                while(i<n && rating[i]<rating[i-1]){
                    down++;
                    candies+=down;
                    i++;
                }
                candies-=min(peak,down);
            }
        return candies;
    }
};
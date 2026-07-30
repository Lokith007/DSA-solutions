// Minimum Number of Pushes to Type Word I [Easy]
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/

class Solution {
public:
    int minimumPushes(string word) {
        int n=size(word);
        cout<<n-8;;
        if(n<=8){
            return n;
        }
        if(n<=16){
            return 8+((n-8)*2);
        }
        if(n<=24){
            return 24+((n-16)*3);
        }
        return 48+((n-24)*4);
    }
};
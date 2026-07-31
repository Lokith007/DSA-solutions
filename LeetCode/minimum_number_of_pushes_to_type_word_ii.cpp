// Minimum Number of Pushes to Type Word II [Medium]
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<size(word);i++){
            mp[word[i]]++;
        }
        vector<pair<int, int>> vec(mp.begin(),mp.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;   
        });
        int n=size(vec);
        int total=0;
        for(int i=0;i<n;i++){
            total+=(vec[i].second)*(i/8+1);
        }
        return total;
    }
};
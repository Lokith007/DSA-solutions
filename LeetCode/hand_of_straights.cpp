// Hand of Straights [Medium]
// https://leetcode.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        map<int,int> freq;
        for(int x : hand)
            freq[x]++;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            if(it->second == 0)
                continue;
            int start = it->first;
            int count = it->second;
            for(int i = 0; i < groupSize; i++) {
                if(freq[start + i] < count)
                    return false;
                freq[start + i] -= count;
            }
        }
        return true;
    }
};
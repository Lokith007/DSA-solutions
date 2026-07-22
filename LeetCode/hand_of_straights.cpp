// Hand of Straights [Medium]
// https://leetcode.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=size(hand);
        if(n%groupSize!=0){
            return false;
        }
        map<int,int>cards;
        for(int h:hand){
            cards[h]++;
        }
    for(auto ch=cards.begin();ch!=cards.end();ch++){
        if(ch->second>0){
            int count=ch->second;
            for(int i=0;i<groupSize;i++){
                if(cards[ch->first+i]<count){
                    return false;
                }
                cards[ch->first+i]-=count;
            }
        }
    }
    return true;
    }
};
// Count the Number of Special Characters II [Medium]
// https://leetcode.com/problems/count-the-number-of-special-characters-ii/

class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int>l(26,0);
        vector<int>h(26,0);
        vector<bool>vis(26,true);
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                if(l[s[i]-'A']==0){
                    vis[s[i]-'A']=false;
                }
                else{
                    h[s[i]-'A']++;
                }
            }
            else{
                if(h[s[i]-'a']>0){
                    vis[s[i]-'a']=false;
                }
                l[s[i]-'a']++;
            }
        }

        int count=0;
        for(int i=0;i<26;i++){
            if(!vis[i])
            continue;
            if(l[i]&&h[i])
            count++;
        }
        return count;
    }
};
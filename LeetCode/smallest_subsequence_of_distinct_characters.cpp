// Smallest Subsequence of Distinct Characters [Medium]
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> vis(26, false);
        for(int i=0;i<s.size();i++)
            last[s[i]-'a']=i;
        string ans="";
        for(int i=0;i<s.size();i++) {
            char c=s[i];
            if(vis[c-'a'])
                continue;
            while(!ans.empty()&&ans.back()>c&&last[ans.back()-'a']>i) {
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans+=c;
            vis[c-'a'] = true;
        }
        return ans;
    }
};
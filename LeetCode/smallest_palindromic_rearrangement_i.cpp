// Smallest Palindromic Rearrangement I [Medium]
// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/

class Solution {
public:
    string smallestPalindrome(string s) {
        int n=size(s);
        int j=0;
        int freq[26]{};
        for(int i=0;i<n>>1;i++){
            freq[(s[i]&31)-1]++;
        }
        for(int i=0;i<26;i++){
            while(freq[i]--){
                s[j]='a'+i;
                s[n-1-j++]='a'+i;
            }
        }
        return s;
    }
};
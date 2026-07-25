// Maximum Product of Two Digits [Easy]
// https://leetcode.com/problems/maximum-product-of-two-digits/

class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits;
        while(n>0){
            digits.push_back(n%10);
            n/=10;
        }
        sort(digits.begin(),digits.end());
        int s=size(digits);
        return digits[s-1]*digits[s-2];
    }
};
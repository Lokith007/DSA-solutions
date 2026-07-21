// Find K Closest Elements [Medium]
// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == 1) {
            return {arr[0]};
        }
        int l=0,r=size(arr)-1;
        while(r-l+1>k){
            if(abs(arr[l]-x)>abs(arr[r]-x)){
                l++;
            }else{
                r--;
            }
        }
        return vector<int>(arr.begin()+l,arr.begin()+r+1);
        //return ans;
    }
};
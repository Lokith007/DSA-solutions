// Find K Closest Elements [Medium]
// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0,right=size(arr)-1;
        while(right-left>=k){
            (abs(arr[left]-x)>abs(arr[right]-x))?left++:right--;
        }
        return vector<int>(arr.begin()+left,arr.begin()+right+1);
    }
};
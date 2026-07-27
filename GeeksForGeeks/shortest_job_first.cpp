// Shortest Job First [Medium]
// https://www.geeksforgeeks.org/problems/shortest-job-first/

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int n=bt.size();
        int sum=0;
        vector<int>vec(n);
        vec[0]=0;
        for(int i=1;i<n;i++){
            sum+=bt[i-1];
            vec[i]=sum;
        }
        int total=accumulate(vec.begin(),vec.end(),0);
        return total/n;
    }
};


 
// Second Largest [Medium]
// https://www.geeksforgeeks.org/problems/second-largest/

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = -1;
        int secondLargest = -1;
        for (int x : arr) {
            if (x > largest) {
                secondLargest = largest;
                largest = x;
            }
            else if (x < largest && x > secondLargest) {
                secondLargest = x;
            }
        }
        return secondLargest;
    }
};
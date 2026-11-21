/*
we are given an array containing only 0 's and 1 's.
the array is sorted in descending order.
that means all the 1 's come first, followed by all the 0 's.

Our task is to Count how many zeros are present.
there are two approaches:
1. Linear Traversal - we visit every element and count how many are zeros.
   i) initialize count = 0
   ii) traverse the array
   iii) if arr[i] == 0, increment count
   iv) return count
this approach takes O(n) time

2. Binary Search (optimal) - here's where the sorrted property help us. Since all zeros are at the end, we only need to find the position of the first zero.
so, our formula is:
      Zero Count = n-firstZeroIndex
  if no zero exists, the answer is 0.

How does Binary Search work here?
we mainatin three variables:
 i) low = 0
 high = n-1
 ans = n(initially assume there are no zeros)
then:
i) calculates middle index: mid = low + (high-low)/2.
ii) if arr[mid] == 0, we found a zero.Store its index and search further left.
iii) if arr[mid] == 1, serach towards the right.
why bcz, we need the FIRST xero, not just any zero.

Complexity:
1. Linear traversal :- O(n)-time and O(1)- auxiliary space
2. Binary search :- O(logn)-time and O(1)-auxiliary space
binry search is optimal here bcz, the arary is already sorted.
*/

//Code:
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countZeroes(vector<int>&arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high) {
            int mid =low+(high-low) / 2;
            if (arr[mid] == 0) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        return n-ans;
    }
};

int main() {
    vector<int> arr = {1,1,1,1,1,0,0,0};
    Solution obj;
    int result = obj.countZeroes(arr);
    cout << "Number of zeros: " << result;
    return 0;
}
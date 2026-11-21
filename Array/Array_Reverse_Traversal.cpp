/*
We are given an array and its size n.
and we need to print the elements from the last index to the first index.

normally, we traverse an array from left to right:
for(int i = 0; i < n; i++)
but here we need to traverse from right to left

here we need to change:
1. start from n-1(last index)
2. continue while i >= 0
3. decrese i using i--

then our loops becomes:
for (iht i =n; i >= 0; i--)

Time complexity: o(n)
Auxiliary space complexity: o(1)
*/

// Code:
#include <iostream>
using namespace std;
class solution {
public:
    void arrayTraversalReverse(int arr[], int n) {
        for (int i = n-1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    int arr[] = {54, 43, 2, 1, 5};
    int n = 5;
    solution obj;
    obj.arrayTraversalReverse(arr, n);
    return 0;
}
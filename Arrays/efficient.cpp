#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        // 2 variables :
        // max_ending_here keeps track of net previous positive segments if -ve it gets zero
        // max_till_now is maximum till now
        long long max_till_now = -1e9, max_ending_here = 0;
        int start = -1, end = -1;
        for (int i = 0; i < n; i++)
        {
            max_ending_here += arr[i];
            if (max_ending_here > max_till_now)
            {
                max_till_now = max_ending_here;
                end = i;
            }

            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                start = i;
            }
        }
        return max_till_now;
    }
};

int main()
{
    int arr[] = {74, -72, 94, -53, -59, -3, -66, 36, -13, 22, 73, 15, -52, 75};
    int V = 14;
    Solution obj;
    cout << obj.maxSubarraySum(arr, V);
}
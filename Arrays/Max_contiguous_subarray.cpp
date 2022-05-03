#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution(int arr[], int n)
    {

        vector<int> res = max_conti_sub_arr(arr, 0, n);
        cout << res[0] << " " << res[1] << " " << res[2] << endl;
    }

    vector<int> max_conti_sub_arr(int arr[], int s, int e)
    {
        vector<int> v = {s,e,0};
        if (s == e)
            return v;

        vector<int> left = max_conti_sub_arr(arr, s, (e + s - 1) / 2);

        vector<int> right = max_conti_sub_arr(arr, (e + s - 1) / 2 + 1, e);

        vector<int> cross = max_cross_arr(arr, s, e, (e + s - 1) / 2);

        if (left[2] > right[2] && left[2] > cross[2])
            return left;
        else if (right[2] > left[2] && right[2] > cross[2])
            return right;
        else
            return cross;
    }

    vector<int> max_cross_arr(int arr[], int s, int e, int m)
    {
        int max_right = 0;
        int sum = 0;
        int r = m;
        for (int i = m; i >= 0; i--)
        {
            sum += arr[i];
            if (sum > max_right)
            {
                r = i;
                max_right = sum;
            }
        }

        int max_left = 0;
        int sum1 = 0;
        int l = m;
        for (int i = m + 1; i < e; i++)
        {
            sum1 += arr[i];
            if (sum1 > max_left)
            {
                l = i;
                max_left = sum1;
            }
        }

        vector<int> v = {r, l, sum + sum1};
        return v;
    }
};
int main()
{
    int arr[] = {7, -1, 5, -3, -6, 4};
    Solution obj(arr, 6);

    return 0;
}
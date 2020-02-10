#include<bits/stdc++.h>
using namespace std;

int max_subarray_sum(int arr[] , int n)
{
    if(n == 1) return arr[0];
    int m = n / 2;
    int left_mss = max_subarray_sum(arr,m);
    int right_mss = max_subarray_sum(arr+m , n - m);
    int l_sum = INT_MIN,r_sum = INT_MIN, sum = 0 , ans;
    for (int i = m; i < n; i++)
    {
        sum += arr[i];
        r_sum = max(r_sum,sum);
    }
    sum = 0;
    for (int i = m-1; i >= 0; i--)
    {
        sum += arr[i];
        l_sum = max(l_sum,sum);
    }
    ans = max(left_mss,right_mss);
    return max(ans,l_sum+r_sum);
}

int main()
{
    int i,n;
    cin >> n;
    int arr[n+2];
    for( i = 0; i < n; i++) cin >> arr[i];
    cout << max_subarray_sum(arr , n) << endl;
    return 0;
}
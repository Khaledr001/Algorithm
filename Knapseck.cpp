#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
vector<int> arr;

int knapseck(vector<int> &price, vector<int> &wt, int w, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (wt[n - 1] <= w)
    {
        int a = price[n - 1] + knapseck(price, wt, w - wt[n - 1], n - 1);
        int b = knapseck(price, wt, w, n - 1);
        // if(a > b)
        //     arr.push_back(price[n-1]);
        return dp[n][w] = max(a,b );
    }
    else
        return dp[n][w] = knapseck(price, wt, w, n - 1);
}

int main()
{
    int i, n, w;

    cin >> w >> n;
    vector<int> wt(n);
    vector<int> value(n);
    memset(dp, -1, sizeof(dp));

    for (i = 0; i < n; i++)
        cin >> wt[i];
    for (i = 0; i < n; i++)
        cin >> value[i];
    int res = knapseck(value, wt, w, n);
    cout << res << endl;
    // for(i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    for(i = n; i > 0 && res > 0; i--) {
        if(res == dp[i-1][w]) {
            continue;
        }
        else {
            arr.push_back(value[i-1]);
            res = res - value[i-1];
            w = w - wt[i-1];
        }
    }

    for(i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
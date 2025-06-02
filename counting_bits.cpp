#include<bits/stdc++.h>
#define ll long long
using namespace std;

// can't store against all, use map
map<ll, ll> dp;

ll fun(ll num)
{
    if(num  == 0) return 0;
    if(num  == 1) return 1;

    if(dp[num]) return dp[num];

    if(num&1)
    {
        return dp[num] = 2*fun(num/2) + num/2 + 1;
    }
    else{
        return dp[num] = fun(num/2) + num/2 + fun(num/2 - 1);
    }
}

int main()
{
    ll n;
    cin >> n;

    // 0001
    // 0010
    // 0011
    // 0100
    // 0101
    // 0110
    // 0111

    // 1000

    // for n = 7, [1, n/2] add a 1 -> [n/2+2, n]
    // f(n) = 2 x f(n/2) + n/2 + 1 

    // for n = 6
    // 0001 
    // 0010
    // 0011
    // 0100 -> 4 + 0
    // 0101 -> 4 + 1
    // 0110 -> 4 + 2

    // [n/2+1, n] depends on [1, n/2 - 1]

    // f(n) = f(n/2 - 1) + f(n/2) + n/2
    cout << fun(n) << endl;
    return 0;
}
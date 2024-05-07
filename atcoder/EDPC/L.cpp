#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N;
long long A[3010];
bool flag[3010][3010][2];
long long dp[3010][3010][2];
long long sm[3010];

// sum[l, r]
long long s(int l, int r){
    return sm[r+1] - sm[l];
}

// 0-indexed
// 0: max, 1: min
long long f(int l, int r, int mode){
    if (l == r){
        return A[l];
    }
    if (flag[l][r][mode]){
        return dp[l][r][mode];
    }
    flag[l][r][mode] = true;
    long long vl, vr;
    
    vl = A[l] + s(l+1, r) - f(l+1, r, (mode+1)%2);
    vr = A[r] + s(l, r-1) - f(l, r-1, (mode+1)%2);
    // cout << l << ", " << r << ", " << vl << ", " << vr << endl;

    return dp[l][r][mode] = std::max(vl, vr);
}

int main()
{
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    sm[0] = 0;
    for (int i=0; i<N; i++){
        sm[i+1] = sm[i] + A[i];
    }

    long long ans;
    ans = 2 * f(0, N-1, 0) - s(0, N-1);
    cout << ans << endl;

    return 0;
}
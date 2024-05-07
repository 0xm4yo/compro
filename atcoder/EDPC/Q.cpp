#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N;
int H[200200], A[200200];
long long dp[200200];

class SegTree{
    public:
    long long node[1000000];
    int size;

    void init(int N){
        size = 1;
        while (size <= N) size *= 2;
        for (int i=0; i<size*2; i++) node[i] = 0;
    }

    void update(int pos, long long x){
        pos += size;
        node[pos] = x;
        while (pos >= 2){
            pos /= 2;
            node[pos] = max(node[pos*2], node[pos*2+1]);
        }
    }

    long long query(int l, int r, int a, int b, int n){
        if (r <= a || b <= l) return 0;
        if (l <= a && b <= r) return node[n];
        int mid = (a + b) / 2;
        long long vl = query(l, r, a, mid, n*2);
        long long vr = query(l, r, mid, b, n*2+1);
        return max(vl, vr);
    }
};

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) cin >> H[i];
    for (int i=0; i<N; i++) cin >> A[i];

    SegTree sg;
    sg.init(N+1);

    for (int i=0; i<N; i++){
        dp[i] = sg.query(0, H[i]+1, 0, sg.size, 1) + A[i];
        sg.update(H[i], dp[i]);
    }

    long long ans = 0;
    for (int i=0; i<N; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
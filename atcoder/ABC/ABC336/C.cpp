#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define smod(n, m) ((((n) % (m)) + (m)) % (m)) // 非負mod
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double PI = 3.141592653589793;
const vector<int> DX = { 1, 0, -1, 0 };
const vector<int> DY = { 0, 1, 0, -1 };
const long long INF = (ll)1e18+10;


/*
    桁の数を n 進数で取得
    n を b 進数で表記したときの各桁の数字を上位桁から順に並べたリストを返す
*/
vector<int> integer_digits(long long n, int b = 10){
	assert(abs(b) >= 2);
	// n = 0
	if (n == 0) return vector<int>{0};

	// mod |b| をとって最下位桁から順に決定
	vector<int> res;
	while (n != 0) {
		int d = smod(n, abs(b));
		res.push_back(d);
		n /= b;
	}

	// 上位桁から順になるように並べ直す
	reverse(all(res));
	return res;
}

int main()
{
    ll n;
    cin>>n;
    auto arr = integer_digits(n-1, 5);
    for (auto a: arr){
        cout << a*2;
    }
    cout << endl;

    // cout << fixed << setprecision(18);
    return 0;
}
////////////////////////////////////////////////
//                                            //
//  Author: Muhammad Faishol Amirul Mukminin  //
//                                            //
////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef pair<ll,ll> pl;
typedef pair<pl,ll> pll;
typedef pair<double,double> pd;
typedef pair<pd,double> pdd;

#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define FORN(i,x,y) for(int i=(x);i<=(y);i++)
#define REV(i,a,b) for(int i=(a);i>(b);i--)
#define REVN(i,a,b) for(int i=(a);i>=(b);i--)
#define BTW(i,a,b) a <= i && i <= b

#define DB(x) cerr << #x << ": " << x << endl;

#define fi first
#define se second
#define PUB push_back
#define POB pop_back
#define PUF push_front
#define POF pop_front
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"

const double EPS = 1e-9;
const double PI = acos(-1);
const ll MOD = 1e9+7;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFFLL;
const ull UINF = 0xFFFFFFFFFFFFFFFFLL;
const int dCol[] = {0,+1,0,-1,+1,+1,-1,-1};
const int dRow[] = {-1,0,+1,0,-1,+1,+1,-1};

template <typename T>
inline void VIN(vector<T> &i){ T x; cin >> x; i.PUB(x); }
inline void FIO(string i){ freopen((i+".in").c_str(), "r", stdin); freopen((i+".out").c_str(), "w", stdout);}

int N, K;
int kartu[100005], fav[100005];
ll score[15], ans = 0, dp[2][5005];

ll solve(int card, int p){
	memset(dp, 0, sizeof dp);
	ll ret = 0;
	int now, bef;

	FORN(i,1,p){
		now = i&1;
		bef = now^1;

		FORN(j, 1, card){
			dp[now][j] = dp[now][j-1];

			FORN(l, 0, min(j, K))
				dp[now][j] = max(dp[now][j], score[l] + dp[bef][j-l]);
		}
	}
	
	FORN(i,0,card){
		ret = max(dp[now][i], ret);
	}
	
	return ret;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	FOR(i,0,N*K){
		int x;
		cin >> x;
		kartu[x]++;
	}
	FOR(i,0,N){
		int x;
		cin >> x;
		fav[x]++;
	}
	FORN(i,1,K) cin >> score[i];

	FOR(i,1,100005){
		if(fav[i] > 0 && kartu[i] > 0){
			ans += solve(kartu[i], fav[i]);
		}
	}

	cout << ans << endl;
	return 0;
}
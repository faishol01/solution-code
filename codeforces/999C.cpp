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

int N, K, frek[27];
char S[400005];
bool cetak[400005];

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(cetak, 1, sizeof cetak);

	cin >> N >> K;
	FOR(i,0,N){
		cin >> S[i];
		frek[S[i]-'a']++;
	}

	FOR(i,0,26){
		char src = 'a'+i;
		int byk = frek[i];
		if(byk >= K){
			byk = K;
			K = 0;
		}else{
			K -= byk;
		}

		FOR(j,0,N){
			if(byk == 0) break;
			if(S[j] == src) cetak[j] = 0, byk--;
		}

		if(K == 0) break;
	} 

	FOR(i,0,N){
		if(cetak[i]) cout << S[i];
	}
	cout << endl;
	return 0;
}
// BEGIN CUT HERE

// END CUT HERE
#line 5 "OrderOfOperations.cpp"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <cassert>
#include <cmath>
#include <string>
#define vi vector<int>
#define LL long long
#define vll vector<LL>
#define PB push_back
#define SWAP(a,b) a^=b,b^=a,a^=b
#define REP(i,n)  for(__typeof(n) i = 0; i < n; i++)
#define REP1(i,n)  for(__typeof(n) i = 1; i <= n; i++)
#define REP2(i,n) for(__typeof(n) i = 1; i < n; i++)
#define REPc(i,j,n)  for(__typeof(n) i = j; i <= n; i++)
#define last_bit(n) (n&(-n))
#define F first
#define S second
#define mod 1000000007ll
#define INF 1<<29
#define smax(a,b) a = max(a, b)
#define smin(a,b) a = min(a, b)
#define MAXM 21
#define MAXN 51

using namespace std;

template <typename T> T gcd(T a, T b) { return b==0?a: gcd(a%b, b); }
template <typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
template <typename T> T expo(T b, T e, const T &m) {if(e <= 1) return e==0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m; }

class OrderOfOperations {
public:
	vi arr;
	vector<string> s;
	int n, m, dp[1<<MAXM] = {0};
	int conversion(string s)
	{
		int size = int(s.size());
		int res = 0, cnt = 0;
		for(int i = size-1; i > -1; i--){
			if(s[i] == '1'){
				res += 1<<cnt;  
			}
			cnt++;
		}
		return res;
	}
	int minTime(vector <string> s) {
		this->s = s;
		n = int(s.size()), m = int(s[0].size());
		int target = 0;
		REP(i,n){
			arr.PB(conversion(s[i]));  
			target = target | arr[i];
		}
		REP(i,1<<MAXM)	dp[i] = INF;
		dp[0] = 0;
		REP(i,1<<m){
			REP(j,n){
				int x = arr[j], g = i|x, temp = __builtin_popcount(g^i);
				smin(dp[g], dp[i] + temp*temp);
			}
		}
		return dp[target];
	}
};

// BEGIN CUT HERE

// END CUT HERE
#line 5 "PaintTheRoom.cpp"
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

using namespace std;

template <typename T> T gcd(T a, T b) { return b==0?a: gcd(a%b, b); }
template <typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
template <typename T> T expo(T b, T e, const T &m) {if(e <= 1) return e==0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m; }

class PaintTheRoom {
public:
	string canPaintEvenly(int R, int C, int K) {
		if(K == 1){
			return "Paint";  
		}
		if(R % 2 == 0 || C % 2 == 0){
			return "Paint";  
		}
		return "Cannot paint";
	}
};

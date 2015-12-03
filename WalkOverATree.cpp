// BEGIN CUT HERE

// END CUT HERE
#line 5 "WalkOverATree.cpp"
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
#define MAXL 102
#define MAXN 50

using namespace std;

template <typename T> T gcd(T a, T b) { return b==0?a: gcd(a%b, b); }
template <typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
template <typename T> T expo(T b, T e, const T &m) {if(e <= 1) return e==0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m; }

class WalkOverATree {
public:
	vi adj[MAXN];
	int L, n, dp[MAXN][MAXL] = { {0} }, subtree[MAXN] = {0};
	void init(int root = 0, int prev = -1)
	{
		int size = int(adj[root].size());
		subtree[root] = 1;
		REP(i,size){
			if(adj[root][i] == prev)	continue;  
			init(adj[root][i], root);
			subtree[root] += subtree[adj[root][i]];
		}
	}
	void DFS(int root = 0, int prev = -1)
	{
		int size = int(adj[root].size());
		REPc(j,0,L){
			dp[root][j] = 1;  
		}
		REP(i,size){
			int child = adj[root][i];
			if(child == prev){
				continue;
			}
			DFS(child, root);
			REP1(l,L){
				REPc(x,0,l-1){
					dp[root][l] = max(dp[root][l], 1 + dp[child][x] + min((l-x-1)/2, subtree[root]-subtree[child]-1));
				}
			}
		}
	}
	int maxNodesVisited(vector <int> parent, int L) {
		this->L = L;
		n = int(parent.size())+1;
		REP(i,n-1){
			adj[parent[i]].PB(i+1), adj[i+1].PB(parent[i]);
		}
		init();
		DFS();
		return dp[0][L];
	}
};

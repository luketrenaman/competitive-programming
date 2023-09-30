#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define dbg(x...)
#endif

const int N = 3e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];
void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}
int dist(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - (dep[l] << 1);
}
//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
  int l = lca(u, v);
  int d = dep[u] + dep[v] - (dep[l] << 1);
  assert(k <= d);
  if (dep[l] + k <= dep[u]) return kth(u, k);
  k -= dep[u] - dep[l];
  return kth(v, dep[v] - dep[l] - k);
}

int main() {
	std::ifstream in("in.txt");
    //std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
  //ios::sync_with_stdio(0);
  int n; cin >> n;
  vector<int> roots;
  for (int i = 1; i <= n; i++) {
    int par; cin >> par;
    if (par == 0) {
      roots.push_back(i);
    } else {
      g[par].push_back(i);
      g[i].push_back(par);
    }
  }
  for (int root : roots) {
    dfs(root);
  }
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int m; cin >> m;
    set<pair<int,int>> qry;
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      assert(x != 0);
      qry.insert(make_pair(dep[x],x));
    }
    int ans = 0;
    while (!qry.empty()) {
      int cur = (*qry.begin()).second;
      qry.erase(qry.begin());
      vector<int> to_erase;
      for (pair<int,int> tb : qry) {
		  i = tb.second;
        int lc = lca(i, cur);
        if (lc == i) {
          cur = i;
        }
        if (lc == cur) {
          to_erase.push_back(i);
        }
      }
      for (int i : to_erase) {
        qry.erase(make_pair(dep[i],i));
      }
      dbg(cur);
      ans += sz[cur];
    }
    cout << ans << '\n';
  }
}

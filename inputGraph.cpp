#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  // =========================================
  // 1. ADJACENCY MATRIX
  // Space: O(N^2)
  // =========================================

  // A. Undirected, Unweighted
  vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

  /*
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    mat[u][v] = 1;
    mat[v][u] = 1;
  }
  */

  // B. Directed, Unweighted
  /*
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    mat[u][v] = 1;
  }
  */

  // C. Undirected, Weighted
  /*
  for(int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    mat[u][v] = w;
    mat[v][u] = w;
  }
  */

  // D. Directed, Weighted
  /*
  for(int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    mat[u][v] = w;
  }
  */

  // =========================================
  // 2. ADJACENCY LIST
  // Space: O(N + E)
  // =========================================

  // A. Undirected, Unweighted
  vector<vector<int>> adj(n + 1);

  /*
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  */

  // B. Directed, Unweighted
  /*
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
  }
  */

  // C. Undirected, Weighted
  // {adjacent_vertex, weight}
  vector<vector<pair<int, ll>>> adjW(n + 1);

  /*
  for(int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    adjW[u].push_back({v, w});
    adjW[v].push_back({u, w});
  }
  */

  // D. Directed, Weighted
  /*
  for(int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    adjW[u].push_back({v, w});
  }
  */

  // =========================================
  // 3. WEIGHTED ADJACENCY LIST TRAVERSAL
  // =========================================

  /*
  int u = 1;

  for(auto [v, w] : adjW[u]) {
    // v = adjacent vertex
    // w = edge weight
  }
  */

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const char nl = '\n';

int main() {
  vector<ll> req = {1, 1, 1};
  int m = req.size();

  vector<vector<ll>> blocks = {{0, 1, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
  int n = blocks.size();
  
  vector<vector<ll>> dist(n, vector<ll>(m));
  
  for (ll i = 0; i < m; i += 1) {
    if (blocks[0][i] == 0) dist[0][i] = INT32_MAX;
    else dist[0][i] = 0;
  }
  
  for (ll i = 1; i < n; i += 1) {
    for (ll j = 0; j < m; j += 1) {
      if (blocks[i][j] == 1) dist[i][j] = 0;
      else dist[i][j] = dist[i - 1][j] + 1;
    }
  }
  
  for (ll i = n - 2; i >= 0; i -= 1) {
    for (ll j = 0; j < m; j += 1) {
      if (blocks[i][j] != 1) dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
    }
  }
  
  // for (ll i = 0; i < n; i += 1) {
  //   for (ll j = 0; j < m; j += 1) {
  //     cout << dist[i][j] << ' ';
  //   }
  //   cout << nl;
  // }
  
  ll mnWalk = INT32_MAX;
  ll minIdx;
  
  for (ll i = 0; i < n; i += 1) {
    ll walkD = *max_element(dist[i].begin(), dist[i].end());
    if (walkD < mnWalk) {
      mnWalk = walkD;
      minIdx = i;
    }
  }
  
  cout << minIdx << nl;
  
  return 0;
}

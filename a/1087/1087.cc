#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct edge {
  int n, c;
};
int N, K;
string iton[200];
int h[200], d[200], v[200];
vector<edge> e[200];
int E, D;
vi ans;
int sol, tot;
double avr;
unordered_map<string, int> ntoi;
void spfa() {
  memset(d, 0x3f, sizeof(d));
  queue<int> Q;
  Q.push(0), v[0] = true, d[0] = 0;
  while(!Q.empty()) {
    int x = Q.front(); Q.pop();
    for(auto &y : e[x]) {
      int dy = d[x] + y.c;
      if(dy < d[y.n]) {
        d[y.n] = dy;
        if(!v[y.n]) Q.push(y.n), v[y.n] = true;
      }
    }
    v[x] = false;
  }
}
void dfs(int s, int cost, int dep, int hap, vi &path) {
  if(cost > D) return;
  if(s == E && cost == D) {
    sol++;
    if(hap > tot || (hap == tot && (1.0 * hap / dep) > avr)) tot = hap, avr = 1.0 * hap / dep, ans = path;
    return;
  }
  else {
    for(auto &y : e[s]) {
      if(v[y.n]) continue;
      int dy = cost + y.c;
      path.push_back(y.n), v[y.n] = true;
      dfs(y.n, dy, dep + 1, hap + h[y.n], path);
      path.pop_back(), v[y.n] = false;
    }
  }
}
int main(int argc, const char *argv[])
{
  ios::sync_with_stdio(false);
  cin >> N >> K >> iton[0];
  ntoi[iton[0]] = 0;
  for(int i=1; i<N; i++) cin >> iton[i] >> h[i], ntoi[iton[i]] = i;
  while(K--) {
    string c1, c2;
    int x;
    cin >> c1 >> c2 >> x;
    e[ntoi[c1]].push_back(edge{ntoi[c2], x});
    e[ntoi[c2]].push_back(edge{ntoi[c1], x});
  }
  spfa();
  E = ntoi["ROM"], D = d[E];
  memset(v, 0, sizeof(v));
  v[0] = true;
  vi p;
  dfs(0, 0, 0, 0, p);
  cout << sol << ' ' << D << ' ' << tot << ' ' << (int)avr << endl;
  cout << iton[0];
  for(int i : ans) cout << "->" << iton[i];
  cout << endl;
  return 0;
}

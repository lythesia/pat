#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, K;
unordered_map<string, int> to_i;
unordered_map<int, string> to_s;
int f[2000], w[2000];
struct edge {
  int x, y, d;
};
edge e[1000];
int fnd(int x) {
  if(f[x] != x) return f[x] = fnd(f[x]);
  else return f[x];
}
void mrg(int x, int y) {
  int fx = fnd(x), fy = fnd(y);
  if(fx != fy) {
    if(w[fx] < w[fy]) f[fx] = fy;
    else f[fy] = fx;
  }
}
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &K);
  K <<= 1;
  char n1[4] = {0}, n2[4] = {0};
  int d, x, y, n = 0;
  for(int i=0; i<N; i++) {
    scanf("%s %s %d", n1, n2, &d);
    string s1(n1), s2(n2);
    if(to_i.count(s1)) x = to_i[s1];
    else x = n++, to_i[s1] = x, to_s[x] = s1;
    if(to_i.count(s2)) y = to_i[s2];
    else y = n++, to_i[s2] = y, to_s[y] = s2;
    w[x] += d, w[y] += d;
    e[i] = edge{x, y, d};
  }
  for(int i=0; i<n; i++) f[i] = i;
  for(int i=0; i<N; i++) mrg(e[i].x, e[i].y);
  unordered_map<int, int> sum, cnt;
  map<string, int> ans;
  for(int i=0; i<n; i++) {
    int fi = fnd(i);
    cnt[fi]++, sum[fi] += w[i];
    // if(sum[fi] > K && cnt[fi] > 2) ans<name, count>.insert(make_pair(to_s[fi], cnt[fi])); <- note this is WRONG! since at this point cnt[fi] is not correct, fuck me ...
    if(sum[fi] > K && cnt[fi] > 2) ans.insert(make_pair(to_s[fi], fi));
  }
  printf("%zu\n", ans.size());
  for(auto &p : ans) printf("%s %d\n", p.first.c_str(), cnt[p.second]);
  return 0;
}

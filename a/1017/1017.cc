#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;

const int START = 8 * 3600;
const int END = 17 * 3600;
int N, K;
pii c[10001];
int ans[10001];
priority_queue<pii, vector<pii>, greater<pii>> Q;

int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &K);
  for(int i=0; i<N; i++) {
    int h, m, s, p;
    scanf("%d:%d:%d%d", &h, &m, &s, &p), c[i] = {h*3600 + m*60 + s, p*60};
  }
  sort(c, c + N);
  int cnt = 0;
  for(int i=0; i<K; i++) Q.emplace(pii{START, i});
  for(int i=0; i<N; i++) {
    if(c[i].first > END) break; // come late, but not in queue late
    pii t = Q.top(); Q.pop();
    int serv = max(t.first, c[i].first);
    ans[i] = c[i].first < t.first ? t.first - c[i].first : 0, cnt++;
    Q.emplace(pii{serv + c[i].second, t.second});
  }
  printf("%.1lf\n", accumulate(ans, ans + cnt, 0) / 60.0 / cnt);
  return 0;
}

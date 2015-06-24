#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef multimap<int, int> pq;

const int START = 8 * 3600, END = 21 * 3600;
struct per {
  int arrv = 0, serv = 0, p = 0, w = -1, v = 0; // w = -1: wait time unset
};
int N, K, M;
per p[10001];
pq tab;
int tabc[101];
bool tabv[101];
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    int hh, mm, ss;
    scanf("%d:%d:%d %d%d", &hh, &mm, &ss, &p[i].p, &p[i].v);
    p[i].arrv = hh * 3600 + mm * 60 + ss, p[i].p = min(p[i].p, 120) * 60;
  }
  scanf("%d%d", &K, &M);
  for(int i=0; i<M; i++) {
    int t;
    scanf("%d", &t);
    tabv[t] = true;
  }
  int s = 0;
  sort(p, p + N, [](const per &x, const per &y){return x.arrv < y.arrv;});
  for(int i=1; i<=K; i++) tab.insert(pii{START, i});
  while(!tab.empty()) {
    // next_table is a set of tables that has min serv time
    // if set has vip table and (vip already in queue || vip not in queue but is next to serv)
    // else fetch first table and process for the next to serv
    int sv = (*tab.begin()).first;
    auto nextp = tab.equal_range(sv);
    auto tp = find_if(nextp.first, nextp.second, [](const pii &t){return tabv[t.second];}); // next vip table
    per *it = find_if(p + s, p + N, [](const per &pp){return pp.w == -1 && pp.v;}); // find next vip
    if(!(tp != nextp.second && it != p + N && (sv >= it->arrv || it == p + s))) {
      tp = nextp.first;
      it = find_if(p + s, p + N, [](const per &pp){return pp.w == -1;});
    }
    if(it == p + N) break;
    if(!it->v) s = it - p, s++;
    if(sv >= it->arrv) it->serv = sv, it->w = (int)round((sv - it->arrv) / 60.0);
    else it->serv = it->arrv, it->w = 0;
    tab.erase(tp); tab.insert(pii{it->serv + it->p, tp->second});
    if(it->serv < END) tabc[tp->second]++;
  }
  sort(p, p + N, [](const per &x, const per &y){return x.serv < y.serv;});
  for(int i=0; i<N; i++) {
    per &pp = p[i];
    if(pp.serv >= END) break;
    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
        pp.arrv / 3600, (pp.arrv - pp.arrv / 3600 * 3600) / 60, pp.arrv % 60,
        pp.serv / 3600, (pp.serv - pp.serv / 3600 * 3600) / 60, pp.serv % 60,
        pp.w);
  }
  for(int i=1; i<K; i++) printf("%d ", tabc[i]);
  printf("%d\n", tabc[K]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, K;
struct park {
  char n[8];
  int t;
  bool out, v;
};
park p[10000]; 
int ttoi(int hh, int mm, int ss) { return hh*3600 + mm*60 + ss; }
bool by_id(const park &x, const park &y) {
  int ss = strcmp(x.n, y.n);
  return ss ? ss < 0 : x.t < y.t;
}
bool by_time(const park &x, const park &y) {
  return x.t < y.t;
}
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &K);
  char s[4];
  int hh, mm, ss;
  for(int i=0; i<N; i++) {
    scanf("%s %d:%d:%d %s", p[i].n, &hh, &mm, &ss, s);
    p[i].t = ttoi(hh, mm, ss), p[i].out = strcmp(s, "in") != 0;
  }
  // largest park
  sort(p, p + N, by_id);
  map<string, int> maxp;
  for(int i=0; i<N-1;) {
    if(!strcmp(p[i].n, p[i+1].n) && (!p[i].out && p[i+1].out)) {
        p[i].v = p[i+1].v = true;
        maxp[string(p[i].n)] += (p[i+1].t - p[i].t);
        i += 2;
    }
    else i++;
  }
  // query
  sort(p, p + N, by_time);
  int ans = 0, last = 0;
  while(K--) {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int q = ttoi(hh, mm, ss);
    for(; last<N; last++) {
      if(p[last].t <= q) {
        if(p[last].v) p[last].out ? ans-- : ans++;
      }
      else break;
    }
    printf("%d\n", ans);
  }
  int mmax = 0;
  for(auto &p : maxp) mmax = max(mmax, p.second);
  for(auto &p : maxp) if(p.second == mmax) printf("%s ", p.first.c_str());
  printf("%02d:%02d:%02d\n", mmax / 3600, (mmax - mmax / 3600 * 3600) / 60, mmax % 60);
  return 0;
}

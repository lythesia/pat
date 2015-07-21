#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int Np, NG;
int m[1000], r[1000], p[1000][2];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &Np, &NG);
  for(int i=0; i<Np; i++) scanf("%d", &m[i]);
  for(int i=0; i<Np; i++) scanf("%d", &p[i][0]);
  int tot = Np, cnt = 0, ip = 0;
  while(true) {
    int mmax = 0, ind = 0, to_next = (tot + NG - 1) / NG;
    for(int i=0; i<tot; i++) {
      if(m[p[i][ip]] > mmax) ind = p[i][ip], mmax = m[ind];
      if(!((i+1) % NG) || i==tot-1) p[cnt++][1-ip] = ind, r[ind]--, mmax = 0;
    }
    for(int i=0; i<Np; i++) {
      if(!r[i]) r[i] = to_next + 1;
      else if(r[i] < 0) r[i] = 0;
    }
    tot = cnt, ip = 1 - ip, cnt = 0;
    if(tot == 1) {
      r[ind] = 1;
      break;
    }
  }
  for(int i=0; i<Np; i++) printf("%s%d", i ? " ":"", r[i]);
  puts("");
  return 0;
}

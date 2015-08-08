#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M, K;
struct apc {
  int id;
  int en, in;
  int ch[5];
  int rnk;
};
bool cmp(const apc &x, const apc &y) {
  double ax = (x.en + x.in) / 2.0, ay = (y.en + y.in) / 2.0;
  return ax != ay ? ax > ay :
         x.en > y.en;
}
int q[100];
vi ad[100];
apc a[40000];
int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &N, &M, &K);
  for(int i=0; i<M; i++) scanf("%d", &q[i]);
  for(int i=0; i<N; i++) {
    a[i].id = i;
    scanf("%d%d", &a[i].en, &a[i].in);
    for(int j=0; j<K; j++) scanf("%d", &a[i].ch[j]);
  }
  sort(a, a + N, cmp);
  for(int i=0; i<N; i++) {
    printf("[%02d]: %3d %3d |", a[i].id, a[i].en, a[i].in);
    for(int j=0; j<K; j++) printf(" %d", a[i].ch[j]); puts("");
  }
  int lasten = a[0].en, lastin = a[0].in, lastrk = 0, lastsl = a[0].ch[0];
  for(int i=0; i<N; i++) {
    if(a[i].en == lasten && a[i].in == lastin) a[i].rnk = lastrk;
    else a[i].rnk = lastrk + 1;
    for(int j=0; j<K; j++) {
      int jj = a[i].ch[j], sz = ad[jj].size();
      if(sz < q[jj] || (a[i].rnk == lastrk && jj == lastsl)) {
        ad[jj].push_back(a[i].id), lastsl = jj;
        break;
      }
    }
    lasten = a[i].en, lastin = a[i].in, lastrk = a[i].rnk;
  }
  for(int i=0; i<M; i++) {
    sort(ad[i].begin(), ad[i].end());
    for(size_t j=0; j<ad[i].size(); j++) printf("%s%d", j ? " ":"", ad[i][j]);
    puts("");
  }
  return 0;
}

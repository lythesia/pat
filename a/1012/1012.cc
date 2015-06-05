#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct stu {
  char id[7] = {0};
  int pt[4] = {0}, rk[4] = {2001};
  int avg() {
    pt[0] = (pt[1] + pt[2] + pt[3]) / 3;
    return pt[0];
  }
};
bool cmpa(const stu &s1, const stu &s2) {
  return s1.pt[0] > s2.pt[0];
}
bool cmpc(const stu &s1, const stu &s2) {
  return s1.pt[1] > s2.pt[1];
}
bool cmpm(const stu &s1, const stu &s2) {
  return s1.pt[2] > s2.pt[2];
}
bool cmpe(const stu &s1, const stu &s2) {
  return s1.pt[3] > s2.pt[3];
}
typedef bool (*comp)(const stu &, const stu &);
comp cmp[] = {cmpa, cmpc, cmpm, cmpe};
const char cs[] = "ACME";

int N, M;
stu st[2001];

int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &M);
  for(int i=0; i<N; i++) scanf("%s %d%d%d", st[i].id, &st[i].pt[1], &st[i].pt[2], &st[i].pt[3]), st[i].avg();
  for(int p=0; p<4; p++) {
    sort(st, st + N, cmp[p]);
    int last = st[0].pt[p];
    st[0].rk[p] = 1;
    for(int i=1; i<N; i++) {
      if(st[i].pt[p] == last) st[i].rk[p] = st[i-1].rk[p];
      else st[i].rk[p] = i + 1, last = st[i].pt[p];
    }
  }
  char id[7] = {0};
  while(M--) {
    scanf("%s", id);
    int i = 0;
    for(; i<N; i++) if(!strcmp(st[i].id, id)) break;
    if(i == N) puts("N/A");
    else {
      auto minrk = min_element(st[i].rk, st[i].rk + 4);
      printf("%d %c\n", *minrk, cs[minrk - st[i].rk]);
    }
  }
  return 0;
}

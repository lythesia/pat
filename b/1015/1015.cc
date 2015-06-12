#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, L, H;
struct stu {
  int id = 0, moral = 0, intel = 0, tot = 0, cl = 0;
  stu() {}
  stu(int n, int m, int i) : id(n), moral(m), intel(i) {
    assert(m >= L && i >= L);
    tot = m + i;
    if(m >= H && i >= H) cl = 4;
    else if(m >= H) cl = 3;
    else if(m >= i && i >= L) cl = 2;
    else if(m < i && m >= L) cl = 1;
  }
};
bool operator < (const stu &s1, const stu &s2) {
  if(s1.cl == s2.cl) {
    if(s1.tot == s2.tot) {
      if(s1.moral == s2.moral) return s1.id < s2.id;
      else return s1.moral > s2.moral;
    }
    else return s1.tot > s2.tot;
  }
  else return s1.cl > s2.cl;
}
stu st[100001];

int main(int argc, const char *argv[])
{
  scanf("%d%d%d", &N, &L, &H);
  int id, moral, intel, cnt = 0;
  for(int i=0; i<N; i++) {
    scanf("%d%d%d", &id, &moral, &intel);
    if(moral >= L && intel >= L) st[cnt++] = stu(id, moral, intel);
  }
  sort(st, st + cnt);
  printf("%d\n", cnt);
  for(int i=0; i<cnt; i++) printf("%08d %d %d\n", st[i].id, st[i].moral, st[i].intel);
  return 0;
}

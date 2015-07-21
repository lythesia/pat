#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, K;
struct rich {
  char name[9] = {0};
  int age = 0;
  int worth = 0;
};
bool operator < (const rich &x, const rich &y) {
  return
    x.worth != y.worth ? x.worth > y.worth :
    x.age != y.age ? x.age < y.age :
    strcmp(x.name, y.name) < 0;
}
rich n[100000];
int by_age[201];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &K);
  for(int i=0; i<N; i++) scanf("%s %d %d", n[i].name, &n[i].age, &n[i].worth);
  sort(n, n + N);
  int tot = 0;
  for(int i=0; i<N; i++) if(by_age[n[i].age]++ < 100) n[tot++] = n[i];
  int M, amin, amax;
  for(int c=1; c<=K; c++) {
    scanf("%d%d%d", &M, &amin, &amax);
    int cnt = 0;
    printf("Case #%d:\n", c);
    for(int i=0; i<tot; i++) {
      if(n[i].age >= amin && n[i].age <= amax) printf("%s %d %d\n", n[i].name, n[i].age, n[i].worth), cnt++;
      if(cnt == M) break;
    }
    if(!cnt) puts("None");
  }
  return 0;
}

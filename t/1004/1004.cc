#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, extra;
int s[100][62];
int need[62], has[62], now[62];

int bead(char c) {
  if(isdigit(c)) return c - '0';
  else if(islower(c)) return c - 'a' + 10;
  else return c - 'A' + 36;
}

void dfs(int p, int ex) { // try s[p]
  if(ex >= extra) return;

  int ineed = 0;
  for(; ineed<62; ineed++) {
    if(now[ineed] + has[ineed] < need[ineed]) return;
    else if(now[ineed] < need[ineed]) break;
  }
  if(ineed >= 62) {
    extra = ex;
    return;
  }
  if(p >= N) return;

  // take s[p] or not take
  bool take = false;
  int new_ex = 0;
  for(int i=0; i<62; i++) {
    if(now[i] < need[i] && s[p][i]) take = true;
    now[i] += s[p][i];
    has[i] -= s[p][i];
    if(now[i] > need[i]) new_ex += now[i] - need[i];
  }
  if(take) dfs(p + 1, new_ex);

  for(int i=0; i<62; i++) now[i] -= s[p][i]; // restore
  dfs(p + 1, ex);
  for(int i=0; i<62; i++) has[i] += s[p][i];
}

int main(int argc, const char *argv[])
{
  char buf[1005];
  scanf("%s", buf);
  for(char *p=buf; *p; p++) need[bead(*p)]++;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%s", buf);
    for(char *p=buf; *p; p++) {
      int b = bead(*p);
      has[b]++, s[i][b]++;
    }
  }
  int ans = 0;
  for(int i=0; i<62; i++) {
    if(need[i] > has[i]) ans += need[i] - has[i];
    else extra += has[i] - need[i];
  }
  if(ans) printf("No %d\n", ans);
  else if(!extra) puts("Yes 0");
  else {
    dfs(0, 0);
    printf("Yes %d\n", extra);
  }
  return 0;
}

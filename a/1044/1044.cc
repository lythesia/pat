#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, M, a[100001];
struct range {
  int s, e, v;
};
struct comp {
  bool operator () (const range &x, const range &y) {
    return x.v == y.v ? x.s > y.s : x.v > y.v;
  }
};
int main(int argc, const char *argv[])
{
  scanf("%d%d", &N, &M);
  for(int i=1; i<=N; i++) scanf("%d", &a[i]);
  priority_queue<range, vector<range>, comp> ans;
  int s = 1, e = 1, sum = 0;
  while(s <= e && e <= N) {
    sum += a[e];
    if(sum >= M) {
      ans.push(range{s, e, sum});
      while(sum >= M) {
        sum -= a[s++];
        if(sum >= M) ans.push(range{s, e, sum});
      }
    }
    e++;
  }
  int prev = ans.top().v;
  while(!ans.empty()) {
    auto t = ans.top();
    if(t.v == prev) printf("%d-%d\n", t.s, t.e);
    else break;
    ans.pop();
  }
  return 0;
}

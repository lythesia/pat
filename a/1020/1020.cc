#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, post[32], in[32];
vi lv[32];
void order(int *s1, int *e1, int *s2, int *e2, int d) {
  if(s1 >= e1 || s2 >= e2) return;
  int root = *(e1 - 1);
  lv[d].push_back(root);
  int *r = find(s2, e2, root);
  order(s1, s1 + (r - s2), s2, r, d + 1);
  order(s1 + (r - s2), e1 - 1, r + 1, e2, d + 1);
}

int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &post[i]);
  for(int i=0; i<N; i++) scanf("%d", &in[i]);
  order(post, post + N, in, in + N, 0);
  int cnt = 0;
  for(vi &v : lv) {
    if(v.empty()) break;
    for(int i : v) printf("%s%d", cnt++ ? " ":"", i);
  }
  puts("");
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, a[1000], ans[1000], cnt, mirr;
stack<int> st;
bool dfs(int *s, int *e) {
  if(s == e) return true;
  int *m = NULL,
      *no_m = find_if_not(s + 1, e, [s](int x){return x < *s;}),
      *if_m = find_if_not(s + 1, e, [s](int x){return x >= *s;});
  bool is_no_m = all_of(no_m, e, [s](int x){return x >= *s;}),
       is_if_m = all_of(if_m, e, [s](int x){return x < *s;});
  if(mirr < 0) {
    if(!is_no_m) return false;
    m = no_m;
  }
  else if(mirr > 0) {
    if(!is_if_m) return false;
    m = if_m;
  }
  else {
    if(is_no_m) mirr = -1, m = no_m;
    else if(is_if_m) mirr = 1, m = if_m;
    else return false;
  }
  assert(m != NULL);
  st.push(*s);
  if(dfs(s + 1, m) && dfs(m, e)) {
    ans[cnt++] = st.top();
    st.pop();
    return true;
  }
  else return false;
}
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &a[i]);
  if(dfs(a, a + N)) {
    puts("YES");
    for(int i=0; i<N; i++) printf("%s%d", i ? " ":"", ans[i]);
    puts("");
  }
  else puts("NO");
  return 0;
}

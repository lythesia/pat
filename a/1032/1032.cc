#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

unordered_map<int, int> nxt;
int len(int head) {
  int ans = 0;
  while(head != -1) ans++, head = nxt[head];
  return ans;
}

int main(int argc, const char *argv[])
{
  int h1, h2, N;
  scanf("%d%d%d", &h1, &h2, &N);
  while(N--) {
    int a, n; char d;
    scanf("%d %c %d", &a, &d, &n);
    nxt.insert(make_pair(a, n));
  }
  int len1 = len(h1), len2 = len(h2), d = len1 - len2;
  if(d < 0) d = -d, swap(h1, h2); // always advance h1
  while(d--) h1 = nxt[h1];
  for(; h1!=-1 && h2!=-1; h1=nxt[h1], h2=nxt[h2]) if(h1 == h2) break;
  h1 == -1 ? puts("-1") : printf("%05d\n", h1);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, head;
int val[100000], nxt[100000];
bool hsh[10001];
int main(int argc, const char *argv[])
{
  scanf("%d%d", &head, &N);
  int addr;
  for(int i=0; i<N; i++) scanf("%d", &addr), scanf("%d%d", val + addr, nxt + addr);
  vi sep;
  int p = nxt[head], prev = head;
  hsh[abs(val[head])] = true;
  while(p != -1) {
    int v = abs(val[p]);
    if(!hsh[v]) hsh[v] = true, prev = p;
    else sep.push_back(p), nxt[prev] = nxt[p];
    p = nxt[p];
  }
  while(head != -1) printf("%05d %d ", head, val[head]), nxt[head] == -1 ? puts("-1") : printf("%05d\n", nxt[head]), head = nxt[head];
  if(!sep.empty()) {
    auto it = sep.begin();
    printf("%05d %d ", *it, val[*it]), it++;
    for(; it!=sep.end(); it++) printf("%05d\n%05d %d ", *it, *it, val[*it]);
    puts("-1");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, k[100];
int a[100], n[100], chd[100][2];
int cnt;
void inorder(int root) {
  if(root == -1) return;
  inorder(chd[root][0]);
  a[root] = k[cnt++];
  inorder(chd[root][1]);
}
int main(int argc, const char *argv[])
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d%d", &chd[i][0], &chd[i][1]);
  for(int i=0; i<N; i++) scanf("%d", &k[i]);
  sort(k, k + N);
  inorder(0);
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()) {
    int t = Q.front(); Q.pop();
    printf("%s%d", t ? " ":"", a[t]);
    if(chd[t][0] != -1) Q.push(chd[t][0]);
    if(chd[t][1] != -1) Q.push(chd[t][1]);
  }
  puts("");
  return 0;
}

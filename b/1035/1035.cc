#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int N, m[100];
bool is_mrg(int len) {
  for(int *p=m; p<m+N; p+=len) {
    if(!is_sorted(p, p + min(len, (int)(m + N - p)))) return false;
  }
  return true;
}
int main(int argc, const char *argv[])
{
  int useless;
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &useless);
  for(int i=0; i<N; i++) scanf("%d", &m[i]);
  bool ins = true;
  int len = 128;
  while(len >= N) len >>= 1;
  for(; len > 1; len >>= 1) { // downward
    if(is_mrg(len)) {
      ins = false, len <<= 1;
      break;
    }
  }
  if(ins) sort(m, is_sorted_until(m, m + N) + 1);
  else for(int *p=m; p<m+N; p+=len) sort(p, p + min(len, (int)(m + N - p)));
  ins ? puts("Insertion Sort") : puts("Merge Sort");
  for(int i=0; i<N-1; i++) printf("%d ", m[i]);
  printf("%d\n", m[N-1]);
  return 0;
}

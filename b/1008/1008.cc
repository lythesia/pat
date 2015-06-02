#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int N, M, A[105];
  scanf("%d%d", &N, &M);
  M %= N;
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  for(int i=N-M; i<N; i++) printf("%d ", A[i]);
  for(int i=0; i<N-M-1; i++) printf("%d ", A[i]);
  printf("%d\n", A[N-M-1]);
  return 0;
}

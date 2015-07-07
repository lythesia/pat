#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int NC, NP;
long C[100000], P[100000];
int main(int argc, const char *argv[])
{
  scanf("%d", &NC);
  for(int i=0; i<NC; i++) scanf("%ld", &C[i]);
  scanf("%d", &NP);
  for(int i=0; i<NP; i++) scanf("%ld", &P[i]);
  int n = min(NC, NP), cnt = 0;
  sort(C, C + NC, greater<int>());
  sort(P, P + NP, greater<int>());
  long ans = 0;
  for(; cnt<n && (C[cnt] | P[cnt])>0; cnt++) ans += C[cnt] * P[cnt];
  for(int i=NC-1, j=NP-1; (C[i] & P[j])<0 && (~i) && (~j) && cnt<n; i--, j--, cnt++) ans += C[i] * P[j];
  printf("%ld\n", ans);
  return 0;
}

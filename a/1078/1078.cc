#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int MAXP = 10010;
int M, N;
bool noprime[MAXP] = {true, true}, h[MAXP];
int main(int argc, const char *argv[])
{
  for(int i=2; i<=100; i++) {
    if(!noprime[i]) {
      for(int j=i*i; j<MAXP; j+=i) noprime[j] = true;
    }
  }
  scanf("%d%d", &M, &N);
  while(noprime[M]) M++;
  int x, i;
  while(N--) {
    scanf("%d", &x);
    for(i=0; i<M; i++) {
      int pos = (x + i * i) % M;
      if(!h[pos]) {
        h[pos] = true;
        printf("%d", pos);
        break;
      }
    }
    if(i == M) putchar('-');
    N ? putchar(' ') : putchar('\n');
  }
  return 0;
}

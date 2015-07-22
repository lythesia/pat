#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int M = 50000, SQ = 223;
long N;
bool no_prime[M + 1];
vector<int> prime;
int main(int argc, const char *argv[])
{
  for(int i=2; i<=SQ; i++) {
    if(!no_prime[i]) for(int j=i*i; j<=M; j+=i) no_prime[j] = true;
  }
  for(int i=2; i<=M; i++) if(!no_prime[i]) prime.push_back(i);
  scanf("%ld", &N);
  if(N == 1) puts("1=1");
  else {
    printf("%ld=", N);
    for(int p : prime) {
      if(N < p) break;
      int c = 0;
      while(!(N % p)) N /= p, c++;
      if(c) {
        c > 1 ? printf("%d^%d", p, c) : printf("%d", p);
        if(N!=1) putchar('*');
      }
    }
    puts("");
  }
  return 0;
}

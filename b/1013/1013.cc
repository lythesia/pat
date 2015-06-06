#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

bool is_prime(int x) {
  for(int i=3;; i+=2) {
    int q = x / i;
    if(q < i) return true;
    if(x == q * i) return false;
  }
  return true;
}
int next_prime(int x) {
  if (x <= 2) return 2;
  if(!(x & 1)) ++x;
  for(; !is_prime(x); x += 2);
  return x;
}
int main(int argc, const char *argv[])
{
  int M = 0, N = 0;
  scanf("%d%d", &M, &N);
  int i = 1, x = 2, cnt = 0;
  while(i != M) x = next_prime(x+1), i++;
  printf("%d", x), cnt++;
  while(i != N) {
    x = next_prime(x+1), i++, cnt++;
    if(cnt % 10 == 0 || i == N) printf(" %d\n", x);
    else if(cnt % 10 == 1) printf("%d", x);
    else printf(" %d", x);
  }
  return 0;
}

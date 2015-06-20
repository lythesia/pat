#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

long gcd(long a, long b) {
  if(a < b) swap(a, b);
  long c;
  while(a) c = a, a = b % a, b = c;
  return b;
}
struct frac {
  long i = 0, n = 0, d = 1;
  bool neg = false, inf = false;
  frac() {}
  frac(long nn, long dd) : n(nn), d(dd) {}
  frac& simp() {
    assert(i == 0);
    if(!d) inf = true;
    else {
      if((n ^ d) < 0) neg = true;
      n = labs(n), d = labs(d);
      long c = gcd(n, d);
      n /= c, d /= c, i = n / d, n %= d;
    }
    return *this;
  }
  frac operator + (const frac &f) {
    frac ans(n * f.d + f.n * d, d * f.d);
    return ans.simp();
  }
  frac operator - (const frac &f) {
    frac ans(n * f.d - f.n * d, d * f.d);
    return ans.simp();
  }
  frac operator * (const frac &f) {
    frac ans(n * f.n, d * f.d);
    return ans.simp();
  }
  frac operator / (const frac &f) {
    frac ans(n * f.d, d * f.n);
    return ans.simp();
  }
  void p() {
    // assume simplified
    if(inf) printf("Inf");
    else {
      if(neg) { printf("(-"); p_aux(); printf(")"); }
      else p_aux();
    }
  }
  void p_aux() {
    if(!i && !n) putchar('0');
    else if(i && !n) printf("%ld", i);
    else if(n && !i) printf("%ld/%ld", n, d);
    else printf("%ld %ld/%ld", i, n, d);
  }
};
char op[] = "+-*/";
int main(int argc, const char *argv[])
{
  frac f1, f2, ans[4];
  scanf("%ld/%ld %ld/%ld", &f1.n, &f1.d, &f2.n, &f2.d);
  ans[0] = f1 + f2;
  ans[1] = f1 - f2;
  ans[2] = f1 * f2;
  ans[3] = f1 / f2;
  f1.simp(); f2.simp();
  for(int i=0; i<4; i++) {
    f1.p(); printf(" %c ", op[i]); f2.p(); printf(" = "); ans[i].p();
    puts("");
  }
  return 0;
}

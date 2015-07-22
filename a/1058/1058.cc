#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int a[3], b[3], r[3] = {INT_MAX, 17, 29};
int main(int argc, const char *argv[])
{
  scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
  for(int i=2, c=0; ~i; i--) {
    int sum = a[i] + b[i] + c;
    a[i] = sum % r[i], c = sum / r[i];
  }
  printf("%d.%d.%d\n", a[0], a[1], a[2]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int a, b, d, sum;
  scanf("%d%d%d", &a, &b, &d), sum = a + b;
  stack<int> st;
  while(sum) {
    st.push(sum % d);
    sum /= d;
  }
  if(st.empty()) st.push(0);
  while(!st.empty()) { printf("%d", st.top()); st.pop(); }
  puts("");
  return 0;
}

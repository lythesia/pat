#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main(int argc, const char *argv[])
{
  int a, b, sum;
  scanf("%d%d", &a, &b);
  sum = a + b;
  if(sum < 0) sum = -sum, putchar('-');
  stack<int> st;
  while(sum >= 1000) {
    st.push(sum % 1000);
    sum /= 1000;
  }
  int r = sum % 1000;
  if((st.size() && r) || st.empty()) st.push(r);
  printf("%d", st.top()); st.pop();
  while(!st.empty()) {
    int t = st.top();
    st.pop();
    printf(",%03d", t);
  }
  puts("");
  return 0;
}

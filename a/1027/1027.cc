#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

void to_13(int x) {
  stack<int> st;
  while(x) {
    st.push(x % 13);
    x /= 13;
  }
  if(st.empty()) st.push(x);
  if(st.size() == 1) putchar('0');
  while(!st.empty()) {
    int t = st.top();
    printf("%c", t < 10 ? '0' + t : 'A' + t - 10);
    st.pop();
  }
}

int main(int argc, const char *argv[])
{
  int c[3];
  scanf("%d%d%d", &c[0], &c[1], &c[2]);
  putchar('#');
  for(int i=0; i<3; i++) to_13(c[i]);
  puts("");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const char tab[][6] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
};
int main(int argc, const char *argv[])
{
  char n[102] = {0};
  scanf("%s", n);
  int len = strlen(n), sum = 0;
  for(int i=0; i<len; i++) sum += n[i]-'0';
  stack<int> st;
  do {
    st.push(sum % 10);
    sum /= 10;
  } while(sum);
  while(st.size() > 1) {
    printf("%s ", tab[st.top()]);
    st.pop();
  }
  printf("%s\n", tab[st.top()]);
  return 0;
}

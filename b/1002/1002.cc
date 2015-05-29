#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const char tab[][5] = {
  "ling",
  "yi",
  "er",
  "san",
  "si",
  "wu",
  "liu",
  "qi",
  "ba",
  "jiu",
};
int main(int argc, const char *argv[])
{
  char s[101] = {0};
  scanf("%s", s);
  int sum = 0, len = strlen(s);
  for(int i=0; i<len; i++) sum += s[i]-'0';
  stack<int> st;
  do {
    st.push(sum % 10);
    sum /= 10;
  } while(sum);
  printf("%s", tab[st.top()]); st.pop();
  while(!st.empty()) {
    printf(" %s", tab[st.top()]);
    st.pop();
  }
  puts("");
  return 0;
}

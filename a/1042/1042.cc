#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

const char colo[] = "SHCD";
int K, deck[2][55], shuf[55];
void putcard(int card, bool eol) {
  if(card < 53) printf("%c%d", colo[(card - 1) / 13], (card - 1) % 13 + 1);
  else printf("J%d", card - 52);
  eol ? puts("") : putchar(' ');
}
int main(int argc, const char *argv[])
{
  scanf("%d", &K);
  int d = 0;
  for(int i=1; i<55; i++) deck[d][i] = i, scanf("%d", &shuf[i]);
  while(K--) {
    for(int i=1; i<55; i++) deck[1-d][shuf[i]] = deck[d][i];
    d = 1 - d;
  }
  for(int i=1; i<54; i++) putcard(deck[d][i], false);
  putcard(deck[d][54], true);
  return 0;
}

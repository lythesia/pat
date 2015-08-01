#include <bits/stdc++.h>
using namespace std;

#define inject(x) { cerr << "Function: " << __FUNCTION__ << ", Line: " << __LINE__ << ", " << #x << ": " << (x) << endl; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

struct Node {
  int dep = 1, val = 0;
  Node *left = NULL, *right = NULL;
};
typedef Node *node;
Node nodes[20];
int depth(node t) {
  return t ? t->dep : 0;
}
node lrotate(node root) {
  node t = root->right;
  root->right = t->left, t->left = root;
  root->dep = max(depth(root->left), depth(root->left)) + 1, t->dep = max(depth(t->left), depth(t->right)) + 1;
  return t;
}
node rrotate(node root) {
  node t = root->left;
  root->left = t->right, t->right = root;
  root->dep = max(depth(root->right), depth(root->right)) + 1, t->dep = max(depth(t->left), depth(t->right)) + 1;
  return t;
}
node insert(node root, node neo) {
  int v = neo->val;
  if(!root) return neo;
  if(v < root->val) {
    root->left = insert(root->left, neo);
    root->dep = max(depth(root->left), depth(root->right)) + 1;
    if(depth(root->left) > depth(root->right) + 1) {
      if(v < root->left->val) return rrotate(root); // LL
      else { // LR
        root->left = lrotate(root->left);
        return rrotate(root);
      }
    }
    else return root;
  }
  else {
    root->right = insert(root->right, neo);
    root->dep = max(depth(root->left), depth(root->right)) + 1;
    if(depth(root->right) > depth(root->left) + 1) {
      if(v > root->right->val) return lrotate(root); // RR
      else { // RL
        root->right = rrotate(root->right); 
        return lrotate(root);
      }
    }
    else return root;
  }
}

int main(int argc, const char *argv[])
{
  int N;
  scanf("%d", &N);
  node avl = NULL;
  for(int i=0; i<N; i++) {
    scanf("%d", &nodes[i].val);
    assert(nodes[i].val != 0);
    avl = insert(avl, &nodes[i]);
  }
  printf("%d\n", avl->val);
  return 0;
}

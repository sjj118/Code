#include <cstdio>
#include <algorithm>

const int MAXN = 10002;
struct Node
{
  bool rev;
  Node *parent, *child[2];
} _memory[MAXN], *EMPTY = _memory;
inline void clear(Node* const x)
{
  if (x == EMPTY) return;
  if (x->rev)
  {
    x->child[0]->rev ^= true;
    x->child[1]->rev ^= true;
    std::swap(x->child[0], x->child[1]);
    x->rev = false;
  }
}
void rotate(Node* const x, const int c)
{
  Node* const y = x->parent;
  y->child[c^1] = x->child[c];
  if (x->child[c] != EMPTY) x->child[c]->parent = y;
  x->parent = y->parent;
  if (y->parent->child[0] == y) x->parent->child[0] = x; else
  if (y->parent->child[1] == y) x->parent->child[1] = x;
  x->child[c] = y;
  y->parent = x;
}
inline bool _splay_parent(Node* const x, Node* (&y))
  { return (y = x->parent) != EMPTY && (y->child[0] == x || y->child[1] == x); }
void splay(Node* const x)
{
  clear(x);
  for (Node *y, *z; _splay_parent(x, y); )
    if (_splay_parent(y, z))
    {
      clear(z), clear(y), clear(x);
      const int c = y == z->child[0];
      if (x == y->child[c]) rotate(x, c^1), rotate(x, c);
      else rotate(y, c), rotate(x, c);
    }
    else
    {
      clear(y), clear(x);
      rotate(x, x == y->child[0]);
    }
}
Node* access(Node* u)
{
  Node* v = EMPTY;
  for (; u != EMPTY; u = u->parent)
  {
    splay(u);
    u->child[1] = v;
    v = u;
  }
  return v;
}
inline Node* getroot(Node* x)
{
  for (x = access(x); clear(x), x->child[0] != EMPTY; x = x->child[0]);
  return x;
}
inline void makeroot(Node* const x)
{
  access(x)->rev ^= true;
  splay(x);
}
void link(Node* const x, Node* const y)
{
  makeroot(x);
  x->parent = y;
  access(x);
}
void cut(Node* const x, Node* const y)
{
  makeroot(x);
  access(y), splay(y);
  y->child[0]->parent = EMPTY;
  y->child[0] = EMPTY;
}

int n, m;
int main()
{
	freopen("code.in","r",stdin);
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; ++i)
  {
    Node* const node = _memory+i;
    node->child[0] = node->child[1] = node->parent = EMPTY;
  }
  for (int i = 0, x, y; i < m; ++i)
  {
    static char buf[10];
    scanf("\n%s%d%d", buf, &x, &y);
    Node *ra, *rb;
    switch (buf[0])
    {
      case 'Q':
        ra = getroot(_memory+x), rb = getroot(_memory+y);
        printf(ra == rb && ra != EMPTY ? "Yes\n" : "No\n"); break;
      case 'D': cut(_memory+x, _memory+y); break;
      case 'C': link(_memory+x, _memory+y); break;
    }
  }
}


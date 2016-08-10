#include <cstdio>
#include <algorithm>

const int BUFSIZE = 20*1024*1024;
char _stdin[BUFSIZE], *p = _stdin;
inline int readint()
{
  char ch = *p++;
  for (; ch > '9' || ch < '0'; ch = *p++);
  int tmp = 0;
  for (; '0' <= ch && ch <= '9'; ch = *p++)
    tmp = tmp*10 + ch - '0';
  return tmp;
}
inline char readchar()
{
  char ch = *p++;
  for (; ch <= 32; ch = *p++);
  return ch;
}

const int MOD = 51061;
const int MAXN = 100002;
struct Edge
{
  int v;
  Edge *next;
} g[MAXN*2], *header[MAXN];
inline void AddEdge(const int x, const int y)
{
  static int LinkSize;
  Edge* const node = g+(LinkSize++);
  node->v = y;
  node->next = header[x];
  header[x] = node;
}


struct Node
{
  int value, sum, add, mul, size;
  bool rev;
  Node* parent, *child[2];
  void clear_mul(const long long m)
  {
    mul = mul * m % MOD;
    sum = sum * m % MOD;
    add = add * m % MOD;
    value = value * m % MOD;
  }
  void clear_add(const int a)
  {
    sum = (sum + static_cast<long long>(a) * size) % MOD;
    add = add + a;
    value = value + a;
  }
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
  if (x->mul != 1)
  {
    if (x->child[0] != EMPTY) x->child[0]->clear_mul(x->mul);
    if (x->child[1] != EMPTY) x->child[1]->clear_mul(x->mul);
    x->mul = 1;
  }
  if (x->add)
  {
    if (x->child[0] != EMPTY) x->child[0]->clear_add(x->add);
    if (x->child[1] != EMPTY) x->child[1]->clear_add(x->add);
    x->add = 0;
  }
}
inline void update(Node* const x)
{
  x->size = x->child[0]->size + 1 + x->child[1]->size;
  x->sum = x->child[0]->sum + x->value + x->child[1]->sum;
}
inline void rotate(Node* const x, const int c)
{
  Node* const y = x->parent;
  y->child[c^1] = x->child[c];
  if (x->child[c] != EMPTY) x->child[c]->parent = y;
  x->parent = y->parent;
  if (y->parent->child[0] == y) x->parent->child[0] = x; else
  if (y->parent->child[1] == y) x->parent->child[1] = x;
  y->parent = x;
  x->child[c] = y;
  update(y);
}
inline bool _splay_parent(Node *x, Node* (&y))
  { return (y = x->parent) != EMPTY && (y->child[0] == x || y->child[1] == x); }
inline void splay(Node* const x)
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
      rotate(x, x == y->child[0]); break;
    }
  update(x);
}
inline Node* access(Node* u)
{
  Node* v = EMPTY;
  for (; u != EMPTY; u = u->parent)
  {
    splay(u);
    u->child[1] = v;
    update(v = u);
  }
  return v;
}
inline void makeroot(Node* const x)
{
  access(x)->rev ^= true;
  splay(x);
}
inline void link(Node* const x, Node* const y)
{
  makeroot(x);
  x->parent = y;
  //access(x);
}
inline void cut(Node* const x, Node* const y)
{
  makeroot(x);
  access(y), splay(y);
  y->child[0]->parent = EMPTY;
  y->child[0] = EMPTY;
  update(y);
}
inline int getsum(Node* const x, Node* const y)
{
  makeroot(x);
  access(y), splay(y);
  return y->sum % MOD;
}
inline void multiply(Node* const x, Node* const y, const int mul)
{
  makeroot(x);
  access(y), splay(y);
  y->clear_mul(mul);
}
inline void add(Node* const x, Node* const y, const int add)
{
  makeroot(x);
  access(y), splay(y);
  y->clear_add(add);
}
void maketree(int u, int parent)
{
  Node* const node = _memory+u;
  node->value = node->sum = node->size = node->mul = 1;
  node->parent = _memory+parent, node->child[0] = node->child[1] = EMPTY;
  for (Edge *e = header[u]; e; e = e->next)
    if (e->v != parent)
      maketree(e->v, u);
}

int n, q;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("std.out","w",stdout);
  fread(_stdin, 1, BUFSIZE, stdin);
  EMPTY->parent = EMPTY->child[0] = EMPTY->child[1] = EMPTY;

  n = readint(), q = readint();
  for (int i = 1, x, y; i < n; ++i)
  {
    x = readint(), y = readint();
    AddEdge(x, y);
    AddEdge(y, x);
//	link(_memory+x,_memory+y); 
  }
  maketree(1, 0);
  for (int i = 0, u, v, x, y; i < q; ++i)
  {
    char op;
    op = readchar(), u = readint(), v = readint();
    switch (op)
    {
      case '+':
        x = readint();
        add(_memory+u, _memory+v, x);
        break;
      case '-':
        x = readint(), y = readint();
        cut(_memory+u, _memory+v);
        link(_memory+x, _memory+y);
        break;
      case '*':
        x = readint();
        multiply(_memory+u, _memory+v, x);
        break;
      case '/':
        printf("%d\n", getsum(_memory+u, _memory+v));
        break;
    }
  }
}


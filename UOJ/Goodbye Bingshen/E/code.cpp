#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define rg register
#define rep(i,x,y) for(rg int i=(x);i<=(y);++i)
#define per(i,x,y) for(rg int i=(x);i>=(y);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#include "isomorphism.h"
using namespace std;
int ha,hb;
const int P=1000000007;
vector<vector<int> > _nxn_matrix(int n)
{
	vector< vector<int> > a;
	for (int v = 0; v < n; v++)
	{
		a.push_back(vector<int>());
		for (int u = 0; u < n; u++)
			a[v].push_back(0);
	}
	return a;
}
vector<vector<int> > _adjacency_matrix(graph g)
{
	vector< vector<int> > a = _nxn_matrix(g.n);
	for (int i = 0; i < (int)g.e.size(); i++) {
		a[g.e[i].first - 1][g.e[i].second - 1] = 1;
		a[g.e[i].second - 1][g.e[i].first - 1] = 1;
	}
	return a;
}

vector<vector<int> > _matrix_mod_mult(vector< vector<int> > a, vector< vector<int> > b)
{
	int n = (int)a.size();
	vector< vector<int> > c = _nxn_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % P;
	return c;
}
int _hash_graph(graph g) {
	vector< vector<int> > matA = _adjacency_matrix(g);
	vector< vector<int> > matS = matA;

	vector<int> diag;
	for (int v = 0; v < g.n; v++)
		diag.push_back(0);
	for (int i = 0; i < g.n; i++) {
		matS = _matrix_mod_mult(matS, matA);
		for (int v = 0; v < g.n; v++)
			diag[v] = ((long long)diag[v] * 13331 + 342605723 + matS[v][v]) % P;
	}

	sort(diag.begin(), diag.end());

	int code = 0;
	for (int v = 0; v < (int)diag.size(); v++)
		code = ((long long)code * 1324321 + 816334567 + diag[v]) % P;
	return code;
}
void hack(){
	graph a, b;
	int n=13;
	a.n=b.n=13;
	rep(i,1,6)a.e.pb(mp(i+1,i+6+1));
	rep(i,1,12)a.e.pb(mp(i+1,i%12+1+1));
	rep(i,2,13)a.e.pb(mp(1,i));
	rep(i,1,6)b.e.pb(mp(i+1,i%6+1+1));
	rep(i,1,6)b.e.pb(mp(i+1,i+6+1));
	rep(i,1,6)b.e.pb(mp(i+6+1,i%6+7+1));
	rep(i,2,13)b.e.pb(mp(1,i));
	ha=_hash_graph(a);
	hb=_hash_graph(b);
	propose(a, b);
}

int identify(graph g){
	return _hash_graph(g)==ha?1:2;
}

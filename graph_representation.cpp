#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int m_adj[MAX][MAX];

vector<int> l_adj[MAX];

int main(){
	int V, E;
	int v,u;
	cin >> V >> E;
	
	//Matriz de Adjacencia grafo não orientado
	for(int i = 0; i <E; i++){
		cin >> v >> u;
		m_adj[v][u] = 1;
		m_adj[u][v] = 1;
	}
	
	//Lista de adjacencia grafo não orientado
	
	for(int i = 0; i <E; i++){
		cin >> v >> u;
		l_adj[u].push_back(v);
		l_adj[v].push_back(u);
	}


	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int n = 6;

bool bfs(int rg[n][n], int s, int t, int p[n]){
	vector<bool> visited(n, false); 
	
	queue<int> q;
	q.push(s);
	
	visited[s] = 1;
	p[s] = -1;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 0; v < n; v++){
			if(visited[v] == 0 && rg[u][v] > 0){
				if(v == t){
					p[v] = u;
					return true;
				}
				q.push(v);
				visited[v] = 1;
				p[v] = u;
			}
		}
	}
	return false;
}

int ford_fulkerson(int g[n][n], int s, int t){
	int rg[n][n];
	
	for(int u = 0; u < n; u++){
		for(int v = 0; v < n; v++){
			rg[u][v] = g[u][v];
		}
	}
	
	int p[n], max_flow = 0;
	
	while(bfs(rg, s, t, p)){
		int path_flow = 1000000;
		for(int v = t; v != s; v = p[v]){
			int u = p[v];
			path_flow = min(path_flow, rg[u][v]);
		}
		
		for(int v = t; v != s; v = p[v]){
			int u = p[v];
			rg[u][v] -= path_flow;
			rg[v][u] += path_flow;
		}
		
		max_flow += path_flow;
	}
	return max_flow;
}

int main(){

	int g[n][n] = {{0, 16, 13, 0, 0, 0},
		           {0, 0, 10, 12, 0, 0},
		           {0, 4, 0, 0, 14, 0},
		           {0, 0, 9, 0, 0, 20},
		           {0, 0, 0, 7, 0, 4},
		           {0, 0, 0, 0, 0, 0}}; 
		       
	/* int g[n][n] = {{0, 1000000, 1000000, 0},
		           {0, 0, 1, 1000000},
		           {0, 0, 0, 1000000},
		           {0, 0, 0, 0}};
               */
	
	cout << "Max Flow : " << ford_fulkerson(g, 0, 5) << endl;
	
	return 0;
}

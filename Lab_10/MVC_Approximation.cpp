#include <bits/stdc++.h>
using namespace std;

class graph {

public:

    vector<vector<int>> adj;

    void addEdge(int u, int v){
        adj.push_back({u, v, 0});
        adj.push_back({v, u, 0});
    }

    unordered_map<int, bool> visited;

    void MVC(int n, int m) {

        // use to store the answer and visited vertices
        set<int> ans, s;

        while(s.size() != n){

            int i;
            srand(time(0));
            i = (rand() % m) + 1;
            
            int u, v;
            // do if edge is not visited
            if(adj[i][2] == 0){
                u = adj[i][0], v = adj[i][1];
                cout << "selected edge : " << u << "-->" << v << endl;
                adj[i][2] = 1;
                s.insert(u);
                s.insert(v);
                ans.insert(u);
                ans.insert(v);

                // traverse all of the edges
                for(int j = 0; j < adj.size(); j++){
                    if((adj[j][0] == u || adj[j][0] == v) && adj[j][2] == 0){
                        // put the visited vertices in the set s
                        s.insert(adj[j][1]);
                        // mark the visited true
                        adj[j][2] = 1;   
                    }
                }
            }
        }
        cout << "MVC : ";
        for(auto j : ans){
            cout << j << " ";
        }
    }

};

int main() {

    int n, m;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;

    graph g;
    cout << "Enter " << m << " edges in (u, v) formate" << endl;
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.MVC(n, m);

    return 0;
}

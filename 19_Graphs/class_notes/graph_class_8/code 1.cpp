#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;


class graph {
    public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool direction) {
        //direction = 1 -> undirected graph
        //direction => 0 -> directed graph;
        adjList[u].push_back(v);
        if(direction == 1) {
            adjList[v].push_back(u);
        }
    }

    // void printAdjList() {
    //     for(auto i: adjList) {
    //         cout << i.first <<"-> ";
    //         for(auto j: i.second) {
    //             cout << "(" << j.first<<", "<<j.second<<"), ";
    //         }
    //         cout << endl;
    //     }
    // }

    // void shortestPathBfs(int src, int dest) {
    //     queue<int> q;
    //     unordered_map<int,bool> visited;
    //     unordered_map<int,int> parent;

    //     //inital steps for src
    //     q.push(src);
    //     visited[src] = 1;
    //     parent[src] = -1;

    //     while(!q.empty()) {
    //         int fNode = q.front();
    //         q.pop();

    //         for(auto nbr: adjList[fNode]) {
    //             if(!visited[nbr.first]) {
    //                 q.push(nbr.first);
    //                 visited[nbr.first] = 1;
    //                 parent[nbr.first] = fNode;
    //             }
    //         }
    //     }

    //     //store path in ans, after traversing in the parent array
    //     vector<int> ans;
    //     int node = dest;
    //     while(node != -1) {
    //         ans.push_back(node);
    //         node = parent[node];
    //     }

    //     reverse(ans.begin(), ans.end());

    //     cout << "printing ANs: " << endl;
    //     for(auto i: ans) {
    //         cout << i<<", ";
    //     }
    //     cout << endl;
        
    // }


    // void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
        
    //     visited[src] = true;

    //     for(auto neighbour: adjList[src]) {
    //         if(!visited[neighbour.first] ) {
    //             topoSortDfs(neighbour.first, visited, ans);
    //         }
    //     }

    //     //while returning, store the node in stack
    //     cout << "Pushing " << src << endl;
    //     ans.push(src);
    // }

 //     void shortestpathDfs(int dest, stack<int> topoOrder, int n) {
    //     vector<int> dist(n, INT_MAX);

    //     int src = topoOrder.top();
    //     topoOrder.pop();
    //     dist[src] = 0;


    //     for(auto nbr: adjList[0]) {
    //         if(dist[0] + nbr.second < dist[nbr.first]) {
    //             dist[nbr.first] = dist[0] + nbr.second;
    //         }
    //     }
            

    //     while(!topoOrder.empty()) {

    //         int topElement = topoOrder.top();
    //         topoOrder.pop();

    //         if(dist[topElement] != INT_MAX) {
    //             for(auto nbr: adjList[topElement]) {
    //                 if(dist[topElement] + nbr.second < dist[nbr.first]) {
    //                     dist[nbr.first] = dist[topElement] + nbr.second;
    //                 }
    //             }
    //         }
    //     }

    //     cout << "Printing Ans: " << endl;
    //     for(int i=0; i<n; i++) {
    //         cout << i <<"-> " << dist[i] << endl;
    //     }
        
        
    // }


    // void floydWarshal(int n) {
    //     vector<vector<int> > dist(n , vector<int>(n,1e9));
    //     //diagnol pr zero mark krdo
    //     for(int i=0; i<n; i++) {
    //         dist[i][i] = 0;
    //     }
    //     //graph k according dist insert krdia h
    //     for(auto t: adjList) {
    //         for(auto nbr: t.second) {
    //             int u = t.first;
    //             int v = nbr.first;
    //             int wt = nbr.second;
    //             dist[u][v] = wt;
    //         }
    //     }

    //     for(int helper=0; helper<n; helper++) {
    //         for(int src =0; src<n; src++) {
    //             for(int dest=0; dest<n; dest++) {
    //                 dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
    //             }
    //         }
    //     }

    //     cout << "Printing distance array: " << endl;
    //     for(int i=0; i<n; i++) {
    //         for(int j=0; j<n; j++) {
    //             cout << dist[i][j]<< ", ";
    //         }
    //         cout << endl;
    //     }
        
    // }

    // void bellmanFordAlgo(int n, int src) {
    //     //assuming directed weightted graph
    //     vector<int> dist(n, INT_MAX);
    //     dist[src] = 0;
    //     //n-1 relaxation step
    //     for(int i=0; i<n-1; i++) {
    //         //for all edges
    //         for(auto t: adjList) {
    //             for(auto nbr: t.second) {
    //                 int u = t.first;
    //                 int v = nbr.first;
    //                 int wt = nbr.second;
    //                 if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
    //                     dist[v] = dist[u] + wt;
    //                 }
    //             }
    //         }
    //     }

    //     //to check for -ve cycle
    //     bool negativeCycle = false;
    //     for(auto t: adjList) {
    //             for(auto nbr: t.second) {
    //                 int u = t.first;
    //                 int v = nbr.first;
    //                 int wt = nbr.second;
    //                 if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
    //                     negativeCycle = true;
    //                     break;
    //                 }
    //             }
    //         }

    //     if(negativeCycle == true)
    //         cout << "-ve cycle present";
    //     else
    //         cout << "-ve cycle absent";

    //     cout << "printing dist array: ";
    //     for(auto i : dist)
    //         cout << i << " ";
        
    // }

    // void shortestDistDijkstra(int src, int n) {
    //     vector<int> dist(n,INT_MAX);
    //     set<pair<int,int> > st;
    //     //intiial steps
    //     dist[src] = 0;
    //     st.insert(make_pair(0,src));

    //     while(!st.empty() ) {
    //         //fetch the smallest or first eklement from set
    //         auto topElement = *(st.begin());
    //         int nodeDistance = topElement.first;
    //         int node = topElement.second;

    //         //pop from set
    //         st.erase(st.begin());

    //             //neighbour traverse
    //         for(auto nbr: adjList[node]) {
    //             if(nodeDistance + nbr.second < dist[nbr.first]) {
    //                 //mujhe distance update krna h
    //                 //finding entry in set
    //                 auto result = st.find(make_pair(dist[nbr.first], nbr.first));
    //                 //if found, then remove
    //                 if(result != st.end()) {
    //                     st.erase(result);
    //                 }
    //                 //updation in dist array and set
    //                 dist[nbr.first] = nodeDistance + nbr.second;
    //                 st.insert(make_pair(dist[nbr.first], nbr.first));
    //             }
    //         }
            
    //     }

    //     cout << "printing ans:" << endl;
    //     for(int i=0; i<n; i++) {
    //         cout << dist[i] <<", ";
    //     }cout << endl;
        
    // }

    void dfs1(int src, stack<int>& s, unordered_map<int,bool>& vis) {
        vis[src] = true;

        for(auto nbr: adjList[src]) {
            if(!vis[nbr]) {
                dfs1(nbr, s, vis);
            }
        }
        s.push(src);
    }

    void dfs2(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int> >& adjNew) {
        visited[src] = true;
        cout << src << ", ";

        for(auto nbr: adjNew[src]) {
            if(!visited[nbr] ) {
                dfs2(nbr, visited, adjNew);
            }
        }
    }
    
    int countSCC(int n) {
        stack<int> s;
        unordered_map<int,bool> visited;

        //find topo ordering
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs1(i,s,visited);
            }
        }

        //reverse all edges
        unordered_map<int,list<int> > adjNew;
        
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr;
                //v-> u insert
                adjNew[v].push_back(u);
            }
        }

        //traversse using DFS
        int count = 0;
        unordered_map<int,bool> visited2;

        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!visited2[node]) {
                cout << "Printing "<< count+1 << "th SCC: ";
                dfs2(node,visited2, adjNew);
                cout << endl;
                count++;
            }

            
        }

        

        return count;
    }

    void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool> vis) {

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr: adjList[src]) {
            if(nbr == parent)
                continue;
            if(!vis[nbr]) {
                //dfs call
                findBridges(nbr, src, timer, tin, low, vis);
                //low update
                low[src] = min(low[src], low[nbr]);
                //check for bridge
                if(low[nbr] > low[src]) {
                    cout << nbr<<"--"<<src <<" is a bridge" << endl;
                }
            }
            else{
                //node is visited and not a parent
                //low update
                low[src] = min(low[src], low[nbr]);
            }
        }
        
        
    }



};

int main() {

    graph g;

    g.addEdge(0,1,1);

    g.addEdge(1,2,1);

    g.addEdge(2,0,1);

    g.addEdge(1,6,1);


    g.addEdge(3,1,1);

    g.addEdge(1,4,1);

    g.addEdge(3,5,1);

    g.addEdge(4,5,1);

    // g.addEdge(0,2,1);

    // g.addEdge(2,1,1);

    // g.addEdge(0,3,1);

    // g.addEdge(3,4,1);

    int n = 7;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int,bool> vis;
    g.findBridges(0, -1,timer, tin, low, vis);
    

    
    // g.addEdge(0,1,0);
    
    // g.addEdge(1,2,0);
    
    // g.addEdge(2,3,0);
    
    // g.addEdge(3,0,0);
    
    // g.addEdge(2,4,0);
    
    // g.addEdge(4,5,0);
    
    // g.addEdge(5,6,0);
    
    // g.addEdge(6,4,0);
    
    // g.addEdge(6,7,0);

    // int ans = g.countSCC(8);
    // cout << "Number of SCC: " << ans << endl;
    


    
    // graph g;

    // g.addEdge(0,1,3,0);
    // g.addEdge(0,3,5,0);
    // g.addEdge(1,0,2,0);

    // g.addEdge(1,3,4,0);
    // g.addEdge(2,1,1,0);
    // g.addEdge(3,2,2,0);
    
    // g.addEdge(3,2,5,0);
    // g.addEdge(4,3,-3,0);
    // g.addEdge(3,1,1,0);
    // g.addEdge(6,3,2,1);
    // g.addEdge(6,1,14,1);
    // g.addEdge(3,1,9,1);
    // g.addEdge(3,2,10,1);
    // g.addEdge(1,2,7,1);
    // g.addEdge(2,4,15,1);
    // g.addEdge(4,3,11,1);

    // g.addEdge(6,5,9,1);
    // g.addEdge(4,5,6,1);
 

    // g.printAdjList();
    // g.floydWarshal(4);
    //g.bellmanFordAlgo(5, 0);
    //g.shortestDistDijkstra(0,3);

    // stack<int> topoOrder;
    // unordered_map<int, bool> visited;
    // g.topoSortDfs(0, visited, topoOrder);

    

    // g.shortestpathDfs(3, topoOrder,5);
    
    

    // int src = 0;
    // // int dest = 4;

    // g.shortestPathBfs(src, dest);


    return 0;
}

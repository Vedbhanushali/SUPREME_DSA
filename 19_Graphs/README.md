# Graphs

It is datastructer made up of nodes and edges

- nodes - to store data
- edges - to connect nodes

## Types of graphs

- directed graphs (unidirection edges between nodes)
- undirected graphs (bidirectional edges between nodes)
- weighted graph (when there is number on given on edges) it can be directed or undirected normally directed/undirected graph edges weight is 1

## Degree of node

number of edges connected to node is called degree.

## In degree

in directed graph number of incoming edges to a node is in degree

## out degree

in a directed graph number of outgoing edges to a node is out degree

## path

graph traversal such that all nodes are covered and non of the nodes are visited twice.

## cyclic graph

it contains a closed path/circle (where started from can be reached again)

undirected graph are always cyclic

## Acyclic graph

there is no cicle in graph. (cannot reach start when traversing again)

## Graph implementation

- using adjancency matrix (using 2D array)
- using adjancency list (using map/list/vector)

### Adjancency matrix

n - number of nodes

- create a 2D matrix of n x n
- fill data with 1 (for edge),  0 for (no edge)
- fill 1 if row index has edge with column index node
- example 4 nodes of undirect graph  
0 1 1 0  
1 0 1 0  
1 1 0 0  
0 0 0 0  

### Adjancency list

n - number of nodes

- create n list
- this index of n will represent the node from where you can visit other nodes
- example of directed graph  
0 - {1,2}  
1 - {3,2}  
2 - {3}  
3 - {}  

### weighed adjancency list

- here in list will be storing to node and its weight also
- example of directed graph  
0 - {{1,5},{2,7}}  
1 - {{3,2},{2,3}}  
2 - {{3,8}}  
3 - {}  

## Graph data Structure

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

class Graph {
    public:
        unordered_map<int,list<int>> adjList;

    void addEdge(int u,int v,bool direction) {
        //direction = 0 mean undirected graph
        //direction = 1 mean directed graph
        // u -> v edge
        adjList[u].push_back(v);
        if(direction == 0){
            // mean undirected mean v -> u edge
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second) {
                cout<<neighbour<<", ";
            }cout<<endl;
        }
    }
};

class WeightedGraph {
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdge(int u,int v,int weight,bool direction){
        adjList[u].push_back({v,weight});
        if(direction == 0){
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjacencyList(){
        for(auto node:adjList){
            cout<<node.first<<" -> ";
            for(auto neighbour : node.second){
                cout<<"{"<<neighbour.first<<","<<neighbour.second<<"}, ";
            }
            cout<<endl;
        }
    }
};

//Generic Graph datatype of node on fly
template <typename T>
class GenericGraph {
    public:
        unordered_map<T,list<T>> adjList;

    void addEdge(T u,T v,bool direction) {
        //direction = 0 mean undirected graph
        //direction = 1 mean directed graph
        // u -> v edge
        adjList[u].push_back(v);
        if(direction == 0){
            // mean undirected mean v -> u edge
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second) {
                cout<<neighbour<<", ";
            }cout<<endl;
        }
    }
};
int main() {

    Graph dg;
    //creating a directed graph
    dg.addEdge(0,1,1);
    dg.addEdge(1,2,1);
    dg.addEdge(0,2,1);
    cout<<endl;
    dg.printAdjacencyList();
    
    //creating a undirected graph
    Graph ug;
    ug.addEdge(0,1,0);
    ug.addEdge(1,2,0);
    ug.addEdge(0,2,0);
    cout<<endl;
    ug.printAdjacencyList();

    //creating a weighted undirected graph
    WeightedGraph wug;
    wug.addEdge(0,1,4,0);
    wug.addEdge(1,2,5,0);
    wug.addEdge(0,2,7,0);
    cout<<endl;
    wug.printAdjacencyList();

    //weighted directed graph
    WeightedGraph wdg;
    wdg.addEdge(0,1,4,1);
    wdg.addEdge(1,2,5,1);
    wdg.addEdge(0,2,7,1);
    cout<<endl;
    wdg.printAdjacencyList();


    //Generic graph
    Graph<int> numberGraph;
    numberGraph.addEdge(0,1,0);
    Graph<char> characterGraph;
    characterGraph.addEdge('a','b',0);
    return 0;
}
```

## Graph Traversal

- BFS (Breadth first search)
- DFS (Depth First search)

### BFS & DFS Traversal

- BFS
it is like level order traversal in tree and also need to keep track of visited nodes so that we don't traverse it again

- DFS
It is like inorder, preorder of postorder traversal of tree.

#### Disconnected graph

there may be many graph components in a given graph but they all are considered a single graph know as disconnected graph

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class GenericGraph {
    public:
        unordered_map<T,list<T>> adjList;

    void addEdge(T u,T v,bool direction) {
        //direction = 0 mean undirected graph
        //direction = 1 mean directed graph
        // u -> v edge
        adjList[u].push_back(v);
        if(direction == 0){
            // mean undirected mean v -> u edge
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second) {
                cout<<neighbour<<", ";
            }cout<<endl;
        }
    }
    //bfs for undirected graph
    void bfs(T src,unordered_map<T,bool> &visited;){
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while(!q.emtpy()){
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            //insert neighbours
            for(auto neighbour: adjList[frontNode]){
                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    //dfs for undirected
    void dfs(T src,unordered_map<T,bool>& visited){
        cout<<src;
        visited[src] = true;

        for(auto neighbour:adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour,visited);
            }
        }
    }

};

int main() {
    Graph<int> g;
    int n = 8; //number of nodes
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
    g.printAdjacencyList();
    cout<<endl<<"BFS traversal:"<<endl;
    unordered_map<T,bool> visited;
    for(int i=0;i<n;i++){ //here 7 is number of nodes
        //doing this because there may be a disconnected graph
        if(!visited[i]){
            g.bfs(i,visited);
        }
    }
    cout<<endl<<"DFS traversal:"<<endl;
    unordered_map<T,bool> visited2;
    for(int i=0;i<n;i++){ //here 7 is number of nodes
        //doing this because there may be a disconnected graph
        if(!visited2[i]){
            g.dfs(i,visited2);
        }
    }
    return 0;
}
```

## Cycle detection

Here we need to keep track of parent node list of all nodes. If a node is visited again but it not a parent node then we can say that there is cycle.

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class Graph {
    public:
        unordered_map<T,list<T>> adjList;

    void addEdge(T u,T v,bool direction) {
        //direction = 0 mean undirected graph
        //direction = 1 mean directed graph
        // u -> v edge
        adjList[u].push_back(v);
        if(direction == 0){
            // mean undirected mean v -> u edge
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second) {
                cout<<neighbour<<", ";
            }cout<<endl;
        }
    }

    void bfs(T src,unordered_map<T,bool> &visited;){
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while(!q.emtpy()){
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            //insert neighbours
            for(auto neighbour: adjList[frontNode]){
                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src,unordered_map<T,bool>& visited){
        cout<<src;
        visited[src] = true;

        for(auto neighbour:adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour,visited);
            }
        }
    }

    //uses parent feature to check cycle
    bool checkCyclicUsingBfs(T src,unordered_map<T,bool> &visited) {
        queue<T> q;
        unordered_map<T,T> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1; //if T is int , if char will not work

        while(!q.empty()){
            T frontNode = q.top(); q.pop();
            for(auto neighbour : adjList[frontNode]){
                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour]  =  true;
                    parent[neighbour]  = frontNode;
                } else {
                    if(neighbour != parent[frontNode]) return true;
                }
            }
        }
        return false;
    }

    //uses parent feature to check cycle
    bool checkCyclicUsingDfs(T src,unordered_map<T,bool> &visited,T parent) {
        visited[src] = true;
        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]){
                if(checkCyclicUsingDfs(neighbour,visited,src)) {
                    return true;
                }
            }
            if(visited[neighbour] && neighbour != parent) {
                return true;
            }
        }
        return false;
    }

    //remebers whole dfs path if in current path a node is already visited we conclude cycle
    //here parent method won't work because a -> b <- c is there a and c both are parent but there is not cycle so but parent method concludes cycle as parent of b are not not same on traversal.
    bool checkCyclicDirectedGraphUsingDfs(T src,unordered_map<T,bool> &visited, unordered_map<T,bool>& dfsVisited) {

        visited[src] = true;
        dfsVisited[src] = true;

        for(auto nbr: adjList[src]){
            if(!visited[nbr]){
                if(checkCyclicDirectedGraphUsingDfs(nbr,visited,dfsVisited)){
                    return true;
                }
            } else {
                if(dfsVisited[nbr]){
                    return true;
                }
            }
        }
        dfsVisted[src] = false;
        return false;
    }

    //refer below toposort algorithm for understanding this function
    //cyclic detection for directed graph using BFS
    void topoSortBfs(int n,vector<T> & ans){ // number of nodes
    //It will work for connected as well as disconnected graph
        queue<T> q;
        unordered_map<T,int> indegree;
        for(auto i : adjList) {
            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        //bfs logic
        while(!q.empty()){
            T frontNode =  q.front(); q.pop();
            //here we are push topo sort in ans but in current case only need length of toposort so we can use single variable cnt and increment it. cnt++;
            ans.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

    }
};

int main() {
    Graph<int> g;
    int n = 8; //number of nodes
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);

    bool ans = false;
    unordered_map<T,bool> visited;
    for(int i=0;i<n;i++){ 
        //doing this because there may be a disconnected graph
        if(!visited[i]){
            ans = g.checkCyclicUsingBfs(i,visited);
            if(ans) {
                break;
            }
        }
    }
    if(ans) cout<<"cycle detected";
    else cout<<"No cycle detected";

    ans = false;
    unordered_map<T,bool> visited2;
    for(int i=0;i<n;i++){ 
        //doing this because there may be a disconnected graph
        if(!visited2[i]){
            ans = g.checkCyclicUsingDfs(i,visited2,-1);
            if(ans) {
                break;
            }
        }
    }
    if(ans) cout<<"cycle detected";
    else cout<<"No cycle detected";

    Graph<int> dg;
    int n = 5; //number of nodes
    dg.addEdge(0,1,1);
    dg.addEdge(1,2,1);
    dg.addEdge(2,3,1);
    dg.addEdge(3,4,1);
    dg.addEdge(4,0,1);

    ans = false;
    unordered_map<T,bool> visited3;
    unordered_map<T,bool> dfsVisited;
    for(int i=0;i<n;i++){ 
        //doing this because there may be a disconnected graph
        if(!visited3[i]){
            ans = dg.checkCyclicDirectedGraphUsingDfs(i,visited2,dfsVisited);
            if(ans) {
                break;
            }
        }
    }
    if(ans) cout<<"cycle detected";
    else cout<<"No cycle detected";

    //Cycle detection in directed graph using BFS kahn's algorithm
    vector<int> ans;
    dg.topoSortBfs(8,ans1);
    if(ans.size() == 8){
        cout<<"dg has no cycle"<<endl;
    } else {
        cout<<"dg has cycle"<<endl;
    }
    return 0;
}
```

## Topological sort

It is applicable to only Directed acyclic graph **DAG**,

Topological sort is linear ordering of vertices such that for every edge (u->v) u comes before v in that ordering

Topological sort does not work on cyclic graph because we never find a node whose indegree is 0, and another point to note is that length of topo sort of cyclic graph is less than number of nodes.

### Using DFS and BFS (also know ans kahn's algorithm)

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>

using namespace std;

template <typename T>
class GenericGraph {
    public:
        unordered_map<T,list<T>> adjList;

    void addEdge(T u,T v,bool direction) {
        //direction = 0 mean undirected graph
        //direction = 1 mean directed graph
        // u -> v edge
        adjList[u].push_back(v);
        if(direction == 0){
            // mean undirected mean v -> u edge
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second) {
                cout<<neighbour<<", ";
            }cout<<endl;
        }
    }

    void topoSortDfs(T src,unordered_map<T,bool> &visited,stack<T> &ans) {
        visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                topoSortDfs(nbr,visited,ans);
            }
        }
        //same as dfs just before returning store the src node in stack
        ans.push(src);
    }

    void topoSortBfs(int n,vector<T> & ans){ // number of nodes
    //It will work for connected as well as disconnected graph
        queue<T> q;
        unordered_map<T,int> indegree;
        for(auto i : adjList) {
            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        //bfs logic
        while(!q.empty()){
            T frontNode =  q.front(); q.pop();
            ans.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

    }
};

int main() {
    Graph<int> dg;
    int n = 8; //number of nodes
    dg.addEdge(0,1,1);
    dg.addEdge(1,2,1);
    dg.addEdge(2,3,1);
    dg.addEdge(3,4,1);
    dg.addEdge(3,5,1);
    dg.addEdge(4,6,1);
    dg.addEdge(5,6,1);
    dg.addEdge(6,7,1);

    stack<int> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i])
            dg.topoSortDfs(i,visited,ans);
    }
    cout<<"Topo sort using DFS:"<<endl;
    while(!ans.empty()){
        cout<<ans.top(); ans.pop();
    }

    vector<int> ans;
    dg.topoSortBfs(n,ans);
    cout<<"Topo sort using BFS:"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
```

## Shortest path

when using BFS traversal destination node visited in level is its shortest path
here from parent we can trace the path till src going backwards after bfs traversal is completed.

### using BFS

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        // u -> {v,wt}
        unordered_map<int, list< pair<int,int> > > adjList;

        void addEdge(int u,int v,int wt,bool direction) {
            //direction: 0 - undirected, 1 directed graph
            adjList[u].push_back({v.wt});
            if(direction == 1){
                adjList[v].push_back({u,wt});
            }
        }

        void printAdjList(){
            for(auto i:adjList){
                cout<<i.first<<" --> ";
                for(auto j : i.second) {
                    cout<<"("<<j.first<<","<<j.second<<")"<<endl;
                }
            }
        }

        void shortestPathBfs(int src,int dest){
            queue<int> q;
            unordered_map<int,int> parent;
            unoredered_map<int,bool> visited;

            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while(!q.empty()){
                int frontNode = q.front(); q.pop();
                for(auto nbr:adjList[frontNode]){
                    if(!visited[nbr.first]){
                        q.push(nbr.first);
                        visited[nbr.first] = true;
                        parent[nbr.first] = frontNode;
                    }
                }
            }

            //travering parent to create path
            vector<int> ans;
            int node = dest;
            while(node != -1){
                ans.emplace_back(node);
                node = parent[node];
            }
            reverse(ans.begin(),ans.end());
            cout<<"path is ";
            for(auto i: ans){
                cout<<i<<" ";
            }
        }
};

int main() {
    Graph g;

    g.addEdge(0,1,1,1);
    g.addEdge(1,2,1,1);
    g.addEdge(2,3,1,1);

    g.addEdge(3,4,1,1);
    g.addEdge(0,5,1,1);
    g.addEdge(5,4,1,1);

    g.addEdge(0,6,1,1);
    g.addEdge(6,7,1,1);
    g.addEdge(7,8,1,1);
    g.addEdge(8,4,1,1);

    int src = 0;
    int dest = 4;

    g.shortestPathBfs(src,dest);
    return 0;
}
```

### using DFS / Topological sort

- find topological sort (gives liner ordering in stack use DFS topo sort)
- for each node in stack update the distance array
- initial value of distance array is INT_MAX (infinity)
- this distance array shows to reach this node minimum cost
- one by one from stack take nodes and update their distances

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        // u -> {v,wt}
        unordered_map<int, list< pair<int,int> > > adjList;

        void addEdge(int u,int v,int wt,bool direction) {
            //direction: 0 - undirected, 1 directed graph
            adjList[u].push_back({v.wt});
            if(direction == 1){
                adjList[v].push_back({u,wt});
            }
        }

        void topoSortDfs(T src,unordered_map<T,bool> &visited,stack<T> &ans) {
            visited[src] = true;
            for(auto nbr:adjList[src]){
                if(!visited[nbr.first]){
                    topoSortDfs(nbr.first,visited,ans);
                }
            }
            ans.push(src);
        }
    

    void shortestPathDfs(int &n, int &dest,stack<int> &topoOrder){
        vector<int> dist(n,INT_MAX);
        int src = topoOrder.top(); topoOrder.pop();
        dist[src] = 0;
        for(auto nbr:adjList[src]){
            dist[nbr.first] = min(dist[nbr.first],dist[src] + nbr.second)
        }

        while(!topoOrder.empty()){
            int topEl = topoOrder.top();
            topoOrder.pop();

            if(dist[topEl] != INT_MAX){
                for(auto nbr:adjList[topEl]){
                    dist[nbr.first] = min(dist[nbr.first],dist[topEl] + nbr.second)
                }
            }
        }

        //printing distance array
        for(int i=0;i<n;i++){
            cout<<i<<" -> "<<distance[i]<<endl;
        }
    }
};

int main() {
    Graph g;

    //Directed graph
    int n = 6;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    stack<int> topoOrder;
    unordered_map<int,bool> visited;
    //(start,visited,ans_stack)
    g.topoSortDfs(0,visited,topoOrder);

    //(number_of_nodes,destination,stack)
    g.shortestPathDfs(n,3,topoOrder);
    return 0;
}
```

## Shortest path using Dijkstra algorithm

It is greedy apporach which uses heap or set this both data structure gives sorts based on shortest distance between nodes so.
E - number of edge  
V - number of vertices  
TC - ElogV

approach :

- insert src dist as 0 and insert it in set
- one by one till set gets empty take smallest distance node
- from this node check distance of all neighbour node is less then update in dist array as well set so new reordering happens and we get smallest distance nodes first

```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        // u -> {v,wt}
        unordered_map<int, list< pair<int,int> > > adjList;

        void addEdge(int u,int v,int wt,bool direction) {
            //direction: 0 - undirected, 1 directed graph
            adjList[u].push_back({v.wt});
            if(direction == 1){
                adjList[v].push_back({u,wt});
            }
        }

        void dijkstar(int src,int n,int dest){
            vector<int> dist(n,INT_MAX); 
            set<pair<int,int>> st;
            //initial steps
            dist[src] = 0;
            st.insert(make_pair(0,src));

            while(!st.emtpy()){
                //fetch the smallest or first element form set
                auto topElement = *(st.begin());
                int nodeDistance = topElement.first;
                int node = topElement.second;

                //remove from set 
                st.erase(st.begin());

                //neighbour traverse
                for(auto nbr:adjList[node]){
                    if(nodeDistance + nbr.second < dist[nbr.first]) {
                        //update distance in distance array as well as set
                        //finding entry in set
                        auto result = st.find(make_pair(dist[nbr.first],nbr.first))
                        //if found then remove
                        if(result != st.end()){
                            st.erase(result);
                        }
                        //updation in dist array and set
                        dist[nbr.first] = nodeDistance + nbr.second;
                        st.insert(make_pair(dist[nbr.first],nbr.first));
                    }
                }

                cout<<"Ans : distance from "<<src<<" to "<<dest<<" is " <<dist[dest];
            }
        }
};

int main() {
    Graph g;

    //Directed graph
    int n = 6;
    g.addEdge(6,3,2,0);
    g.addEdge(6,1,14,0);
    g.addEdge(3,1,9,0);
    g.addEdge(3,2,10,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,4,15,0);
    g.addEdge(4,3,11,0);
    g.addEdge(6,5,9,0);
    g.addEdge(4,5,6,0);

    g.dijkstar(6,4,n+1); 
    return 0;
}
```

## Number of provincies

<https://leetcode.com/problems/number-of-provinces/>

approach - using dfs or bfs just need to count number of components of graph

```cpp
class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] && !visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }
    void dfs(int node,vector<vector<int>>& grid,vector<bool>& visited){
        visited[node] = true;
        for(int i=0;i<grid.size();i++){
            if(grid[node][i] == 1 && !visited[i]){
                visited[i] = true;
                dfs(i,grid,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // int n = isConnected.size();
        // int numberOfComponents = 0;
        // vector<bool> visit(n);

        // for (int i = 0; i < n; i++) {
        //     if (!visit[i]) {
        //         numberOfComponents++;
        //         bfs(i, isConnected, visit);
        //     }
        // }

        // return numberOfComponents;
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
};
```

## Number of islands

approach - using dfs exploring all connected islands, (and keeping count of disconnected graph component when explored)

<https://leetcode.com/problems/number-of-islands/>

```cpp
class Solution {
public:
    void solve(int x,int y,vector<vector<char>>&grid){
        //up call
        if(x-1>=0 && grid[x-1][y] == '1'){
            grid[x-1][y] = '0';
            solve(x-1,y,grid);
        }
        //down call
        if(x+1<grid.size() && grid[x+1][y] == '1'){
            grid[x+1][y] = '0';
            solve(x+1,y,grid);
        }
        //left call
        if(y-1>=0 && grid[x][y-1] == '1'){
            grid[x][y-1] = '0';
            solve(x,y-1,grid);
        }
        //right call
        if(y+1<grid[0].size() && grid[x][y+1] == '1'){
            grid[x][y+1] = '0';
            solve(x,y+1,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    solve(i,j,grid);
                }
            }
        }
        return ans;
    }
};
```

## Flood fill

approach - it is dfs approach marking all connected nodes to given color

<https://leetcode.com/problems/flood-fill/>

```cpp
class Solution {
public:
    void solve(vector<vector<int>>&image,int &mainColor,int& color,int x,int y,vector<vector<bool>>&visited){
        //left
        image[x][y] = color;
        if(y-1>=0 && image[x][y-1] == mainColor && !visited[x][y-1]){
            visited[x][y-1] = true;
            solve(image,mainColor,color,x,y-1,visited);
        }
        //right
        if(y+1<image[0].size() && image[x][y+1] == mainColor && !visited[x][y+1]){
            visited[x][y+1] = true;
            solve(image,mainColor,color,x,y+1,visited);
        }
        //bottom
         if(x+1<image.size() && image[x+1][y] == mainColor && !visited[x+1][y]){
            visited[x+1][y] = true;
            solve(image,mainColor,color,x+1,y,visited);
        }
        //up
        if(x-1>=0 && image[x-1][y] == mainColor && !visited[x-1][y]){
            visited[x-1][y] = true;
            solve(image,mainColor,color,x-1,y,visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y,int color) {
        int mainColor = image[x][y];
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(),false));
        solve(image,mainColor,color,x,y,visited);
        return image;
    }
};
```

## Rotting oranges

<https://leetcode.com/problems/rotting-oranges/>

approach - bfs algorithm such a way need to find how much deep level can go that is answer that much minimum time it will take to rot all oranges

```cpp
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        //bfs approach and level is ans
        queue<pair<int,pair<int,int>>> q; //level is also stored

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
            }
        }
        
        int ans = 0;
        //x and y = 2 is already visited
        
        while(!q.empty()){
            auto currNode = q.front();
            q.pop();
            int level = currNode.first;
            ans = max(ans,level);
            int x = currNode.second.first;
            int y = currNode.second.second;
            //up
            if(x - 1 >=0 && grid[x-1][y] == 1) {
                grid[x-1][y] = 2; //visited
                q.push({level+1,{x-1,y}});
            }
            //down
            if(x+1 <grid.size() && grid[x+1][y] == 1){
                grid[x+1][y] = 2;
                q.push({level+1,{x+1,y}});
            }
            //left
            if(y-1>=0 && grid[x][y-1] == 1){
                grid[x][y-1] = 2;
                q.push({level+1,{x,y-1}});
            }
            //right
            if(y+1<grid[0].size() && grid[x][y+1] == 1){
                grid[x][y+1] = 2;
                q.push({level+1,{x,y+1}});
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};
```

## Course schedule

topoplogical sort question

<https://leetcode.com/problems/course-schedule/>

```cpp
class Solution {
private:
    bool topoSortBfs(int n,unordered_map<int,list<int>> &adjList){
        vector<int> ans;
        unordered_map<int,int> indegree;
        queue<int> q;

        //indegree calculate
        for(auto i : adjList) {
            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }
        //BFS
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int frontNode =  q.front(); q.pop();
            ans.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return ans.size() == n;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,list<int>> adjList;
        for(auto task : pre){
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }
        //Application of toposort if able to find topo sort correct then all courses can be done
        //condition course lenght == toposort length
        return topoSortBfs(numCourses,adjList);
    }
};
```

## Course Schedule II

Same as course schedule above only need to send topo sort path
<https://leetcode.com/problems/course-schedule-ii/description/>

```cpp
class Solution {
    private:
    vector<int> topoSortBfs(int n,unordered_map<int,list<int>> &adjList){
        vector<int> ans;
        unordered_map<int,int> indegree;
        queue<int> q;

        //indegree calculate
        for(auto i : adjList) {
            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }
        //BFS
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int frontNode =  q.front(); q.pop();
            ans.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size() == n){
            return ans;
        } else {
            return {};
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,list<int>> adjList;
        for(auto task : pre){
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }
        //Application of toposort if able to find topo sort correct then all courses can be done
        //condition course lenght == toposort length
        return topoSortBfs(numCourses,adjList);
    }
};
```

## Word ladder

application - shortest path finding using BFS

<https://leetcode.com/problems/word-ladder/>

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //using bfs shortest path
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end()); //act as visited array
        //difference is that visited will be removed from the set
        //word inserted in queue will be removed from set
        while(!q.empty()){
            pair<string,int> fnode = q.front(); q.pop();
            string currString = fnode.first;
            int level = fnode.second;

            //check if it is destination word
            if(currString == endWord) return level;

            for(int index = 0;index<currString.length();index++){
                //replacing index values with a to z
                char originalChar = currString[index];
                for(char ch = 'a';ch<='z';ch++){
                    currString[index] = ch;
                    //check new word in wordlist
                    if(st.find(currString)!=st.end()){
                        //found
                        q.push({currString,level+1});
                        st.erase(currString);
                    }
                }
                //bringing back the original string
                currString[index] = originalChar;
            }
        }
        return 0;
    }
};
```

## Path With Minimum Effort

approach - Dijkstar algorithm using priority queue

<https://leetcode.com/problems/path-with-minimum-effort/submissions/1258696482/>

```cpp

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(),INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto fNode = pq.top();
            pq.pop();
            int frontNodeDifference = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;

            //check if not reached ans
            if(x ==  heights.size() -1 && y == heights[0].size() - 1){
                return dist[x][y];
            }

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >=0 && newY>=0 && newX < heights.size() && newY < heights[0].size()){
                    int currDiff = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDifference,currDiff);
                    if(newMax < dist[newX][newY]) {
                        dist[newX][newY] = newMax;
                        pq.push({newMax,{newX,newY}});
                    }
                }
            }
        }
        return 0;
    }
};

```

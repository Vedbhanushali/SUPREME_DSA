# Graphs

it is datastructer made up of nodes and edges

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
-example 4 nodes of undirect grap
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

there may be many graph components but they all are considered a single graph which is know as disconnected graph

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



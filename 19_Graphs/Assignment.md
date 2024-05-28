# Assignment

## Prim's Algorithm

Used to find minimum spanning tree, it does by building tree from scratch. it contains three data structure ( key, MST, parent)

- key: contains value of each node
- MST: tracks which node has been included in MST as of now
- parent: stores final structure of MST.

### Spanning Tree

(removes edges from graph to convert it into tree)
minimum spanning tree (from all possible subsets of spanning tree whoes edges weights sum is minimum is minimum spanning tree)

- convert a graph to a tree (no cycle)
- in tree, every node should be reachable by every other node
- Tree would have n nodes and n-1 nodes

steps -

1. key vector initial value (0,infi,infi,...)
2. mst vector initial value (false, false, false,...)
3. parent vector initial value (-1,-1,-1,...)
4. find min value node from key ( that node should be out of MST mst[u] = false) let it be u and MST[u] = true
5. get all adjacent of u , let v = adj node and w = weight of adjNode and if(mst[v] == F && w<key[v]) {
    key[v] = w;
    parent[v] = u;
}

```cpp
//V is number of Vertices in graph
int getMinValueNode(vector<int>&key,vector<int>&mst){
    int temp = INT_MAX;
    int index = -1; //node having min value
    for(int i=0;i<key.size();i++){
        if(key[i] < temp && mst[i] == false){
            temp  = key[i];
            index = i;
        }
    }
    return index; //index represent node
}
int spanningTree(int V,vector<vector<int>> adj[]){
    //prims algorithm
    vector<int> key(V,INT_MAX);
    key[0] = 0;
    vector<int> mst(V,false);
    vector<int> parent(V,-1);
    while(true){
        //step 1 get minimum value node
        int u = getMinValueNode(key,mst);
        //base case
        if(u == -1){
            //mean all nodes are traversed in mst
            break;
        }
        //step mst u true
        mst[u] = true;

        //process adj node
        for(auto edge : adj[u]){
            int v = edge[0];
            int w = edge[1];
            if(mst[v] == false && wt < key[v]){
                key[v] = wt;
                parent[v] = u;
            }
        }
    }

    //find sum weights of the edges of MST
    int sum = 0;
    for(int u=0;u<parent.size();u++){
        if(parent[u] == -1) continue;
        for(auto edge : adj[u]){
            int v = edge[0];
            int wt = edge[1];
            if(parent[u] == v) {
                sum +=w;
            }
        }
    }
    return sum;
}
```

## Kruskal's Algorithm

used to find minimum spanning tree. approach is using disjoint set, disjoint set is way to find whether two nodes are in same component or not.
two type of operation can be done on disjoint set

1. findParent or findSet (both are same)
2. union()

Union

- all component are parent of itselt at starting
- when two component are union which have more rank (more element) will become parent when both have same rank any one can became parent of that union.

### algorithm

- uses linear DS which stores all edges in form of [u,v,w]
- parent vector (initial values pointing to itself mean num[index] = index)
- rank vector (initial value 0)
- sort edges based on weights
- find lowest weight edge will get u and v
- find parent of u and v (p1 != p2 both are in different component then need to union else ignore)
- in union process (make parent who rank is higher and also increase its rank again)

## Eventual Safe States

## Word Ladder-2

## Minimum Multiplications to reach End

## Number of Operations to Make Network Connected

## Find the City With the Smallest Number of Neighbours at a Threshold Distance

## Accounts Merge

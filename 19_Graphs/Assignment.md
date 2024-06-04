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

```cpp
static bool mycmp(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}
int findParent(vector<int>&parent,int node){
    if(parent[node] == node){
        return node;
    }
    //actually it is
    // return findParent(parent,parent[node]);
    //but applying DP or path compression to get faster results
    return parent[node] = findParent(parent,parent[node]); //path compression
}
void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
    u = findParent(parent,u);
    v = findparent(parent,v);
    if(rank[u] < rant[v]){
        //u will be added in v
        parent[u] = v;
        rank[v]++;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}
int spanningTree(int V,vector<vector<int>>adj[]){
    vector<int> parent(V);
    vector<int> rank(V,0);
    for(int u=0;u<V;u++){
        parent[u] = u;
    }
    
    //creating linear DS of edges of graph
    vector<vector<int>>edges;
    for(int u=0;u<V;u++){
        for(auto edge:adj[u]){
            int v = edge[0];
            int w = edge[1];
            edges.push_back({u,v,w});
        }
    }
    //sorting edges
    sort(edges.begin(),edges.end(),mycmp);

    int ans = 0;
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            unionSet(u,v,parent,rank);
            ans += w; //here in union we are uniont parent 
        }
    }
    return ans;
}
```

## Eventual Safe States

approach cycle detection

```cpp
bool cycleDetection(vector<int> adj[],int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,vector<bool>&safeNode){
    visited[src] = true;
    dfsVisited[src] = true;
    safeNode[src] = false;
    for(auto nbr:adj[src]){
        if(visited[nbr] && dfsVisited[nbr]){       
            //cycle found
            return true; 
        }
        if(!visited[nbr]){
            //need to explore it
            if(cycleDetection(adj,nbr,visited,dfsVisited)) return true; 
        }
    }
    dfsVisited[src] = false; 
    safeNode[src] = true;
    return false;
}
vector<int> eventualSafeNodes(int V,vector<int>adj[]){
    vector<int> ans;
    unordered_map<int,bool> visited, dfsVisited;
    vector<bool> safeNode(V);
    for(int i =0;i<V;i++){
        if(!visited[i])
            cycleDetection(adj,i,visited,dfsVisited,safeNode);
    }
    for(int i=0;i<V;i++){
        if(safeNode[i]){
            ans.push_back(i);
        }
    } 
    return ans;
}
```

## Word Ladder-2

approach bfs to find shortest path (also storing all that shortest path of that level)

```cpp
vector<vector<string>> findSequence(string beginWord,string endWord,vector<string>&wordList){
    vector<vector<string>> ans;
    //here as per word ladder we were only storing pair string,int (current latest and level), but here storing vector<string> which contains the whole path traversed.
    queue<pair<vector<string>,int>>q;
    q.push({{beginWord},1});
    unordered_set<string> st(wordList,begin(),wordList.end());
    int prevLevel = -1;
    vector<string>toBeRemoved; //removing from set after completion of currentLevel
    while(!q.empty()){
        pair<vector<string>,int> frontNode = q.front(); q.pop();

        vector<string> currSeq = frontNode.first;
        string currString = currSeq[currSeq.size()-1];
        int currLevel = frontNode.second;

        if(currLevel != prevLevel){
            for(auto s : toBeRemoved){
                st.erase(s);
            }
            toBeRemoved.clear();
            prevLevel = currLevel;
        }
        
        if(currString == endWord){
            ans.push_back(currSeq);
        }

        for(int index=0;index<currString.length();index++){
            char OriginalChar = currString[index];
            for(char ch = 'a';ch<='z';ch++){
                currString[index] = ch;
                if(st.find(currString)!=st.end()){
                    auto temp = currSeq;
                    temp.push_back(currString);
                    q.push({temp,currLevel+1});
                    toBeRemoved.push_back(currString);
                }
            }
            currString[index] = originalChar;
        }
    }
    return ans;
}
```

## Minimum Multiplications to reach End

approach - bfs to find shortest path

```cpp
int minimumMultiplications(vector<int>&arr,int start,int end){
    //bfs
    queue<int> q;
    const int mod = 100000;
    vector<int> ans(100000,-1); //will also work as visited array in bfs and it stores steps of bfs level
    ans[start] = 0;
    q.push(start);
    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(front == end){
            return ans[front];
        }

        for(auto i: arr){
            int newNode = (i * frontNode)%mod;
            if(ans[newNode] == -1){
                ans[newNode] = ans[front] + 1;
                q.push(newNode);
            }
        }
    }
    return -1;
}
```

## Number of Operations to Make Network Connected

<https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/>

approach - kruskal's algorithm (disjoint set union to get minimum edges required to joined disjoined component of graph)

steps

- A way to find number of connected components let it be n then will require n-1 edges to connect all disconnected component of graph
- A way to find extra edges (n-1) from connected nodes such that it's removal doesn't increase diconnected component.

```cpp

```

## Find the City With the Smallest Number of Neighbours at a Threshold Distance

## Accounts Merge

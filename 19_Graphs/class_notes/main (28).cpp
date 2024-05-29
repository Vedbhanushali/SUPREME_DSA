#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;
template <typename T>
class Graph {
public:
	unordered_map<T, list<T > > adjList;

	void addEdge(T u, T v, bool direction) {
		//direction = 0 -> undirected graph
		//direction = 1 -> directed graph
		//create an edge from u to v
		adjList[u].push_back(v);
		if(direction == 0)
		{
			//undirected edge
			//create an edge from v to u
			adjList[v].push_back(u);
		}
	}

	void printAdjacencyList() {
		for(auto node: adjList) {
			cout << node.first << "-> " ;
			for(auto neighbour: node.second) {
				cout <<neighbour<<", ";
			}
			cout << endl;
		}
	}

	void bfs(int src, unordered_map<int, bool>& visited) {
		queue<int> q;
		
		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			int frontNode= q.front();
			q.pop();
			cout << frontNode << ", ";

			//insert neighbours
			for(auto neighbour: adjList[frontNode]) {
				if(!visited[neighbour] ) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void dfs(int src, unordered_map<int, bool>& visited) {
		cout << src << ", ";
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour] ) {
				dfs(neighbour, visited);
			}
		}
	}


	void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour] ) {
				topoSortDfs(neighbour, visited, ans);
			}
		}

		//while returning, store the node in stack
		ans.push(src);
	}

	void topoSortBfs(int n, vector<int>& ans) {
		queue<int> q;
		unordered_map<int, int> indegree;

		//indegree calculate
		for(auto i: adjList ) {
			int src = i.first;
			for(auto nbr:i.second) {
				indegree[nbr]++;
			}
		}

		//put all nodes inside queue, which has indegree=0
		for(int i=0; i<n; i++) {
			if(indegree[i] == 0) {
				q.push(i);
			}
		}

		//bfs logic
		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			ans.push_back(fNode);
			//or we can do count++

			for(auto nbr: adjList[fNode]) {
				indegree[nbr]--;
				//check for zero again
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}	
			}
			
		}
		
	}


};

// class Graph {
// public:
// 	unordered_map<int, list<pair<int,int> > > adjList;

// 	void addEdge(int u, int v,int weight, bool direction) {
// 		//direction = 0 -> undirected graph
// 		//direction = 1 -> directed graph
// 		//create an edge from u to v
// 		adjList[u].push_back({v,weight});
// 		if(direction == 0)
// 		{
// 			//undirected edge
// 			//create an edge from v to u
// 			adjList[v].push_back({u,weight});
// 		}
// 	}

// 	void printAdjacencyList() {
// 		for(auto node: adjList) {
// 			cout << node.first << "-> " ;
// 			for(auto neighbour: node.second) {
// 				cout <<"("<<neighbour.first<<","<<neighbour.second<<"), ";
// 			}
// 			cout << endl;
// 		}
// 	}


// };



int main() {

	Graph<int> g;
	//n -> number of nodes in graph
	int n = 8;
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,1,1);

	// g.addEdge(3,7,1);
	// g.addEdge(6,7,1);
	// g.addEdge(7,0,1);
	// g.addEdge(7,1,1);

	g.printAdjacencyList();
	cout << endl;

	vector<int> ans;
	//connected or disconnected 
	g.topoSortBfs(n, ans);

	if(ans.size() == n) {
		cout << "It is a valid topo sort" << endl;
	}
	else {
		cout << "Cycle Present or Invalid topo sort " << endl;
	}

	
	cout << "Printing Topological Sort using BFS: " << endl;
	for(auto i: ans) {
		cout << i << ", ";
	}cout << endl;

	

	// unordered_map<int,bool> visited;
	// stack<int> ans;
	// for(int i=0; i<n; i++) {
	// 	if(!visited[i] ){
	// 		g.topoSortDfs(i,visited,ans);
	// 	}
	// }

	// cout << "Top Sort: " << endl;
	// while(!ans.empty()) {
	// 	cout << ans.top();
	// 	ans.pop();
	// }

	// unordered_map<int, bool> visited;
	// //run a loop for all nodes
	// cout << "Printing BFS Traversal: " << endl;
	// for(int i=0; i<n; i++) {
	// 	if(!visited[i]) {
	// 		g.bfs(i, visited);
	// 	}
	// }
	// cout << endl << "Printing DFS Traversal: " << endl;
	// unordered_map<int, bool> visited2;
	// for(int i=0; i<n; i++) {
	// 	if(!visited2[i]) {
	// 		g.dfs(i, visited2);
	// 	}
	// }

	// Graph<char> g;
	// g.addEdge('a','b', 0);
	// g.addEdge('b', 'c', 0);
	// g.addEdge('a', 'c', 0);
	// g.printAdjacencyList();

	

	//directed input
	//g.addEdge(srcNode, destNode, weight, direction);
	// g.addEdge(0,1,5,1);
	// g.addEdge(1,2,8,1);
	// g.addEdge(0,2,6,1);
	// cout << endl;
	// g.printAdjacencyList();

	//undirected edge input
	// g.addEdge(0,1,0);
	// g.addEdge(1,2,0);
	// g.addEdge(0,2,0);
	// cout << endl;
	// g.printAdjacencyList();

	
	// int n;
	// cout << "Enter the number of nodes: " << endl;
	// cin >> n;


	// int e;
	// cout << "Enter the number of edges: " << endl;
	// cin >> e;

	// //undirected graph
	




	
	// int n;
	// cout << "Enter the number of nodes: " << endl;
	// cin >> n;

	// vector<vector<int> > adj(n, vector<int>(n,0));

	// int e;
	// cout << "Enter the number of edges: " << endl;
	// cin >> e;
	
	// for(int i=0; i<e; i ++) {
	// 	int u,v;
	// 	cin >> u >> v;
	// 	//mark 1
	// 	adj[u][v] = 1;
	// }

	// //printing
	// for(int i=0; i<n; i++) {
	// 	for(int j =0; j<n; j++) {
	// 		cout << adj[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	



	return 0;
}
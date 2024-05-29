#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
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

	bool checkCyclicUsingBfs(int src, unordered_map<int,bool>& visited) {
		queue<int> q;
		unordered_map<int,int> parent;
		
		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();

			for(auto nbr: adjList[frontNode]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr]=frontNode;
				}
				if(visited[nbr] && nbr != parent[frontNode]) {
						//cycle present
						return true;
				}
			}
		}
		return false;
	}

	bool checkCyclicUsingDfs(int src, unordered_map<int,bool>& visited, int parent) {
		visited[src] = true;

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src);
				if(checkAageKaAns == true)
					return true;
			}
			if(visited[nbr] && nbr != parent) {
				//cycle present
				return true;
			}
		}
		return false;
	}

	bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int,bool>& visited,
unordered_map<int,bool> dfsVisited) {

		visited[src] = true;
		dfsVisited[src] = true;

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
				if(aageKaAnswer == true)
					return true;
			}
			if(visited[nbr] == true && dfsVisited[nbr] == true) {
				return true;
			}
		}
		//yaha hi galti hoti h 
		dfsVisited[src] = false;
		return false;
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
	int n = 5;
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);
	g.addEdge(4,0,1);

	g.printAdjacencyList();
	cout << endl;

	bool ans = false;
	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisited;
	for(int i=0; i<n; i++) {
		if(!visited[i] ) {
			ans = g.checkCyclicDirectedGraphUsingDfs(i,visited,dfsVisited);
			if(ans == true)
				break;
		}
	}

	if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;

	// bool ans = false;
	// unordered_map<int, bool> visited;
	// for(int i=0; i<n; i++) {
	// 	if(!visited[i]) {
	// 		 ans = g.checkCyclicUsingBfs(i,visited);
	// 		if(ans == true)
	// 			break;
	// 	}
	// }

	// if(ans == true) 
	// 	cout << "Cycle is Present" << endl;
	// else
	// 	cout << "Cycle Absent" << endl;


	// bool ansDfs = false;
	// unordered_map<int, bool> visitedDfs;
	// for(int i=0; i<n; i++) {
	// 	if(!visitedDfs[i]) {
	// 		 ansDfs = g.checkCyclicUsingDfs(i,visitedDfs, -1);
	// 		if(ansDfs == true)
	// 			break;
	// 	}
	// }

	// if(ansDfs == true) 
	// 	cout << "Cycle is Present" << endl;
	// else
	// 	cout << "Cycle Absent" << endl;

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
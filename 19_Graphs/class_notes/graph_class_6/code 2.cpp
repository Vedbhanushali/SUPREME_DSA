class Solution {
private:
  vector<int> topoSortBfs(int n, unordered_map<int,list<int> >& adjList) {
    vector<int> ans;
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

    if(ans.size() == n) {
      //valid topo sort
      return ans;
    }
    else {
      //invalid
      return {};
    }
    
  }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adjList;
        //build adjacency list
        for(auto task: prerequisites) {
          int u = task[0];
          int v = task[1];
          adjList[v].push_back(u);
        }

        vector<int> ans = topoSortBfs(numCourses, adjList);
        return ans;
    }
};
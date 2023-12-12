# Heap Assignment

## Check if tree is a heap

<https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1>

### approach -

1. check if is complete binary tree, by find total number of nodes and for each node of tree check if any child node number is greater then total number of nodes
2. if CBT check max heap property

```cpp
class Solution {
  public:
    pair<int,bool> heapProp(struct Node* root){
        if(root == NULL) {
            return make_pair(INT_MIN,true);
        }
        auto left = heapProp(root->left);
        auto right = heapProp(root->right);
        
        bool valid = left.second && right.second;
        valid = valid & ((root->data > left.first) && (root->data > right.first));
        return make_pair(root->data,valid);
    }
    int countNodes(struct Node* root){
        if(root == NULL) return 0;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left+right+1;
    }
    bool isCBT(struct Node* root,int i,int &n){
        if(!root) return true;
        if(i > n) return false;
        return isCBT(root->left, 2*i,n) && isCBT(root->right,2*i+1,n);
    }
    bool isHeap(struct Node* root) {
        // code here
        //finding nodes
        int n = countNodes(root);
        //checking completeness
        int i = 1;
        if(isCBT(root,i,n)){
            //checking heap property
            return heapProp(root).second;    
        }
        return false;
    }
};
```

## Merge 2 Max Heaps

<https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1>

### approach

1. merge two heap vectors
2. lets heapify the concatenated vector

```cpp

class Solution{
    public:
    void heapify(vector<int>&c,int i,int &n){
        while(true){
            int left = 2*i + 1;
            int right = 2*i +2;
            int swapIndex = i;
            if(left < n && c[swapIndex] < c[left]){
                swapIndex = left;
            }
            if(right < n && c[swapIndex] < c[right]){
                swapIndex = right;
            }
            if(swapIndex == i) break;
            swap(c[swapIndex],c[i]);
            i = swapIndex;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> c(a.begin(),a.end());
        c.insert(c.end(),b.begin(),b.end());
        int s = c.size();
        
        for(int i=(s/2)-1;i>=0;i--){
            heapify(c,i,s);
        }
        return c;
    }
};
```

## K Closest Point to Origin

<https://leetcode.com/problems/k-closest-points-to-origin/description/>

```cpp
class point {
    public:
    int x;
    int y;
    double dist;
    point(int x,int y){
        this->x = x;
        this->y = y;
        dist = sqrt(x*x + y*y);
    }
};
class comp {
    public:
    bool operator()(point &a,point &b){
       return a.dist < b.dist;//maxHeap
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // closed mean dist is minimum
        priority_queue<point,vector<point>,comp > maxHeap;
        for(int i=0;i<k;i++){
            // cout<<points[i][0]<<" "<<points[i][1]<<endl;
            maxHeap.push(point(points[i][0],points[i][1]));
        }
        vector<vector<int> > answer(k);
        // cout<<maxHeap.top().x<<" "<<maxHeap.top().y<<" "<<maxHeap.top().dist;
        for(int i=k;i<points.size();i++){
            point temp(points[i][0],points[i][1]);
            if(maxHeap.top().dist > temp.dist){
                maxHeap.pop();
                maxHeap.push(temp);
            }
        }
        for(int i=0;i<k;i++){
            vector<int> tempVect(2);
            point temp = maxHeap.top(); maxHeap.pop();
            tempVect[0] = temp.x ;
            tempVect[1] = temp.y ;
            answer[i] = tempVect;
        }
        return answer;
    }
};
```

## Sliding Window Maximum

<https://leetcode.com/problems/sliding-window-maximum/>

```cpp
class point {
    public:
    int data;
    int index;
    point(int x,int y){
        this->data = x;
        this->index = y;
    }
};
class comp {
    public:
    bool operator()(point &a,point &b){
       return a.data < b.data;//maxHeap
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<point,vector<point>,comp > maxHeap;
        for(int i=0;i<k;i++){
            maxHeap.push(point(nums[i],i));
        }
        vector<int> answer;
        answer.emplace_back(maxHeap.top().data);
        for(int i=k;i<nums.size();i++){
            maxHeap.push(point(nums[i],i));
            while(maxHeap.top().index <= i-k){
                maxHeap.pop();
            }
            answer.emplace_back(maxHeap.top().data);
        }
        return answer;
    }
};
```

## Get Biggest three rhombus sums in a grid

<https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/>

```cpp
 class Solution {
public:
    bool checkBound(vector<vector<int> >&grid,vector<pair<int,int> > &v){
        int m = grid.size();
        int n = grid[0].size();
        for(auto pt:v){
            if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n){
                return false;
            }
        }
        return true;
    }
    bool getAllVertices(vector<vector<int>>& grid,vector<pair<int,int> > &v,int &cx,int &cy,int &delta){
        pair<int,int> A(cx-delta,cy);
        pair<int,int> B(cx,cy+delta);
        pair<int,int> C(cx+delta,cy);
        pair<int,int> D(cx,cy-delta);
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;
        return checkBound(grid,v);
    }
    void getAllSum(vector<vector<int>>& grid,int &cx,int &cy,priority_queue<int>& pq){
        //push zero area current point rhonmbus value
        pq.push(grid[cx][cy]);
        int delta = 1;
        vector<pair<int,int> > v(4);
        while(getAllVertices(grid,v,cx,cy,delta)){
            pair<int,int>&A = v[0];
            pair<int,int>&B = v[1];
            pair<int,int>&C = v[2];
            pair<int,int>&D = v[3];
            //calculating vertices points
            int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];
            //calculating edges between vertices
            //btw AB
            for(int i=1;i<(B.first-A.first);i++){
                csum += grid[A.first+i][A.second+i];
            }
            //btw BC
            for(int i=1;i<(C.first-B.first);i++){
                csum += grid[B.first+i][B.second-i];
            }
            //btw CD
            for(int i=1;i<(C.first-D.first);i++){
                csum += grid[C.first-i][C.second-i];
            }
            //btw AD
            for(int i=1;i<(D.first-A.first);i++){
                csum += grid[D.first-i][D.second+i];
            }
            pq.push(csum);
            delta++;
            //    A
            // D     B
            //    C
        }

    }
    bool checkRep(vector<int> &ans,int &top){
        for(auto i:ans){
            if(i == top) return true;
        }
        return false;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        priority_queue<int>pq;
        int m =grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                getAllSum(grid,i,j,pq);
            }
        }

        while(!pq.empty() && ans.size()<3){
            int top = pq.top();
            pq.pop();
            if(!checkRep(ans,top)){
                ans.emplace_back(top);
            }
        }
        return ans;

    }
};
```

## Min Diff in Sum after element removal

<https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/>

approach  
will pick n elements from front and n elements from back such a way that sum_for - sum_back is minimum  
task sum_pre - sum_suf minimum so minimize prefix  and maximize suffix
prefix - sum of first n min elements from left
sufix -  sum of last n max elements from right

```cpp
class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<ll> prefix(nums.size(),-1), suffix(nums.size(),-1);
        //prefix - sum of n elements from left side
        //suffix - sum of n elements from right side

        ll sum = 0; // min n elements sum
        priority_queue<ll> pq; //max heap
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            pq.push(nums[i]);
            if(pq.size() > n) {
                sum = sum - pq.top();
                pq.pop();
            }
            if(pq.size() == n){
                prefix[i] = sum;
            }
        }

        sum = 0; // max n elements sum
        priority_queue<ll,vector<ll>,greater<ll>> pq2; //min heap
        for(int i=nums.size()-1;i>=0;i--){
            sum += nums[i];
            pq2.push(nums[i]);
            if(pq2.size() > n) {
                sum = sum - pq2.top();
                pq2.pop();
            }
            if(pq2.size() == n){
                suffix[i] = sum;
            }
        }
        ll ans = LONG_LONG_MAX;
        for(int i = n-1;i<2*n;i++){
            ans = min(ans,prefix[i]-suffix[i+1]);
        }
        return ans;
    }
};
```

## Min number of refuelling stops

<https://leetcode.com/problems/minimum-number-of-refueling-stops/>

```cpp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int,int>> pq; // {fuel,pos}
        while(true){

            while( i < stations.size()) {
              //push stations within the reach with my current fuel levels from my current pos  
              if(stations[i][0] <= dist + fuel){
                  pq.push({stations[i][1],stations[i][0]});
              } else {
                  break;
              }
              ++i;
            }

            //travel with full fuel level
            dist += fuel;
            fuel = 0;

            //reached
            if(dist >= target) break;

            //no fuel stations within reach
            if(pq.empty()){
                stops = -1;
                break;
            }

            //refuel ans re-adjust dist and fuel based on distance travelled 
            auto& top = pq.top();
            fuel = (dist - top.second) + top.first;
            dist = top.second;
            pq.pop();
            ++stops;
        }
        return stops;
    }
};
```

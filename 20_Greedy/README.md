# Greedy approach

this approach uses sorting, min/max, priority queue, set, hashMap...

## arrival time of train

given arrival and departure of trains and there is one platform shedule maximum trains in that one platform

```cpp
bool comp(pair<int,int> &a,pair<int,int> &b){
    return a.second > b.second;
}
int solve(int n,int arr[],int dep[]){
    vector<pair<int,int>> data;
    for(int i=0;i<n;i++){
        data.push_back({arr[i],dep[i]});
    }
    sort(data.begin(),data.end(),comp);

    int cnt = 1;
    int lastDep = data[0].second;
    for(int i = 1;i < n;i++){
        if(data[i].first >= lastDep){
            //current train can be included
            cnt++;
            lastDep = data[i].second;
        }
    }
    return cnt;
}
int main(){
    int n = 4;
    int arr[] = {5,8,2,4};
    int dep[] = {7,11,6,5};

    int ans = solve(n,arr,dept);
}
```

## Lollipop  

given prices of lollipop and buying one lollipop any 2 lollipop is free. solve that this 2 free lollipop price is maximum.

```cpp
int main(){
    vector<int> prices = {2,3,5,6,7,8,1,9};
    sort(prices.beign(),prices.end());
    int buy = 0;
    int free = prices.size() - 1;
    int cost = 0;
    while(buy <= free){
        cost += prices[buy];
        if(free <= buy) break;
        cost += prices[free];
        free--;
        if(free <= buy) break;
        cost += prices[free];
        free--;
        buy++;
    }
}
```

## DEFKIN

<https://www.spoj.com/problems/DEFKIN/>

```cpp
int main() {
    int x,y,n;
    cin>>x>>y>>n;
    int t = n;
    vector<int> rowC;
    vector<int> colC;
    //grid following 1 based indexing
    rowC.push_back(0); // | | |x | | for row 1 x at index 3 there is not left filled so manually adding 0 for finding width
    colC.push_back(0);

    while(t--){
        int a,b;
        cin>>a>>b;
        rowC.push_back(a);
        colC.push_back(b);
    }

    //simlarly for last element filleing right and bottom for col and row respectively for finding width
    rowC.push_back(x);
    colC.push_back(y);

    sort(rowC.begin(),rowC.end());
    sort(colC.begin(),colC.end());

    int maxLen = INT_MIN;
    for(int i=1;i<rowC.size();i++){
        int a = rowC[i-1];
        int b = rowC[i];

        maxLen = max(maxLen,b-a-1);
    }

    int maxWid = INT_MIN;
    for(int i=1;i<colC.size();i+++){
        int a = colC[i-1];
        int b = colC[i];

        maxWid = max(maxWid,b-a+1);
    }

    cout<<"ans "<<maxLen * maxWid;
    return 0;
}
```

## Min cost of ropes

multiple pieces of ropes with cost, joining both ropes cost their price addition, joining all ropes how much it will cost.

ex -
[4,3,2,6]  (3,2) (5)  
[4,5,6]    (4,5) (9)  
[9,6]            (15)  

total cost - 5 + 9 + 15 = 29

```cpp
int main() {
    priority_queue<int,vector<int>,greater<int>> minHeap;
    vector<int> costs = {4,3,2,6};
    for(int i : costs) {
        minHeap.push(i);
    }
    int ans  = 0;
    while(minHeap.size() != 1 ){
        //mean there is atleast two elements in heap
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        ans += a + b;
        minHeap.push(a+b);
    } 
    cout<<"ans "<<ans;
    return 0;
}
```

## HuffMan encoding

TODO

## Fractional knapsack

given value and weight array and given capacity chose such maximum values such that their wieght does not exceed given capacity.

will compare based on ration of value per kg

```cpp
bool comp(pair<int,int> &a,pair<int,int> &b){
    double r1 = ((1.0)*a.first) / a.second;
    double r2 = ((1.0)*b.first) / b.second;
    return r1 > r2;
}
int main() {
    int n = 3;
    int val[] = {69,100,120};
    int wt[] = {10,20,30};
    int capacity = 50;
    vector<pair<int,int>> data;
    for(int i=0;i<n;i++){
        data.emplace_back({val[i],wt[i]});
    }
    sort(data.begin(),data.end(),comp);
    int ans = 0;
    for(int i=0;i<n;i++){
        pair<int,int item = data[i];
        int itemVal = item.first;
        int itemWt = item.second;
        if(itemWt <= capacity){
            capacity -= itemWt;
            ans += itemVal;
        } else {
            double r1 = ((1.0)*itemVal)/itemWt;
            ans += capacity * r1
            capacity = 0;
            break;
        }
    }
    cout<<"ans "<<ans;
    return 0;
}
```

## Chocolate Distribution

there are n packets, m students , all n packets of chocolate contains some chocolates which is given in array
distribute chocolates to each student that it receives only one packet and difference between min and max No. of chocolate received to student is minimum.

### approach -

sort the chocolates and create a sliding window of size m (students) find diff of first element of window which will be mini no of chocolate and last element of window which will be maxi no of chocolate and among all windows find the minimum.

```cpp
int main() {
    int n = 8,m = 5;
    vector<int> choco  = {13,5,1,5,7,10,12,15};
    sort(choco.begin(),choco.end());
    int s = 0;
    int e = m-1;
    int ans = INT_MAX;
    while(e < choco.size()){
        int newDiff = choco[e] - choco[s];
        s++; e++;
        ans = min(ans,newDiff);
    }
    cout<<ans;
    return 0;
}
```

# Backtracking

## Permutation of string

total permutation of string is n! factorial

```cpp
void perm(string &str,int i){
    if(i>=str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j = i;j<str.length();j++){
        swap(str[i],str[j]);
        perm(str,i+1);
        swap(str[i],str[j]);
    }
}
```

## House Robber problem

we have to rob and can't rob adjacent house rob to loot max

arr = [1,2,3,1]  
ans = 4 , index 0 and 2

arr = [2,1,1,2]
ans = 4 , index 0 and 3;

```cpp
int rob(vector<int> &nums,int i){
    //base case
    if(i>=nums.size())
    return 0;

    //rob current house and move to next to next house
    int n1 = rob(nums,i+2) + nums[i];

    //leave the house and rob from next house
    int n2 = rob(nums,i+1);

    return max(n1,n2);
}
```

## Rate in maze

0 - rasta blocked  
1 - rasta open  

rat can move up, down, right, left

```cpp
bool isSafe(int i,int j,int row,int col,int arr[3][3],vector<vector<bool> > visited){
    if((i>=0 && i<row) && (j>=0 && j<col) && (arr[i][j]==1) && (visited[i][j]==false)){
        return true;
    } else return false;
}
void solveMaze(int arr[3][3],int row,int col,int i,int j,vector<vector<bool> >& visited,vector<string> & path, string outout){
    //base case
    if(i==row-1 && j==col-1){
        //answer found
        path.emplace_back(output);
        return;
    }

    //down case
    if(isSafe(i+1,j,row,col,arr,visited)){
        visited[i+1][j] = true;
        solveMaze(arr,row,col,i+1,j,visited,path,output+'D');
        visited[i+1][j] = false;
    }
    //left case
    if(isSafe(i,j-1,row,col,arr,visited)){
        visited[i][j-1] = true;
        solveMaze(arr,row,col,i,j-1,visited,path,output+'L');
        visited[i][j-1] = false;
    }

    //up
    if(isSafe(i-1,j,row,col,arr,visited)){
        visited[i-1][j] = true;
        solveMaze(arr,row,col,i-1,j,visited,path,output+'U');
        visited[i-1][j] = false;
    }

    //right
    if(isSafe(i,j+1,row,col,arr,visited)){
        visited[i][j+1] = true;
        solveMaze(arr,row,col,i,j+1,visited,path,output+'R');
        visited[i][j+1] = false;
    }
}
//calling function
solveMaze(arr,row,col,0,0,visited,path,output);
```

## Sudoko solver

no repetition  
each column contains 1-9  
each row  contains 1-9

more clues - more unique solution
less clues - multilple answer possible

### approach -

filling number row wise from 1 to 9 in box and check

1. check is safe (unique in row)
2. check is safe (unique in column)
3. check is safe (unique in 3x3 box)
    if not safe back track and start using next number in that box

```cpp
void isSafe(char value,vector<vector<char> >& board,int row,int col){
    for(int i=0;i<9;i++){
        //checking row compability
        if(board[row][i]==value) return false;
        //checking column compability
        if(board[i][col]==value) return false;
        //checking 3x3 box compability
        //method of liner nxn array to represen in n row and n column
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value) false;
    }
}
//board size is in power of 9
void solve(vector<vector<char> >&board){
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){
                //trying to fill the box from 1 to n
                for(char ch = '1',ch<='9',ch++){
                    if(isSafe(ch,board,i,j)){
                        board[i][j] = value;

                        //recursion for checking next posibility
                        bool aggekaSolve = solve(board);
                        if(aggekaSolve) return true;
                        //backtrack if not able to solve
                        board[i][j] = '.';
                    }
                }
                //koi bhi value 1 to 9 nahi dali
                return false; 
            }
        }
    }
    // all values are inserted correctly
    return true;
}
solve(board)
//driver call
solve(board,n);
```

## N Queen

we have to place queen such that it does not violet queen placing rule, if it does then we will just place to next till not place left.

Rules

- only one queen in row
- only one queen in column
- only one queen in both diagonals

```cpp
void isSafe(vector<vector<bool> >&queen,int row,int col,int &n){
    int i = row;
    int j = col;
    //column check
    while(j>=0){
        if(queen[row][j--]) return false;
    }
    //row check
    while(i>=0){
        if(queen[i--][col]) return false;
    }
    // diagonal check
    //up side left
    i = row;
    j = col;
    while(i>=0 && j>=0){
        if(queen[i--][j--]) return false;
    }
    i = row;
    j = col;
    //left side bottom
    while(i<n && j>=0){
        if(queen[i++][j--]) return false;
    }
    return true;
}

void solve(vector<vector<int> >&queen,int col, int &n){
    //base case
    if(col>=n){
        return; // print answer
    }
    //top to bottom column filling  and moving to next column approach
    for(int row=0;row<n;row++){
        if(isSafe(queen,row,col,n)){
            queen[row][col] = 1;
            solve(queen,col+1,n);
            queen[row][col] = 0;
        }
    }
}
//driver code
solve(queen,0,n);
```

optimization using unordered map
for row checking we will create row map and once fill that whole row will represent that can't fill again this mean we will hold complete diagonal, if we just store i+j value and if that value comes again and map alread contains value mean conflict.
TODO

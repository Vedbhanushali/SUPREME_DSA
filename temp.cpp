#include<iostream>
#include<std/bitsc++.h>
using namespace std;

bool isPossible(vector<int>& cookRanks,int p,int timeLimit){
    int currP = 0; //track of cooked parata
    for(int i = 0;i<cookRanks.size();i++){
        int R = cookRanks[i] , j = 1; // j - 1 for first time then increase as time increase as 1R, 2R, 3R,...
        int timeTaken = 0;
        while(true){
            if(timeTaken + j*R<=timeLimit){
                timeTaken += j*R;
                ++j;
                ++currP;
            } else {
                break; 
            }
        }
        if(currP >= P) return true;
    }
    return false;
}
int completeOrder(vector<int>& cookRanks,int p){
    int s = 0;
    int max_rank = *max_element(cookRanks.begin(),cookRanks.end());
    int e = (max_rank*(p*(p+1) / 2));
    int ans = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(cookRanks,p,mid)){
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
void solve(){
    int nP,int nC;
    cin>>nP>>nC;
    vector<int> cookRanks;
    while(nC--){
        int rank;cin>>rank;
        cookRanks.emplace_back(rank);
    }
    cout<<completeOrder(cookRanks,nP);
}
int main(){
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
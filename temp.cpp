int countPrime(int n){
    if(n==0) return 0;
    vector<bool> prime(n,true);
    prime[0]=prime[1] = false;
    int ans = 0;
    for(int i=2;i<n;i++){
        if(prime[i]){
            ans++;
            j = i*2;
            while(j<n){
                prime[j] = false;
                j = j+i;
            }
        }
    }
    return ans;
}
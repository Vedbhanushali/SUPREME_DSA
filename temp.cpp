int expsearch(int a[],int n,int x){
    if(a[0]==x) return 0;
    while(i<n && a[i]<=x){
        i = i*2;
    }
    return bs(a,i/2,min(i,n-1),x);
}
int bs(int arr[],int l,int h,int x){
    while(l<=e){
        int mid = l + (e-l)/2;
        int(a[mid]==x) return mid;
        else if(a[mid] < x) start = mid +1;
        else end = mid - 1;
    }
}
/* The functions which
builds the segment tree */
void build(int i,int l,int r,int st[],int arr[])
{
    if(l==r)
    {
        st[i]=arr[l];
        return;
    }
    
    int mid=(l+r)/2;
    build(2*i+1,l,mid,st,arr);
    build(2*i+2,mid+1,r,st,arr);
    st[i]=min(st[2*i+1],st[2*i+2]);
    
}
int *constructST(int arr[], int n) {
    // Your code here
    int*st=new int[4*n];
    build(0,0,n-1,st,arr);
    return st;
}

/* The functions returns the
 min element in the range
 from a and b */
int querr(int i,int l,int r,int st[],int ql,int qr)
{
    if(qr<l||ql>r)
    {
        return INT_MAX;
    }
    
    if(ql<=l&&r<=qr)
    {
        return st[i];
    }
    
    else
    { int mid=(l+r)/2;
        int lval=querr(2*i+1,l,mid,st,ql,qr);
        int rval=querr(2*i+2,mid+1,r,st,ql,qr);
        return min(lval,rval);
    }
}
int RMQ(int st[], int n, int a, int b) {
    int ans=querr(0,0,n-1,st,a,b);
    return ans;
    
    
    // Your code here
}

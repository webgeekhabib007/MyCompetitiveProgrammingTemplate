template<typename T>
class SegmentTree{
    vector<T> tree;
    vector<T> lazy;
    ll n;
    void build(ll node,vector<T>& arr,ll start,ll end){
        if(start == end){
            tree[node] = arr[start];
        }
        else{
            ll mid = start + (end-start)/2;
            build(node*2,arr,start,mid);
            build(node*2+1,arr,mid+1,end);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    void update(int idx,T val,ll node,ll start,ll end){
        if(start == end){
            tree[node] = val;
        }else{
            ll mid = start + (end - start)/2;
            if(idx <= mid){
                update(idx,val,node*2,start,mid);
            }else{
                update(idx,val,node*2+1,mid+1,end);
            }
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }

    void updateRange(ll left,ll right,T val,ll node,ll start,ll end){
        if(lazy[node]){
            tree[node] += (end-start+1)*lazy[node];
            if(start!=end){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(start > right or end < left)return ;
        if(start >= left and end <= right){
            tree[node] += (end-start+1)*val;
            if(start!=end){
                lazy[node*2] += val;
                lazy[node*2+1] += val;
            }
            return ;
        }
        int mid = start + (end-start)/2;
        updateRange(left,right,val,node*2,start,mid);
        updateRange(left,right,val,node*2+1,mid+1,end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    T query(ll left,ll right,ll node,ll start, ll end){
        if(start > right or end < left)return 0;
        if(lazy[node]){
            tree[node] += (end-start+1)*lazy[node];
            if(start!=end){
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(start>=left and end <= right){
            return tree[node];
        }
        ll mid = start + (end - start)/2;
        T leftSum = query(left,right,node*2,start,mid);
        T rightSum = query(left,right,node*2+1,mid+1,end);
        return leftSum+rightSum;
    }
public:
    SegmentTree(vector<T>& arr){
        n = arr.size();
        tree.resize(4*n+1);
        lazy.resize(4*n+1,0);
        build(1,arr,0,n-1);
    }
    void updateAt(ll idx,T val){
        update(idx,val,1,0,n-1);
    }
    T sumRange(ll l,ll r){
        return query(l,r,1,0,n-1);
    }
    void updateRange(ll left,ll right,T val){
        updateRange(left,right,val,1,0,n-1);
    }
};
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;


ll binarySearch(const vector<ll>&v, ll item){
    ll left=0,right= v.size()-1;
    ll pos = -1;
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(v[mid]== item){
            pos = mid;
            break;
        }
        if(v[mid]>item)right = mid-1;
        else left = mid+1;
    }
    return pos;
}
ll closestToLeft(const vector<ll>&v, ll item){
    ll left=0,right= v.size()-1;
    ll pos = -1;
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(v[mid]<=item){
            left = mid+1;
            pos = mid;
        }else right = mid-1;
    }
    return pos;
}
ll closestToRight(const vector<ll>&v, ll item){
    ll left=0,right= v.size()-1;
    ll pos = -1;
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(v[mid]>=item){
            right = mid-1;
            pos = mid;
        }else left = mid+1;
    }
    return pos;
}


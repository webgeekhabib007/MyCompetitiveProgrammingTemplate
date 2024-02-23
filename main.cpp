#include<bits/stdc++.h> 
using namespace std; 
bool Check(int colorFound,int color,unordered_map<int,int>&GetColor){ 
    if(colorFound==color)return true; 
    else if(GetColor[colorFound]){ 
        GetColor[colorFound]=0; 
        return true; 
    } 
} 
void Solve(int arr[],unordered_map<int,vector<int>>&adj,int n){ 
    queue<pair<int,int>>q; 
    q.push({1,arr[0]}); 
    unordered_map<int,int>GetColor; 
    GetColor[arr[0]]=1; 
    vector<int>visited(n+1,0); 
    visited[1]=1; 
    long long int count=0; 
    while(!q.empty()){ 
        auto it=q.front(); 
        q.pop(); 
        int node=it.first; 
        int color=it.second; 
        for(auto its:adj[node]){ 
            if(!visited[its]){ 
                visited[its]=1; 
                if(Check(arr[its-1],color,GetColor))count++; 
                q.push({its,arr[its-1]}); 
                GetColor[arr[its-1]]=1; 
            } 
        } 
    } 
    cout<<count<<endl; 
} 
int main(){ 
    int tame; 
    cin>>tame; 
    while(tame--){ 
        int n; 
        cin>>n; 
        int arr[n]; 
        for(int i=0;i<n;i++)cin>>arr[i]; 
        unordered_map<int,vector<int>>adj; 
        for(int i=0;i<n-1;i++){ 
            int a,b; 
            cin>>a>>b; 
            adj[a].push_back(b); 
            adj[b].push_back(a); 
        } 
        Solve(arr,adj,n); 
    } 
    return 0; 
}
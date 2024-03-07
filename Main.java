void solve(ll cases=0){
    ll n;cin>>n;
    string s;cin>>s;
    ll p = s.size(),flag ;
    for(ll i=0;i<p/2;i++){
        if(s[i]<s[p-1-i]){
            flag = 0;
            break;
        }
        if(s[i]>s[p-1-i]){
            flag = 1;
            break;
        }
    }

    if(flag == 0)cout << s << nl;
    else{
        string cp = s;
        reverse(all(s));
        s+=cp;
        cout << s << nl;
    }
}
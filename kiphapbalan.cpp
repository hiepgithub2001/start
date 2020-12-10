#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,a,b)  for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define fore(i,a)  for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define TASK "calexp"
#define fi  first
#define se  second
#define LL long long
#define exp asdsad
using   namespace   std;
typedef pair<int,int> ii;
stack <int> st;
stack <double> ST;
vector <ii> exp;
int H[60];
string s;
//--------------------------
void    infix_to_suffix(){
    H['*']=H['/']=2;
    H['+']=H['-']=1;
    H['(']=H[')']=0;
    ///deg of operator
    int tmp=0;
    rep(i,0,s.size()){
        if (s[i]=='(') st.push('(');
        if (s[i]==')'){
            while (st.top()!='('){/// until meet '('
                exp.push_back(ii(1,st.top()));
                st.pop();
            }
            st.pop();
        }
        if (s[i]=='-' || s[i]=='+' || s[i]=='*' || s[i]=='/'){
            while (st.size() && H[st.top()]>=H[s[i]]){
                exp.push_back(ii(1,st.top()));
                st.pop();
            }
            st.push(s[i]);
        }
        if ('0'<=s[i] && s[i]<='9'){/// read number
            tmp=tmp*10+s[i]-'0';
            if (!(i+1<s.size() && '0'<=s[i+1] && s[i+1]<='9')){
                exp.push_back(ii(2,tmp));
                tmp=0;
            }
        }
    }
    while (st.size()) exp.push_back(ii(1,st.top())),st.pop();
}
//--------------------------
void    cal_exp(){
    double A,B,C;
    fore(it,exp){
        int id=(*it).fi;/// id : 1 - number ; 2 - operator
        int c=(*it).se;
        if (id==2) ST.push(c);
        else{
            B=ST.top();ST.pop();
            A=ST.top();ST.pop();
            if (c=='-') C=A-B;
            if (c=='+') C=A+B;
            if (c=='*') C=A*B;
            if (c=='/') C=A/B;
            ST.push(C);
            /// out 2 in 1
        }
    }
}
//--------------------------
void    solve(){
    cin>>s;
    infix_to_suffix();
    cal_exp();
    cout<<setprecision(4)<<fixed<<ST.top()<<"\n";
}
//--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
}



#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int lcsRecursive(int x,int y,string &s1,string &s2)
{
    if(x==0||y==0)
        return 0;
    else if(s1[x-1]==s2[y-1]){
        return lcsRecursive(x-1,y-1,s1,s2)+1;
    }else{
        return max(lcsRecursive(x-1,y,s1,s2),lcsRecursive(x,y-1,s1,s2));
    }
}

int lcsMemoized(int x,int y,string &s1,string &s2)
{
    if(x==s1.size()&&y==s2.size()){
        memset(dp,-1,sizeof(dp));
    }
    if(x==0||y==0)
        return 0;
    else if(dp[x][y]!=-1){
        return dp[x][y];
    }
    else if(s1[x-1]==s2[y-1]){
        return dp[x][y]=lcsMemoized(x-1,y-1,s1,s2)+1;
    }else{
        return dp[x][y]=max(lcsMemoized(x-1,y,s1,s2),lcsMemoized(x,y-1,s1,s2));
    }
}

int lcsTabular(int x, int y, string &s1, string &s2)
{
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=y;j++){
        dp[0][j]=0;
    }
    
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}

int main(){
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcsTabular(n,m,s1,s2);
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<memory.h>
using namespace std;

string str,temp,dic[7];
int a[210][210],f[210][40];

int main(void) {
    int n,k,s,i,j,l,repeat,ri;
    bool y;
    
    cin>>repeat;
    for (ri=1;ri<=repeat;ri++) {
        
    cin>>n>>k;
    str="";
    for (i=1;i<=n;i++) {
        cin>>temp;
          str+=temp;
    }
    cin>>s;
    for (i=1;i<=s;i++) cin>>dic[i];
    
    memset(a,0,sizeof(a));
    for (j=str.size()-1;j>=0;j--)
        for (i=j;i>=0;i--) {
            y=0;
            for (l=1;l<=s;l++) {
                if (str.find(dic[l],i)==i&&dic[l].size()<=j-i+1) y=1;
                //if (y) cout<<dic[l]<<" "<<i<<endl;
                if (y) break;
            }
            if (y) a[i][j]=a[i+1][j]+1;
            else a[i][j]=a[i+1][j];
        }
    
    memset(f,0,sizeof(f));
    for (i=0;i<=str.size()-1;i++) f[i][1]=a[0][i];
    for (i=0;i<=str.size()-1;i++)
        for (j=2;j<=k&&j<=i+1;j++) {
            for (l=j-2;l<i;l++)
                f[i][j]=max(f[i][j],f[l][j-1]+a[l+1][i]);
        }
    cout<<f[str.size()-1][k]<<endl;
        
    }
    
    return 0;
}

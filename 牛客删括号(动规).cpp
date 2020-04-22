#include<bits/stdc++.h>
 
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
using namespace std;
 
int main(){
    char s[101]{}, t[101]{};
    scanf("%s", s);
    scanf("%s", t);
    int sl = strlen(s), tl = strlen(t);
    bool dp[sl+1][tl+1]{};
    dp[0][0] = true;
    for(int i = 1; i <= sl; ++i)
        for(int j = 1; j <= tl; j++){
            if(s[i-1] == t[j-1]) dp[i][j] |= dp[i-1][j-1];//末尾相同
            if(s[i-1] == ')'){//尝试删去s末尾的有效括号子串
                int k = i-1, p = 1;
                while(p > 0) p += (s[k-1] == ')' ? 1 : -1), k--;
                dp[i][j] |= dp[k][j];
            }
 
        }
    if(dp[sl][tl]) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}

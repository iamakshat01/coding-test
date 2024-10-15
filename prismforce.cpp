#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;

bool canCross(int ind, int curPower, int a, int b, int p, int n, vector<int> &circles)
{
    if(ind==n || (n-ind-1)<=a)
        return true;

    string identifier=to_string(a)+"#"+to_string(b)+"#"+to_string(ind)+"#"+to_string(curPower);
    if(dp.find(identifier)!=dp.end())
        return dp[identifier];

    bool ans=false;
    // skip
    if(a>0)
        ans |= canCross(ind+1, curPower, a-1, b, p, n, circles);
        
    // enemy power
    int enemyPower=circles[ind];
    if(ind==3 || ind==7)
        enemyPower+=circles[ind-1]/2;

    // recharge before entering
    if(b>0 && p>=enemyPower)
        ans |= canCross(ind+1, p-enemyPower, a, b-1, p, n, circles);

    // recharge and skip both
    if(a>0 && b>0)
        ans |= canCross(ind+1, p, a-1, b-1, p, n, circles);
    
    // nothing required
    if(curPower>=enemyPower)
        ans |= canCross(ind+1, curPower-enemyPower, a, b, p, n, circles);
    
    return dp[identifier]=ans;
}

int main()
{
    int n=11;
    vector<int> circles={10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int p=100, a=6, b=6;
    if(canCross(0, p, a, b, p, n, circles))
        cout<<"YES\n";
    else
        cout<<"NO\n";

    dp.clear();

    p=100, a=5, b=3;
    if(canCross(0, p, a, b, p, n, circles))
        cout<<"YES\n";
    else
        cout<<"NO\n";

    dp.clear();

    p=100, a=3, b=1;
    if(canCross(0, p, a, b, p, n, circles))
        cout<<"YES\n";
    else
        cout<<"NO\n";

    dp.clear();

    p=100, a=3, b=0;
    if(canCross(0, p, a, b, p, n, circles))
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}

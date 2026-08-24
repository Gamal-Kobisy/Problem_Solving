ll memo[20][2][2];
string a , b;

ll solve(int i , bool sm , bool lr){
    if(i == b.size()) return 1;
    ll &ret = memo[i][sm][lr];
    if(~ret) return ret;
    ret = 0;
    int lower = lr ? 0 : a[i];
    int upper = sm ? 9 : b[i];
    for(int d = lower ; d <= upper ; d++){
        ret += solve(i + 1 ,
                     sm or d < b[i],
                     lr or d > a[i]
                     );
    }
    return ret;
}
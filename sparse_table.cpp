const int maxn=N;
const int max_logn=20;
template<typename T>
struct SparseTable{
    int log[maxn];
    T dp[max_logn][maxn];
    T combine(T a,T b){
        return min(a,b);
    }
    SparseTable(){
        log[1] = 0;
        for (int i = 2; i < maxn; i++)
            log[i] = log[i/2] + 1;
    }
    void build(vector<T> b)
    {
        int n=b.size();
        for (int i = 0; i < n; ++i){
            dp[0][i]=b[i];
        }
        for (int j = 1; j < max_logn; j++)
            for (int i = 0; i + (1 << j) < maxn; i++)
                dp[j][i] = combine(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
    T query(int l,int r)
    {
        int j=log[r-l+1];
        return combine(dp[j][l],dp[j][r-(1<<j)+1]);
    }
};
SparseTable<int> sp;
// to build :- sp.build(arr) where arr is a vector
// to call :- sp.query(l, r)

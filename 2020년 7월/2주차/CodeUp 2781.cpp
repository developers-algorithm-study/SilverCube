#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define mp make_pair
#define ft first
#define sd second
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define pdd pair<db, db>
#define len(X) (int)(X).size()
#define all(X) (X).begin(), (X).end()
#define loop() while(1)
#define use_cin() cin.tie(0), ios::sync_with_stdio(0)
#define oper(X, Y, Z) bool operator X(const Y &Z) const

#define inf9 1e9
#define inf18 1e18
#define mod 1000000007
#define MAX 100000
#define MAX_T 262144

vector<pii> st;
int m[20][20], res[20][20];
bool visited[20][20], finished[20][20];
int N, M, cnt;

bool range(int x, int y)
{
    return 0<=x && x<M && 0<=y && y<N;
}

void dfs(int x, int y)
{
    if(range(x, y) && m[y][x])
    {
        if(!visited[y][x])
        {
            st.push_back(mp(x, y));
            visited[y][x] = true;

            if(m[y][x] == 1)
                dfs(x+1, y);
            else if(m[y][x] == 3)
                dfs(x-1, y);
            else if(m[y][x] == 2)
                dfs(x, y+1);
            else
                dfs(x, y-1);

            st.pop_back();
            finished[y][x] = true;
        }
        else if(!finished[y][x])
        {
            for(int i=len(st)-1; st[i]!=mp(x, y); i--)
            {
                res[st[i].sd][st[i].ft] = 1;
                finished[st[i].sd][st[i].ft] = true;
            }

            res[y][x] = 1;
            finished[y][x] = true;
            cnt++;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            scanf("%d", &m[y][x]);

    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            if(m[y][x] && !visited[y][x])
                dfs(x, y);

    printf("%d\n", cnt);

    for(int y=0; y<N; y++,puts(""))
        for(int x=0; x<M; x++)
            printf("%d ", res[y][x]);

    return 0;
}
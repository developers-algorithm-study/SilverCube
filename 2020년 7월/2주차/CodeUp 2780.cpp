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

int m[100][100];
bool visited[100][100];
int W, H, cnt;
db res;

bool range(int x, int y)
{
    return 0<=x && x<W && 0<=y && y<H;
}

void dfs(int x, int y)
{
    if(range(x, y) && m[y][x] && !visited[y][x])
    {
        visited[y][x] = true;
        cnt++;

        dfs(x+1, y);
        dfs(x-1, y);
        dfs(x, y+1);
        dfs(x, y-1);
    }
}

int main()
{
    scanf("%d %d", &W, &H);

    for(int y=0; y<H; y++)
        for(int x=0; x<W; x++)
            scanf("%d", &m[y][x]);

    for(int y=0; y<H; y++)
    {
        for(int x=0; x<W; x++)
        {
            if(m[y][x] && !visited[y][x])
            {
                cnt = 0;
                dfs(x, y);
                res += sqrt(cnt);
            }
        }
    }

    printf("%.4f", res);
    return 0;
}
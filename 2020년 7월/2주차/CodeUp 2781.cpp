#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> st;
int m[20][20], res[20][20];
bool visited[20][20], finished[20][20];
int N, M, dcnt;

bool inRange(int x, int y) {
    return 0<=x && x<M && 0<=y && y<N;
}

void dfs(int x, int y) {
    if(inRange(x, y) && m[y][x]) {
        if(!visited[y][x]) {
            st.push_back(make_pair(x, y));
            visited[y][x] = true;

            if(m[y][x] == 1) dfs(x+1, y);
            else if(m[y][x] == 3) dfs(x-1, y);
            else if(m[y][x] == 2) dfs(x, y+1);
            else dfs(x, y-1);

            st.pop_back();
            finished[y][x] = true;
        } else if(!finished[y][x]) {
            for(int i=(int)st.size()-1; st[i]!=make_pair(x, y); i--) {
                res[st[i].second][st[i].first] = 1;
                finished[st[i].second][st[i].first] = true;
            }

            res[y][x] = 1;
            finished[y][x] = true;
            dcnt++;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            scanf("%d", &m[y][x]);

    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            if(m[y][x] && !visited[y][x])
                dfs(x, y);

    printf("%d\n", dcnt);
    for(int y=0; y<N; y++,puts(""))
        for(int x=0; x<M; x++)
            printf("%d ", res[y][x]);

    return 0;
}
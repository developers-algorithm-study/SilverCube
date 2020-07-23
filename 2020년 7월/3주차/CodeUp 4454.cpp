#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(101);
queue<int> q;
bool visited[101];
int lv[101];

void bfs(int s) {
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int v1 = q.front();
        q.pop();

        for(int v2: graph[v1]) {
            if(!visited[v2]) {
                visited[v2] = true;
                lv[v2] = lv[v1]+1;
                q.push(v2);
            }
        }
    }
}

int main() {
    int n, s, e, m;
    scanf("%d %d %d %d", &n, &s, &e, &m);

    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs(s);

    printf("%d", (visited[e] ? lv[e] : -1));
    return 0;
}
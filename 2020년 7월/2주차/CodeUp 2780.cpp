#include <bits/stdc++.h>
using namespace std;

int m[100][100];
bool visited[100][100];
int W, H, dcnt;
double res;

bool inRange(int x, int y) {
    return 0<=x && x<W && 0<=y && y<H;
}

void dfs(int x, int y) {
    if(inRange(x, y) && m[y][x] && !visited[y][x]) {
        visited[y][x] = true;
        dcnt++;

        dfs(x+1, y);
        dfs(x-1, y);
        dfs(x, y+1);
        dfs(x, y-1);
    }
}

int main() {
    scanf("%d %d", &W, &H);

    for(int y=0; y<H; y++)
        for(int x=0; x<W; x++)
            scanf("%d", &m[y][x]);

    for(int y=0; y<H; y++) {
        for(int x=0; x<W; x++) {
            if(m[y][x] && !visited[y][x]) {
                dcnt = 0;
                dfs(x, y);

                res += sqrt(dcnt);
            }
        }
    }

    printf("%.4f", res);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

set<pii> s;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

pii sum(pii a, pii b) {
    int x = a.first*b.second+a.second*b.first;
    int y = a.second*b.second;
    int g = gcd(x, y);

    return make_pair(x/g, y/g);
}

bool cmp(pii a, pii b) {
    return a.first*b.second < a.second*b.first;
}

int main() {
    int D1, D2;
    scanf("%d %d", &D1, &D2);

    for(int i=D1; i<=D2; i++) {
        pii itv = make_pair(360, i);
        pii t = make_pair(0, 1);

        while(cmp(t, make_pair(360, 1))) {
            s.insert(t);
            t = sum(t, itv);
        }
    }

    printf("%d", (int)s.size());
    return 0;
}
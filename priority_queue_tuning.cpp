#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator()(int x, int y) {
        return x > y;
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    priority_queue<int, vector<int>, cmp> q;
    q.push(1);
    q.push(8);
    q.push(4);

    while(q.size() > 0) {
        cout << q.top() << ' ';
        q.pop();
    }

    return 0;
}
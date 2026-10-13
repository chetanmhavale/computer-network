#include <iostream>
using namespace std;

int main() {
    int n, e, cost[10][10] = {0};
    int dist[10], visited[10] = {0}, parent[10];

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of connections: ";
    cin >> e;

    cout << "Enter connections (A B cost):\n";

    for (int i = 0; i < e; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        cost[a-'A'][b-'A'] = c;
        cost[b-'A'][a-'A'] = c;
    }

    char s, d;
    cout << "Enter source: ";
    cin >> s;
    cout << "Enter destination: ";
    cin >> d;

    int source = s-'A', dest = d-'A';

    for (int i = 0; i < n; i++) {
        dist[i] = 9999;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++)
            if (!visited[j] &&
                (u == -1 || dist[j] < dist[u]))
                u = j;

        if (u == -1 || dist[u] == 9999)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (cost[u][v] > 0 &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == 9999) {
        cout << "No path exists";
        return 0;
    }

    cout << "Shortest distance: " << dist[dest];
    cout << "\nShortest path: ";

    int path[10], k = 0;

    for (int v = dest; v != -1; v = parent[v])
        path[k++] = v;

    for (int i = k-1; i >= 0; i--) {
        cout << char(path[i] + 'A');
        if (i > 0) cout << " -> ";
    }

    return 0;
}

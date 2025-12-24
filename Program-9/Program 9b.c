#include <stdio.h>

void dfs(int);

int n, i, j, a[10][10], vis[10], count = 0;

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }

    printf("DFS traversal:\n");
    dfs(1);   // start DFS from vertex 1

    // Count visited vertices
    for (i = 1; i <= n; i++) {
        if (vis[i] == 1)
            count++;
    }

    if (count == n)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}

void dfs(int v) {
    vis[v] = 1;
    printf("%d ", v);

    for (j = 1; j <= n; j++) {
        if (a[v][j] == 1 && vis[j] == 0) {
            dfs(j);
        }
    }
}

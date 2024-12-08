/**
 * Question: https://leetcode.com/problems/redundant-connection/
 */

class Solution {
    int[] parent;
    int[] size;

    void initialize(int n) {
        parent = new int[n+1];
        size = new int[n+1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int x) {
        if (x != parent[x]) {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }

    void merge(int rootX, int rootY) {
        if (size[rootX] >= size[rootY]) {
            size[rootX] += size[rootY];
            parent[rootY] = rootX;
        } else {
            size[rootY] += size[rootX];
            parent[rootX] = rootY;
        }
    }

    boolean check(int[] edge) {
        int rootX = findParent(edge[0]);
        int rootY = findParent(edge[1]);

        if (rootX != rootY) {
            merge(rootX, rootY);
            return false;
        } else {
            return true;
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        int length = edges.length;
        initialize(length);
        for(int i = 0; i < edges.length; i++) {
            if (check(edges[i])) {
                return edges[i];
            }
        }
        int[] ans = {-1, -1};
        return ans;
    }
}
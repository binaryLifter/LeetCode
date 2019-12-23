class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int mx = INT_MIN;
        for (const auto& edge : edges) {
            for (const auto& i : edge) {
                mx = std::max(mx, i);
            }
        }
        parent.resize(mx + 1);
        size.resize(mx + 1);
        for (int i = 0; i < int(parent.size()); i += 1) {
            parent[i] = i;
            size[i] = 1;
        }
        for (const auto& edge : edges) {
            int x = FIND(edge[0]);
            int y = FIND(edge[1]);
            if (x == y) {
                return edge;
            }
            UNION(x, y);
        }
        return std::vector<int>();
    }

private:
    std::vector<int> parent;
    std::vector<int> size;

    void UNION(const int& x, const int& y) {
        if (size[x] < size[y]) {
            parent[x] = parent[y];
            size[y] += size[x];
            size[x] = 0;
        } else {
            parent[y] = parent[x];
            size[x] += size[y];
            size[y] = 0;
        }

    }

    int FIND(const int& x) {
        if (x != parent[x]) {
            parent[x] = FIND(parent[x]);
        }
        return parent[x];
    }
};
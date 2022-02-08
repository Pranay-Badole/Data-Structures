// Forming by edges
// once we get n-1 edges, we stop

class Edge {
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};

// Overload the < operator.
bool operator<(const Edge& edge1, const Edge& edge2) {
    return edge1.cost > edge2.cost;
}

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    // Kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int sz = points.size();
        priority_queue<Edge> pq;
        UnionFind uf(sz);

        for (int i = 0; i < sz; i++) {
            vector<int>& coordinate1 = points[i];
            for (int j = i + 1; j < sz; j++) {
                vector<int>& coordinate2 = points[j];
                // Calculate the distance between two coordinates.
                int cost = abs(coordinate1[0] - coordinate2[0]) +
                           abs(coordinate1[1] - coordinate2[1]);
                Edge edge(i, j, cost);
                pq.push(edge);
            }
        }

        int result = 0;
        int count = sz - 1;
        while (!pq.empty() && count > 0) {
            Edge edge = pq.top();
            pq.pop();
            if (!uf.connected(edge.point1, edge.point2)) {
                uf.unionSet(edge.point1, edge.point2);
                result += edge.cost;
                count--;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    Solution solution;
    cout << "Minimum Cost to Connect Points = " << solution.minCostConnectPoints(points) << endl;
    return 0;
}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Mine-

class Solution {
public:
    vector<int> root;
    
    int find(int i){
        if(i == root[i]){
            return i;
        }
        return (root[i] = find(root[i]));
        
    }
     
    int minCostConnectPoints(vector<vector<int>>& v) {
        vector<pair<int, pair<int, int>>> edges;
        
     //   This part below is the pre processing to get desired form of input we want
     //   Here ==> vectors of pair<int, pair<int, int>>


        int n = v.size();
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(i == j) continue;
                int dist = abs(v[j][0] - v[i][0]) + abs(v[j][1] - v[i][1]);
                edges.push_back({dist, {i, j}});
            }
        }

     //   greedy approach   
     //   sort the edges or use heap
     
        sort(edges.begin(), edges.end());
        int ans = 0;
        
        for(auto &x : edges){
            int u = x.second.first;
            int v = x.second.second;
            
            int root_u = find(u);
            int root_v = find(v);
            
            if(root_u != root_v) {
                root[root_v] = root_u;
                ans += x.first;
            }
        }
            
        return ans;
    }
};
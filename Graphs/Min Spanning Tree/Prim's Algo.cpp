// Forming by vertices
// once we get n vertices, we stop

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

class Solution {
public:
    // Prim's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int sz = points.size();
        priority_queue<Edge> pq;
        vector<bool> visited(sz);
        int result = 0;
        int count = sz - 1;
        // Add all edges from points[0] vertex
        vector<int>& coordinate1 = points[0];
        for (int j = 1; j < sz; j++) {
            // Calculate the distance between two coordinates
            vector<int>& coordinate2 = points[j];
            int cost = abs(coordinate1[0] - coordinate2[0]) +
                       abs(coordinate1[1] - coordinate2[1]);
            Edge edge(0, j, cost);
            pq.push(edge);
        }
        visited[0] = true;

        while (!pq.empty() && count > 0) {
            Edge edge = pq.top();
            pq.pop();
            int point1 = edge.point1;
            int point2 = edge.point2;
            int cost = edge.cost;
            if (!visited[point2]) {
                result += cost;
                visited[point2] = true;
                for (int j = 0; j < sz; j++) {
                    if (!visited[j]) {
                        int distance = abs(points[point2][0] - points[j][0]) +
                                       abs(points[point2][1] - points[j][1]);
                        pq.push(Edge(point2, j, distance));
                    }
                }
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

#define pii     pair<int, int>
#define two(x)                        cout << x.first << ' ' << x.second << ' ';
#define auvv(v)                       for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}

class cmp{
    public:
    bool operator()(pii a, pii b){
        return (a.first > b.first);
    }  
};

class Solution {
public:
    
    
    int minCostConnectPoints(vector<vector<int>>& v) {
        
        int n = v.size();
        
        vector<vector<int>> adj(n, vector<int>(n, -1));

        // This part below is the pre processing to get desired form of input we want
        // Here ==> adjancey list but here as there is a edge between one vertex and every other vertices 
        // so i used adjancey matrix else use adjancey list.

 
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int dist = abs(v[j][0] - v[i][0]) + abs(v[j][1] - v[i][1]);
                adj[i][j] = adj[j][i] = dist;
            }
        }
        int ans = 0;
        
        vector<bool> vis(n, 0);
        
        priority_queue<pii, vector<pii>, cmp> pq;
    
        //  insert any arbitrary vertex 

        pq.push({0, 0});
        int cnt = 0;
        
        while(cnt < n && !pq.empty()) {
            // choose the min vertex approahable from heap
            auto top = pq.top();
            pq.pop();
            
            int dist = top.first;
            int idx = top.second;
            
            // if it is already in MST skip
            if(vis[idx]) continue;
            
            ans += dist;
            cnt++;
            
            // mark it to vis as it is not in MST
            vis[idx] = 1;
            
            for(int j = 0; j < n; j++) {
                if(j == idx) continue;
                if(!vis[j]){

            // here to prevent unwanted insertions to heap we can use key array which will store the min dist require to reach
            // that vertex at any instance, thus if adj[idx][j] < key[j] then only we will insert it in heap
                    
                    pq.push({adj[idx][j], j});
                }
            }
        }
            
        return ans;
    }
};
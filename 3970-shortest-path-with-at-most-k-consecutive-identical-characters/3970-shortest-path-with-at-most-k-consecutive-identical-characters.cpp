class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {

            auto [wt, node, cnt] = pq.top();
            pq.pop();

            if(wt > dist[node][cnt]) continue;

            if(node == n - 1) return wt;

            for(auto &[v, w] : adj[node]) {

                int newCnt;

                if(labels[node] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if(newCnt > k) continue;

                int newWt = wt + w;

                if(newWt < dist[v][newCnt]) {
                    dist[v][newCnt] = newWt;
                    pq.push({newWt, v, newCnt});
                }
            }
        }

        return -1;
    }
};
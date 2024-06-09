class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int ,vector<pair<int,int>>> graph;
        for(auto i:times){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            graph[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;

        while(!minHeap.empty()){
            auto [curr_dist,u] = minHeap.top();
            minHeap.pop();

            if(curr_dist>dist[u]){
                continue;
            }

            for(auto[v,w]: graph[u]){
                int dst = curr_dist + w;
                if(dst<dist[v]){
                    dist[v] = dst;
                    minHeap.push({dst,v});
                }
            }

        }

        int maxDist = 0;
        for(int i= 1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            maxDist = max(maxDist,dist[i]);
        }
        return maxDist;
    }
};
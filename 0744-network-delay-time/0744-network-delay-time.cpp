class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(auto i: times){
            int sn = i[0];
            int tn = i[1];
            int t = i[2];
            graph[sn].push_back({tn,t});
        }

        vector<int> distance(n+1,INT_MAX);
        distance[k] = 0;

        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,k});

        while(!minHeap.empty()){
            int currDistance = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();

            if(currDistance>distance[currNode]){
                continue;
            }
            for(auto g:graph[currNode]){
                int tn = g.first;
                int t = g.second;
                if(distance[tn] > currDistance + t){
                    distance[tn] = currDistance + t;
                    minHeap.push({distance[tn],tn});
                } 
            }
        }

        int maxDist = *max_element(distance.begin()+1,distance.end());
        return maxDist == INT_MAX? -1 : maxDist;
    }
};
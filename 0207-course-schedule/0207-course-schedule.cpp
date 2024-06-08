class Solution {
public:
    bool dfs(int course,vector<vector<int>> &graph,vector<int> &visited){
        if(visited[course] == 1) return true;
        if(visited[course] == 2) return false;
        visited[course] = 1;

        for(auto nextCourse: graph[course]){
            if(dfs(nextCourse,graph,visited)){
                return true;
            }
        }
        visited[course] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses,0);
        for(auto i:prerequisites){
            graph[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(dfs(i,graph,visited)){
                return false;
            }
        }
        return true;
    }
};
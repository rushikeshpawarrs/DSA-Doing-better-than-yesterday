class Solution {
public: 
//topology sort length != n invalid condition
    bool topsBfs(int n, unordered_map<int , list<int> >& adjList){
        vector<int> ans;
        queue<int> q;
        unordered_map<int, int> indegree;

        //indegree calculation
        for(auto i: adjList){
            int src = i.first;
            for(auto nbr: i.second){
                indegree[nbr]++;
            }
        }

        //put all nodes inside queue, which has indegree = 0
        for(int i = 0; i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //bfs logic
        while(!q.empty()){
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);
            for(auto nbr: adjList[fNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

      return ans.size() == n ? true : false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int , list<int> > adjList;

        for(auto task: prerequisites){
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }

        bool ans = topsBfs(numCourses, adjList);
        return ans;
    }
};

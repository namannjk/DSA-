
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    set <pair<int,int>> s;
    int currTime = 0;
    
    vector <int> insertionTime,minTime,visited;
    
    void dfs(int curr,int par,vector <int> adj[]){
        
        insertionTime[curr] = ++currTime;
        minTime[curr] = currTime;
        visited[curr] = 1;
        for(auto &x:adj[curr]){
            if(x==par) continue;
            if(!visited[x]){
                dfs(x,curr,adj);
            }
            minTime[curr] = min(minTime[curr],minTime[x]);
            
            if(insertionTime[curr]<minTime[x]){
                s.insert({curr,x});
            }
        }
        
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        insertionTime.resize(V);
        minTime.resize(V);
        visited.resize(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i])  dfs(i,-1,adj);
        }
        //for(auto &x:s) cout<<x.first<<" "<<x.second<<endl;
        if(s.count({c,d}) || s.count({d,c})) return 1;
        return 0;
        
    }
};
bool isCycle(vector<vector<int>>&adjList , int source  , vector<int>&color){
    color[source] = 1 ;
    for(auto it : adjList[source]){
        if(color[it] == 1)
            return true;
        if(color[it] ==0 && isCycle(adjList , it , color))
            return true;
    }
    color[source] = 2;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>>adjList(n+1 );
    for(auto it : edges){
        adjList[it.first].push_back(it.second);
    }
    vector<int>color(n+1 , 0);
    for(int i = 0 ; i < n ; i++){
        if(color[i] == 0){
            if(isCycle(adjList , i , color))
                return 1 ;
        }
    }
    return 0 ;
}

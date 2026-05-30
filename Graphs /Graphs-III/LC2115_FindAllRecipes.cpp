class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, vector<string>> graph; // ingredient --> recipes vector
        unordered_set<string> sup(supplies.begin(), supplies.end());
        vector<int> indeg(n); // stores number of dependencies that are not resolved -> number of ingredients that are not there in supplies
        queue<string> q;
        map<string,int> recipeIdx;
        vector<string> ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<ingredients[i].size(); j++){
                graph[ingredients[i][j]].push_back(recipes[i]) ;
                if(!sup.count(ingredients[i][j])){ 
                    // if the ingredient is not in supplies then perform indegree increment 
                    indeg[i] ++;
                }
            }
            recipeIdx[recipes[i]] = i;           
        }

        for(string r : recipes){
            if(indeg[recipeIdx[r]] == 0){
                q.push(r);
            }
        }

        while(!q.empty()){
            string curr = q.front();
            q.pop();
            ans.push_back(curr);

            if(graph.contains(curr)){ // if there as an ingredient then perform indegree decrement 
                for(string r : graph[curr]){
                    indeg[recipeIdx[r]] -- ;

                    if(indeg[recipeIdx[r]] == 0){
                        q.push(r);
                    }
                }
            }
        }
        return ans;
    }
};

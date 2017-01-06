

void dfs(int u){
        REP(i, gn[u].size()){
            if ( !vis[gn[u][i]] ){ vis[gn[u][i]] = 1; dfs( gn[u][i] ); }
        }
    }

//z uzlu 1;
MM(vis,0);
vis[1] = 1;
dfs(1);

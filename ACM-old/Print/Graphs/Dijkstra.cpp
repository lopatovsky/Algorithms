vii adj[20005];
bool used[20005];
int len[20005];

int f, l, u, e;

int dijkstra(){

    priority_queue <ii, vii, greater<ii> > pq;
    memset(used,0,sizeof(bool)* u);

    REP(i,u) len[i] = INF;
    len[f] = 0;
    pq.push( ii(len[f], f) );

    while(!pq.empty()){

        f = pq.top().second; pq.pop();
        if(used[f]) continue;
        if (f == l) return len[l];
        used[f] = 1;

        TR(adj[f],it){

            if( !used[it->first] && len[it->first] > len[f] + it->second  ) {
                 len[it->first] = len[f] + it->second;
                 pq.push(  ii( len[it->first], it->first ) ); }
        }
    }
    return -1;
}

int main()
{
    int x, y , w;
    int cs;
    scanf("%d",&cs);
    FOR(iter,1,cs){
        scanf("%d%d%d%d",&u,&e, &f, &l);
        REP(i,u) adj[i].clear();
        REP(i,e){
            scanf("%d%d%d", &x, &y, &w);
            adj[x].PB(ii(y,w));
            adj[y].PB(ii(x,w));
        }
        x = dijkstra();
        printf("Case #%d: ",iter);
        if (x < 0) printf("unreachable\n");
        else printf("%d\n",x);
    }
	return 0;
}

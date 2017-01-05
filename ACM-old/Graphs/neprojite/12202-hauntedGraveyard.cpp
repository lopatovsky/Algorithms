// @TODO negativni cykly, ktere nasleduji za cilem uz nejsou problem
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int GRAVE    = 0;
const int GRASS    = 1;
const int HOLE     = 2;
const int INFINITY = 100000000;

struct
{
  int s; // surface
  int x, y, t;
} p[32][32];
int W, H;
int steps[4][2] = {
  {0,-1},
  {-1,0},
  {1,0},
  {0,1}
};
struct Vertex
{
  Vertex( ) { };
  Vertex( int vx, int vy, int vd ) { x = vx; y = vy; d = vd; };
  bool operator<(const Vertex & v) const { return (x == v.x) ? (y < v.y) : (x < v.x); }
  int x;
  int y;
  int d; // distance
};
vector<Vertex> v;
struct Edge
{
  bool operator<(const Edge & e) const { return (v[from] < v[e.from]) ? true : (v[to] < v[e.to]); }
  unsigned from, to;
  int      dist;
};
vector<Edge>   e;

int bellman_ford( bool & fail )
{
  bool change = true;
  fail        = false;

  for ( unsigned i = 1; change && i < v.size(); ++i )
  {
    change = false;
    for ( vector<Edge>::iterator it = e.begin(); it != e.end(); ++it )
    {
      if ( v[ it->from ].d != INFINITY && v[ it->from ].d + it->dist < v[ it->to ].d )
      {
        change = true;
        v[ it->to ].d = v[ it->from ].d + it->dist;
      }
    }
  }

  for ( vector<Edge>::iterator it = e.begin(); it != e.end(); ++it )
    if ( v[ it->from ].d != INFINITY && v[ it->from ].d + it->dist < v[ it->to ].d )
    {
      fail = true;
      break;
    }
  return v.rbegin()->d;
}

void print()
{
  for (int i = H+1; i >= 0; --i)
  {
    for (int j = 0; j <= W+1; ++j)
    {
      switch (p[i][j].s)
      {
        case GRAVE:
          printf("#");
        break;
        case HOLE:
          printf("O");
        break;
        case GRASS:
          printf(".");
        break;
      }
    }
    printf("\n");
  }
}


int main()
{
  unsigned vertices[32][32];
  int      G, E, x, y;
  Edge     edge;

  while (scanf("%d %d", &W, &H) && W)
  {
    v.clear(), e.clear();
    // reset border
    for (int i = 0; i <= W+1; ++i)
      p[0][i].s = p[H+1][i].s = GRAVE;
    for (int i = 0; i <= H+1; ++i)
      p[i][0].s = p[i][W+1].s = GRAVE;
    for (int i = 1; i <= H; ++i)
      for (int j = 1; j <= W; ++j)
        p[i][j].s = GRASS;
    for ( scanf("%d", &G); G--; )
    {
      scanf("%d %d", &x, &y);
      ++x, ++y;
      p[y][x].s = GRAVE;
    }
    // parse holes
    for ( scanf("%d", &E); E--; )
    {
      scanf("%d %d", &x, &y);
      ++x, ++y;
      p[y][x].s = HOLE;
      scanf("%d %d %d", &p[y][x].x, &p[y][x].y, &p[y][x].t);
      ++p[y][x].x, ++p[y][x].y;
    }

    // parse vertexes
    for (int i = 1; i <= H; ++i)
      for (int j = 1; j <= W; ++j)  
        if ( p[i][j].s != GRAVE )
        {
          v.push_back( Vertex( j, i, INFINITY ) );
          vertices[i][j] = v.size() - 1;
        }
    // parse edges
    for (int i = 1; i <= H; ++i)
      for (int j = 1; j <= W; ++j)
      {
        if ( p[i][j].s == GRAVE || (i == H && j == W) )
          continue;
        edge.from = vertices[i][j];
        edge.dist = 1;
        if ( p[i][j].s == HOLE )
        {
          edge.to   = vertices[ p[i][j].y ][ p[i][j].x ];
          edge.dist = p[i][j].t;
          e.push_back( edge );
          continue;
        }
        for (int k = 0; k < 4; ++k)
        {
          int x = j+steps[k][0], y = i+steps[k][1];
          if ( p[y][x].s != GRAVE )
          {
            edge.to = vertices[y][x];
            e.push_back( edge );
          }
        }
      }
    // print( );
    // set start distance to 0
    v[0].d = 0;

    bool fail   = false;
    int  result = bellman_ford( fail );
    // for ( vector<Vertex>::iterator it = v.begin(); it != v.end(); ++it)
    //   printf("[%d;%d] %d\n", it->x, it->y, it->d);
    // printf("\n");
    // print( );
    // for ( vector<Edge>::iterator it = e.begin(); it != e.end(); ++it)
    //   printf("[%d;%d]->[%d;%d] %d\n", v[ it->from ].x, v[ it->from ].y, v[ it->to ].x, v[ it->to ].y, it->dist);
    // printf("\n");

    if (fail)
      printf("Never\n");
    else if (result == INFINITY)
      printf("Impossible\n");
    else
      printf("%d\n", result);
  }
  return 0;
}
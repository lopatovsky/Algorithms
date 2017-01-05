struct Vec
{
  double x, y;
  Vec(double _x=0.0, double _y=0.0): x(_x), y(_y) {}

  bool operator<(const Vec & v) const { return x < v.x || (x == v.x && y < v.y); }
  Vec operator-(const Vec & v) const { return Vec(x-v.x, y-v.y); }
  //void operator/=(double n) { x /= n; y/=n; }
  //double size() const { return sqrt(x*x+y*y); }
};

/*double dot(const Vec & v1, const Vec & v2)
{
  return v1.x * v2.x + v1.y * v2.y;
}*/

double cross(const Vec & v1, const Vec & v2)
{
  return v1.x * v2.y - v1.y * v2.x;
}

double direction(const Vec & v1, const Vec & v2, const Vec & point)
{
  return cross(point-v1, v2-v1);
}



void convex_hull(vector<Vec> & points, vector<Vec> & hull)
{
  sort(points.begin(), points.end());
  vector<Vec> top, bot;
  REP(i, points.size())
  {
    while (top.size() >= 2 && direction(top[top.size()-2], points[i], top[top.size()-1]) <= 0)
      top.pop_back();  // vymaz (b, b-1)  kym vector (b, b-2) je na lavo od vektoru ( b, b-1 );
    top.push_back(points[i]);

    while (bot.size() >= 2 && direction(bot[bot.size()-2], points[i], bot[bot.size()-1]) >= 0)
      bot.pop_back();  // vymaz (b, b-1)  kym vector (b, b-2) je na pravo od vektoru ( b, b-1 );
    bot.push_back(points[i]);
  }
  reverse(bot.begin(), bot.end());
  hull = top;
  if (bot.size() > 2)
    hull.insert(hull.end(), bot.begin()+1, bot.end()-1);
  // ukladanie bodov v protismere hodinovych ruc.  od najlavejsieho bodu.
}



int main() {
    int n;
    while (scanf("%d", &n) == 1){

        vector<Vec> points(n), hull;
        REP(i, n) scanf("%lf%lf", &points[i].x, &points[i].y);
        convex_hull(points, hull);
        TR(hull,it){
            cout << "point " << it->x << " : " << it->y << endl;
        }
    }

  return 0;
}

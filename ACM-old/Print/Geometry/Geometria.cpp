struct Point{
    double x,y;
};
//vzdialenost na sfere
double greatCircleDistance(double pLat, double pLong,
                            double qLat, double qLong, double radius) {
    pLat *= M_PI / 180; pLong *= M_PI / 180;
    qLat *= M_PI / 180; qLong *= M_PI / 180;

    return radius * acos(
                         cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                         cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
                         sin(pLat)*sin(qLat)
                         );
}


inline double size( Point a){
    return sqrt( a.x*a.x + a.y*a.y);
}
inline double cross( Point a, Point b){
    return a.x*b.y - b.x*a.y;
}
//vzdialenost priamky p(p1,p2) od bodu q
inline double distPointLine(Point p1,Point p2,Point q){
    Point vec, qp1;
    vec.x = p2.x - p1.x;
    vec.y = p2.y - p1.y;
    qp1.x = q.x - p1.x;
    qp1.y = q.y - p1.y;
    return fabs(cross( qp1 , vec))/ size(vec);
}

struct P{
    double x,y;
};

P lineInter( P a1, P a2, P b1, P b2){

    double a,b,c,d,e,f;

    a = a1.y - a2.y;
    b = -1 * (a1.x - a2.x);
    c =  (a * a1.x + b * a1.y); //zodpoveda rovnici a.x + b*y = c;

    d = b1.y - b2.y;
    e = -1 * (b1.x - b2.x);
    f =  (d * b1.x + e * b1.y);

    P ret; ret.x = ( c * e - b * f ) / ( a * e - b * d );
    ret.y = ( c * d - a * f )  / ( b * d - a * e );
    return ret;
}

int main( )
{
    int cs;
    P a1, a2, b1, b2;
    scanf("%d",&cs);
    printf("INTERSECTING LINES OUTPUT\n");
    REP(i,cs){
        scanf("%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y);//!!lf
        scanf("%lf%lf%lf%lf",&b1.x,&b1.y,&b2.x,&b2.y);


        P p = lineInter(a1,a2,b1,b2);



        if(isnan(p.x) && isnan(p.y) ) printf("LINE\n"); // su totozne
        else if (!isfinite(p.x) || !isfinite(p.y)) printf("NONE\n"); // su rovnobezne
        else{
             /*if(pdd.first==0)printf("POINT 0.00");  //pre istotu aby nehadzalo -0.00
            else*/ printf("POINT %.2f",p.x);
            /*if(pdd.second==0) printf(" 0.00\n");
            else*/ printf(" %.2f\n",p.y);
        }
    }
    printf("END OF OUTPUT\n");
	return 0;
}

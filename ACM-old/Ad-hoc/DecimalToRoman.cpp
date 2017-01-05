void unit( int n )
{
  switch(n)
  {
    case 3: printf("I");
    case 2: printf("I");
    case 1: printf("I"); break;
    case 4: printf("I");
    case 5: printf("V"); break;
    case 6: printf("VI"); break;
    case 7: printf("VII"); break;
    case 8: printf("VIII"); break;
    case 9: printf("IX"); break;
  }
}
void ten( int n )
{
  switch( n )
  {
    case 3: printf("X");
    case 2: printf("X");
    case 1: printf("X"); break;
    case 4: printf("XL"); break;
    case 5: printf("L"); break;
    case 6: printf("LX"); break;
    case 7: printf("LXX"); break;
    case 8: printf("LXXX"); break;
    case 9: printf("XC"); break;
  }
}
void hnd( int n )
{
  switch( n )
  {
    case 3: printf("C");
    case 2: printf("C");
    case 1: printf("C"); break;
    case 4: printf("CD"); break;
    case 5: printf("D"); break;
    case 6: printf("DC"); break;
    case 7: printf("DCC"); break;
    case 8: printf("DCCC"); break;
    case 9: printf("CM"); break;
  }
}
void roman( int n )
{
  int a, i;
  if ( n >= 1000 )
  {
    a = n/1000;
    for ( i=1; i <= a; ++i )
      printf("M");
  }
  n = n % 1000;
  hnd( n / 100 );
  n = n % 100;
  ten( n / 10 );
  unit( n % 10 );
}
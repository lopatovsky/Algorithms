int matrix[15][15];
int path  [15][15];

void printPath( int i, int j ) {
  if ( i == j )
    printf(" %d", i);
  else if ( path[i][j] == 0 )
    printf("Path does not exist\n");
  else {
    printPath( i, path[i][j] );
    printf(" %d", j);
  }
}

int main( ) {
// nastaveni matice cest 
FOR( i, 1, n )
  FOR( j, 1, n )
    if ( matrix[i][j] == INF )
      path[i][j] = -1;
    else
      path[i][j] = i;

  FOR( k, 1, n )
    FOR( i, 1, n )
      FOR( j, 1, n )
        if ( matrix[i][j] > matrix[i][k] + matrix[k][j] ) {
          matrix[i][j] = matrix[i][k] + matrix[k][j];
          path  [i][j] = path[k][j];
        }
  printPath( from, to );

  return 0;
}
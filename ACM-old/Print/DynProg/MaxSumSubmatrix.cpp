const int MAXROW = 100;
const int MAXCOL = 100;

int matrix[MAXROW][MAXCOL];

int kadane( int * arr, int & start, int & finish, int n )
{
    int sum = 0, maxSum = INT_MIN;
    finish = -1;

    int local_start = 0;
    FOR( i, 0, n-1 )
    {
        sum += arr[i];
        if ( sum < 0 )
        {
            sum = 0;
            local_start = i + 1;
        }
        else if ( sum > maxSum )
        {
            maxSum = sum;
            start  = local_start;
            finish = i;
        }
    }
    if ( finish != -1 )
        return maxSum;
    maxSum = arr[0];
    start = finish = 0;
    FOR( i, 1, n-1 )
    {
        if ( arr[i] > maxSum )
        {
            maxSum = arr[i];
            start = finish = i;
        }
    }
    return maxSum;
}

int findMaxSum( int row, int col )
{
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right;
    int temp[row], sum, start, finish;

    FOR( left, 0, col - 1 )
    {
        memset( temp, 0, sizeof(temp) );
        FOR( right, left, col-1 )
        {
            FOR( i, 0, row-1 )
                temp[i] += matrix[i][right];
            sum = kadane( temp, start, finish, row );
            if ( sum > maxSum )
            {
                maxSum      = sum;
                finalLeft   = left;
                finalRight  = right;
                finalTop    = start;
                finalBottom = finish;
            }
            maxSum = max( sum, maxSum );
        }
    }
    return maxSum;
}

int main( )
{
    int n;

    while ( scanf("%d", &n) == 1 )
    {
        FOR( i, 0, n-1 )
            FOR( j, 0, n-1 )
                scanf("%d", &matrix[i][j]);
        printf("%d\n", findMaxSum( n, n ));
    }


    return 0;
}

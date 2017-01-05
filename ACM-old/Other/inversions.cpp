#include <iostream>
using namespace std;

const int MAXN = 100000;
const int INF  = 1 << 29;
int arr[MAXN+2], tmp[MAXN+2];
long long cnt;

void merge( int left, int mid, int right ) {
  int i, j, k;

  for ( i = left, j = mid + 1, k = 0; i <= mid && j <= right; ) {
    if ( arr[i] <= arr[j] ) {
      tmp[k++] = arr[i++];
    } else {
      cnt += mid - i + 1;
      tmp[k++] = arr[j++];
    }
  }
  while ( i <= mid )
    tmp[k++] = arr[i++];
  while ( j <= right )
    tmp[k++] = arr[j++];

  for ( i = 0, j = left; i < k; ++i, ++j )
    arr[j] = tmp[i];
}

void mergeSort( int left, int right ) {
  if ( left < right ) {
    int mid = (left+right)/2;
    mergeSort( left, mid );
    mergeSort( mid+1, right );
    merge    ( left, mid, right);
  }
}

int main(){
  int i, n, caseCnt;
  for ( cin >> caseCnt; caseCnt--; ) {
    cnt = 0;
    cin >> n;
    for ( int i = 0; i < n; ++i ) {
       cin >> arr[i];
    }
    mergeSort( 0, n-1 );
    cout << cnt << endl;
  }
  return 0;
}

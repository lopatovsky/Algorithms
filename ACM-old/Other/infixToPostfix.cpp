#include <iostream>
#include <cctype>
#include <stack>
#include <string>
using namespace std;

bool isOperand( const string & s ) {
  return !s.empty( ) && isdigit( s[0] );
}

bool isOperator( const string & s ) {
  return !s.empty( ) && ( s == "+" || s == "-" || s == "*" || s == "/" );
}

int priority( const string & op ) {
  if ( op == "*" || op == "/" )
    return 4;
  if ( op == "+" || op == "-" )
    return 3;
  if ( op == "(" )
    return 2;
  return 1;
}

int main( ) {
  int    t;
  string token;

  cin >> t;
  cin.get( );
  cin.get( );
  for ( int caseNr = 1; caseNr <= t; ++caseNr ) {
    if ( caseNr != 1 )
      cout << endl;
    stack<string> st;
    while ( getline( cin, token ) && !token.empty( ) ) {
      if ( isOperand( token ) ) {
        cout << token;
      } else if ( isOperator( token ) ) {
        for ( ; !st.empty( ) && priority( token ) <= priority( st.top( ) ); st.pop( ) )
          cout << st.top( );
        st.push( token );
      } else if ( token == "(" ) {
        st.push( token );
      } else if ( token == ")" ) {
        for ( ; st.top( ) != "("; st.pop( ) )
          cout << st.top( );
        st.pop( );
      }
    }
    for ( ; !st.empty( ); st.pop( ) )
      if ( st.top( ) != "(" )
        cout << st.top( );
    cout << endl;
  }
  return 0;
}
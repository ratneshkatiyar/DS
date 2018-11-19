#include <iostream>
#include <list>
#include <vector>
#include <map>

#include <bits/stdc++.h>

#define LL long long

using namespace std;

LL
compute( LL x, LL y )
{
    if ( x == 0 || y == 0 )
        return 1;
    return compute( x - 1, y ) + compute( x, y - 1 );
}
string
solve( LL n, LL m, LL k )
{
    if ( n == 0 && m == 0 )
        return "";
    else if ( n == 0 )
    {
        m--;
        return "V" + solve( n, m, k );
    }
    else if ( m == 0 )
    {
        n--;
        return "H" + solve( n, m, k );
    }
    else
    {
        if ( compute( n - 1, m ) > k )
        {
            return "H" + solve( n - 1, m, k );
        }
        else
        {
            return "V" + solve( n, m - 1, k - compute( n - 1, m ) );
        }
    }
}

int
main( )
{
    int t;
    cin >> t;
    while ( t-- )
    {
        long long int n, m, k;
        cin >> n >> m >> k;
        assert( k <= compute( n, m ) );
        solve( n, m, k );
        cout << endl;
    }
    return 0;
}
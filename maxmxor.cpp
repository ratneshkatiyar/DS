#include <iostream>

using namespace std;
int
maxXor( int l, int r, int k )
{
    int max = 0;

    for ( int a = l; a <= r; a++ )
    {
        for ( int b = a + 1; b <= r; b++ )
        {
            max = std::max( max, a ^ b );
            if ( max >= k )
                return k;
        }
    }
    return max;
}
int
main( )
{
    cout << maxXor( 5, 6, 10 ) << endl;
    return 0;
}
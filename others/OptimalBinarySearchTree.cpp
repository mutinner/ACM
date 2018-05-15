/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Tue 15 May 2018 08:24:59 AM CST
 *	File Name     :08:24:59.cpp
 *************************************************** */

#include <cstdio>
#include <cstring>

const int maxn = 100;
const int inf = 1 << 30;
int q[ maxn ], p[ maxn ], m[ maxn ][ maxn ];
int w[ maxn ][ maxn ], root[ maxn ][ maxn ];

int main() {
	int n;	scanf( "%d", &n );
	for ( int i = 1; i <= n; i++ ) scanf( "%d", &p[ i ] );
	for ( int i = 0; i <= n; i++ ) scanf( "%d", &q[ i ] );
	memset( root, 0, sizeof( root ) );
	memset( w, 0, sizeof( w ) );
	memset( m, 0, sizeof( m ) );
	for ( int i = 1; i <= n + 1; i++ ) {
		m[ i ][ i - 1 ] = w[ i ][ i - 1 ] = q[ i - 1 ];
	}
	for ( int r = 0; r < n; r++ ) {
		for ( int i = 1; i <= n - r; i++ ) {
			int j = i + r;
			m[ i ][ j ] = inf;
			w[ i ][ j ] = w[ i ][ j - 1 ] + p[ j ] + q[ j ];
			for ( int k = i; k <= j; k++ ) {
				int t = m[ i ][ k - 1 ] + m[ k + 1 ][ j ] + w[ i ][ j ];
				if ( t < m[ i ][ j ] ) {
					m[ i ][ j ] = t;
					root[ i ][ j ] = k;
				}
			}
		}
	}
	printf( "%d\n", m[ 1 ][ n ] );
	return 0;
}

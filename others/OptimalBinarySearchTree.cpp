/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Mon 14 May 2018 08:48:35 PM CST
 *	File Name     :20:48:35.cpp
 *************************************************** */

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100;
const int inf = 1 << 30;
int q[ maxn ], p[ maxn ], m[ maxn ][ maxn ];
int w[ maxn ][ maxn ], root[ maxn ][ maxn ];

int main() {
	int n;	scanf( "%d", &n );
	for ( int i = 1; i < n + 1; i++ ) scanf( "%d", &p[ i ] );
	for ( int i = 0; i < n + 1; i++ ) scanf( "%d", &q[ i ] );
	memset( root, 0, sizeof( root ) );
	memset( w, 0, sizeof( w ) );
	memset( m, 0, sizeof( m ) );
	for ( int i = 1; i < n + 2; i++ ) {
		root[ i ][ i ] = i;
		m[ i ][ i - 1 ] = w[ i ][ i - 1 ] = q[ i - 1 ];
	}
	for ( int r = 0; r < n; r++ ) {
		for ( int i = 1; i <= n - r; i++ ) {
			int j = i + r;
			m[ i ][ j ] = inf;
			w[ i ][ j ] = w[ i ][ j - 1 ] + p[ j ] + q[ j ];
			for ( int k = root[ i ][ j - 1 ]; k <= root[ i + 1 ][ j ]; k++ ) {
				int t = m[ i ][ k - 1 ] + m[ k + 1 ][ j ] + w[ i ][ j ];
				if ( t < m[ i ][ j ] ) {
					m[ i ][ j ] = t;
					root[ i ][ j ] = k;
				}
			}
		}
	}
	return 0;
}

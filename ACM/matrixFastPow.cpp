/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Thu 13 Sep 2018 02:24:26 PM CST
 *	File Name     :14:24:26.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

template< typename T >
class matrix {
	public :
		int n, m;
		vector< vector< T > > node;

		matrix() {}

		matrix( int n ) : n( n ), m( n ) {
			new( &node ) vector< vector< T > >( n );
			for ( auto& it : node ) {
				new( &it ) vector< T >( m );
			}
		}

		matrix( int n, int m ) : n( n ), m( m ) {
			new( &node ) vector< vector< T > >( n );
			for ( auto& it : node ) {
				new( &it ) vector< T >( m );
			}
		}

		matrix( vector< vector< T > >& arr ) {
			node = arr;
			n = arr.size();
			m = arr.front().size();
		}

		matrix E() {
			matrix ans( n, m );
			for ( int i = 0; i < n; i++ ) ans[ i ][ i ] = ( T ) 1;
			return ans;
		}

		vector< T >& operator []( int x ) {
			return node[ x ];
		}

		matrix operator + ( matrix& cnt ) {
			matrix ans( node );
			for ( int i = 0; i < n; i++ ) {
				for ( int j = 0; j < m; j++ ) ans[ i ][ j ] = ( ans[ i ][ j ] + cnt[ i ][ j ] ) % mod;
			}
			return ans;
		}

		matrix operator * ( matrix& cnt ) {
			matrix ans( n, cnt.m );
			for ( int k = 0; k < m; k++ ) {
				for ( int i = 0; i < n; i++ ) {
					for ( int j = 0; j < cnt.m; j++ ) ans[ i ][ j ] = ( ans[ i ][ j ] + node[ i ][ k ] * cnt[ k ][ j ] ) % mod;
				}
			}
			return ans;
		}

		matrix operator ^ ( ll x ) {
			matrix ans = E(), a( node );
			while ( x ) {
				if ( x & 1 ) ans = ans * a;
				a = a * a;
				x >>= 1;
			}
			return ans;
		}

		friend ostream& operator << ( ostream& output, const matrix& ans ) {
			for ( int i = 0; i < ans.n; i++ ) {
				for ( int j = 0; j < ans.m; j++) output << ans.node[ i ][ j ] << "  ";
				output << endl;
			}
			return output;
		}
};

int main() {
	return 0;
}

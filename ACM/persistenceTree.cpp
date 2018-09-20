/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Wed 19 Sep 2018 04:48:33 PM CST
 *	File Name     :persistenceTree.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template< typename T >
class node {
	public :
		int L, R, l, r;
		T val;

		node() {}

		node( int L, int R, int l, int r, T val ) : L( L ), R( R ), l( l ), r( r ), val( val ) {}
};

template< typename T >
class PerTree {
	public :
		int n, cur;
		vector< int > root;
		vector< node< T > > cnt;

		PerTree() {}

		PerTree( int n, int m ) : PerTree( vector< T >( n ), m ) {}

		PerTree( const vector< T >& arr, int m ) : n( arr.size() ), cur( 0 ) {
			new( &cnt ) vector< node< T > >( 40 * n );	// 4n + mlogn
			root.push_back( build( 0, n - 1, arr ) );
		}

		int build( int l, int r, const vector< T >& arr ) {
			int x = cur++;
			if ( l == r ) { new( &cnt[ x ] ) node< T >( -1, -1, l, r, arr[ l ] ); }
			else {
				int mid = l + r >> 1;
				new( &cnt[ x ] ) node< T >( build( l, mid, arr ), build( mid + 1, r, arr ), l, r, 0 );
				pushup();
			}
			return x;
		}

		void pushup() {}

		void update( int old, int pos, T val ) {
			root.push_back( dfs( old, pos, val ) );
		}

		int dfs( int old, int pos, T val ) {
			int x = cur++;
			cnt[ x ] = cnt[ old ];
			cnt[ x ].val = val;
			if ( cnt[ x ].l != cnt[ x ].r ) {
				int mid = cnt[ x ].l + cnt[ x ].r >> 1;
				if ( pos < mid + 1 ) cnt[ x ].L = dfs( cnt[ old ].L, pos, val );
				else cnt[ x ].R = dfs( cnt[ old ].R, pos, val );
			}
			return x;
		}

		T query( int x, int pos ) {
			if ( cnt[ x ].l == cnt[ x ].r ) return cnt[ x ].val;
			int mid = cnt[ x ].l + cnt[ x ].r >> 1;
			return query( ( pos < mid + 1 ) ? cnt[ x ].L : cnt[ x ].R, pos );
		}

};

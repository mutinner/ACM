/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Wed 22 Aug 2018 04:34:09 PM CST
 *	File Name     :zkw.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

template< typename T >
class node {
	public :
		T val;

		node() {}

		node( T& x ) {
			val = x;
		}
};


template< typename T >
class tree {
	public :
		int bit = 1;
		vector< node< T > > cnt;

		tree( vector< T >& arr ) {
			while ( bit < arr.size() + 2 ) bit <<= 1;
			new( &cnt ) vector< node< T > >( bit << 1 );
			for ( int i = 0; i < arr.size(); i++ )
				new( &cnt[ i + bit + 1 ] ) node< T >( arr[ i ] );
			for ( int i = bit - 1; i; i-- ) pushup( i );
		}

		/*
		 *void pushup( int x ) {
		 *    cnt[ x ].val = cnt[ x << 1 ].val + cnt[ x << 1 | 1 ].val;
		 *    cnt[ x ].maxval = max( cnt[ x << 1 ].maxval, cnt[ x << 1 | 1 ].maxval );
		 *    cnt[ x ].minval = min( cnt[ x << 1 ].minval, cnt[ x << 1 | 1 ].minval );
		 *}
		 */

		void pushup( int x ) {
			if ( !x ) return ;
			T val = min( cnt[ x << 1 ].val, cnt[ x << 1 | 1 ].val );
			cnt[ x ].val += val;
			cnt[ x << 1 ].val -= val;
			cnt[ x << 1 | 1 ].val -= val;
		}

		void update( int x, T val ) {
			cnt[ x += bit ].val += val;
			while ( x ) pushup( x >>= 1 );
		}

		void update( int L, int R, T val ) {
			for ( L += bit - 1, R += bit + 1; L ^ R ^ 1; L >>= 1, R >>= 1 ) {
				if ( ~ L & 1 ) cnt[ L ^ 1 ].val += val;
				if ( R & 1 ) cnt[ R ^ 1 ].val += val;
				pushup( L >> 1 );
				pushup( R >> 1 );
			}
			while ( L ) pushup( L >>= 1 );
		}

		T query( int x ) {
			T ans = cnt[ x += bit ].val;
			while ( x ) ans += cnt[ x >>= 1 ].val;
			return ans;
		}

		T query( int L, int R ) {
			T ans = 0;
			for ( L += bit - 1, R += bit + 1; L ^ R ^ 1; L >>= 1, R >>= 1 ) {
				if ( ~ L & 1 ) ans += cnt [ L ^ 1 ].val;
				if ( R & 1 ) ans += cnt[ R ^ 1 ].val;
			}
			return ans;
		}

		template< typename F >
		T query( int L, int R, F func ) {
			if ( L == R ) return query( L );
			T Lans = 0, Rans = 0;
			for ( L += bit, R += bit; L ^ R ^ 1; L >>= 1, R >>= 1 ) {
				Lans += cnt[ L ].val;	Rans += cnt[ R ].val;
				if ( ~ L & 1 ) Lans = func( Lans, cnt[ L ^ 1 ].val );
				if ( R & 1 ) Rans = func( Rans, cnt[ R ^ 1 ].val );
			}
			T ans = func( Lans + cnt[ L ].val, Rans + cnt[ R ].val );
			while ( L ) ans += cnt[ L >>= 1 ].val;
			return ans;
		}
};

int main() {
	int n;	cin >> n;
	vector< int > arr( n );
	for ( auto& it : arr ) cin >> it;
	tree< int > cnt( arr );
	for ( auto& it : cnt.cnt ) cout << it.val << endl;
	cout << cnt.query( 2, n, []( int x, int y ) {
			return min( x, y );
			} );
	return 0;
}

/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Sat 28 Jul 2018 11:23:24 AM CST
 *	File Name     :11:23:24.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1 << 30;

class node {
public :
	int sz, val, tag;
	node *ch[ 2 ], *fa;

	void pushup() {
		sz = 1;
		for ( auto& it : ch )  sz += it -> sz;
	}

	void pushdown() {
		if ( tag ) {
			swap( ch[ 0 ], ch[ 1 ] );
			for ( auto& it : ch ) it -> tag ^= 1;
			tag ^= 1;
		}
	}
};

void hhh() {
	cout << " hhh " << endl;
}

class Splay {
public :
	node *tot, *root, *arr, *zero;
	int sz;

	void init( vector< int >& a ) {
		arr = new node[ maxn * 32 ];
		tot = arr + 1;
		zero = arr;
		zero -> val = -1;
		sz = a.size();
		root = build( 1, a.size(), NULL, a );
	}

	node* build( int L, int R, node* pre, vector< int >& a ) {
		if ( L > R ) return zero;
		node* nd = tot++;
		int mid = L + R >> 1;
		nd -> fa = pre;
		nd -> val = a[ mid - 1 ];
		nd -> ch[ 0 ] = build( L, mid - 1, nd, a );
		nd -> ch[ 1 ] = build( mid + 1, R, nd, a );
		nd -> pushup();
		return nd;
	}

	bool son( node* x ) {
		return x -> fa -> ch[ 1 ] == x;
	}

	void rotate( node* x ) {
		node* y = x -> fa;
		node* z = y -> fa;
		int k = son( x );
		if ( z != NULL ) z -> ch[ son( y ) ] = x;
		y -> ch[ k ] = x -> ch[ k ^ 1 ];
		if ( x -> ch[ k ^ 1 ] != zero ) x -> ch[ k ^ 1 ] -> fa = y;
		x -> ch[ k ^ 1 ] = y;
		y -> fa = x;
		x -> fa = z;
		y -> pushup();
		x -> pushup();
	}

	void splay( node* x, node* top = NULL ) {
		while ( x -> fa != top ) {
			node* y = x -> fa;
			if ( y -> fa != NULL && y -> fa != top ) {
				rotate( son( x ) ^ son( y ) ? x : y );
			}
			rotate( x );
		}
		if ( top == NULL ) root = x;
	}
	
	node* find( int pos ) {
		node* x = root;
		while ( 1 ) {
			x -> pushdown();
			if ( pos < x -> ch[ 0 ] -> sz + 1 ) {
				x = x -> ch[ 0 ];
			} else if ( pos > x -> ch[ 0 ] -> sz + 1 ) {
				pos -= x -> ch[ 0 ] -> sz + 1;
				x = x -> ch[ 1 ];
			} else {
				splay( x );
				return x;
			}
		}
	}

	void reverse( int x, int y ) {
		node* L = find( x - 1 );
		node* R = find( y + 1 );
		splay( L );
		splay( R, L );
		node* ls = R -> ch[ 0 ];
		ls -> tag ^= 1;
		ls -> pushdown();
		splay( ls );
	}

	void show( node* x, int h = 1 ) {
		for ( auto& it : x -> ch ) {
			if ( it != zero ) show( it, h + 1 );
		}
	}

	void bug() {
		for ( int i = 2; i < sz; i++ ) cout << find( i ) -> val << " \n"[ i == sz - 1 ];
	}
};

int main() {
	int n;	cin >> n;
	vector< int > arr( n + 2 );
	iota( arr.begin(), arr.end(), 0 );
	Splay cnt;	cnt.init( arr );
	cnt.bug();
	while ( 1 ) {
		int L, R;	cin >> L >> R;
		cnt.reverse( L + 1, R + 1 );
		cnt.bug();
	}
	return 0;
}

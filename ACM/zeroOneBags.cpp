/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Sun 06 May 2018 03:38:09 PM CST
 *	File Name     :15:38:09.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

//	pair< weight, value >
int zeroOneBag( vector< pair< int, int > >& cnt, int w ) {
	vector< int > dp( w + 1 );
	int sz = cnt.size();
	int sum = accumulate( cnt.begin(), cnt.end(), 0, []( int val, pair< int, int > x ) {
			return x.first;
			} );
	for ( int i = 0; i < sz; i++ ) {
		int bound = max( w - sum, cnt[ i ].first );
		for ( int j = w; j >= bound; j-- ) {
			dp[ j ] = max( dp[ j ], dp[ j - cnt[ i ].first ] + cnt[ i ].second );
		}
		sum -= cnt[ i ].first;
	}
	return dp[ w ];
}

int zeroOneBagSwap( vector< pair< int, int > >& cnt, int w ) {
	int sum = accumulate( cnt.begin(), cnt.end(), 0, []( int val, pair< int, int > x ) {
			return x.first;
			} );
	const int inf = 1 << 30;
	int sz = cnt.size();
	vector< int > dp( sum + 1, inf );	dp[ 0 ] = 0;
	for ( int i = 0; i < sz; i++ ) {
		for ( int j = sum; j >= cnt[ i ].second; j-- ) {
			dp[ j ] = min( dp[ j ], dp[ j - cnt[ i ].second ] + cnt[ i ].first );
		}
	}
	for ( int i = num; i >= 0; i-- ) {
		if ( dp [ i ] < w ) {
			return i;
		}
	}
}

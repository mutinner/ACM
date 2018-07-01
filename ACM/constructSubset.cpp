/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Tue 29 May 2018 09:59:25 PM CST
 *	File Name     :constructSubset.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class constructSubset {
public:
	int n, k;	ll x;
	constructSubset( int n, int k ) {
		this->n = n;
		this->k = k;
		x = ( 1LL << k ) - 1;
	}
	ll next_subset() {
		ll b = x & -x;
		ll c = ( x + b ) ^ x;
		ll m = ( c >> 2 ) / b;
		x = ( x + b ) | m;
		return x < ( 1LL << n ) ? x : x = 0;
	}
};

int main() {
	int n, k;	cin >> n >> k;
	for ( auto it = constructSubset( n, k ); it.x != 0; it.next_subset() ) {
		//cout << bitset< 10 >( it.x ) << endl;
	}
	return 0;
}

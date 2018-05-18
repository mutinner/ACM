/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Thu 17 May 2018 02:25:20 PM CST
 *	File Name     :14:25:20.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

int josephus( int n, int m ) {
	return n == 1 ? 0 : ( josephus( n - 1, m ) + m ) % n;
}

int main() {
	int T;	cin >> T;
	while ( T-- ) {
		int n, k;	cin >> n >> k;
		cout << josephus( n - 1, k ) << endl;
	}
	return 0;
}

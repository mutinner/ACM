/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Wed 01 Aug 2018 07:38:03 PM CST
 *	File Name     :DescartesTree.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

class node {
public :
	int index, val;
	node *L, *R, *fa;

	void setnode( int index, int val ) {
		this -> index = index;
		this -> val = val;
		this -> L = this -> R = this -> fa = NULL;
	}
};

class DTree {
public :
	node *arr, *root;

	DTree( vector< int >& a ) {
		arr = new node[ a.size() ];
		root = build( a );
	}

	node* build( vector< int >& a ) {
		stack< node* > cnt;
		for ( int i = 0; i < a.size(); i++ ) {
			node* cur = arr + i;
			cur -> setnode( i, a[ i ] );
			while ( !cnt.empty() ) {
				node* x = cnt.top();
				if ( x -> val > cur -> val ) {
					if ( x -> R ) {
						x -> R -> fa = cur;
						cur -> L = x-> R;
					}
					x -> R = cur;
					cur -> fa = x;
					break;
				}
				cnt.pop();
				if ( cnt.empty() ) {
					x -> fa = cur;
					cur -> L = x;
				}
			}
			cnt.push( cur );
		}
		while ( cnt.size() != 1 ) cnt.pop();
		return cnt.top();
	}
};

int main() {
}

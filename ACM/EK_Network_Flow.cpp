/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Sat 15 Sep 2018 08:51:55 PM CST
 *	File Name     :EK_Network_Flow.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template< typename T >
class EKflow {
	public :
		int n, m;
		vector< vector< T > > G;
		T ans;

		EKflow() {}

		EKflow( int n ) : n( n ) {
			new( &G ) vector< vector< T > >( n );
			for ( auto& it : G ) {
				new( &it ) vector< T >( n );
			}
			ans = ( T )0;
		}

		void add( int u, int v, T val ) {
			G[ u ][ v ] += val;
		}

		bool bfs( int s, int t ) {
			vector< int > vis( n ), pre( n, -1 );
			vis[ s ] = 1;
			T flow = 1 << 30;
			queue< int > q;
			q.push( s );
			while ( !q.empty() ) {
				int u = q.front();	q.pop();
				if ( u == t ) break;
				for ( int i = 0; i < n; i++ ) {
					if ( !vis[ i ] && G[ u ][ i ] != 0 ) {
						q.push( i );
						flow = min( flow, G[ u ][ i ] );
						pre[ i ] = u;
						vis[ i ] = 1;
					}
				}
			}
			ans += pre[ t ] != -1 ? flow : 0;
			int u = t;
			while ( pre[ u ] != -1 ) {
				G[ pre[ u ] ][ u ] -= flow;
				G[ u ][ pre[ u ] ] += flow;
				u = pre[ u ];
			}
			return pre[ t ] != -1;
		}

		T get( int s, int t ) {
			while ( bfs( s, t ) ) ;
			return ans;
		}

		friend ostream& operator << ( ostream& output, const EKflow& ans ) {
			for ( int i = 0; i < ans.n; i++ ) {
				for ( int j = 0; j < ans.n; j++ ) output << ans.G[ i ][ j ] << ' ';
				output << endl;
			}
			return output;
		}
};


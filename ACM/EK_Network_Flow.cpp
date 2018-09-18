/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Sat 15 Sep 2018 08:51:55 PM CST
 *	File Name     :EK_Network_Flow.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

template< typename T >
class edge {
	public :
		int u, v;
		T val;
		int nxt;

		edge() {}

		edge( int u, int v, T val, int nxt ) :
			u( u ), v( v ), val( val ), nxt( nxt ) {}
};

template< typename T >
class EKflow {
	public :
		int n;
		vector< int > head;
		vector< edge< T > > G;
		T ans;

		EKflow() {}

		EKflow( int n ) : n( n ) {
			new( &head ) vector< int >( n, -1 );
			ans = ( T )0;
		}

		void add( int u, int v, T val ) {
			G.push_back( edge< T >( u, v, val, head[ u ] ) );
			head[ u ] = G.size() - 1;
			G.push_back( edge< T >( v, u, 0, head[ v ] ) );
			head[ v ] = G.size() - 1;
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
				for ( int i = head[ u ]; i != -1; i = G[ i ].nxt ) {
					int v = G[ i ].v;
					if ( !vis[ v ] && G[ i ].val > 0 ) {
						q.push( v );
						flow = min( flow, G[ i ].val );
						pre[ v ] = i;
						vis[ v ] = 1;
					}
				}
			}
			ans += pre[ t ] != -1 ? flow : 0;
			if ( pre[ t ] == -1 ) return false;
			int u = t;
			while ( u != s ) {
				G[ pre[ u ] ].val -= flow;
				G[ pre[ u ] ^ 1 ].val += flow;
				u = G[ pre[ u ] ].u;
			}
			return pre[ t ] != -1;
		}

		T get( int s, int t ) {
			while ( bfs( s, t ) ) ;
			return ans;
		}

};

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
				int u = q.front();    q.pop();
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

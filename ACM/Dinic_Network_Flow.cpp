/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Mon 17 Sep 2018 12:07:27 PM CST
 *	File Name     :Dinic_Network_Flow.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;

template< typename T >
class edge {
	public :
		int v, val, nxt;

		edge() {}

		edge( int v, int val, int nxt ) :
			v( v ), val( val ), nxt( nxt ) {}
};

template< typename T >
class Dinic {
	public :
		int n;
		vector< int > head;
		vector< edge< T > > G;
		T ans;

		Dinic() {}

		Dinic( int n ) : n( n ) {
			new( &head ) vector< int >( n, -1 );
			ans = ( T )0;
		}

		void add( int u, int v, T val ) {
			G.push_back( edge< T >( v, val, head[ u ] ) );
			head[ u ] = G.size() - 1;
			G.push_back( edge< T >( u, 0, head[ v ] ) );
			head[ v ] = G.size() - 1;
		}

		bool bfs( int s, int t, vector< int >& dis ) {
			fill( dis.begin(), dis.end(), 0 );
			queue< int > q;
			q.push( s );
			dis[ s ] = 1;
			while ( !q.empty() ) {
				int u = q.front();	q.pop();
				for ( int i = head[ u ]; i != -1; i = G[ i ].nxt ) {
					int v = G[ i ].v;
					if ( G[ i ].val > 0 && !dis[ v ] ) {
						dis[ v ] = dis[ u ] + 1;
						q.push( v );
						if ( v == t ) return true;
					}
				}
			}
			return dis[ t ] != 0;
		}

		T dfs( int u, int t, T flow, vector< int >& dis ) {
			if ( u == t ) return flow;
			T cur = 0;
			for ( int i = head[ u ] ; i != -1; i = G[ i ].nxt ) {
				int v = G[ i ].v;
				if ( G[ i ].val > 0 && dis[ v ] == dis[ u ] + 1 ) {
					T val = dfs( v, t, min( flow - cur, G[ i ].val ), dis );
					G[ i ].val -= val;
					G[ i ^ 1 ].val += val;
					cur += val;
					if ( cur == flow ) break;
				}
			}
			if ( !cur ) dis[ u ] = -1;
			return cur;
		}

		T get( int s, int t ) {
			vector< int > dis( n );
			while ( bfs( s, t, dis ) ) {
				ans += dfs( s, t, inf, dis );
			}
			return ans;
		}

};

int main() {
	ios::sync_with_stdio( false );
	cin.tie( 0 );	cout.tie( 0 );
	int T, cs = 0;	cin >> T;
	while ( T-- ) {
		int n, m;	cin >> n >> m;
		Dinic< int > cnt( n );
		for ( int i = 0; i < m; i++ ) {
			int u, v, val;	cin >> u >> v >> val;
			u--;	v--;
			cnt.add( u, v, val );
		}
		cout << "Case " << ++cs << ": " << cnt.get( 0, n - 1 ) << endl;
	}
	return 0;
}

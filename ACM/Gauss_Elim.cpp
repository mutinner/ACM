/* ***************************************************
 *	Author        :mutinner
 *	Created Time  :Sun 07 Oct 2018 08:37:28 PM CST
 *	File Name     :Gauss_Elim.cpp
 *************************************************** */

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
vector<double> Gauss(vector<vector<double>>& a, vector<double>& x) {
	int n = a.size();
	int m = a[0].size();
	vector<double> ans(m);
	vector<int> pos(n), free;
	int z = 0;
	for (int i = 0; i < m && z < n; i++, z++) {
		int r = z;
		for (int j = z + 1; j < n; j++) {
			if (abs(a[j][i]) - abs(a[r][i]) > eps) r = j;
		}
		if (abs(a[r][i]) <= eps) {
			free.push_back(i);
			z--;
			continue;
		}
		swap(a[z], a[r]);
		swap(x[z], x[r]);
		x[z] /= a[z][i];
		for (int j = i + 1; j < m; j++) a[z][j] /= a[z][i];
		a[z][i] = 1;
		for (int j = z + 1; j < n; j++) {
			if (abs(a[j][i]) > eps) {
				x[j] -= x[z] * a[j][i];
				for (int k = i + 1; k < m; k++) {
					if (abs(a[z][k]) > eps) a[j][k] -= a[z][k] * a[j][i];
				}
				a[j][i] = 0;
			}
		}
		ans[i] = x[z];
		pos[z] = i;
	}
	for (int i = z; i < n; i++) if (abs(x[i]) > eps) return vector<double>();
	// TODO: enumerate free_x
	for (int i = z - 1; i >= 0; i--) {
		for (int j = pos[i] + 1; j < m; j++) {
			if (abs(a[i][j]) > eps) ans[pos[i]] -= a[i][j] * ans[j];
		}
	}
	return ans;
}

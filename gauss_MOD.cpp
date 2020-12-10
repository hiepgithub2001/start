#include <bits/stdc++.h>
#define TASK "something"
#define int long long
using namespace std;

const int N = 15;
const int MOD = 1e6 + 3;
int A[N][N];

void add(int &a, int b) { a = (((a + b) % MOD) + MOD) % MOD; }
int Power(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	int t = Power (a, b / 2);
	if (b % 2 == 0)
		return t * t % MOD;
	return t * t % MOD * a % MOD;
}

void answer() {
	int n = 11;
    for (int i=0; i<11; i++) {
        int maxRow = i;
        for (int k=i+1; k<11; k++) {
            if (abs(A[k][i]) > 0){
                maxRow = k;
                continue;
            }
        }

        for (int k=i; k<n+1;k++) {
            int tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        for (int k=i+1; k<n; k++) {
            // double c = -A[k][i]/A[i][i];
            int c = ((-A[k][i] * Power (A[i][i], MOD - 2) % MOD) + MOD) % MOD;
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    // A[k][j] += c * A[i][j];
                    add (A[k][j], c * A[i][j]);
                }
            }
        }
    }

    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        // x[i] = A[i][n]/A[i][i];
        x[i] = A[i][n] * Power (A[i][i], MOD - 2) % MOD;
        for (int k=i-1;k>=0; k--) {
            // A[k][n] -= A[k][i] * x[i];
            add (A[k][n], -A[k][i] * x[i]);
        }
    }

    for (int val = 0; val < MOD; val++) {
    	int sum = 0;
    	for (int i = 0; i < n; i++) {
    		add (sum, x[i] * Power (val, i));
    	}
    	if (sum == 0) {
    		cout << "! " << val << '\n';
    		exit (0);
    	}
    }

    cout << "! -1\n";
    exit (0);
}

void ask(int v) {
	int sum = 0;
	cout << "? " << v << '\n';
	cout.flush(); cin >> sum;
	for (int i = 0; i <= 10; i++) {
		A[v][i] = Power (v, i);
	}
	A[v][11] = sum;
}

main() {
	ios :: sync_with_stdio(0);
	cin.tie (0); cout.tie (0);

	if (fopen ("main.in", "r"))
		freopen ("main.in", "r", stdin);
	else if (fopen (TASK".inp", "r"))
		freopen (TASK".inp", "r", stdin),
		freopen (TASK".out", "w", stdout);

	for (int i = 0; i <= 10; i++)
		ask (i);

	answer();

	return 0;
}
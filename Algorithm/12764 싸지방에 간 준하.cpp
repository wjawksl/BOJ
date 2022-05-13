#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define FIO ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define INF 1e9
using namespace std;

struct Person {
	int s;
	int e;
	int n;
};
struct cmp1 {
	bool operator()(Person p1, Person p2) {
		if (p1.s > p2.s)
			return true;
		else return false;
	}
};
struct cmp2 {
	bool operator()(Person p1, Person p2) {
		if (p1.e > p2.e)
			return true;
		else return false;
	}
};
priority_queue<Person, vector<Person>, cmp1> wait;
priority_queue<Person, vector<Person>, cmp2> use;
int seat[100005];
int N, P, Q, curIdx = 0, maxIdx = 0, minN = INF;
int main() {

	FIO;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> Q;
		Person p = { P,Q, 1 };
		wait.push(p);
	}
	
	while (!wait.empty()) {
		if (use.empty()) {
			use.push(wait.top());
			
			seat[use.size()]++;
		}
		else {
			if (use.top().e > wait.top().s) {
				int size = use.size();
				use.push({ wait.top().s, wait.top().e, size+1 });
				
				maxIdx = max(size + 1, maxIdx);
				seat[use.size()]++;
			}
			else {
				minN = INF;
				while (!use.empty() && use.top().e < wait.top().s) {
					minN = min(use.top().n, minN);
					use.pop();
				}
				if (use.empty()) {
					use.push(wait.top());

					seat[use.size()]++;
				}
				else {
					use.push({ wait.top().s, wait.top().e, minN });
					seat[minN]++;
				}				
			}
		}
		wait.pop();
	}
	cout << maxIdx << "\n";
	for (int i = 1; i <= maxIdx; i++) {
		cout << seat[i] << " ";
	}
	return 0;
}
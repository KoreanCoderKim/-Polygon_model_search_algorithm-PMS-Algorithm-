#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> Logical;
static vector<int> visited;
static int NodeCNT;
bool binarysearch(int find, int s, int e);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int answer = 0;

	cin >> NodeCNT;
	Logical.resize(NodeCNT+1);
	int LAA = 0;

	while (true) {
		int S,E;
		cin >> S;
		if (S == -1) {
			break;
		}
		cin >> E;
		Logical[S].push_back(E);
		LAA = S;
	}

	int now = 1;
	bool chek = false;

	while (now <= LAA) {
		int indegree = Logical[now].size();
		if (indegree == 2) {
			visited.push_back(now);
			answer += 1;
		    sort(visited.begin(),visited.end());
			for (int i : Logical[now]) {
				if (!binarysearch(i, 0, visited.size()-1)) {
					now = i;
					chek = true;
					break;
				}
			}
			if (!chek) {
				break;
			}
			chek = false;
		}
		else {
			cout << "No Shape..." << "\n";
			return 0;
		}
	}
	cout << answer << "\n";
	return 1;
}

bool binarysearch(int find, int s, int e) {
	while (s <= e) {
		int midi = (s + e) / 2;
		int midv = visited[midi];
		if (midv < find) {
			s = midi + 1;
		}
		else if (midv > find) {
			e = midi - 1;
		}
		else {
			return true;
		}
	}
	return false;
}

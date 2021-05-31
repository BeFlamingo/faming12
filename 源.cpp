#include <iostream>
using namespace std;
int m;//色数
int point;//点数
int edge;//边数
int total = 0;//总数
int Graph[100][100] = { 0 };//两点连接与否
int x[100] = { 0 };//颜色用整数表示

bool IsOk(int i){
	for (int j = 1; j < i; ++j) {
		if (Graph[i][j] == 1 && x[j] == x[i]) {
			return false;
		}
	}
	return true;
}

void BackTrack(int i){
	int j;
	if (i > point){
		cout << "方案" << ++total << ":";
		for (j = 1; j <= point; ++j){
			cout << x[j];
		}
		cout << endl;
		return;
	}
	else{
		for (j = 1; j <= m; ++j){
			x[i] = j;
			if (IsOk(i)) {
				BackTrack(i + 1);
			}
			x[i] = 0;
		}
	}
}

int main(){
	int p1, p2;
	cout << "输入点数、色数、边数:";
	cin >> point >> m >> edge;
	cout << "输入每个点的起点和终点:\n";
	for (int i = 1; i <= edge; ++i){
		cin >> p1 >> p2;
		Graph[p1][p2] = 1;
		Graph[p2][p1] = 1;
	}
	BackTrack(1);
	if (total > 0) {
		cout << "一共有" << total << "种方案\n";
	}
	else {
		cout << "NO\n";
	}
}

/*4 3 5
1 2
1 3
1 4
2 3
2 4*/
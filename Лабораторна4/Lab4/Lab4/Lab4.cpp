using namespace std;
#include <stdio.h>
#include <iostream>

#define V 11

int graph[V][V] = {
	{0, 4, 3, 7, 0, 0, 0, 0, 0, 0, 0},
	{4, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0},
	{3, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0},
	{7, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0},
	{0, 2, 1, 0, 0, 0, 0, 4, 7, 0, 0},
	{0, 0, 7, 2, 0, 0, 0, 4, 0, 5, 0},
	{0, 1, 0, 2, 0, 0, 0, 0, 3, 3, 0},
	{0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 4},
	{0, 0, 0, 0, 7, 0, 3, 0, 0, 0, 6},
	{0, 0, 0, 0, 0, 5, 3, 0, 0, 0, 5},
	{0, 0, 0, 0, 0, 0, 0, 4, 6, 5, 0}
};

int main() {

	int no_edge;           
	int selected[V];
	memset(selected, false, sizeof(selected));

	no_edge = 0;

	selected[0] = true;

	int x;           
	int y;            

	cout << "Edge" << " : " << "Weight";
	cout << endl;
	while (no_edge < V - 1) {


		int min = INT_MAX;
		x = 0;
		y = 0;

		for (int i = 0; i < V; i++) {
			if (selected[i]) {
				for (int j = 0; j < V; j++) {
					if (!selected[j] && graph[i][j]) { 
						if (min > graph[i][j]) {
							min = graph[i][j];
							x = i;
							y = j;
						}

					}
				}
			}
		}
		cout << x + 1 << " - " << y + 1 << " : " << graph[x][y];
		cout << endl;
		selected[y] = true;
		no_edge++;
	}

	return 0;
}
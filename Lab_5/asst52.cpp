#include <iostream>
#include <queue>
using namespace std;

struct QueueNode {
	int position; // Current position on the board
	int distance; // Distance from the start
};

int getMinimumThrows(int moves[], int boardSize) {
	bool* visited = new bool[boardSize];
	for (int i = 0; i < boardSize; i++)
		visited[i] = false;

	queue<QueueNode> queue;

	visited[0] = true;
	QueueNode startNode = {0, 0};
	queue.push(startNode);

	QueueNode currentNode;
	while (!queue.empty()) {
		currentNode = queue.front();
		int currentPosition = currentNode.position;

		if (currentPosition == boardSize - 1)
			break;

		queue.pop();
		for (int nextPosition = currentPosition + 1; nextPosition <= currentPosition + 6 && nextPosition < boardSize; ++nextPosition) {
			if (!visited[nextPosition]) {
				QueueNode nextNode;
				nextNode.distance = currentNode.distance + 1;
				visited[nextPosition] = true;

				if (moves[nextPosition] != -1)
					nextNode.position = moves[nextPosition];
				else
					nextNode.position = nextPosition;
				queue.push(nextNode);
			}
		}
	}

	return currentNode.distance;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "r", stdin);
        freopen("output2.txt", "w", stdout);
    #endif

	int boardSize;
    cin >> boardSize;
	int *paths = new int[boardSize];

	for (int i = 0; i < boardSize; i++)
		paths[i] = -1;

    int ladders, snakes;
    cin >> ladders >> snakes;

    for (int i = 0; i < ladders; i++){
        int a, b;
        cin >> a >> b;
        paths[a] = b;
    }

    for (int i = 0; i < snakes; i++){
        int a, b;
        cin >> a >> b;
        paths[a] = b;
    }
	// // Ladders
	// paths[2] = 21; paths[4] = 7; paths[10] = 25; paths[19] = 28;

	// // Snakes
	// paths[26] = 0; paths[20] = 8; paths[16] = 3; paths[18] = 6;

	cout << "Minimum dice throws required is " << getMinimumThrows(paths, boardSize);
	return 0;
}

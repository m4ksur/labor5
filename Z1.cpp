#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int max_size = 6, i, j, start;
bool* vektor = (bool*)malloc(max_size * sizeof(bool));


void DFS(int st, int** b, int num_of_elem, bool* visited) {
	queue<int> Q;
	int t;

	Q.push(st);
	visited[st] = true;
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		printf("%d ", t + 1);
		for (int i = 0; i < num_of_elem; i++)
		{
			if (b[t][i] == 1 && !visited[i])
			{
				Q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));


	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = i + 1; j < max_size; j++)
		{
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}

	for (i = 0; i < max_size; i++)
	{
		vektor[i] = false;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}


	///////////////////////////////////////

	printf("\nÎáõîä ãðàôà â øèðèíó\ncòàðòîâàÿ âåðøèíà - ");
	scanf_s("%d", &start);
	printf("Âûâîä: ");
	DFS(start - 1, a, max_size, vektor);
}
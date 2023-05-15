// Algoritma Analizi ve Tasarýmý Dersi Kýsa Sýnav 2 1.Kýsým
// Ahmet Tayyip Aðzýgüzel
// 1210505008

#include <iostream>
#include <vector>
#include <ctime>
#include <climits>
#include <algorithm>

#define ARRAY_SIZE 20
#define GRAPH_SIZE 10
#define MAX_WEIGHT 10

// Sýnýrsýz sayý için sonsuz sayý
#define INF INT_MAX

using namespace std;

void generateRandomArray(vector<int>& array, int size);
void bubbleSort(vector<int>& array, int size);
int findAverageMaximumSubarraySum(vector<int>& array, int size);
void floydWarshallAlgorithm(vector<vector<int> >& graph, vector<vector<int> >& dist, int size);
void printArray(vector<int>& array, int size);
void printMatrix(vector<vector<int> >& matrix, int size);
void printShortestPaths(vector<vector<int> >& dist, int size, int threshold);

int main() {
	
	cout << "Algoritma Analizi ve Tasarimi Dersi Kisa Sinav 2 1.Kisim" << endl;
	cout << "Ahmet Tayyip Agziguzel" << endl;
	cout << "1210505008" << endl;
	cout << "****************************************************************************" << endl;
	
    vector<int> array(ARRAY_SIZE);
    int graph_data[GRAPH_SIZE][GRAPH_SIZE] = {
        { 0, 10, 3, 0, 0, 5, 0, 17, 0, 22},
        {10, 0, 5, 0, 2, 0, 13, 0, 0, 0},
        { 3, 5, 0, 2, 0, 4, 0, 21, 0, 11},
        { 0, 0, 2, 0, 7, 0, 6, 0, 0, 0},
        { 0, 2, 0, 7, 0, 6, 0, 0, 19, 0},
        { 5, 0, 4, 0, 6, 0, 9, 3, 0, 0},
        { 0, 13, 0, 6, 0, 9, 0, 4, 0, 0},
        {17, 0, 21, 0, 0, 3, 4, 0, 8, 0},
        { 0, 0, 0, 0, 19, 0, 0, 8, 0, 5},
        {22, 0, 11, 0, 0, 0, 0, 0, 5, 0}
    };
    vector<vector<int> > graph(GRAPH_SIZE, vector<int>(GRAPH_SIZE));
    for (int i = 0; i < GRAPH_SIZE; i++) {
        for (int j = 0; j < GRAPH_SIZE; j++) {
            graph[i][j] = graph_data[i][j];
        }
    }
    vector<vector<int> > dist(GRAPH_SIZE, vector<int>(GRAPH_SIZE));
    int threshold;
    // Rastgele sayý üretmek için seed ayarla
    srand(time(NULL));

    // Çalýþma süresinin hesaplanmasý
    clock_t start, end;
    double time;

    start = clock();

    generateRandomArray(array, ARRAY_SIZE);
    cout << "Dizi:\n";
printArray(array, ARRAY_SIZE);
bubbleSort(array, ARRAY_SIZE);
cout << "\nBubble Sort Sonucu:\n";
printArray(array, ARRAY_SIZE);

threshold = findAverageMaximumSubarraySum(array, ARRAY_SIZE);
cout << "\nMaximum Alt Dizi Toplami Ortalamasi: " << threshold << "\n";

cout << "\nGraf:\n";
printMatrix(graph, GRAPH_SIZE);

floydWarshallAlgorithm(graph, dist, GRAPH_SIZE);
cout << "\nFloyd-Warshall Algoritmasi Sonucu:\n";
printMatrix(dist, GRAPH_SIZE);
cout << "\n" << threshold << " icin en kisa yollar:\n";
printShortestPaths(dist, GRAPH_SIZE, threshold);

end = clock();
time = ((double)(end - start)) / CLOCKS_PER_SEC;
cout << "\nCalisma Suresi: " << time << " sn\n";

return 0;
}

void generateRandomArray(vector<int>& array, int size) {
for (int i = 0; i < size; i++) {
array[i] = rand() % (2 * MAX_WEIGHT) - MAX_WEIGHT;
}
}

void bubbleSort(vector<int>& array, int size) {
for (int i = 0; i < size - 1; i++) {
for (int j = 0; j < size - 1 - i; j++) {
if (array[j] > array[j + 1]) {
swap(array[j], array[j + 1]);
}
}
}
}

int findAverageMaximumSubarraySum(vector<int>& array, int size) {
int maximum_sum = 0, current_sum = 0, count = 0;
for (int i = 0; i < size; i++) {
if (current_sum + array[i] > 0) {
current_sum = current_sum + array[i];
} else {
current_sum = 0;
}
if (current_sum > maximum_sum) {
maximum_sum = current_sum;
count++;
}
}
return maximum_sum / count;
}

void floydWarshallAlgorithm(vector<vector<int> >& graph, vector<vector<int> >& dist, int size) {
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (i == j) {
dist[i][j] = 0;
} else if (graph[i][j] != 0) {
dist[i][j] = graph[i][j];
} else {
dist[i][j] = INF;
}
}
}
for (int k = 0; k < size; k++) {
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (dist[i][k] != INF && dist[k][j] != INF &&
dist[i][k] + dist[k][j] < dist[i][j]) {
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
}
}

void printArray(vector<int>& array, int size) {
for (int i = 0; i < size; i++) {
cout << array[i] << " ";
if ((i + 1) % 10 == 0) {
cout << "\n";
}
}
}

void printMatrix(vector<vector<int> >& matrix, int size) {
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (matrix[i][j] == INF) {
cout << "INF ";
} else {
cout << matrix[i][j] << " ";
}
}
cout << "\n";
}
}

void printShortestPaths(vector<vector<int> >& dist, int size, int threshold) {
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (i != j && dist[i][j] < threshold) {
cout << static_cast<char>('A' + i) << " -> " << static_cast<char>('A' + j) << ": " << dist[i][j] << "\n";
}
}
}
}


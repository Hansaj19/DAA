#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getRandom(int low, int high) {
    return low + rand() % (high - low + 1);
}

// Pair: {value, original_index}
int partition(vector<pair<int, int>>& arr, int low, int high) {
    int pivotIdx = getRandom(low, high);
    swap(arr[pivotIdx], arr[high]);
    auto pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j].first <= pivot.first) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<pair<int, int>>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n); // {value, index}

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }

    srand(time(0));
    quickSort(arr, 0, n - 1);

    for(auto p : arr) cout << p.first << " ";
    cout << endl;

    for(auto p : arr) cout << p.second << " ";
    cout << endl;

    return 0;
}

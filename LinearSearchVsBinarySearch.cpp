#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    int target = 7;

    int lin = linearSearch(arr, target);
    int bin = binarySearch(arr, target);

    cout << "Linear Search Index: " << lin << "\n";
    cout << "Binary Search Index: " << bin << "\n";
}
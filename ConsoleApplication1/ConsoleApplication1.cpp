#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция слияния двух отсортированных подмассивов
void merge(vector<pair<string, string>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создание временных подмассивов
    vector<pair<string, string>> L(n1), R(n2);

    // Копирование данных во временные подмассивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Объединение временных подмассивов обратно в arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов L[], если такие есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов R[], если такие есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Функция сортировки слиянием
void mergeSort(vector<pair<string, string>>& arr, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Функция для вызова сортировки слиянием
void mergeSort(vector<pair<string, string>>& arr) {
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
}

// Функция для вывода элементов вектора
void printVector(const vector<pair<string, string>>& arr) {
    for (const auto& item : arr) {
        cout << item.first << " - " << item.second << endl;
    }
}

vector<pair<string, string>> findSubstring(const vector<pair<string, string>>& arr, const string& substr) {
    vector<pair<string, string>> result;
    for (const auto& item : arr) {
        size_t found = item.first.find(substr);
        if (found != string::npos) {
            result.push_back(item);
        }
    }
    return result;
}

int main() {
    vector<pair<string, string>> components = { {"Intel", "Processor"}, {"AMD", "Processor"}, {"Nvidia", "Graphics Card"}, {"Asus", "Motherboard"}, {"MSI", "Graphics Card"} };

    cout << "Before sorting:" << endl;
    printVector(components);

    mergeSort(components);

    cout << "\nAfter sorting:" << endl;
    printVector(components);

    string substr = "AMD";

    vector<pair<string, string>> foundComponents = findSubstring(components, substr);
    if (!foundComponents.empty()) {
        cout << "\nComponents containing \"" << substr << "\":" << endl;
        printVector(foundComponents);
    }
    else {
        cout << "\nNo components containing \"" << substr << "\" found" << endl;
    }
    return 0;
}

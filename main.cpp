#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Функция для выполнения бинарного поиска наименьшего элемента, который больше или равен цели.
int binarySearch(const vector<int>& data, int target) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Возвращаем левый указатель, который указывает на элемент, больший или равный цели.
    return left;
}

int main() {
    ifstream input("input.txt");  // Открываем файл для чтения входных данных.
    ofstream output("output.txt");  // Открываем файл для записи выходных данных.

    int n;
    input >> n;  // Считываем количество элементов в последовательности.
    vector<int> sequence(n);  // Создаем вектор для хранения входной последовательности.
    vector<int> lis;  // Создаем вектор для хранения наибольшей возрастающей подпоследовательности.

    for (int i = 0; i < n; ++i) {
        input >> sequence[i];  // Считываем элементы последовательности.
        int index = binarySearch(lis, sequence[i]);  // Ищем индекс для текущего элемента в LIS.

        if (index == lis.size()) {
            lis.push_back(sequence[i]);  // Если индекс равен длине LIS, добавляем элемент в LIS.
        } else {
            lis[index] = sequence[i];  // Иначе заменяем элемент в LIS, если нашли более маленький элемент.
        }
    }

    output << lis.size() << endl;  // Записываем длину наибольшей возрастающей подпоследовательности в файл.

    input.close();  // Закрываем файл ввода.
    output.close();  // Закрываем файл вывода.

    return 0;
}

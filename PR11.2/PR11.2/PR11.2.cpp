#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

// Функція, яка знаходить максимальну кількість послідовних пробілів у рядку
size_t MaxConsecutiveSpaces(const string& s) {
    size_t maxCount = 0;
    size_t currentCount = 0;

    for (char ch : s) {
        if (ch == ' ') {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        }
        else {
            currentCount = 0;
        }
    }
    return maxCount;
}

// Функція для читання вмісту файлу
string ReadFileContent(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filePath);
    }

    string content, line;
    while (getline(file, line)) {
        content += line + '\n';
    }

    file.close();
    return content;
}

// Головна функція
int main() {
    // Фіксований шлях до файлу
    string filePath = "D:\\C\\PR11.2\\11.txt";
    cout << "File path: " << filePath << endl;

    try {
        // Зчитуємо вміст файлу
        string fileContent = ReadFileContent(filePath);

        // Шукаємо максимальну кількість послідовних пробілів у файлі
        size_t maxSpaces = MaxConsecutiveSpaces(fileContent);

        // Виводимо результат
        cout << "Maximum consecutive spaces in the file: " << maxSpaces << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

// main.cpp (Demo)
#include "File.hpp"
#include <iostream>

int main() {
    setlocale(LC_ALL, "");
    try {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Записать текст в demo.txt\n";
        std::cout << "2. Прочитать текст из указанного файла\n";
        std::cout << "Ваш выбор: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // очистить \n после ввода числа

        if (choice == 1) {
            std::cout << "Введите текст (пустая строка для завершения):\n";
            File outFile("demo.txt", File::Mode::Write);
            std::string input;
            while (true) {
                std::getline(std::cin, input);
                if (input.empty()) break;
                outFile.writeLine(input);
            }
            std::cout << "Текст успешно записан в demo.txt\n";

        }
        else if (choice == 2) {
            std::cout << "Введите путь к файлу для чтения: ";
            std::string path;
            std::getline(std::cin, path);

            File inFile(path, File::Mode::Read);
            std::string line;
            std::cout << "\nСодержимое файла:\n";
            while (!(line = inFile.readLine()).empty()) {
                std::cout << line << std::endl;
            }

        }
        else {
            std::cout << "Неверный выбор. Выход.\n";
        }

    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

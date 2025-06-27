// main.cpp (Demo)
#include "File.hpp"
#include <iostream>

int main() {
    setlocale(LC_ALL, "");
    try {
        std::cout << "�������� ��������:\n";
        std::cout << "1. �������� ����� � demo.txt\n";
        std::cout << "2. ��������� ����� �� ���������� �����\n";
        std::cout << "��� �����: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // �������� \n ����� ����� �����

        if (choice == 1) {
            std::cout << "������� ����� (������ ������ ��� ����������):\n";
            File outFile("demo.txt", File::Mode::Write);
            std::string input;
            while (true) {
                std::getline(std::cin, input);
                if (input.empty()) break;
                outFile.writeLine(input);
            }
            std::cout << "����� ������� ������� � demo.txt\n";

        }
        else if (choice == 2) {
            std::cout << "������� ���� � ����� ��� ������: ";
            std::string path;
            std::getline(std::cin, path);

            File inFile(path, File::Mode::Read);
            std::string line;
            std::cout << "\n���������� �����:\n";
            while (!(line = inFile.readLine()).empty()) {
                std::cout << line << std::endl;
            }

        }
        else {
            std::cout << "�������� �����. �����.\n";
        }

    }
    catch (const std::exception& ex) {
        std::cerr << "������: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

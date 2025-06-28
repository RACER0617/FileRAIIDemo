// main.cpp (Demo)
#include "File.hpp"
#include <iostream>
#include <filesystem>
#include <string>
#include <limits>

int main() {
    setlocale(LC_ALL, "");

    try {
        std::cout << "�������� ��������:\n";
        std::cout << "1. �������� ����� � demo.txt\n";
        std::cout << "2. ��������� ����� �� ���������� �����\n";
        std::cout << "3. ����: ������� �������������� ����\n";
        std::cout << "4. ����: readLine � ������ ������\n";
        std::cout << "5. ����: writeLine � ������ ������\n";
        std::cout << "6. ����: ������ ����� � ������������� ���������\n";
        std::cout << "7. ����: ������ ������������ �������� � ����\n";
        std::cout << "��� �����: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            std::cout << "������� ����� (������ ������ ��� ����������):\n";
            File outFile(std::filesystem::path("demo.txt"), File::Mode::Write);
            std::string line;
            while (true) {
                std::getline(std::cin, line);
                if (line.empty()) break;
                outFile.writeLine(line);
            }
            std::cout << "����� ������� � demo.txt\n";
            std::cin.get();
            break;
        }
        case 2: {
            std::cout << "������� ���� � ����� ��� ������: ";
            std::string path;
            std::getline(std::cin, path);
            File inFile(std::filesystem::path(path), File::Mode::Read);
            std::cout << "���������� �����:\n";
            std::string line;
            while (!(line = inFile.readLine()).empty()) {
                std::cout << line << '\n';
            }
            std::cin.get();
            break;
        }
        case 3: {
            try {
                File f(std::filesystem::path("nonexistent.txt"), File::Mode::Read);
            }
            catch (const std::exception& ex) {
                std::cout << "������: " << ex.what() << '\n';
            }
            std::cin.get();
            break;
        }
        case 4: {
            try {
                File f(std::filesystem::path("demo.txt"), File::Mode::Write);
                f.readLine();
            }
            catch (const std::exception& ex) {
                std::cout << "������: " << ex.what() << '\n';
            }
            std::cin.get();
            break;
        }
        case 5: {
            try {
                File f(std::filesystem::path("demo.txt"), File::Mode::Read);
                f.writeLine("test");
            }
            catch (const std::exception& ex) {
                std::cout << "������: " << ex.what() << '\n';
            }
            std::cin.get();
            break;
        }
        case 6: {
            try {
                File f(std::filesystem::path("noread.txt"), File::Mode::Read);
                f.readLine();
            }
            catch (const std::exception& ex) {
                std::cout << "������: " << ex.what() << '\n';
            }
            std::cin.get();
            break;
        }
        case 7: {
            try {
                File f(std::filesystem::path("protected.txt"), File::Mode::Write);
                f.writeLine("������� � ������� ������� ����");
            }
            catch (const std::exception& ex) {
                std::cout << "������: " << ex.what() << '\n';
            }
            std::cin.get();
            break;
        }
        default:
            std::cout << "�������� �����.\n";
            std::cin.get();
        }

    }
    catch (const std::exception& ex) {
        std::cerr << "������: " << ex.what() << std::endl;
        std::cin.get();
        return 1;
    }

    return 0;
}

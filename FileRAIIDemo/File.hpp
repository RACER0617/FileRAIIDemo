// File.hpp
#ifndef FILE_RAII_HPP
#define FILE_RAII_HPP

#include <string>
#include <fstream>
#include <stdexcept>

class File {
public:
    enum class Mode { Read, Write };

    File(const std::string& path, Mode mode);
    ~File();

    std::string readLine();
    void writeLine(const std::string& line);

    // disable copy
    File(const File&) = delete;
    File& operator=(const File&) = delete;
    // allow move
    File(File&& other) noexcept;
    File& operator=(File&& other) noexcept;

private:
    std::fstream stream_;
    Mode mode_;
};

#endif // FILE_RAII_HPP#pragma once

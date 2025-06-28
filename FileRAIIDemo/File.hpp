#ifndef FILE_HPP
#define FILE_HPP

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>

class File {
public:
    enum class Mode { Read, Write };

    File(const std::filesystem::path& path, Mode mode);
    ~File();

    std::string readLine();
    void writeLine(const std::string& line);

    File(const File&) = delete;
    File& operator=(const File&) = delete;
    File(File&& other) noexcept;
    File& operator=(File&& other) noexcept;

private:
    std::fstream stream_;
    Mode mode_;
};

#endif // FILE_RAII_HPP
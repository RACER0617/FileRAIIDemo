#include "File.hpp"

File::File(const std::filesystem::path& path, Mode mode)
    : mode_(mode)
{
    std::ios_base::openmode flags = (mode_ == Mode::Read)
        ? std::ios::in
        : (std::ios::out | std::ios::trunc);

    stream_.open(path, flags);
    if (!stream_.is_open()) {
        throw std::runtime_error("Ошибка открытия файла: " + path.string());
    }
}

File::~File() {
    if (stream_.is_open()) {
        stream_.close();
    }
}

std::string File::readLine() {
    if (mode_ != Mode::Read) {
        throw std::runtime_error("Файл не открыт в режиме чтения");
    }

    std::string line;
    if (!std::getline(stream_, line)) {
        if (stream_.eof()) {
            return {};
        }
        throw std::runtime_error("Ошибка чтения из файла");
    }

    // Проверка на недопустимые символы (не-ASCII)
    for (char c : line) {
        if (static_cast<unsigned char>(c) > 127) {
            throw std::runtime_error("Ошибка чтения из файла: строка содержит недопустимые символы");
        }
    }

    return line;
}

void File::writeLine(const std::string& line) {
    if (mode_ != Mode::Write) {
        throw std::runtime_error("Файл не открыт в режиме записи");
    }

    // Проверка на недопустимые символы (не-ASCII)
    for (char c : line) {
        if (static_cast<unsigned char>(c) > 127) {
            throw std::runtime_error("Ошибка записи файла: строка содержит недопустимые символы");
        }
    }

    stream_ << line << '\n';

    if (!stream_) {
        throw std::runtime_error("Ошибка записи файла");
    }
}

File::File(File&& other) noexcept
    : stream_(std::move(other.stream_))
    , mode_(other.mode_)
{
}

File& File::operator=(File&& other) noexcept {
    if (this != &other) {
        if (stream_.is_open()) {
            stream_.close();
        }
        stream_ = std::move(other.stream_);
        mode_ = other.mode_;
    }
    return *this;
}

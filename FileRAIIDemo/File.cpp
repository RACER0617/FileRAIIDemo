#include "File.hpp"

File::File(const std::string& path, Mode mode)
    : mode_(mode)
{
    std::ios_base::openmode flags = (mode_ == Mode::Read)
        ? (std::ios::in)
        : (std::ios::out | std::ios::trunc);

    stream_.open(path, flags);
    if (!stream_.is_open()) {
        throw std::runtime_error("������ �������� �����: " + path);
    }
}

File::~File() {
    if (stream_.is_open()) {
        stream_.close();
    }
}

std::string File::readLine() {
    if (mode_ != Mode::Read) {
        throw std::runtime_error("���� �� ������ � ������ ������");
    }
    std::string line;
    if (!std::getline(stream_, line)) {
        if (stream_.eof()) return {};
        throw std::runtime_error("������ ������ �� �����");
    }
    return line;
}

void File::writeLine(const std::string& line) {
    if (mode_ != Mode::Write) {
        throw std::runtime_error("���� �� ������ � ������ ������");
    }
    stream_ << line;
    if (!stream_) {
        throw std::runtime_error("������ ������ �����");
    }
    stream_ << '\n';
}

File::File(File&& other) noexcept
    : stream_(std::move(other.stream_)), mode_(other.mode_)
{
    // leave other in closed state
}

File& File::operator=(File&& other) noexcept {
    if (this != &other) {
        if (stream_.is_open()) stream_.close();
        stream_ = std::move(other.stream_);
        mode_ = other.mode_;
    }
    return *this;
}

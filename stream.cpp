#include "stream.hpp"

bool utils::ReadFileToMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer)
{
    std::ifstream file_ifstream(file_path, std::ios::binary);

    if (!file_ifstream)
        return false;

    out_buffer->assign((std::istreambuf_iterator<uint8_t>(file_ifstream)), std::istreambuf_iterator<uint8_t>());
    file_ifstream.close();

    return true;
}

bool utils::CreateFileFromMemory(const std::string& desired_file_path, const uint8_t* address, size_t size)
{
    std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

    if (!file_ofstream.write(reinterpret_cast<const char*>(address), size))
    {
        file_ofstream.close();
        return false;
    }

    file_ofstream.close();
    return true;
}

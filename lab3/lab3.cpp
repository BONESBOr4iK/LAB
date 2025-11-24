#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

#pragma pack(push, 1)

struct Rar_head
{
    uint16_t header_crc;
    uint8_t header_type;
    uint16_t header_flags;
    uint16_t header_size;
};
struct File_head
{
    uint32_t PackSize;
    uint32_t UnpSize;
    uint8_t HostOS;
    uint32_t FileCRC;
    uint32_t FileTime;
    uint8_t UnpVer;
    uint8_t Method;
    uint16_t NameSize;
    uint32_t FileAttr;
};

#pragma pack(pop)

int main()
{
    std::ifstream file_rar("Example.rar", std::ios::binary);
    if (!file_rar.is_open())
    {
        std::cout << "ERROR!" << std::endl;
    }
    file_rar.seekg(0, std::ios::end);
    int filesize = file_rar.tellg();
    std::cout << "File size: " << filesize << std::endl;
    file_rar.seekg(0, std::ios::beg);
    std::vector<char> rar_data(filesize, 0);
    file_rar.read(rar_data.data(), filesize);
    Rar_head *p_header = reinterpret_cast<Rar_head *>(&rar_data[7]);
    std::cout << "Header type: 0x" << std::hex << int(p_header->header_type) << std::endl;
    std::cout << "Header size: " << std::dec << int(p_header->header_size) << std::endl;
    return 0;
}

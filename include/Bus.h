#pragma once

#include <cstdint>
#include <array>
#include "D6504.h"



class Bus
{
public:
    Bus();
    ~Bus();

public:  // Dispositivos conectados ao Bus

    // CPU
    D6504 cpu;

    // RAM fake por enquato de 64KB
    std::array<u8, 64 * 1024> ram;

public:  // Leitura e Escrita do Bus
    void write(u16 addr, u8 data);
    u8 read(u16 addr, bool bReadOnly = false);
};



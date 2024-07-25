#include "Bus.h"

Bus::Bus() {
    // Limpa a RAM
    for (auto &i : ram) i = 0x00;

    // Conecta a CPU ao Bus
    cpu.ConnectBus(this);
}

Bus::~Bus() {
}

void Bus::write(u16 addr, u8 data) {
    if (addr >= 0x0000 && addr <= 0xFFFF)
        ram[addr] = data;
}

u8 Bus::read(u16 addr, bool bReadOnly) {
    if (addr >= 0x0000 && addr <= 0xFFFF)
        return ram[addr];

    return 0x00;
}
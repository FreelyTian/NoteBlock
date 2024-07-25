#pragma once

#include <cstdint>
#include "common.h"
#include <vector>
class D6504
{
public:
    D6504();
    ~D6504();

public:
    enum FLAGS6504
    {
        C = (1 << 0), // Carry Bit           -> Definida pelo user ou pelo processo em si
        Z = (1 << 1), // Zero                -> Diz se o resultado de uma operação é zero
        I = (1 << 2), // Disable Interrupts  -> Desabilita interrupções
        D = (1 << 3), // Decimal Mode          (Não tem nessa implementação)
        B = (1 << 4), // Break               -> Sinal de break
        U = (1 << 5), // Unused              -> Não utilizado
        V = (1 << 6), // Overflow
        N = (1 << 7), // Negative
    };

    u8 a = 0x00; // Acumulador
    u8 x = 0x00; // Index X
    u8 y = 0x00; // Index Y
    u8 stkp = 0x00; // Stack Pointer    -> aponta um local no Bus
    u16 pc = 0x0000; // Program Counter
    u8 status = 0x00; // Status Register

    void ConnectBus(Bus* n) { bus = n; }

    // Modos de Endereçamento

    u8 IMP();  // Implied
    u8 IMM();  // Immediate
    u8 ABS();  // Absolute
    u8 ABX();  // Absolute X
    u8 ABY();  // Absolute Y
    u8 REL();  // Relative
    u8 ZP0();  // Zero Page
    u8 ZPX();  // Zero Page X
    u8 ZPY();  // Zero Page Y
    u8 IND();  // Indirect
    u8 IZX();  // Indirect X
    u8 IZY();  // Indirect Y

    // Opcodes
    u8 ADC();	u8 AND();	u8 ASL();	u8 BCC();
    u8 BCS();	u8 BEQ();	u8 BIT();	u8 BMI();
    u8 BNE();	u8 BPL();	u8 BRK();	u8 BVC();
    u8 BVS();	u8 CLC();	u8 CLD();	u8 CLI();
    u8 CLV();	u8 CMP();	u8 CPX();	u8 CPY();
    u8 DEC();	u8 DEX();	u8 DEY();	u8 EOR();
    u8 INC();	u8 INX();	u8 INY();	u8 JMP();
    u8 JSR();	u8 LDA();	u8 LDX();	u8 LDY();
    u8 LSR();	u8 NOP();	u8 ORA();	u8 PHA();
    u8 PHP();	u8 PLA();	u8 PLP();	u8 ROL();
    u8 ROR();	u8 RTI();	u8 RTS();	u8 SBC();
    u8 SEC();	u8 SED();	u8 SEI();	u8 STA();
    u8 STX();	u8 STY();	u8 TAX();	u8 TAY();
    u8 TSX();	u8 TXA();	u8 TXS();	u8 TYA();

    // Opcodes não oficiais
    u8 XXX();

    void clock();
    void reset();
    void irq();  // Interrupt Request
    void nmi();  // Non-Maskable Interrupt

    u8 fetch();  // Pra fetchar quaisquer tipo de instruções
    u8 fetched = 0x00;
    u16 addr_abs = 0x0000;
    u16 addr_rel = 0x00;
    u8 opcode = 0x00;
    u8 cycles = 0;

private:
    Bus* bus = nullptr;
    u8 read(u16 address);
    void write(u16 address, u8 data);

    // Por conveniência, um conjunto de funções para acessar o Status Register

    u8 GetFlag(FLAGS6504 flag); // Pega o valor de uma flag
    void SetFlag(FLAGS6504 flag, bool value);  // Seta o valor de uma flag

    struct INSTRUCTION
    {
        std::string name;  // Nome da instrução
        u8(D6504::* operate)(void) = nullptr;  // Ponteiro para a função que executa a instrução
        u8(D6504::* addrmode)(void) = nullptr;  // Ponteiro para a função que executa o modo de endereçamento
        u8 cycles = 0;  // Ciclos que a instrução leva para ser executada
    };

    std::vector<INSTRUCTION> lookup;
};
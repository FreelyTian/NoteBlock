
# FLAGS

## Carry Flag

É settada se a última operação causou um overflow do bit 7 ou um underflow do bit 0, pode ser setado durante aritmética, comparação ou trocas locais, pode ser setada com [SEC](#sec---set-carry-flag) e limpa com [CLC](#clc---clear-carry-flag).

## Zero Flag

É settada se a última operação foi 0.

## Interrupt Disable

Settada pela instrução [SEI](#sei---set-interrupt-disable). Enquanto settada a CPU não vai responder às interrupts dos devices até que uma [CLI](#cli---clear-interrupt-disable) seja executada.

## Decimal Mode

Enquanto ativa o processador vai usar Decimais binary-coded pra aritmética durante a adição e subtração. Settada pela instrução [SED](#sed---set-decimal-flag) e limpa pela [CLD](#cle---clear-decimal-flag)

## Break Command

Settado quando uma [BRK](#brk---force-interrupt) é chamada com uma interrupt gerada pra processar ela.

## Overflow Flag

Aparentemente settada durante uma operação aritmética errada tipo + com + dar menos. Eu não entendi ainda como e definida

## Negative Flag

Settada quando a última operação resultou no bit 7 como 1

#

# INSTRUÇÕES CPU

## **BRK** - "Force Interrupt"

Força a geração de uma solicitação de interrupção. O PC e o PS são colocados na pilha, então o vetor de interrupção IRQ em $FFFE/F é carregado no PC e o sinalizador de interrupção no status é definido como 1.

| Letra |       Nome        |   Alterações  |
|-------|-------------------|---------------|
|   C   |    Carry Flag     |  Não Afetada  |
|   Z   |    Zero Flag      |  Não Afetada  |
|   I   | Interrupt Disable |  Não Afetada  |
|   D   | Decimal Mode Flag |  Não Afetada  |
|   B   |   Break Command   | Settada pra 1 |
|   V   |   Overflow Flag   |  Não Afetada  |
|   N   |   Negative Flag   |  Não Afetada  |

| Modo de Endereçamento | Opcode | Bytes | Ciclos |
|-----------------------|--------|-------|--------|
|       Implied         |  $00   |   1   |   7    |

## **CLC** - "Clear Carry Flag"

Setta a Carry Flag pra 0.

| Letra |       Nome        |   Alterações  |
|-------|-------------------|---------------|
|   C   |    Carry Flag     | Settada pra 0 |
|   Z   |    Zero Flag      |  Não Afetada  |
|   I   | Interrupt Disable |  Não Afetada  |
|   D   | Decimal Mode Flag |  Não Afetada  |
|   B   |   Break Command   |  Não Afetada  |
|   V   |   Overflow Flag   |  Não Afetada  |
|   N   |   Negative Flag   |  Não Afetada  |

| Modo de Endereçamento | Opcode | Bytes | Ciclos |
|-----------------------|--------|-------|--------|
|       Implied         |  $18   |   1   |   2    |

## **CLE** - "Clear Decimal Flag"

Setta a Decimal Flag pra 0

| Letra |       Nome        |   Alterações  |
|-------|-------------------|---------------|
|   C   |    Carry Flag     |  Não Afetada  |
|   Z   |    Zero Flag      |  Não Afetada  |
|   I   | Interrupt Disable |  Não Afetada  |
|   D   | Decimal Mode Flag | Settada pra 0 |
|   B   |   Break Command   |  Não Afetada  |
|   V   |   Overflow Flag   |  Não Afetada  |
|   N   |   Negative Flag   |  Não Afetada  |

| Modo de Endereçamento | Opcode | Bytes | Ciclos |
|-----------------------|--------|-------|--------|
|       Implied         |  $D8   |   1   |   2    |

## **CLI** - "Clear Interrupt Disable"

Setta a Interrupt Disable Flag pra 0 permitindo interrupt requests

| Letra |       Nome        |   Alterações  |
|-------|-------------------|---------------|
|   C   |    Carry Flag     |  Não Afetada  |
|   Z   |    Zero Flag      |  Não Afetada  |
|   I   | Interrupt Disable | Settada pra 0 |
|   D   | Decimal Mode Flag |  Não Afetada  |
|   B   |   Break Command   |  Não Afetada  |
|   V   |   Overflow Flag   |  Não Afetada  |
|   N   |   Negative Flag   |  Não Afetada  |

| Modo de Endereçamento | Opcode | Bytes | Ciclos |
|-----------------------|--------|-------|--------|
|       Implied         |  $58   |   1   |   2    |

## **SEC** - "Set Carry Flag"

Setta a Carry Flag pra 1

| Letra |       Nome        |   Alterações  |
|-------|-------------------|---------------|
|   C   |    Carry Flag     | Settada pra 1 |
|   Z   |    Zero Flag      |  Não Afetada  |
|   I   | Interrupt Disable |  Não Afetada  |
|   D   | Decimal Mode Flag |  Não Afetada  |
|   B   |   Break Command   |  Não Afetada  |
|   V   |   Overflow Flag   |  Não Afetada  |
|   N   |   Negative Flag   |  Não Afetada  |

| Modo de Endereçamento | Opcode | Bytes | Ciclos |
|-----------------------|--------|-------|--------|
|       Implied         |  $38   |   1   |   2    |

## **SED** - "Set Decimal Flag"

Setta a Decimal Flag pra 1

| Letra |       Nome        |   Alterações  |
|-------|-------------------|---------------|
|   C   |    Carry Flag     |  Não Afetada  |
|   Z   |    Zero Flag      |  Não Afetada  |
|   I   | Interrupt Disable |  Não Afetada  |
|   D   | Decimal Mode Flag | Settada pra 1 |
|   B   |   Break Command   |  Não Afetada  |
|   V   |   Overflow Flag   |  Não Afetada  |
|   N   |   Negative Flag   |  Não Afetada  |

| Modo de Endereçamento | Opcode | Bytes | Ciclos |
|-----------------------|--------|-------|--------|
|       Implied         |  $F8   |   1   |   2    |

## **SEI** - "Set Interrupt Disable"

Setta a Interrupt Disable Flag pra 1

| Letra |       Nome        |   Alterações  |
|-------|-------------------|---------------|
|   C   |    Carry Flag     |  Não Afetada  |
|   Z   |    Zero Flag      |  Não Afetada  |
|   I   | Interrupt Disable | Settada pra 1 |
|   D   | Decimal Mode Flag |  Não Afetada  |
|   B   |   Break Command   |  Não Afetada  |
|   V   |   Overflow Flag   |  Não Afetada  |
|   N   |   Negative Flag   |  Não Afetada  |

| Modo de Endereçamento | Opcode | Bytes | Ciclos |
|-----------------------|--------|-------|--------|
|       Implied         |  $78   |   1   |   2    |

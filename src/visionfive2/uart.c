#include "../include/libc/stdint.h"
#define UART0_BASE 0x10000000
#define UART0_TXDATA (UART0_BASE + 0x0)
#define UART0_TXCTRL (UART0_BASE + 0x8)
#define NCPU 4

char stack0[4096 * NCPU];

#define UART_TX_READY (1 << 31)
static inline void uart_putc(char c) {
    // Wait for the UART to be ready for transmission
    while (*(volatile uint32_t *)UART0_TXDATA & UART_TX_READY) {
    }
    // Write the character to the TXDATA register
    *(volatile uint32_t *)UART0_TXDATA = (uint32_t)c;
}
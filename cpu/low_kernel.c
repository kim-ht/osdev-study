#include "./low_kernel.h"

/* port_byte_in - reads a byte from register linked to a I/O address
 * into result.
 *
 * @port - the I/O address to access
 */
unsigned char port_byte_in(unsigned short port) {
    unsigned char result;

    __asm__ __volatile__(
        "in %%dx, %%al"
        : "=a" (result)
        : "d" (port)
    );
    return result;
}

/* port_word_in - reads two bytes from register linked to a I/O address
 * into result.
 *
 * @port - the I/O address to access
 */
unsigned char port_word_in(unsigned short port) {
    unsigned short result;

    __asm__ __volatile__(
        "in %%dx, %%ax"
        : "=a" (result)
        : "d" (port)
    );
    return result;
}

/* port_byte_out - write a byte to a register linked to given I/O address.
 *
 * @port - the I/O address linked with register
 * @data - the data to write
 */
void port_byte_out(unsigned short port, unsigned char data) {
    __asm__ __volatile__(
        "out %%al, %%dx"
        :
        : "a" (data), "d" (port)
    );
}

/* port_word_out - write two bytes to a register linked to given
 * I/O address.
 *
 * @port - the I/O address linked with register
 * @data - the data to write
 */
void port_word_out(unsigned short port, unsigned short data) {
    __asm__ __volatile__(
        "out %%ax, %%dx"
        :
        : "a" (data), "d" (port)
    );
}


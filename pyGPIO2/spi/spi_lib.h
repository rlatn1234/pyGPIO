/*
 *
 * This file is part of pyGPIO2.
 * spi_lib.c is python SPI extension.
 *



 */

#ifndef _I2C_LIB_H
#define _I2C_LIB_H

#include <stdint.h>

typedef struct {
    uint8_t mode;
    uint8_t bits_per_word;
    uint32_t speed;
    uint16_t delay;
} spi_config_t;

extern int spi_open(char *device, spi_config_t config);
extern int spi_close(int fd);
extern int spi_xfer(int fd, uint8_t *tx_buffer, uint8_t tx_len, uint8_t *rx_buffer, uint8_t rx_len);
extern int spi_read(int fd, uint8_t *rx_buffer, uint8_t rx_len);
extern int spi_write(int fd, uint8_t *tx_buffer, uint8_t tx_len);


#endif

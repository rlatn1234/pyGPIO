/*
 *
 * This file is part of pyGPIO2.
 * sppi_lib.c is python SPI extension.
 *



 */

#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>

#include <linux/spi/spidev.h>

#include "spi_lib.h"

int spi_open(char *device, spi_config_t config) {
    int fd;

    /* Open block device */
    fd = open(device, O_RDWR);
    if (fd < 0) {
        return fd;
    }

    /* Set SPI_POL and SPI_PHA */
    if (ioctl(fd, SPI_IOC_WR_MODE, &config.mode) < 0) {
        return -1;
    }
    if (ioctl(fd, SPI_IOC_RD_MODE, &config.mode) < 0) {
        return -1;
    }

    /* Set bits per word*/
    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &config.bits_per_word) < 0) {
        return -1;
    }
    if (ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &config.bits_per_word) < 0) {
        return -1;
    }

    /* Set SPI speed*/
    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &config.speed) < 0) {
        return -1;
    }
    if (ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &config.speed) < 0) {
        return -1;
    }

    /* Return file descriptor */
    return fd;
}

int spi_close(int fd) {
    return close(fd);
}

int spi_xfer(int fd, uint8_t *tx_buffer, uint8_t tx_len, uint8_t *rx_buffer, uint8_t rx_len){
    struct spi_ioc_transfer spi_message[2];
    memset(spi_message, 0, sizeof(spi_message));

    spi_message[0].rx_buf = (unsigned long)tx_buffer;
    spi_message[0].len = tx_len;

    spi_message[1].tx_buf = (unsigned long)rx_buffer;
    spi_message[1].len = rx_len;

    return ioctl(fd, SPI_IOC_MESSAGE(2), spi_message);
}

int spi_read(int fd, uint8_t *rx_buffer, uint8_t rx_len){
    struct spi_ioc_transfer spi_message[1];
    memset(spi_message, 0, sizeof(spi_message));

    spi_message[0].rx_buf = (unsigned long)rx_buffer;
    spi_message[0].len = rx_len;

    return ioctl(fd, SPI_IOC_MESSAGE(1), spi_message);
}

int spi_write(int fd, uint8_t *tx_buffer, uint8_t tx_len){
    struct spi_ioc_transfer spi_message[1];
    memset(spi_message, 0, sizeof(spi_message));

    spi_message[0].tx_buf = (unsigned long)tx_buffer;
    spi_message[0].len = tx_len;

    return ioctl(fd, SPI_IOC_MESSAGE(1), spi_message);
}

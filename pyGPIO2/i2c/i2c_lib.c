/*
 *
 * This file is part of pyGPIO2.
 * i2c_lib.c is python I2C extension.
 *



 */


#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/ioctl.h>

#include <linux/i2c.h>
#include <linux/i2c-dev.h>

int i2c_open(char *device, uint8_t address) {
    int fd;
    int ret;

    fd = open(device, O_RDWR);
    if (fd < 0)
        return fd;

    ret = ioctl(fd, I2C_SLAVE_FORCE, address);
    if (ret < 0)
        return ret;

    return fd;

}

int i2c_close(int fd) {
    return (close(fd));
}

int i2c_send(int fd, uint8_t *buffer, uint8_t num_bytes) {
    return (write(fd, buffer, num_bytes));
}

int i2c_read(int fd, uint8_t *buffer, uint8_t num_bytes) {
    return (read(fd, buffer, num_bytes));
}

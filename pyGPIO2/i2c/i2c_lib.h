/*
 *
 * This file is part of pyGPIO2.
 * i2c_lib.h is python I2C extension.
 *



 */

#ifndef _I2C_LIB_H
#define _I2C_LIB_H

extern int i2c_open(char *device, uint8_t address);
extern int i2c_close(int fd);
extern int i2c_send(int fd, uint8_t *buffer, uint8_t num_bytes);
extern int i2c_read(int fd, uint8_t *buffer, uint8_t num_bytes);

#endif
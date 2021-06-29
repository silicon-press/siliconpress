/** siliconpress.h
 * 
 * Copyright (c) 2021 Silicon Press Ltd
 * License: MIT
 */

#ifndef SILICONPRESS_H
#define SILICONPRESS_H

#include <stdint.h>

struct siliconpress_t {
    const uint8_t uuid[16]; // 128-bit globally unique identifier 
    const uint8_t key[16];  // 128-bit symetric key 
    const uint8_t ecc[32];  // 256-bit ECC private key
};

extern const struct siliconpress_t siliconpress;

#endif





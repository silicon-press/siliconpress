# Silicon Press Per-Device Identity Injection

These files are used to enable automatic injection of per-device identity and keys by the Silicon Press production line.

## Usage in Firmware

To support per-device injection, simply add the `siliconpress.h` and `siliconpress.c` files to your project.

The files will instansiate a const structure called `siliconpress` within the firmware image that includes:
 * `uid` - a 128-bit globally unique ID, represented as uint8_t[8] 
 * `key` - a 128-bit secret key, represented as uint8_t[8] 
 * `ecc` - a 256-bit private ECC key, represented as uint8_t[16] 

The actual structure is:
```c
struct siliconpress_t {
    const uint8_t uid[16];  // 128-bit globally unique identifier 
    const uint8_t key[16];  // 128-bit symetric key 
    const uint8_t ecc[32];  // 256-bit ECC private key
};
```

This structure instance can then be used within your firmware application:

```c
// Example using Silicon Press injected identity & keys

#include "siliconpress.h"

int main() {

    printf("Device UID: ");
    for(int i=0; i<16; i++) {
        printf("0x%02X ", siliconpress.uid[i]
    }
    printf("\n");

    printf("Device KEY: ");
    for(int i=0; i<16; i++) {
        printf("0x%02X ", siliconpress.key[i]
    }
    printf("\n");

    printf("Device ECC: ");
    for(int i=0; i<32; i++) {
        printf("0x%02X ", siliconpress.ecc[i]
    }
    printf("\n");
}
```

## Device Customisation in Production

When you upload your final firmware .hex or .bin to Silicon Press, the system will confirm if the injection block is included.

If it is, Silicon Press will automatically inject unique identity and keys in to each device as they are manufactured.

## More Information

See https://siliconpress.org for more information, and email support@siliconpress.org with any questions

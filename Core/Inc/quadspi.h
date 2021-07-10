#ifndef __quadspi_H
#define __quadspi_H
#ifdef __cplusplus
extern "C" {
#endif

/* USER CODE BEGIN Private defines */
#include "main.h"

extern QSPI_HandleTypeDef hqspi;
uint8_t CSP_QUADSPI_Init(void);
uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
uint8_t CSP_QSPI_EnableMemoryMappedMode(void);
uint8_t CSP_QSPI_Erase_Chip (void);

/* USER CODE END Private defines */
void MX_QUADSPI_Init(void);

/* USER CODE BEGIN Prototypes */

/*MX25R6435F memory parameters*/
#define MEMORY_FLASH_SIZE               0x800000  /* 64 MBits => 8MBytes */
#define MEMORY_SECTOR_SIZE              0x1000    /* 2048 subsectors of 4kBytes */
#define MEMORY_PAGE_SIZE                0x100     /* 128 pages of 256 bytes */


/*MX25R6435F commands */
#define WRITE_ENABLE_CMD 0x06//ok
#define READ_STATUS_REG_CMD 0x05//ok
#define WRITE_STATUS_REG_CMD 0x01//ok
#define SECTOR_ERASE_CMD 0x20//ok
#define CHIP_ERASE_CMD 0xC7//ok
#define QUAD_IN_FAST_PROG_CMD 0x38//ok
#define READ_CONFIGURATION_REG_CMD 0x15//ok
#define QUAD_READ_IO_CMD 0xEB
#define QUAD_OUT_FAST_READ_CMD 0x6B
#define DUMMY_CLOCK_CYCLES_READ_QUAD 8
#define ALTER_CLOCK_CYCLES_READ_QUAD 2
#define RESET_ENABLE_CMD 0x66
#define RESET_EXECUTE_CMD 0x99

/* USER CODE END Prototypes */
#ifdef __cplusplus
}
#endif
#endif /*__ quadspi_H */

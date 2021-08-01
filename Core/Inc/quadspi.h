#ifndef __quadspi_H
#define __quadspi_H
#ifdef __cplusplus
extern "C" {
#endif

/* USER CODE BEGIN Private defines */
#include "main.h"
#include "mx25r6435f.h"

extern QSPI_HandleTypeDef hqspi;
/*MX25R6435F memory parameters*/
#define MEMORY_FLASH_SIZE               MX25R6435F_FLASH_SIZE  /* 64 MBits => 8MBytes */
#define MEMORY_SECTOR_SIZE              MX25R6435F_SECTOR_SIZE    /* 2048 subsectors of 4kBytes */
#define MEMORY_PAGE_SIZE                MX25R6435F_PAGE_SIZE     /* 128 pages of 256 bytes */

/* USER CODE END Private defines */
void MX_QUADSPI_Init(void);

/* USER CODE BEGIN Prototypes */
uint8_t CSP_QUADSPI_Init(void);
uint8_t CSP_QSPI_Read_All_Reg(uint8_t* test_buffer);
uint8_t CSP_QSPI_Erase_Chip(void);
uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address,uint32_t buffer_size);
uint8_t CSP_QSPI_ReadMemory(uint8_t* buffer, uint32_t address,uint32_t buffer_size);
uint8_t CSP_QSPI_EnableMemoryMappedMode(void);

uint8_t CSP_QSPI_Read_ID(uint8_t* test_buffer);
uint8_t CSP_QSPI_Read_Electonic_ID(uint8_t* test_buffer);
uint8_t CSP_QSPI_Read_Manufa_ID(uint8_t* test_buffer);

/* USER CODE END Prototypes */
#ifdef __cplusplus
}
#endif
#endif /*__ quadspi_H */

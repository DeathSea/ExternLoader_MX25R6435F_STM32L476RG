/**
  ******************************************************************************
  * @file    Loader_Src.h
  * @author  MCD Tools Team
  * @date    October-2015
  * @brief   Loader Header file.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LOADER_SRC_H
#define __LOADER_SRC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_qspi.h"
#include "mx25r6435f.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/


#if defined(__CC_ARM)
extern uint32_t Load$$QSPI$$Base;
extern uint32_t Load$$QSPI$$Length;
#elif defined(__ICCARM__)
#pragma section =".qspi"
#pragma section =".qspi_init"
#elif defined(__GNUC__)
extern uint32_t _qspi_init_base;
extern uint32_t _qspi_init_length;
#endif


#ifdef __ICCARM__                //IAR
#define KeepInCompilation __root 
#elif __CC_ARM                   //MDK-ARM
#define KeepInCompilation __attribute__((used))
#else //TASKING               //TrueStudio
#define KeepInCompilation __attribute__((used))
#endif

#define QSPI_ADDRESS_WIDTH QSPI_ADDRESS_24_BITS



/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Definition for QSPI clock resources */
#define QSPI_CLK_ENABLE()          __HAL_RCC_QSPI_CLK_ENABLE()
#define QSPI_CLK_DISABLE()         __HAL_RCC_QSPI_CLK_DISABLE()
#define QSPI_CS_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#define QSPI_CLK_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define QSPI_D0_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOF_CLK_ENABLE()
#define QSPI_D1_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOF_CLK_ENABLE()
#define QSPI_D2_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOF_CLK_ENABLE()
#define QSPI_D3_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOF_CLK_ENABLE()
#define QSPI_DMA_CLK_ENABLE()      __HAL_RCC_DMA2_CLK_ENABLE()

#define QSPI_FORCE_RESET()         __HAL_RCC_QSPI_FORCE_RESET()
#define QSPI_RELEASE_RESET()       __HAL_RCC_QSPI_RELEASE_RESET()

/* Definition for QSPI Pins */
#define QSPI_CS_PIN                GPIO_PIN_11
#define QSPI_CS_GPIO_PORT          GPIOB
#define QSPI_CLK_PIN               GPIO_PIN_10
#define QSPI_CLK_GPIO_PORT         GPIOB
#define QSPI_D0_PIN                GPIO_PIN_1
#define QSPI_D0_GPIO_PORT          GPIOB
#define QSPI_D1_PIN                GPIO_PIN_0
#define QSPI_D1_GPIO_PORT          GPIOB
#define QSPI_D2_PIN                GPIO_PIN_7
#define QSPI_D2_GPIO_PORT          GPIOA
#define QSPI_D3_PIN                GPIO_PIN_6
#define QSPI_D3_GPIO_PORT          GPIOA

/* Definition for QSPI DMA */
#define QSPI_DMA_INSTANCE          DMA1_Channel5
#define QSPI_DMA_CHANNEL           DMA_REQUEST_5
#define QSPI_DMA_IRQ               DMA1_Channel5_IRQn
#define QSPI_DMA_IRQ_HANDLER       DMA1_Channel5_IRQHandler

/* MX25R6435F M memory */
/* Size of the flash */
#define QSPI_FLASH_SIZE                      25
#define QSPI_PAGE_SIZE                       256
#define QSPI_DEV_SIZE                        0x800000
#define QSPI_START_ADRESS                    0x90000000

/* End address of the QSPI memory */
#define QSPI_END_ADDR              (1 << QSPI_FLASH_SIZE)

/* Size of buffers */
#define BUFFERSIZE                 (COUNTOF(aTxBuffer) - 1)

/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)        (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))



int SectorErase (uint32_t EraseStartAddress ,uint32_t EraseEndAddress);

int  QSPI_WritePage(unsigned long adr, unsigned long sz, unsigned char *buf);
static int QSPI_WriteEnable(QSPI_HandleTypeDef *hqspi);
int QSPI_AutoPollingMemReady(QSPI_HandleTypeDef *hqspi);
void ResetMemory(QSPI_HandleTypeDef *hqspi);
static int QSPI_DummyCyclesCfg(QSPI_HandleTypeDef *hqspi);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
void HAL_Delay(__IO uint32_t Delay);
void SystemClock_Config(void);
int QUADSPI_MappedMode(void);

//All system initialisation
int Init (uint8_t configureMemoryMappedMode);

//QSPI operation functions
KeepInCompilation int EraseSector (unsigned long adr); 
KeepInCompilation int Write(uint32_t Address, uint32_t Size, uint8_t* buffer);
KeepInCompilation uint64_t Verify (uint32_t MemoryAddr, uint32_t RAMBufferAddr, uint32_t Size, uint32_t missalignement);
uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal);

#endif /* __LOADER_SRC_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

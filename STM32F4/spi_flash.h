/**
  ******************************************************************************
  * @file    spi_flash.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    18-January-2013
  * @brief   This file contains all the functions prototypes for the spi_flash
  *          firmware driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* M25P SPI Flash supported commands */  
#define sFLASH_CMD_WRITE          0x12  /* Write to Memory instruction */
#define sFLASH_CMD_WRSR           0x01  /* Write Status Register instruction */
#define sFLASH_CMD_WREN           0x06  /* Write enable instruction */
#define sFLASH_CMD_READ           0x13  /* Read from Memory instruction */
#define sFLASH_CMD_RDSR           0x05  /* Read Status Register instruction  */
#define sFLASH_CMD_RDID           0x9F  /* Read identification */
#define sFLASH_CMD_SE             0xD8  /* Sector Erase instruction */
#define sFLASH_CMD_BE             0xC7  /* Bulk Erase instruction */

#define sFLASH_WIP_FLAG           0x01  /* Write In Progress (WIP) flag */

#define sFLASH_DUMMY_BYTE         0xA5
#define sFLASH_SPI_PAGESIZE       0x100

#define sFLASH_M25P128_ID         0x202018
#define sFLASH_M25P64_ID          0x202017
  
/* M25P FLASH SPI Interface pins  */  
#define sFLASH_SPI                           SPI3
#define sFLASH_SPI_CLK                       RCC_APB1Periph_SPI3
#define sFLASH_SPI_CLK_INIT                  RCC_APB1PeriphClockCmd

#define sFLASH_SPI_SCK_PIN                   GPIO_Pin_10
#define sFLASH_SPI_SCK_GPIO_PORT             GPIOC
#define sFLASH_SPI_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOC
#define sFLASH_SPI_SCK_SOURCE                GPIO_PinSource10
#define sFLASH_SPI_SCK_AF                    GPIO_AF_SPI3

#define sFLASH_SPI_MISO_PIN                  GPIO_Pin_11
#define sFLASH_SPI_MISO_GPIO_PORT            GPIOC
#define sFLASH_SPI_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOC
#define sFLASH_SPI_MISO_SOURCE               GPIO_PinSource11
#define sFLASH_SPI_MISO_AF                   GPIO_AF_SPI3

#define sFLASH_SPI_MOSI_PIN                  GPIO_Pin_12
#define sFLASH_SPI_MOSI_GPIO_PORT            GPIOC
#define sFLASH_SPI_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOC
#define sFLASH_SPI_MOSI_SOURCE               GPIO_PinSource12
#define sFLASH_SPI_MOSI_AF                   GPIO_AF_SPI3

#define sFLASH_CS1_PIN                        GPIO_Pin_8
#define sFLASH_CS1_GPIO_PORT                  GPIOE
#define sFLASH_CS1_GPIO_CLK                   RCC_AHB1Periph_GPIOE
   
#define sFLASH_CS2_PIN                        GPIO_Pin_9
#define sFLASH_CS2_GPIO_PORT                  GPIOE
#define sFLASH_CS2_GPIO_CLK                   RCC_AHB1Periph_GPIOE   
   
#define sFLASH_CS3_PIN                        GPIO_Pin_10
#define sFLASH_CS3_GPIO_PORT                  GPIOE
#define sFLASH_CS3_GPIO_CLK                   RCC_AHB1Periph_GPIOE   
  
#define sFLASH_CS4_PIN                        GPIO_Pin_11
#define sFLASH_CS4_GPIO_PORT                  GPIOE
#define sFLASH_CS4_GPIO_CLK                   RCC_AHB1Periph_GPIOE  
  
#define sFLASH_CS5_PIN                        GPIO_Pin_12
#define sFLASH_CS5_GPIO_PORT                  GPIOE
#define sFLASH_CS5_GPIO_CLK                   RCC_AHB1Periph_GPIOE   
   
#define sFLASH_RES_PIN                        GPIO_Pin_7
#define sFLASH_RES_GPIO_PORT                  GPIOE
#define sFLASH_RES_GPIO_CLK                   RCC_AHB1Periph_GPIOE   
   
#define BlbSns_PIN                            GPIO_Pin_15
#define BlbSns_GPIO_PORT                      GPIOE
#define BlbSns_GPIO_CLK                       RCC_AHB1Periph_GPIOE  
    
#define BlbCrl_PIN                            GPIO_Pin_14
#define BlbCrl_GPIO_PORT                      GPIOE
#define BlbCrl_GPIO_CLK                       RCC_AHB1Periph_GPIOE 
   
#define USBSns_PIN                            GPIO_Pin_13
#define USBSns_GPIO_PORT                      GPIOE
#define USBSns_GPIO_CLK                       RCC_AHB1Periph_GPIOE 



   
/* Exported macro ------------------------------------------------------------*/
/* Select sFLASH: Chip1 Select pin low */
#define sFLASH_CS1_LOW()       GPIO_ResetBits(sFLASH_CS1_GPIO_PORT, sFLASH_CS1_PIN)
/* Deselect sFLASH: Chip1 Select pin high */
#define sFLASH_CS1_HIGH()      GPIO_SetBits(sFLASH_CS1_GPIO_PORT, sFLASH_CS1_PIN)   

/* Select sFLASH: Chip2 Select pin low */
#define sFLASH_CS2_LOW()       GPIO_ResetBits(sFLASH_CS2_GPIO_PORT, sFLASH_CS2_PIN)
/* Deselect sFLASH: Chip2 Select pin high */
#define sFLASH_CS2_HIGH()      GPIO_SetBits(sFLASH_CS2_GPIO_PORT, sFLASH_CS2_PIN)      
   
/* Select sFLASH: Chip3 Select pin low */
#define sFLASH_CS3_LOW()       GPIO_ResetBits(sFLASH_CS3_GPIO_PORT, sFLASH_CS3_PIN)
/* Deselect sFLASH: Chip3 Select pin high */
#define sFLASH_CS3_HIGH()      GPIO_SetBits(sFLASH_CS3_GPIO_PORT, sFLASH_CS3_PIN)    
   
/* Select sFLASH: Chip4 Select pin low */
#define sFLASH_CS4_LOW()       GPIO_ResetBits(sFLASH_CS4_GPIO_PORT, sFLASH_CS4_PIN)
/* Deselect sFLASH: Chip4 Select pin high */
#define sFLASH_CS4_HIGH()      GPIO_SetBits(sFLASH_CS4_GPIO_PORT, sFLASH_CS4_PIN)     
   
/* Select sFLASH: Chip5 Select pin low */
#define sFLASH_CS5_LOW()       GPIO_ResetBits(sFLASH_CS5_GPIO_PORT, sFLASH_CS5_PIN)
/* Deselect sFLASH: Chip5 Select pin high */
#define sFLASH_CS5_HIGH()      GPIO_SetBits(sFLASH_CS5_GPIO_PORT, sFLASH_CS5_PIN)     
   
/* Reset sFLASH: pin low */
#define sFLASH_RES_LOW()       GPIO_ResetBits(sFLASH_RES_GPIO_PORT, sFLASH_RES_PIN)
/* DeReset sFLASH: pin high */
#define sFLASH_RES_HIGH()      GPIO_SetBits(sFLASH_RES_GPIO_PORT, sFLASH_RES_PIN)   
   
/* Bulb off: pin low */
#define BlbCrl_off()           GPIO_ResetBits(BlbCrl_GPIO_PORT, BlbCrl_PIN)
/* Bulb on: pin high */
#define BlbCrl_on()            GPIO_SetBits(BlbCrl_GPIO_PORT, BlbCrl_PIN)      
   
/* BulbSense status */
#define BlbSns_sts()           GPIO_ReadInputDataBit(BlbSns_GPIO_PORT, BlbSns_PIN)
#define BlbCrl_sts()           GPIO_ReadOutputDataBit(BlbCrl_GPIO_PORT, BlbCrl_PIN)  

/* USBSense status */
#define USBSns_sts()           GPIO_ReadInputDataBit(USBSns_GPIO_PORT, USBSns_PIN)   
   
/* Exported functions ------------------------------------------------------- */

/* High layer functions  */
void sFLASH_LowLevel_DeInit(void);
void sFLASH_LowLevel_Init(void);    
void sFLASH_DeInit(void);
void sFLASH_Init(void);
void sFLASH_EraseSector(uint32_t SectorAddr);
void sFLASH_EraseBulk(void);
void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);
uint32_t sFLASH_ReadID(uint8_t NM);
void sFLASH_StartReadSequence(uint32_t ReadAddr);
void seaddress(void);
void buble(void);

/* Low layer functions */
uint8_t sFLASH_ReadByte(void);
uint8_t sFLASH_SendByte(uint8_t byte);
uint16_t sFLASH_SendHalfWord(uint16_t HalfWord);
void sFLASH_WriteEnable(void);
void sFLASH_WaitForWriteEnd(void);

#ifdef __cplusplus
}
#endif

#endif /* __SPI_FLASH_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

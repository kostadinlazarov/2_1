/**
  ******************************************************************************
  * @file    ADC/ADC_DMA/main.h 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    18-January-2013
  * @brief   Header for main.c module
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include <stdio.h>

#if defined (USE_STM324xG_EVAL)
  #include "stm324xg_eval.h"
  #include "stm324xg_eval_lcd.h"

#elif defined (USE_STM324x7I_EVAL) 
  #include "stm324x7i_eval.h"
  #include "stm324x7i_eval_lcd.h"

#else
 #error "Please select first the Evaluation board used in your application (in Project Options)"
#endif



/* Exported types ------------------------------------------------------------*/
    

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#if defined (USE_STM324xG_EVAL)

  #define FOOTER_MESSAGE    " ADC conversion w/DMA transfer example  " 
  #define CONFIG1_MESSAGE   "ADC Ch11 Conv @2.4Msps" 
  #define CONFIG2_MESSAGE   "  Turn RV1(PC.01)    "
  #define CONFIG3_MESSAGE   "   Potentiometer     "

  #define ADCx                     ADC1
  #define ADC_CHANNEL              ADC_Channel_7
  #define ADCx_CLK                 RCC_APB2Periph_ADC1
  #define ADCx_CHANNEL_GPIO_CLK    RCC_AHB1Periph_GPIOA
  #define GPIO_PIN                 GPIO_Pin_7
  #define GPIO_PORT                GPIOA
  #define DMA_CHANNELx             DMA_Channel_0
  #define DMA_STREAMx              DMA2_Stream0
  #define ADCx_DR_ADDRESS          ((uint32_t)0x4001204C)

#else /* defined (USE_STM324x7I_EVAL)*/ 

  #define FOOTER_MESSAGE    " ADC conversion w/DMA transfer example  "
  #define CONFIG1_MESSAGE   "ADC Ch1 Conv @2.4Msps" 
  #define CONFIG2_MESSAGE   "  Turn RV1(PC.01)    "
  #define CONFIG3_MESSAGE   "   Potentiometer     "

  #define ADCx                     ADC1
  #define ADC_CHANNEL              ADC_Channel_7
  #define ADCx_CLK                 RCC_APB2Periph_ADC1
  #define ADCx_CHANNEL_GPIO_CLK    RCC_AHB1Periph_GPIOA
  #define GPIO_PIN                 GPIO_Pin_7
  #define GPIO_PORT                GPIOA
  #define DMA_CHANNELx             DMA_Channel_0
  #define DMA_STREAMx              DMA2_Stream0
  #define ADCx_DR_ADDRESS          ((uint32_t)0x4001204C)
#endif
/* Exported functions ------------------------------------------------------- */
void phase0(void);                                                                      //exti0
void phase1(void);                                                                      //exti1
void phase2(void);                                                                      //exti2
void phase3(void);                                                                      //exti3
void phase4(void);                                                                      //exti4
void phase5(void);                                                                      //exti5

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

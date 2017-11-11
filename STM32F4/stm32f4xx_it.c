/**
  ******************************************************************************
  * @file    ADC/ADC_DMA/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    18-January-2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "global.h"
#include "stdlib.h"


    
/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup ADC_DMA
  * @{
  */  

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

    
uint16_t capture = 0;
extern __IO uint16_t CCR1_Val3;
extern __IO uint16_t CCR2_Val3;
extern __IO uint16_t CCR3_Val3;
extern __IO uint16_t CCR4_Val3;
extern __IO uint16_t CCR1_Val4;
extern __IO uint16_t CCR2_Val4;
extern __IO uint16_t CCR3_Val4;
extern __IO uint16_t CCR4_Val4;
extern __IO uint32_t CCR1_Val2;
extern __IO uint32_t CCR2_Val2;
extern __IO uint32_t CCR3_Val2;
extern __IO uint32_t CCR4_Val2;

extern __IO uint16_t CCR1_Val5;
extern __IO uint16_t CCR2_Val5;

extern __IO uint16_t CCR1_Val6;
extern __IO uint16_t CCR2_Val6;

extern __IO uint16_t CCR1_Val7;
extern __IO uint16_t CCR2_Val7;




uint16_t rperm = 500;
uint16_t timfourcounter;
uint8_t swtch = 1;


uint8_t startflag = 0;
uint8_t dek = 30;
uint8_t tempdek = 0;

uint16_t test = 0;



uint16_t opt1=0;




uint32_t swstart=0;





uint8_t vdvzak=0;

uint16_t vazgen = 130;

uint16_t flagc = 0;
uint8_t message = 0;







uint16_t zap=3600; 



uint8_t ca0a=1;
uint8_t ca1a=0;
uint8_t ca2a=1;
uint8_t ca3a=0;
uint8_t ca4a=1;
uint8_t ca5a=0;

uint8_t vdvcik=0;





uint8_t ca0b=1;
uint8_t ca1b=1;
uint8_t ca2b=1;
uint8_t ca3b=1;
uint8_t ca4b=1;
uint8_t ca5b=1;





uint8_t casevazg=0;
uint8_t casevazd=0;
uint8_t pokvazg=0;




/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void states(void);
/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/**
  * @brief  This function handles TIM3 global interrupt request.
  * @param  None
  * @retval None
  */
    
    
void TIM2_IRQHandler(void)
{
  
  
  if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)                                  //this is for the engine's bridge
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);    
    
    
        resnom2=nomperiod2;
        
        if(firt){
        
          timfourcounter=TIM_GetCounter(TIM5);  
          TIM_SetCompare1(TIM5, (timfourcounter+3600)); 
        
        
        }
        else{
          TIM_SetCounter(TIM5, 0);
          TIM_SetCompare1(TIM5, 3600);
          
                   
        }
          
        if((swdvig==1) && (swdstop==1)){ 
        
           switch(nomperiod2)
  {
  case 0:
//    if(swrpm){GPIO_SetBits(GPIOD, GPIO_Pin_0);}                                                            //D3


 if(swrpm){GPIO_SetBits(GPIOD, 8);}   
 //GPIO_SetBits(GPIOD, 8);     //
 GPIO_SetBits(GPIOD, 16); 

      
    break;
  case 1:
 
 GPIO_SetBits(GPIOD, 1);
// GPIO_SetBits(GPIOD, 32);     //
 if(swrpm){GPIO_SetBits(GPIOD, 32);}     
    
    break;
  case 2:
    
 if(swrpm){GPIO_SetBits(GPIOD, 2);}    
 //GPIO_SetBits(GPIOD, 2);     //
 GPIO_SetBits(GPIOD, 4);      
    
    break;
  case 3:
   
GPIO_SetBits(GPIOD, 1);
GPIO_SetBits(GPIOD, 2);     
   
    break; 
  case 4:
GPIO_SetBits(GPIOD, 4);      
GPIO_SetBits(GPIOD, 8);     
  
    break;
  case 5:
GPIO_SetBits(GPIOD, 16);
 GPIO_SetBits(GPIOD, 32);
   
    break;       
  }
    
        }
        
      
       
   }
  
   if (TIM_GetITStatus(TIM2, TIM_IT_CC2) != RESET)                                       //this is for the main bridge - engine
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
     
           if(firt){
        
          TIM_SetCounter(TIM5, 0);
          TIM_SetCompare2(TIM5, zap);          //3600
        
        
        }
        else{

          timfourcounter=TIM_GetCounter(TIM5);  
          TIM_SetCompare2(TIM5, (timfourcounter+zap));           
                   
        }
    
    resnom=nomperiod;
        
           switch(nomperiod)
  {
  case 0:
    if(ca0a){if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_11);}  } 
    if(ca0b){if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_12);} }
    
 
    break;
  case 4:
    if(ca1a){if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_10);}  } 
    if(ca1b){if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_11);} }       

    
  
    break;
  case 2:
    if(ca2a){if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_10);}   }
     if(ca2b){if(swvgen){GPIO_SetBits(GPIOD, GPIO_Pin_7);}   }
   
    
    break;
  case 3:
    if(ca3a){if(swvgen){GPIO_SetBits(GPIOD, GPIO_Pin_6);}   }
     if(ca3b){if(swvgen){GPIO_SetBits(GPIOD, GPIO_Pin_7);}    }
        
    break; 
  case 1:
    if(ca4a){if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_13);}   }
     if(ca4b){ if(swvgen){GPIO_SetBits(GPIOD, GPIO_Pin_6);}   }
    
    
    break;
  case 5:
    if(ca5a){  if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_12);}   }
    if(ca5b){ if(swvgen){GPIO_SetBits(GPIOG, GPIO_Pin_13);}     }
     
    
    break;       
  }
    
        
 } 
 
 
   if (TIM_GetITStatus(TIM2, TIM_IT_CC3) != RESET)                                  //this is for the engine's bridge
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);    
    
    if(swaogen){GPIO_SetBits(GPIOH, GPIO_Pin_3);}
      
       
   }
    
}  
    
    void TIM5_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)                                  //this is for the generator's bridge
  {
    TIM_ClearITPendingBit(TIM5, TIM_IT_CC1);
    
             switch(resnom2)
  {
  case 0:
 
 GPIO_ResetBits(GPIOD, 8); 
 GPIO_ResetBits(GPIOD, 16);  
  
    break;
  case 1:
    
GPIO_ResetBits(GPIOD, 32);
GPIO_ResetBits(GPIOD, 1);  
    
    break;
  case 2:
 
 GPIO_ResetBits(GPIOD, 2); 
 GPIO_ResetBits(GPIOD, 4);  
 
    
    break;
  case 3:
  
GPIO_ResetBits(GPIOD, 1);   
GPIO_ResetBits(GPIOD, 2); 
    
    break; 
  case 4:
 
GPIO_ResetBits(GPIOD, 4); 
GPIO_ResetBits(GPIOD, 8);   
    
    break;
  case 5:
    
 GPIO_ResetBits(GPIOD, 32);
 GPIO_ResetBits(GPIOD, 16);   
 
    break;       
  }   
     
  }
  
   if (TIM_GetITStatus(TIM5, TIM_IT_CC2) != RESET)                                       //this is for the main bridge - engine
  {
 
 //   nom[nomco]=resnom;
 //   nomco++;
 //   if(nomco>5){nomco=0;}
    
    
               switch(resnom)
  {
  case 0:
    GPIO_ResetBits(GPIOG, GPIO_Pin_11);                                                            //D4
    GPIO_ResetBits(GPIOG, GPIO_Pin_12);                                                            //D2
  
    break;
  case 4:
    GPIO_ResetBits(GPIOG, GPIO_Pin_11);                                                            //D4
    GPIO_ResetBits(GPIOG, GPIO_Pin_10);                                                            //D3
  
    break;
  case 2:
     GPIO_ResetBits(GPIOG, GPIO_Pin_10);                                                            //D3
     GPIO_ResetBits(GPIOD, GPIO_Pin_7);                                                          //D6        
    break;
  case 3:
     GPIO_ResetBits(GPIOD, GPIO_Pin_6);                                                            //D5
    GPIO_ResetBits(GPIOD, GPIO_Pin_7);                  
    break; 
  case 1:
     GPIO_ResetBits(GPIOG, GPIO_Pin_13);                                                            //D1 
     GPIO_ResetBits(GPIOD, GPIO_Pin_6);                                                            //D5
    break;
  case 5:
    GPIO_ResetBits(GPIOG, GPIO_Pin_12);                                                            //D2
     GPIO_ResetBits(GPIOG, GPIO_Pin_13);                                                            //D1 
   break;       
  }     
    TIM_ClearITPendingBit(TIM5, TIM_IT_CC2);    
    
  } 
  
}   
    

void TIM3_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM3, TIM_IT_CC1) != RESET)                                  //this is for the generator's bridge
  {
    TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);
    
       resnom3=nomperiod3;
      
       if(swvdvig){
       
      switch(nomperiod3)
  {
  case 0:
    break;
    
  case 1:
    if(swvstop){GPIO_SetBits(GPIOD, 32768);}                                                            //D4          GPIO_SetBits(GPIOG, 32768);     
    if(swvstop){GPIO_SetBits(GPIOD, 4096);}                                                            //D1       GPIO_SetBits(GPIOG, 4096);  
    break;
    
  case 2:
    break;
  case 3:
    break; 
    
  case 4:
    if(swvstop){GPIO_SetBits(GPIOD, 16384);}                                                            //D3         GPIO_SetBits(GPIOG, 16384);    
    if(swvstop){GPIO_SetBits(GPIOD, 8192);}                                                            //D2      GPIO_SetBits(GPIOG, 8192);   
    break;
    
  case 5:
    break;       
  }  
       }
          TIM_SetCounter(TIM4, 0);
          TIM_SetCompare1(TIM4, 1800);
//  timfourcounter=TIM_GetCounter(TIM4);  
//  TIM_SetCompare1(TIM4, (timfourcounter+1800));
    
  }
  else if (TIM_GetITStatus(TIM3, TIM_IT_CC2) != RESET)                                       //this is for the main bridge - engine
  {
    TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);
  }
  else if (TIM_GetITStatus(TIM3, TIM_IT_CC3) != RESET)                                  //this is for the monopphase bridge
  {
    TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);
  }
  else
  {
    TIM_ClearITPendingBit(TIM3, TIM_IT_CC4);

 test++;
   
  }
}


void TIM4_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM4, TIM_IT_CC1) != RESET)                                  //this is for the generator's bridge
  {
    TIM_ClearITPendingBit(TIM4, TIM_IT_CC1);
     
     switch(resnom3)
  {
  case 0:

    break;
    
  case 1:
 
         GPIO_ResetBits(GPIOD, 32768);                                                            
         GPIO_ResetBits(GPIOD, 4096);                                                            
         
    break;
    
  case 2:
        
    break;
    
  case 3:
 
    break; 
    
  case 4:
    
       GPIO_ResetBits(GPIOD, 16384);                                                                
       GPIO_ResetBits(GPIOD, 8192);                                                                
       
       break;
       
  case 5:
   
    break;       
  }  
 
 
 
    
  }
  else if (TIM_GetITStatus(TIM4, TIM_IT_CC2) != RESET)                                       //this is for the main bridge - engine
  {
    TIM_ClearITPendingBit(TIM4, TIM_IT_CC2);
  }
  else if (TIM_GetITStatus(TIM4, TIM_IT_CC3) != RESET)                                  //this is for the monopphase bridge
  {
    TIM_ClearITPendingBit(TIM4, TIM_IT_CC3);
  }
  else
  {
    TIM_ClearITPendingBit(TIM4, TIM_IT_CC4);
 
  }
}


/*     void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
  
 // tempavph2= TIM_GetCounter(TIM14);
  TIM_SetCounter(TIM14, 0);
  
  if (TIM_GetITStatus(TIM14, TIM_IT_CC1) != RESET)                                  //this is for the generator's bridge
  {
        
    
    TIM_ClearITPendingBit(TIM14, TIM_IT_CC1);
    
         switch(phseq[countphseq])
  {
  case 0:
    phase0();
    break;
    
  case 1:
    phase1();
    break;
    
  case 2:
    phase2();
    break;
  case 3:
    phase3();
    break; 
    
  case 4:
    phase4();
    break;
    
  case 5:
    phase5();
    break;       
  } 
   
   countphseq++;
   if(countphseq>5){
     countphseq=0;
   }  
   
  }  
    
}   
*/





/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f40xx.s/startup_stm32f427x.s).                         */
/******************************************************************************/
/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */


/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @brief  This function handles External line 0 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0) != RESET)                                             //line
  {
     ph0=TIM_GetCounter(TIM2);    
     TIM_SetCounter(TIM2, 0);
    
    
    if(GPIO_ReadInputDataBit(GPIOC, 1)){
    
      tcommt=commt;
      commt=0;

    GPIO_ResetBits(GPIOH, GPIO_Pin_3);
     
      
//     if(ph0<20000){phasepoc++;}
//     if(ph0>28000){phasepoc++;}
     
 //    if((ph0>24000) && (ph1>24000) && (ph2>24000) && (ph3>24000) && (ph4>24000) && (ph5>24000) && (pokuart==1)){                                                                     //communication with 2.4 - t1
 //      flagmes=1;
 //      USART_SendData(USART1, flagmes);
 //      pokuart=0;
 //    }
     
     if(prog[trans][et][4]==1){
        narab++;
     }
 

 
 torqch=1;
 
     timcan1++;
     if(timcan1==25){
  
       tvcan=t1;
       t1h=((tvcan>>8)&0xFF);
       tvcan=t1;
       t1l=(tvcan&0xFF);
       
       tvcan=t2;
       t2h=((tvcan>>8)&0xFF);
       tvcan=t2;
       t2l=(tvcan&0xFF);       
       
       tvcan=t3;
       t3h=((tvcan>>8)&0xFF);
       tvcan=t3;
       t3l=(tvcan&0xFF);

       tvcan=p1;
       p1h=((tvcan>>8)&0xFF);
       tvcan=p1;
       p1l=(tvcan&0xFF);       
       
       
       cancod=CAN_GetLastErrorCode(CAN1);
       if(cancod>0){cancod10=cancod;}
       canrcod=CAN_GetReceiveErrorCounter(CAN1);
       if(canrcod>0){canrcod10=canrcod;}
       cantcod=CAN_GetLSBTransmitErrorCounter(CAN1);
       if(cantcod>0){cantcod10=cantcod;}
       
       
  TxMessage1.RTR = CAN_RTR_DATA;
  TxMessage1.IDE = CAN_ID_STD;
  TxMessage1.DLC = 8;
  TxMessage1.StdId = 0x10;     
  TxMessage1.Data[0] = t1h;
  TxMessage1.Data[1] = t1l;  
  TxMessage1.Data[2] = t2h;
  TxMessage1.Data[3] = t2l;  
  TxMessage1.Data[4] = t3h;
  TxMessage1.Data[5] = t3l;
  TxMessage1.Data[6] = p1h;       
  TxMessage1.Data[7] = p1l;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage1);      
  
     }
     
/*     if(CAN_GetFlagStatus(CAN1, CANTXOK)){
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 4;
  TxMessage.StdId = 0x10;     
  TxMessage.Data[0] = t1;
  TxMessage.Data[1] = t2;
  TxMessage.Data[2] = t3;
  TxMessage.Data[3] = p1;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage);     
     }
     
     
         GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    vdvcurrent=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    rpm =GPIO_ReadInputData(GPIOE);
     
      Start communication - vazb.tok, rpm  
     i0=0;
     i2=0;
     i3=0;
     GPIO_SetBits(GPIOI, GPIO_Pin_0);
     GPIO_SetBits(GPIOI, GPIO_Pin_2);
     GPIO_SetBits(GPIOI, GPIO_Pin_3);
     
     while(i0==0){
       i0=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_0);
     }
     while(i2==0){
       i2=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_2);
     }     
     while(i3==0){
       i3=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_3);
     }         
     
     
    GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 2048);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 2048);

      
    }
    toku2=GPIO_ReadInputData(GPIOF);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 2048);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 2048);

      
    }
    optrones23 =GPIO_ReadInputData(GPIOF); */
   
    /*  Stop communication - vazb.tok, rpm */   
   
//   if(kdvValue==generator){
//     kdvValue=kdvValue-3;
 //    generator=generator+4;
//   }
   
   if(kdvValue>generator){firt=1;}
   else{firt=0;}
   
    TIM_SetCompare1(TIM3, vgenValue);
    TIM_SetCompare1(TIM2, kdvValue);
    TIM_SetCompare2(TIM2, generator);
    TIM_SetCompare3(TIM2, aogen);

       nomperiod=0;
       nomperiod2=0;
       nomperiod3=0;
//       pokuart=1;
        
    }
    /* Clear the EXTI line 0 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line0);                                                 //line
  }
}


void EXTI1_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line1) != RESET)                                             //line
  {
    ph1=TIM_GetCounter(TIM2); 
    TIM_SetCounter(TIM3, 0);
    TIM_SetCounter(TIM2, 0);   
   
    
      if(GPIO_ReadInputDataBit(GPIOC, 2)){  
    tcommt=commt;
      commt=0;

    GPIO_ResetBits(GPIOH, GPIO_Pin_3);
      
//    if(ph1<20000){phasepoc++;}
//    if(ph1>28000){phasepoc++;}
    
 //    if((ph0>24000) && (ph1>24000) && (ph2>24000) && (ph3>24000) && (ph4>24000) && (ph5>24000) && (pokuart==1)){                                                                     //communication with 2.4 - t2
 //      flagmes=2;
  //     USART_SendData(USART1, flagmes);
 //      pokuart=0;
 //    }    
    



   
/*              GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    vdvcurrent=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    rpm =GPIO_ReadInputData(GPIOE);
    
    
           
     Start communication - napr.dv., optroni  
          
     i0=1;
     i2=0;
     i3=1;
     GPIO_ResetBits(GPIOI, GPIO_Pin_0);
     GPIO_SetBits(GPIOI, GPIO_Pin_2);
     GPIO_ResetBits(GPIOI, GPIO_Pin_3);
     
     while(i0==1){
       i0=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_0);
     }
     while(i2==0){
       i2=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_2);
     }     
     while(i3==1){
       i3=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_3);
     }
         
     
    GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
      
    }
    voltagedv=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);

    }
    optrones =GPIO_ReadInputData(GPIOE);*/
   
    /*  Stop communication - napr.dv., optroni */   

   if(kdvValue==generator){
     kdvValue=kdvValue-3;
     generator=generator+4;
   }
   
   if(kdvValue>generator){firt=1;}
   else{firt=0;}
   
 
   /*  Generators power control */   
      if(swaogen==1){
   
           
        
        
      poweraogen=tokiso*a1;
      
      if(paocd>20){
         
      switch(paoc){
     
        
        
   case 0 :
     pao1=poweraogen;
     paoc++;
     break;
     
   case 1 :
     pao2=poweraogen;
     paoc++;     
     break;
     
   case 2 :
     pao3=poweraogen;
     paoc++;     
     break;
     
   case 3 :
     pao4=poweraogen;
     paoc++;     
     break;  
       
          
   }
   
   if(paoc>3){paoc=0;}
   pao5=pao1+pao2+pao3+pao4;
   pao5=pao5/4;
   
   
   paocd=0;
      }
      else{
        paocd++;
      }
      
      
      
      diff=pao5-valaop;
      diff=abs(diff);
      if(diff<8000){
        aostep=1;
        aod=25;
      }
      if((diff>8000) && (diff<18000)){
        aostep=1;
        aod=3;
      }
      if((diff>18000) && (diff<28000)){
        aostep=3;
        aod=1;
      }     
      if(diff>20000){
        aod=0;
        aostep=5;
      }  
      
      if((paostep==1) && (pao5<100000) && (aod>3)){
        aod=2;
      }
      if(pao5>100000){
        paostep=0;
      }
     
      if(aodc>aod){
     if(pao5<valaop){                            //130
        aogen=aogen-aostep;
        if(aogen<600){aogen=600;}
      }
         
      if(pao5>valaop){aogen=aogen+aostep;}             //130
             
      if(aogen>26100){aogen=26100;}   
 
      aodc=1;
      }
      else{
        aodc++;
      }
 
   }   
   
   
    TIM_SetCompare1(TIM3, vgenValue);
    TIM_SetCompare1(TIM2, kdvValue); 
    TIM_SetCompare2(TIM2, generator);   
    TIM_SetCompare3(TIM2, aogen);
 
       nomperiod=1;
       nomperiod2=1;
       nomperiod3=1;
  //     pokuart=1;
       
       
       can2cod=CAN_GetLastErrorCode(CAN2);
       if(can2cod>0){can2cod22=can2cod;}
       can2rcod=CAN_GetReceiveErrorCounter(CAN2);
       if(can2rcod>0){can2rcod22=can2rcod;}
       can2tcod=CAN_GetLSBTransmitErrorCounter(CAN2);
       if(can2tcod>0){can2tcod22=can2tcod;}
       
        TxMessage2.RTR = CAN_RTR_DATA;
        TxMessage2.IDE = CAN_ID_STD;
        TxMessage2.DLC = 8;
        TxMessage2.StdId = 0x22;     
        TxMessage2.Data[0] = 22;
        TxMessage2.Data[1] = 0;  
        TxMessage2.Data[2] = 0;
        TxMessage2.Data[3] = 0;  
        TxMessage2.Data[4] = 0;
        TxMessage2.Data[5] = 0;
        TxMessage2.Data[6] = 0;       
        TxMessage2.Data[7] = 22;  
        TransmitMailbox2 = CAN_Transmit(CAN2, &TxMessage2);           
       
       
      }
    /* Clear the EXTI line 1 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line1);                                                 //line
  }
}

void EXTI2_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line2) != RESET)                                             //line
  {
      ph2=TIM_GetCounter(TIM2);     
    TIM_SetCounter(TIM2, 0);    
   
      
    tcommt=commt;
      commt=0;
        if(GPIO_ReadInputDataBit(GPIOC, 4)){

          GPIO_ResetBits(GPIOH, GPIO_Pin_3);
      
 //     if(ph2<20000){phasepoc++;}
 //     if(ph2>28000){phasepoc++;}
      
 //    if((ph0>24000) && (ph1>24000) && (ph2>24000) && (ph3>24000) && (ph4>24000) && (ph5>24000) && (pokuart==1)){                                                                     //communication with 2.4 - t3
//       flagmes=3;
//       USART_SendData(USART1, flagmes);
//       pokuart=0;
//     }      
      

 


  /*        GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    vdvcurrent=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    rpm =GPIO_ReadInputData(GPIOE);
      
      
           
      Start communication - tok, optroni  
          
     i0=0;
     i2=0;
     i3=1;
     GPIO_SetBits(GPIOI, GPIO_Pin_0);
     GPIO_SetBits(GPIOI, GPIO_Pin_2);
     GPIO_ResetBits(GPIOI, GPIO_Pin_3);
     
     while(i0==0){
       i0=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_0);
     }
     while(i2==0){
       i2=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_2);
     }     
     while(i3==1){
       i3=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_3);
     }
     
    
    GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);

    }
    tokiso=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);

    }
    optrones =GPIO_ReadInputData(GPIOE);*/
   
     /* Stop communication - tok, optroni */   
   
    tokiso2[cti2]=tokiso;

 cti2++;
 
  tokiso=(tokiso2[0]+tokiso2[1]+tokiso2[2]+tokiso2[3])/4;  
  
 if(cti2>3){

   cti2=0;
 }
   
   
    if(kdvValue==generator){
     kdvValue=kdvValue-3;
     generator=generator+4;
   }
   
   if(kdvValue>generator){firt=1;}
   else{firt=0;}  
   
 
    TIM_SetCompare1(TIM3, vgenValue);
    TIM_SetCompare1(TIM2, kdvValue);  
    TIM_SetCompare2(TIM2, generator);    
    TIM_SetCompare3(TIM2, aogen);
  
      nomperiod=2;
      nomperiod2=2;
      nomperiod3=2;
 //     pokuart=1;
 
      
        }
    /* Clear the EXTI line 2 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line2);                                                 //line
  }
}

void EXTI3_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line3) != RESET)                                             //line
  {
      ph3=TIM_GetCounter(TIM2);
    TIM_SetCounter(TIM2, 0);    
 
  
      
        if(GPIO_ReadInputDataBit(GPIOC, 8)){
    tcommt=commt;
      commt=0;

      GPIO_ResetBits(GPIOH, GPIO_Pin_3);
      
 //     if(ph3<20000){phasepoc++;}
 //     if(ph3>28000){phasepoc++;}
      
//     if((ph0>24000) && (ph1>24000) && (ph2>24000) && (ph3>24000) && (ph4>24000) && (ph5>24000) && (pokuart==1)){                                                                     //communication with 2.4 - p1
//       flagmes=4;
//       USART_SendData(USART1, flagmes);
//       pokuart=0;
//     }         
      
     

 

      if(timcan1>500){timcan1=0;}
     if(timcan1==100){
   timcan1=0;  
       tvcan=rerpmop;
       t1h=((tvcan>>8)&0xFF);
       tvcan=rerpmop;
       t1l=(tvcan&0xFF);
       
       tvcan=torqued;
       t2h=((tvcan>>8)&0xFF);
       tvcan=torqued;
       t2l=(tvcan&0xFF);       
       
       if(typetr==17){
       tvcan=vdvcurrent;
       t3h=((tvcan>>8)&0xFF);
       tvcan=vdvcurrent;
       t3l=(tvcan&0xFF);
       }
       
       if(typetr==24){
         tvcan=0;
         if(fullpr==1){
           
           if((petap==1) || (petap==2)){
       tvcan=pao5/2000;                   //10;   //pao5/2000;         //////////////////////////////////////////////////////////////////////Not working KP (no CAN messages to the control panel
           }
           if((petap==3) || (petap==4) || (petap==6) || (petap==7)){
       tvcan=pao5/1428;                           //15;   //pao5/1428;        //////////////////////////////////////////////////////////////////////Not working KP (no CAN messages to the control panel
           }
       t3h=0;
       //tvcan=vdvcurrent;
       t3l=(tvcan&0xFF);     
       if(petap==0){
         
         t3h=0;
         t3l=0;
       }

         }
         else{
         tvcan=vdvcurrent;
       t3h=((tvcan>>8)&0xFF);
       tvcan=vdvcurrent;
       t3l=(tvcan&0xFF);  
         }
         
       }

       tvcan=toku2;
       p1h=((tvcan>>8)&0xFF);
       tvcan=toku2;
       p1l=(tvcan&0xFF);       
       
       cancod=CAN_GetLastErrorCode(CAN1);
       if(cancod>0){cancod11=cancod;}
       canrcod=CAN_GetReceiveErrorCounter(CAN1);
       if(canrcod>0){canrcod11=canrcod;}
       cantcod=CAN_GetLSBTransmitErrorCounter(CAN1);
       if(cantcod>0){cantcod11=cantcod;}
       
       
  TxMessage3.RTR = CAN_RTR_DATA;
  TxMessage3.IDE = CAN_ID_STD;
  TxMessage3.DLC = 8;
  TxMessage3.StdId = 0x11;     
  TxMessage3.Data[0] = t1h;
  TxMessage3.Data[1] = t1l;  
  TxMessage3.Data[2] = t2h;
  TxMessage3.Data[3] = t2l;  
  TxMessage3.Data[4] = t3h;
  TxMessage3.Data[5] = t3l;
  TxMessage3.Data[6] = p1h;       
  TxMessage3.Data[7] = p1l;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage3);
 
     }      
      
      
  /*          if(CAN_GetFlagStatus(CAN1, CANTXOK)){
  TxMessage.StdId = 0x11;     
  TxMessage.Data[0] = rerpmop;
  TxMessage.Data[1] = torque;
  TxMessage.Data[2] = vdvcurrent;
  TxMessage.Data[3] = tokdc;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage);     
     }      
            GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    vdvcurrent=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    rpm =GPIO_ReadInputData(GPIOE);
      
      
       Start communication 2.3 - tokdc, rpmop  
          
     i0=0;
     i2=1;
     i3=0;
     GPIO_SetBits(GPIOI, GPIO_Pin_0);
     GPIO_ResetBits(GPIOI, GPIO_Pin_2);
     GPIO_SetBits(GPIOI, GPIO_Pin_3);
     
     while(i0==0){
       i0=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_0);
     }
     while(i2==1){
       i2=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_2);
     }     
     while(i3==0){
       i3=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_3);
     }
     
    
    GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 2048);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 2048);
      }
    tokdc=GPIO_ReadInputData(GPIOF);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 2048);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 2048);
      }
     rpmop=GPIO_ReadInputData(GPIOF);*/
   
   switch(rpmopc){
     
   case 0 :
     rpmopt1=rpmop;
     rpmopc++;
     break;
     
   case 1 :
     rpmopt2=rpmop;
     rpmopc++;     
     break;
     
   case 2 :
     rpmopt3=rpmop;
     rpmopc++;     
     break;
       
          
   }
   
   if(rpmopc>2){rpmopc=0;}
   rerpmop=rpmopt1+rpmopt2+rpmopt3;
   
   
     /* Stop communication - tokdc, rpmop */             
  
   
 //  if(oboroti>8000){swvgen=1;}          //5100
   

  
 torquesum=torquesum+(torque- torquem[torquec]);
 torquem[torquec]=torque;
 torqued=torquesum>>7;
  torquec++; 
 if(torquec>127){

   torquec=0;
   
 }
 
    if(swvgen==1){
     /*
      if(tokdc<vazgen){                            //130
        generator=generator-2;
        if(generator<600){generator=600;}
      }
      
         
      if(tokdc>vazgen){generator=generator+2;}             //130
             
      if(generator>26100){generator=26100;} 
      
  
     
      
      
      
      if(torqued<valtor){                            //130
        generator=generator-vgstep;
        if(generator<600){generator=600;}
      }
      
         
      if(torqued>valtor){generator=generator+vgstep;}             //130
             
      if(generator>26100){generator=26100;}        
      
      diff=powergen-valtor;
      diff=abs(diff); */
      
 
      diff=abs(powergen-valtor);
      if(diff<9000){dstep=dstepuf;}
      if((diff>9000) && (diff<19000)){dstep=dstepf;}
      if((diff>19000) && (diff<29000)){dstep=dstepnf;}     
      if(diff>29000){dstep=0;}  

/*     27.03.2016 TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!      
      diff=abs(powergen-valtor);
      if(diff<12000){dstep=(dstepuf+15);}
      if((diff>12000) && (diff<25000)){dstep=(dstepf+10);}
      if((diff>25000) && (diff<39000)){dstep=(dstepnf+5);}     
      if(diff>39000){dstep=0;}
//    27.03.2016 TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!       
*/  //    27.03.2016 TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!       
      if(powert1==0){
      if(avpowergenc==0){
        avpowergen1=tokiso*toku2;
        avpowergenc=1;
      }
      if(avpowergenc==1){
        avpowergen2=tokiso*toku2;
        avpowergenc=0;
      }
      
      powergen=(avpowergen1+avpowergen2)/2;
      }      
      
          
      if(powert1==1){
      if(avpowergenc==0){
        avpowergen1=tokiso*toku2;
        avpowergenc=1;
      }
      if(avpowergenc==1){
        avpowergen2=tokiso*toku2;
        avpowergenc=2;
      }
      if(avpowergenc==2){
        avpowergen3=tokiso*toku2;
        avpowergenc=0;
      }
      
      
      powergen=(avpowergen1+avpowergen2+avpowergen3)/3;
      }
      
      if(powert1==2){
      if(avpowergenc==0){
        avpowergen1=tokiso*toku2;
        avpowergenc=1;
      }
      if(avpowergenc==1){
        avpowergen2=tokiso*toku2;
        avpowergenc=2;
      }
      if(avpowergenc==2){
        avpowergen3=tokiso*toku2;
        avpowergenc=3;
      }
      
      
      if(avpowergenc==3){
        avpowergen4=tokiso*toku2;
        avpowergenc=4;
      }
      if(avpowergenc==4){
        avpowergen5=tokiso*toku2;
        avpowergenc=5;
      }
      if(avpowergenc==5){
        avpowergen6=tokiso*toku2;
        avpowergenc=0;
      }      
      
      
      
      
      
      powergen=(avpowergen1+avpowergen2+avpowergen3+avpowergen4+avpowergen5+avpowergen6)/6;
      }      
      
      
      
      
      
      if((pstep==1) && (dstep<2)){
        dstep=2;
      }
      
/*     
      if(powergen<valtor){                            //130
        if(flstep>dstep){
        generator=generator-vgstep;
        flstep=1;
        }
        else{flstep++;}
      }
      
         
      if(powergen>valtor){
        if(flstep>dstep){
        generator=generator+vgstep;
        flstep=1;
        }
        else{flstep++;}
      }             //130
      
      
 */     
      
      if(powergen<valtor){                            //130
        if((pokvazd==0) || (pokvazd==1)){
        if(flstep>dstep){
        generator=generator-vgstep;
        flstep=1;
        }
        else{flstep++;}
        pokvazd=0;
      }
      }
      
         
      if(powergen>valtor){
        if((pokvazd==0) || (pokvazd==2)){
        if(flstep>dstep){
        generator=generator+vgstep;
        flstep=1;
        }
        else{flstep++;}
        pokvazd=0;
        }
      }             //130      
             
      if(generator>26100){generator=26100;}       
      if(generator<600){generator=600;}     
     
      
 
   }   
   

   
   //generator=22800;
   
   
     if(kdvValue==generator){
     kdvValue=kdvValue-3;
     generator=generator+4;
   }
   
   if(kdvValue>generator){firt=1;}
   else{firt=0;}    
   
    TIM_SetCompare1(TIM3, vgenValue);
    TIM_SetCompare1(TIM2, kdvValue);
    TIM_SetCompare2(TIM2, generator);  
    TIM_SetCompare3(TIM2, aogen);
    
      nomperiod=3;
      nomperiod2=3;
      nomperiod3=3;
 //     pokuart=1;
       
      
        }
    /* Clear the EXTI line 3 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line3);                                                 //line
  }
}

void EXTI4_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line4) != RESET)                                             //line
  {
      ph4=TIM_GetCounter(TIM2); 
      TIM_SetCounter(TIM3, 0);
      TIM_SetCounter(TIM2, 0);  
      
    
        if(GPIO_ReadInputDataBit(GPIOC, 16)){

          GPIO_ResetBits(GPIOH, GPIO_Pin_3);
          
      tcommt=commt;
      commt=0;
//      if(ph4<20000){phasepoc++;}
 //     if(ph4>28000){phasepoc++;}
      
 //     if((ph0>24000) && (ph1>24000) && (ph2>24000) && (ph3>24000) && (ph4>24000) && (ph5>24000) && (pokuart==1)){                                                                     //communication with 2.4 - current generators
 //      flagmes=5;
 //      USART_SendData(USART1, flagmes);
 //      pokuart=0;
 //    }              
      
     
 /*SELF TEST*/
     
   if((typetr==17) && (prog[trans][et][4]==0) && (swrpm==0) && (optrones23==109) && (timacc==0) && (sefst==0)){
    sefst=1;
    }
    if((typetr==24) && (prog[trans][et][4]==0) && (swrpm==0) && (optrones23==61) && (timacc==0) && (sefst==0)){
    sefst=1;
    }   
    
    if(sefst==1){
      
      timsefst++;
      
      swvgen=1;
      swvdvig=1;
      
      
      if(timsefst==3){
        generator=12000;
        vgenValue=12000;
      }
      
      if(timsefst==400){        //400
        
       
        sefstvdv=vdvcurrent-150;
        sefstvdv=abs(sefstvdv);
        
        sefstvgen=tokdc-46;
        sefstvgen=abs(sefstvgen);
        
        if(sefstvdv>20){
          sefstpok=1;
          timsefst=899;
        }
        if(sefstvgen>20){
          sefstpok=2;
          timsefst=899;
        }           
         if((sefstvdv>20) && (sefstvgen>20)){
          sefstpok=3;
          timsefst=899;
        }    
        
        generator=10000;
        vgenValue=10000;
         
      }      
      
      if(timsefst==800){        //800
        
        sefstvdv=abs(vdvcurrent-254);
        sefstvgen=abs(tokdc-112);
        
        if(sefstvdv>40){
          sefstpok=1;
          timsefst=899;
        }
        if(sefstvgen>40){
          sefstpok=2;
          timsefst=899;
        }           
         if((sefstvdv>20) && (sefstvgen>20)){
          sefstpok=3;
          timsefst=899;
        }         
                
      }            
      
      if(timsefst==900){        //900
        
       sefst=2;                
      }         
      
      
    }
      
 /*END OF SELF TEST*/ 
   
   
       can2cod=CAN_GetLastErrorCode(CAN2);
       if(can2cod>0){can2cod23=can2cod;}
       can2rcod=CAN_GetReceiveErrorCounter(CAN2);
       if(can2rcod>0){can2rcod23=can2rcod;}
       can2tcod=CAN_GetLSBTransmitErrorCounter(CAN2);
       if(can2tcod>0){can2tcod23=can2tcod;}
   
        TxMessage4.RTR = CAN_RTR_DATA;
        TxMessage4.IDE = CAN_ID_STD;
        TxMessage4.DLC = 8;
        TxMessage4.StdId = 0x23;     
        TxMessage4.Data[0] = 23;
        TxMessage4.Data[1] = 0;  
        TxMessage4.Data[2] = 0;
        TxMessage4.Data[3] = 0;  
        TxMessage4.Data[4] = 0;
        TxMessage4.Data[5] = 0;
        TxMessage4.Data[6] = 0;       
        TxMessage4.Data[7] = 23;  
        TransmitMailbox2 = CAN_Transmit(CAN2, &TxMessage4);        
   
   
      
      if(swrpm){
        timetap++;
        
        /*common for all programs*/
        if(timetap==6000){      //3 min from the begining, lasts 15 min
          pstep=0;
          generator=9500;  
          swvgen=1;
          valtor=10000;         //valtor=11500;
  //        valaop=5000;
          swaogen=0;
          pokcheck=0;
                     
        }            
        if(timetap==7500){      //3 min from the begining, lasts 15 min
          vdvdel=9700;
          dvdel=11800;
          vgendel=8060;
 //         vaogendel=;
          ukotva=718;
          igen=12;
 //         iaogen;
          ivdv=240;
          ivgen=121;
          torqye=6580;
          pokcheck=0;           
        }
        
        
        
       /*common for all programs*/        
        
              /*stop algorithm*/
        
        if(timetap==590000){
          valaop=0;  
          aostep=50;
          valtor=0;
          dstep=0;
          vgstep=20;          
        }                
        if(timetap==590100){
          swaogen=0;  
          GPIO_ResetBits(GPIOH, GPIO_Pin_12);

        }             
        if(timetap==590150){
          swvgen=0;  
          kdstop=100;
            }      
        if(timetap==590300){
          swdstop=0;  
          vdvtok=0;
        }             
        if(timetap==590800){
          swvstop=0;  
         
        }             
       /*stop algorithm*/ 
        
        
        if(typetr==24){
          if(fullpr){
        if(timetap==9000){      //3 min from the begining
          petap=1;   
          swvgen=1;
          valtor=175000;         //valtor=11500;
          //relaogen=1;
         // swaogen=1;
          paostep=1;
          valaop=100000;
          tetap=9000;
          temtap=54000;
          torq50=81;   //81+50=131
          pokcheck=0;
        }
        if(timetap==9500){      //3 min from the begining
          vdvdel=9750;
          dvdel=10840;
          vgendel=7550;
          vaogendel=8830;
          ukotva=717;
          igen=250;
          iaogen=110;
          ivdv=240;
          ivgen=138;
          torqye=11700;
          rpmzad=370;
          pokcheck=1;  
        }
        
        if(timetap==54000){
          petap=2;   
          valtor=218570;         //valtor=12600;   
          valaop=100000;
          tetap=54000;
          temtap=114000;          
          torq50=111;   //111+50=161
          pokcheck=0;
        }     
     
        if(timetap==54500){      //3 min from the begining
          vdvdel=9700;
          dvdel=10600;
          vgendel=7300;
          vaogendel=8750;
          ukotva=718;
          igen=300;
          iaogen=110;
          ivdv=240;
          ivgen=142;
          torqye=13000;
          rpmzad=370;
          pokcheck=1;  
        }
        
        if(timetap==114000){
          petap=3;  
          valtor=283730;          //valtor=15000; 
          valaop=100000;
          tetap=114000;
          temtap=159000;    
          torq50=159;   //159+50=209    
          pokcheck=0;  
         
        }        
        
        if(timetap==114500){      //3 min from the begining
          vdvdel=9700;
          dvdel=10100;
          vgendel=7000;
          vaogendel=7960;
          ukotva=719;
          igen=395;
          iaogen=130;
          ivdv=240;
          ivgen=150;
          torqye=15100;
          rpmzad=370;
          pokcheck=1;  
        }
        
        if(timetap==159000){
          petap=4;  
          valtor=393690;          //valtor=17800; 
          valaop=100000;
          tetap=159000;
          temtap=174000;   
          torq50=240;   //240+50=290  
          pokcheck=0;     
        }        
        
        if(timetap==159500){      //3 min from the begining
          vdvdel=9700;
          dvdel=9180;
          vgendel=6474;
          vaogendel=7930;
          ukotva=720;
          igen=546;
          iaogen=130;
          ivdv=240;
          ivgen=163;
          torqye=18800;
          rpmzad=370;
          pokcheck=1;  
        }
        
        if(timetap==173500){
           valaop=10000;          
        }
        
        if(timetap==174000){
          petap=5;  
          pstep=1;
          valtor=10000;          //valtor=7000; 
          valaop=10000;
          tetap=174000;
          temtap=189000;      
          torq50=10;   //100+50    
          pokcheck=0;
        }        
        
        if(timetap==189000){
          pstep=0;
          paostep=1;
          petap=6; 
          valtor=283730;           //valtor=15000;  
          valaop=100000;
          tetap=189000;
          temtap=249000;      
          torq50=159;   //159+50=209   
          pokcheck=0;
        }   
   
        if(timetap==189500){      //3 min from the begining
          vdvdel=9700;
          dvdel=10100;
          vgendel=7000;
          vaogendel=7960;
          ukotva=719;
          igen=395;
          iaogen=130;
          ivdv=240;
          ivgen=150;
          torqye=15100;
          rpmzad=370;
          pokcheck=1;  
        }
        
        if(timetap==249000){
          petap=7; 
          valtor=393690;           //valtor=17800;  
          valaop=100000;
          tetap=249000;
          temtap=264000;    
          torq50=240;   //240+50=290
          pokcheck=0;     
        }  
  
        if(timetap==249500){      //3 min from the begining
          vdvdel=9700;
          dvdel=9180;
          vgendel=6474;
          vaogendel=7930;
          ukotva=720;
          igen=546;
          iaogen=130;
          ivdv=240;
          ivgen=163;
          torqye=18800;
          rpmzad=370;
          pokcheck=1;  
        }
        
        if(timetap==264000){
          pstep=1;
          petap=8;  
          valtor=0;          //valtor=3000; 
          valaop=0;
          dstep=0;
          aostep=10;
          tetap=264000;
          temtap=273000;   
          torq50=0;   //shut down     
          pokcheck=0; 
          endch=1;
        }        
        
        if(timetap==270000){
          vgstep=20;
        }
     
     if(timetap==272500){
          swvgen=0;
          swaogen=0;
          relaogen=0;
        }   
        
        if(timetap==273000){
          timetap=272999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          relaogen=0;
          ok=80;
         
          
        }         
 
          }
      
             
          
          
          if(shpr9){                    //209kg-60min, no generators, 10 min acceleration
        if(timetap==9000){      //3 min from the begining
          petap=1;   
          swvgen=1;
          valtor=233730;         //valtor=11500;
          swaogen=0;
          torq50=159;   //159+50=209    
          pokcheck=0;  
          tetap=9000;
          temtap=189000;
        }
        
        if(timetap==11550){      //3 min from the begining
          
          valtor=283730;         //valtor=11500;
          
        }
        
        if(timetap==16500){      //
          vdvdel=9700;
          dvdel=10600;
          vgendel=7000;
          vaogendel=23000;
          ukotva=718;
          igen=395;
          iaogen=0;
          ivdv=240;
          ivgen=150;
          torqye=15100;
          rpmzad=370;
          pokcheck=0; 
        }
        
        
        if(timetap==189000){
          pstep=1;
          petap=8;  
         valtor=0;          //valtor=3000;
         dstep=0; 
         poweraogen=0;
         torq50=0;   //159+50    
          pokcheck=0;
          tetap=189000;
          temtap=198000;  
  endch=1;        
        }     
        
        if(timetap==195000){
          vgstep=20;
        } 
        
        
        if(timetap==197500){
          swvgen=0;
          swaogen=0;
          relaogen=0;
        }
        
        if(timetap==198000){
          timetap=197999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          ok=80;
          
        }     
        
            }   
          
    /*      
          if(shpr1){                    //131kg-15min
        if(timetap==9000){      //3 min from the begining
          petap=1;   
          swvgen=1;
          valtor=198240;         //valtor=11500;
          swaogen=1;
          tetap=9000;
          temtap=54000;
        }
        
        if(timetap==54000){
          petap=8;  
         valtor=0;          //valtor=3000; 
         vgstep=10;
         dstep=0;
         poweraogen=0;
          tetap=54000;
          temtap=63000;          
        }        
        
        if(timetap==63000){
          timetap=62999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          
        }     
        
            } 
          
          if(shpr3){                    //209kg-15min
        if(timetap==9000){      //3 min from the begining
          petap=1;   
          swvgen=1;
          valtor=198240;         //valtor=11500;
          swaogen=1;
          tetap=9000;
          temtap=54000;
        }
        
        if(timetap==54000){
          petap=8;  
         valtor=0;          //valtor=3000; 
         vgstep=10;
         dstep=0;
         poweraogen=0;
          tetap=54000;
          temtap=63000;          
        }        
        
        if(timetap==63000){
          timetap=62999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          
        }     
        
            }    
          if(shpr4){                    //290kg-5min
        if(timetap==9000){      //3 min from the begining
          petap=1;   
          swvgen=1;
          valtor=198240;         //valtor=11500;
          swaogen=1;
          tetap=9000;
          temtap=24000;
        }
        
        if(timetap==24000){
          petap=8;  
         valtor=0;          //valtor=3000; 
         vgstep=10;
         dstep=0;
         poweraogen=0;
          tetap=24000;
          temtap=33000;          
        }        
        
        if(timetap==33000){
          timetap=32999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          
        }     
        
            }    */
   
        }   
       
       
        if(typetr==17){
          /*
          if(fullpr){
           
        if(timetap==9000){      //3 min from the begining, lasts 15 min
          petap=1;   
          swvgen=1;
          valtor=150000;         //valtor=11500;
          swaogen=0;
          tetap=9000;
          temtap=69000;           
        }
        
        if(timetap==39000){      //same load as prevoius
          petap=2;   
          valtor=150000;         //valtor=12600;     
          tetap=9000;
          temtap=69000;             
        }        
        
        if(timetap==69000){
          petap=3;  
         valtor=255000;          //valtor=15000; 
          tetap=69000;
          temtap=159000;          
        }        
        
        if(timetap==159000){
          petap=4;  
         valtor=305000;          //valtor=17800; 
          tetap=159000;
          temtap=174000;          
        }        
        
        if(timetap==174000){
          petap=5;  
         valtor=10000;          //valtor=7000; 
          tetap=174000;
          temtap=189000;          
        }        
        
        if(timetap==189000){
          petap=6; 
        valtor=238000;           //valtor=15000;  
          tetap=189000;
          temtap=264000;         
        }        
        
        if(timetap==264000){
          petap=7; 
        valtor=282000;           //valtor=17800;  
          tetap=264000;
          temtap=279000;         
        }        
        
        if(timetap==279000){
          petap=8;  
         valtor=0;          //valtor=3000; 
         vgstep=5;
         poweraogen=0;
          tetap=279000;
          temtap=288000;          
        }        
        
        if(timetap==288000){
          timetap=287999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
                   
        }   
          }
          if(shpr1){            //71kg-20min
         
          
        if(timetap==9000){      //3 min from the begining, lasts 15 min
          petap=1;   
          swvgen=1;
          valtor=150000;         //valtor=11500;
          swaogen=0;
          tetap=9000;
          temtap=69000;           
        }
    
        if(timetap==69000){
          petap=8;  
          dstep=1;
         valtor=0;          //valtor=3000; 
         vgstep=10;
         poweraogen=0;
          tetap=69000;
          temtap=78000;          
        }        
        
        if(timetap==78000){
          timetap=77999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
                   
        }   
          }   */
        
        //opashen val Mi-8
          
          if(shpr9){                    //132kg-60min, no generators, 10 min acceleration
        if(timetap==15000){      //3 min from the begining      //9000
          petap=1;   
          swvgen=1;
          valtor=124250;         //valtor=11500;        //160500
          swaogen=0;
          torq50=82;   //82+50    
          pokcheck=0;  
          tetap=15000;  //9000
          temtap=189000;
        }
        
        if(timetap==18500){      //3 min from the begining      //12500
          petap=1;   
          swvgen=1;
          valtor=187500;         //valtor=11500;
          swaogen=0;
          torq50=82;   //82+50    
          pokcheck=0;  
          tetap=15000;  //9000
          temtap=189000;
        }        
        
       
        
        if(timetap==189000){
          pstep=1;
          petap=8;  
         valtor=0;          //valtor=3000;
         dstep=0; 
         poweraogen=0;
         torq50=0;   //    
          pokcheck=0;
          tetap=189000;
          temtap=198000;  
  endch=1;        
        }     
        
        if(timetap==195000){
          vgstep=20;
        }
        
        if(timetap==197500){
          swvgen=0;
          swaogen=0;
          relaogen=0;
        }
        
        if(timetap==198000){
          timetap=197999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          ok=80;
          
        }     
        
            }     
          
    //krai opashen val Mi-8      ó
          
  
        //1-va obkatka Mi-8
          
          if(shpr3){                    //132kg-60min, no generators, 10 min acceleration
        if(timetap==15000){      //3 min from the begining
          petap=1;   
          swvgen=1;
          valtor=124250;         //valtor=11500;
          swaogen=0;
          torq50=40;   //40+50    
          pokcheck=0;  
          tetap=15000;
          temtap=195000;
        }
        
 //       if(timetap==11550){      //3 min from the begining
          
 //         valtor=283730;         //valtor=11500;
          
  //      }
        
        if(timetap==16500){      //
          vdvdel=9700;
          dvdel=10600;
          vgendel=7000;
          vaogendel=23000;
          ukotva=718;
          igen=395;
          iaogen=0;
          ivdv=240;
          ivgen=150;
          torqye=15100;
          rpmzad=370;
          pokcheck=0; 
        }
        
        
        if(timetap==195000){
          pstep=1;
          petap=8;  
         valtor=0;          //valtor=3000;
         dstep=0; 
         poweraogen=0;
         torq50=0;   //    
          pokcheck=0;
          tetap=195000;
          temtap=204000;   
   endch=1;       
        }   
        
        if(timetap==201000){
          vgstep=20;
        } 
        
        if(timetap==203500){
          swvgen=0;
          swaogen=0;
          relaogen=0;
        }
        
        if(timetap==204000){
          timetap=203999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          ok=80;
          
        }     
        
            }     
          
    //krai 1-va obkatka Mi-8
        
        
        //2-ra obkatka Mi-8
          
          if(shpr5){                    //132kg-60min, no generators, 10 min acceleration
        if(timetap==15000){      //5 min from the begining
          petap=1;   
          swvgen=1;
          valtor=124250;         //valtor=11500;
          swaogen=0;
          torq50=40;   //40+50    
          pokcheck=0;  
          tetap=15000;
          temtap=195000;
        }
        
         
        if(timetap==195000){      //5 min from the begining
          petap=2;   
          valtor=187500;         //valtor=11500;
          torq50=82;   //82+50    
          pokcheck=0;  
          tetap=195000;
          temtap=375000;
        }
        
  
        
        if(timetap==375000){      //5 min from the begining
          petap=3;   
          valtor=233300;         //valtor=11500;
          torq50=113;   //113+50    
          pokcheck=0;  
          tetap=375000;
          temtap=390000;
        }
        
    
        
        if(timetap==390000){
          pstep=1;
          petap=8;  
         valtor=0;          //valtor=3000;
         dstep=0; 
         poweraogen=0;
         torq50=0;   //    
          pokcheck=0;
          tetap=390000;
          temtap=399000;      
      endch=1;    
        }    
        
        if(timetap==396000){
          vgstep=20;
        } 
        
        if(timetap==398500){
          swvgen=0;
          swaogen=0;
          relaogen=0;
        }
        
        if(timetap==399000){
          timetap=398999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          ok=80;
          
        }     
        
            }     
          
    //krai 2-ra obkatka Mi-8        
        
  
  
        //3-ta obkatka Mi-8
          
          if(shpr4){                    //132kg-60min, no generators, 10 min acceleration
        if(timetap==15000){      //5 min from the begining
          petap=1;   
          swvgen=1;
          valtor=187500;         //valtor=11500;
          swaogen=0;
          torq50=82;   //82+50    
          pokcheck=0;  
          tetap=15000;
          temtap=90000;
        }
        
         
        if(timetap==90000){      //5 min from the begining
          petap=2;   
          valtor=233300;         //valtor=11500;
          torq50=113;   //113+50    
          pokcheck=0;  
          tetap=90000;
          temtap=105000;
        }
        
      
 
        if(timetap==105000){
          pstep=1;
          petap=8;  
         valtor=0;          //valtor=3000;
         dstep=0; 
         poweraogen=0;
         torq50=0;   //    
          pokcheck=0;
          tetap=105000;
          temtap=114000;      
      endch=1;    
        }  
        
        if(timetap==108000){
          vgstep=20;
        }   
        
        if(timetap==113500){
          swvgen=0;
          swaogen=0;
          relaogen=0;
        }
        
        if(timetap==114000){
          timetap=113999;
          petap=9;  
          swvgen=0;
          swdstop=0;
          swvdvig=0;
          swaogen=0;
          ok=80;
          
        }     
        
            }     
          
    //krai 3-ta obkatka Mi-8      
          
  
        }          
 
      }
      
     
     
     if(timcan1==50){
    
  /*            
       mingn=timetap/3000;
       secgn=mingn*3000;
       secgn=timetap-secgn;
       secgn=secgn/50;       
       if(typetr==24){
         mingk=91-mingn;
         secgk=59-secgn;
       }
       if(typetr==17){
         mingk=96-mingn;
         secgk=59-secgn;
       }      
       minmn=(timetap-tetap)/3000;
       secmn=minmn*3000;
       secmn=(timetap-tetap)-secmn;
       secmn=secmn/50;       
       minmk=((temtap-timetap)-1)/3000;
       secmk=59-secmn;      
      
       */
       
       
       if((timacc>0) && (timacc<50000)){
         
         mingn=10+pokprob;
         mingn=((mingn+errora+ok)&0xFF);
         minmn=((timacc/3000)&0xFF);
         secmn=minmn*3000;
         secmn=timacc-secmn;
         secmn=((secmn/50)&0xFF);
         minmk=((endacc-minmn)&0xFF);
         secmk=((59-secmn)&0xFF);
       }
       if(timacc>49999){
         
         mingn=40+pokprob;
         mingn=((mingn+errora+ok)&0xFF);
         //pokprob=0;
       }
       if(timetap>0){
         if(timetap<uskorhz){
           minmn=((timetap/3000)&0xFF);
           secmn=minmn*3000;
           secmn=timetap-secmn;
           secmn=((secmn/50)&0xFF);       
           minmk=((pokgrpm-minmn)&0xFF);
           secmk=((59-secmn)&0xFF);    
           mingk=0;
         }
         else{
           minmn=(((timetap-tetap)/3000)&0xFF);
           secmn=minmn*3000;
           secmn=(timetap-tetap)-secmn;
           secmn=((secmn/50)&0xFF);       
           minmk=((((temtap-timetap)-1)/3000)&0xFF);
           secmk=((59-secmn)&0xFF);  
           mingk=1;
           if(ok==80){
             mingk=2;
           }
         }
                 
       }
       
       narabt=narab;
       if(narabt==0){narabt=1;}
       narabt=narabt/3000;
       secgk=narabt;
       nar8=(secgk&0xFF);
      //nar8=0;
       
       cancod=CAN_GetLastErrorCode(CAN1);
       if(cancod>0){cancod22=cancod;}
       canrcod=CAN_GetReceiveErrorCounter(CAN1);
       if(canrcod>0){canrcod22=canrcod;}
       cantcod=CAN_GetLSBTransmitErrorCounter(CAN1);
       if(cantcod>0){cantcod22=cantcod;}
       
       if(pokop==0){    
  TxMessage5.RTR = CAN_RTR_DATA;
  TxMessage5.IDE = CAN_ID_STD;
  TxMessage5.DLC = 8;
  TxMessage5.StdId = 0x22;     
  TxMessage5.Data[0] = mingn;
  TxMessage5.Data[1] = torq50;  
  TxMessage5.Data[2] = mingk;
  TxMessage5.Data[3] = nar8;  
  TxMessage5.Data[4] = minmn;
  TxMessage5.Data[5] = secmn;
  TxMessage5.Data[6] = minmk;       
  TxMessage5.Data[7] = secmk;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage5);
     }           
     
     else{
  TxMessage5.RTR = CAN_RTR_DATA;
  TxMessage5.IDE = CAN_ID_STD;
  TxMessage5.DLC = 8;
  TxMessage5.StdId = 0x33;     
  TxMessage5.Data[0] = mingn;
  TxMessage5.Data[1] = secgn;  
  TxMessage5.Data[2] = mingk;
  TxMessage5.Data[3] = nar8;  
  TxMessage5.Data[4] = sefst;
  TxMessage5.Data[5] = sefstpok;
  TxMessage5.Data[6] = prog[trans][et][4];       
  TxMessage5.Data[7] = optrones23;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage5);       
 pokop=0;      
              
     }
     }
     
       
       
       
         
      
      
      
  /*             GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    vdvcurrent=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    rpm =GPIO_ReadInputData(GPIOE);
      
       Start communication 2.3 - toku, torque  
     
 
      
     i0=1;
     i2=0;
     i3=0;
     GPIO_ResetBits(GPIOI, GPIO_Pin_0);
     GPIO_SetBits(GPIOI, GPIO_Pin_2);
     GPIO_SetBits(GPIOI, GPIO_Pin_3);
     
     while(i0==1){
       i0=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_0);
     }
     while(i2==0){
       i2=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_2);
     }     
     while(i3==0){
       i3=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_3);
     }
     
    
    GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 2048);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 2048);
    
    }
    toku=GPIO_ReadInputData(GPIOF);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 2048);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 2048);
   
    }
     torque=GPIO_ReadInputData(GPIOF);*/
   
     /* Stop communication - toku, torque */         
 
   
     if(kdvValue==generator){
     kdvValue=kdvValue-3;
     generator=generator+4;
   }
   
   if(kdvValue>generator){firt=1;}
   else{firt=0;}    
   
   powerdvig=tokiso*voltagedv;
   
   
     TIM_SetCompare1(TIM3, vgenValue);
     TIM_SetCompare1(TIM2, kdvValue); 
     TIM_SetCompare2(TIM2, generator);
     TIM_SetCompare3(TIM2, aogen);
 
     nomperiod=4;
     nomperiod2=4;
     nomperiod3=4;
//     pokuart=1;
     
     
        }
    /* Clear the EXTI line 4 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line4);                                                 //line
    
    
  }
  
  
}

void EXTI9_5_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line5) != RESET)                                             //line
  {
      ph5=TIM_GetCounter(TIM2);    
      TIM_SetCounter(TIM2, 0); 
      
        if(GPIO_ReadInputDataBit(GPIOC, 32)){

          GPIO_ResetBits(GPIOH, GPIO_Pin_3);
          
      tcommt=commt;
      commt=0;
 //     if(ph5<20000){phasepoc++;}
 //     if(ph5>28000){phasepoc++;}
      

      
       /*        GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    vdvcurrent=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    }
    rpm =GPIO_ReadInputData(GPIOE);
 
       Start communication 2.3 - toku2, optrones23  
          
     i0=0;
     i2=1;
     i3=1;
     GPIO_SetBits(GPIOI, GPIO_Pin_0);
     GPIO_ResetBits(GPIOI, GPIO_Pin_2);
     GPIO_ResetBits(GPIOI, GPIO_Pin_3);
     
     while(i0==0){
       i0=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_0);
     }
     while(i2==1){
       i2=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_2);
     }     
     while(i3==1){
       i3=GPIO_ReadInputDataBit(GPIOI, GPIO_Pin_3);
     }
     
    
    GPIO_SetBits(GPIOI, 2);
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    while(comm==0){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
    
    }
    vdvcurrent=GPIO_ReadInputData(GPIOE);
    GPIO_ResetBits(GPIOI, 2); 
    comm=GPIO_ReadInputDataBit(GPIOI, 1024);
   while(comm){
      comm=GPIO_ReadInputDataBit(GPIOI, 1024);
     
    }
     rpm=GPIO_ReadInputData(GPIOE);*/
   
     /* Stop communication - toku2, optrones23 */     
 
      if((ph0>10000) && (ph1>10000) && (ph2>10000) && (ph3>10000) && (ph4>10000) && (ph5>10000)){                                                                     //communication with 2.4 - current generators

        
        
        can2cod=CAN_GetLastErrorCode(CAN2);
       if(can2cod>0){can2cod24=can2cod;}
       can2rcod=CAN_GetReceiveErrorCounter(CAN2);
       if(can2rcod>0){can2rcod24=can2rcod;}
       can2tcod=CAN_GetLSBTransmitErrorCounter(CAN2);
       if(can2tcod>0){can2tcod24=can2tcod;}
        
       TxMessage6.RTR = CAN_RTR_DATA;
        TxMessage6.IDE = CAN_ID_STD;
        TxMessage6.DLC = 8;
        TxMessage6.StdId = 0x24;     
        TxMessage6.Data[0] = 24;
        TxMessage6.Data[1] = 0;  
        TxMessage6.Data[2] = 0;
        TxMessage6.Data[3] = 0;  
        TxMessage6.Data[4] = 0;
        TxMessage6.Data[5] = 0;
        TxMessage6.Data[6] = 0;       
        TxMessage6.Data[7] = 24;  
        TransmitMailbox2 = CAN_Transmit(CAN2, &TxMessage6);  
        
     }     
      
               
  
  
      
 
   
   start=prog[trans][et][4];
   
   if(start==0 && (sefst==0)){
     swvgen=0;
     swvdvig=0;
     swdvig=0;
     vgenValue=11000;
     kdvValue=25200;
     generator=24500;     
   }
   
   if(start==0 && (sefst==2)){
     swvgen=0;
     swvdvig=0;
     swdvig=0;
     vgenValue=11000;
     kdvValue=25200;
     generator=24500;     
   }   
   if((swrpm==0) && (stoppd==1)){
     swvgen=0;
     swvdvig=0;
     swdvig=0;
     vgenValue=11000;
     kdvValue=25200;
     generator=24500;     
   }
   if(start){
     swvdvig=1;     
   }   
    
    realrpm=rpm/2;
    if((rpm-oboroti)>1000){rpm=oboroti;}
    oboroti=rpm;
    
/*    27.03.2016 TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      diff=vdvcurrent-vdvtok;
      diff=abs(diff);
      if(diff<2){vdvcik=3;}
      if((diff>2) && (diff<4)){vdvcik=1;}
         
      if(diff>4){vdvcik=0;}   
    
    
    if(vdvzak>vdvcik){ 
    
    if(vdvcurrent<vdvtok){                                                            // dvigatel vazbuzdane
      vgenValue--;}
    if(vdvcurrent>vdvtok){
      vgenValue++;}
    
    vdvzak=1;
    }
    else{
      vdvzak++;
    }
*/   //   27.03.2016 TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
    
//    if(vdvcurrent<vdvtok){                                                            // dvigatel vazbuzdane
//      vgenValue--;}
//    if(vdvcurrent>vdvtok){
//      vgenValue++;}    
    
 //   27.03.2016 TEST!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    
    
    
    if(vdvcurrent<vdvtok){                                                            // dvigatel vazbuzdane
      vgenValue--;
      pokvazd=1;
    }
    if(vdvcurrent>vdvtok){
      vgenValue++;
      pokvazd=2;
    }     
    
    
    
    if((delfalarm<300) && (swvdvig==1)&& (sefst==2)){                                   //ring bell
      //GPIO_SetBits(GPIOH, GPIO_Pin_11);
      GPIO_SetBits(GPIOH, GPIO_Pin_10);
      delfalarm++;
    }
    if(delfalarm>299){
      //GPIO_ResetBits(GPIOH, GPIO_Pin_11);
      GPIO_ResetBits(GPIOH, GPIO_Pin_10);
      delfalarm=301;
    }
   
    if((uskor==0) && (sefst==2) && (delfalarm>300)){
    if(vdvcurrent<(vdvtok-60)){ swdvig=0;}                                                           // dvigatel vazbuzdane
    if(vdvcurrent>(vdvtok-40)){ swdvig=1;}                                                           // dvigatel vazbuzdane    
    }
    
    
    if(beg==0 && swdvig==1){
      if(rpmop>90 && rpmop<120 && timacc<102){
        timacc++;
      }
      if((timacc>100) && (timacc<pracc) && (typetr==24)){

        if(rpmop<185){                                        //mi-17 4800             //mi-24 6000
          kdvValue=kdvValue-1;
          if(kdvValue<22200){kdvValue=22200;}
        }
        if(rpmop<185 && rpmop>=175){                 //mi-17 5178,4800               //mi-24 6480,6000
          kdvValue=kdvValue-1;
          if(kdvValue<22200){kdvValue=22200;}
        }    
        if(rpmop>195){kdvValue=kdvValue+2;}                    //mi-17 6000                  //mi-24 7000
             
        if(rpmop>185 && rpmop<=195){kdvValue=kdvValue+1;}      //mi-17 5178,6000            //mi-24 6480, 7000
        if(kdvValue>25300){kdvValue=25300;}                      
        
        timacc++;
      }
      
      if((timacc>100) && (timacc<pracc) && (typetr==17)){

        if(rpmop<188){                                        //mi-17 4800             //mi-24 6000
          kdvValue=kdvValue-1;
          if(kdvValue<22200){kdvValue=22200;}
        }
        if(rpmop<188 && rpmop>=175){                 //mi-17 5178,4800               //mi-24 6480,6000
          kdvValue=kdvValue-1;
          if(kdvValue<22200){kdvValue=22200;}
        }    
        if(rpmop>195){kdvValue=kdvValue+2;}                    //mi-17 6000                  //mi-24 7000
             
        if(rpmop>188 && rpmop<=195){kdvValue=kdvValue+1;}      //mi-17 5178,6000            //mi-24 6480, 7000
        if(kdvValue>25300){kdvValue=25300;}                      
        
        timacc++;
      }
      
      
      if(timacc>1200 && timacc<5500){
        vdvtok=vaz2;
        uskor=1;
         }      
      if(timacc>5800){
        
        uskor=0;
         }  
     
      if((timacc>300) && (timacc<pracc)){
        if(rpmop<70){
          rpmch++;
          pokprob=7;
        }
        else{
          rpmch=0;
        }
        if(rpmch>250){
          stoppd=1;          
        }
         }     
      
      
      if(timacc==pracc){
        vdvtok=vaz2;
        swdvig=0;
        kdvValue=23000;
        swrpm=1;
        timacc=50000;
        beg=1;
      }
      
    }
    /*
    if(oboroti>2200){
   //   if(vdvtok<200){vgenValue=10000;}
      vdvtok=vaz2;               //190
      if(swstart==0){
        kdvValue=25200;}
      swrpm=1;                                  //new!!!!!!!
    }*/
    
    if(timacc<10){                    // vazbuzdane na visoki oboroti za razli4nite transmisii, proverka vednaz
      if(typetr==24){
        vaz2=240;
      }
      else{
        vaz2=380;
      }
    }
 
    
//    if(swrpm==1 && swdvig==1){swstart++;}
    if(swrpm==1 && swdvig==1){
//      swstart=401;
      
      
      if(typetr==24){
      if(rpmop>70){
        
      if(rpmop<300){                                        //mi-17 4800             //mi-24 6000
        kdvValue=kdvValue-2;
        if(kdvValue<600){kdvValue=600;}
      }
      
      if((rpmop<368) && (rpmop>=300)){                 //mi-17 5178,4800               //mi-24 6480,6000
        kdvValue=kdvValue-1;
        if(kdvValue<600){kdvValue=600;}
      }      
      
      if((rpmop<370) && (rpmop>=368)){                 //mi-17 5178,4800               //mi-24 6480,6000
        
        if(kdvd1>kdvd2){
        kdvValue=kdvValue-1;
        kdvd1=0;
              }
              else{
                kdvd1++;
              }
        
        if(kdvValue<600){kdvValue=600;}
      }           
      
      
      
      
      if(rpmop>400){kdvValue=kdvValue+2;}                    //mi-17 6000                  //mi-24 7000
             
      if((rpmop>372) && (rpmop<=400)){
        
        kdvValue=kdvValue+1;
        
      }      //mi-17 5178,6000            //mi-24 6480, 7000
      
      if((rpmop>370) && (rpmop<=372)){
        
            if(kdvd1>kdvd2){
        kdvValue=kdvValue+1;
        kdvd1=0;
              }
              else{
                kdvd1++;
              }
        
      }      //mi-17 5178,6000            //mi-24 6480, 7000      
      
      
      
        if(kdvValue>25300){kdvValue=25300;}              
        
        
      }
      
      else{
      
      if(oboroti<6000){                                        //mi-17 4800             //mi-24 6000
        kdvValue=kdvValue-2;
        if(kdvValue<600){kdvValue=600;}
      }
      
      if((oboroti<6480) && (oboroti>6000)){                 //mi-17 5178,4800               //mi-24 6480,6000
        kdvValue=kdvValue-1;
        if(kdvValue<600){kdvValue=600;}
      }      
      
      
      if(oboroti>7000){kdvValue=kdvValue+2;}                    //mi-17 6000                  //mi-24 7000
             
      if((oboroti>6480) && (oboroti<7000)){kdvValue=kdvValue+1;}      //mi-17 5178,6000            //mi-24 6480, 7000
        if(kdvValue>25300){kdvValue=25300;}      
      
      }
      }
 
      if(typetr==17){
      if(rpmop>70){
        
      if(rpmop<300){                                        //mi-17 4800             //mi-24 6000
        kdvValue=kdvValue-2;
        if(kdvValue<600){kdvValue=600;}
      }
      
      if((rpmop<373) && (rpmop>=300)){                 //mi-17 5178,4800               //mi-24 6480,6000
        
        kdvValue=kdvValue-1;
        
        if(kdvValue<600){kdvValue=600;}
      }      
            if((rpmop<375) && (rpmop>=373)){                 //mi-17 5178,4800               //mi-24 6480,6000
        
              if(kdvd1>kdvd2){
        kdvValue=kdvValue-1;
        kdvd1=0;
              }
              else{
                kdvd1++;
              }
        
        if(kdvValue<600){kdvValue=600;}
      }      
      
      
      
      
      if(rpmop>400){kdvValue=kdvValue+2;}                    //mi-17 6000                  //mi-24 7000
             
      if((rpmop>377) && (rpmop<=400)){
        
        kdvValue=kdvValue+1;
        
      }      //mi-17 5178,6000            //mi-24 6480, 7000
      
      if((rpmop>375) && (rpmop<=377)){
        
         if(kdvd1>kdvd2){
        kdvValue=kdvValue+1;
        kdvd1=0;
              }
              else{
                kdvd1++;
              }
        
      }      //mi-17 5178,6000            //mi-24 6480, 7000      
      
      
      
      
        if(kdvValue>25300){kdvValue=25300;}              
        
        
      }
      
      else{
      
      if(oboroti<4800){                                        //mi-17 4800             //mi-24 6000
        kdvValue=kdvValue-2;
        if(kdvValue<600){kdvValue=600;}
      }
      
      if(oboroti<5178 && oboroti>4800){                 //mi-17 5178,4800               //mi-24 6480,6000
        kdvValue=kdvValue-1;
        if(kdvValue<600){kdvValue=600;}
      }      
      
      
      if(oboroti>6000){kdvValue=kdvValue+2;}                    //mi-17 6000                  //mi-24 7000
             
      if(oboroti>5178 && oboroti<6000){kdvValue=kdvValue+1;}      //mi-17 5178,6000            //mi-24 6480, 7000
        if(kdvValue>25300){kdvValue=25300;}      
      
      }
      }      
      
      
      
      
      
      
    }
    
  
     if(kdvValue==generator){
     kdvValue=kdvValue-3;
     generator=generator+4;
   }
   
   if(kdvValue>generator){firt=1;}
   else{firt=0;}     
    

   kdvValue=kdvValue+kdstop;
      if(kdvValue>26100){kdvValue=26100;}
   
    TIM_SetCompare1(TIM3, vgenValue);
    TIM_SetCompare1(TIM2, kdvValue);
    TIM_SetCompare2(TIM2, generator);
    TIM_SetCompare3(TIM2, aogen);
    
  
    nomperiod=5;
    nomperiod2=5;
    nomperiod3=5;
    /* Clear the EXTI line 5 pending bit */

    
        }
      EXTI_ClearITPendingBit(EXTI_Line5);                                                 //line
  
  } 
}








/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

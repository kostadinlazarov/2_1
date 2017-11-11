/**
  ******************************************************************************
  * @file    ADC/ADC_DMA/main.c 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    18-January-2013
  * @brief   Main program body
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
#include "main.h"
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




TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;
__IO uint16_t CCR1_Val3 = 64000;
__IO uint16_t CCR2_Val3 = 63000;
__IO uint16_t CCR3_Val3 = 62000;
__IO uint16_t CCR4_Val3 = 10000;

__IO uint16_t CCR1_Val4 = 64200;
__IO uint16_t CCR2_Val4 = 63200;
__IO uint16_t CCR3_Val4 = 62200;
__IO uint16_t CCR4_Val4 = 65000;


__IO uint16_t CCR1_Val2 = 64500;
__IO uint16_t CCR2_Val2 = 63500;
__IO uint16_t CCR3_Val2 = 63450;

__IO uint16_t CCR1_Val5 = 64300;
__IO uint16_t CCR2_Val5 = 63300;

__IO uint16_t CCR1_Val6 = 64500;
__IO uint16_t CCR2_Val6 = 63500;

__IO uint16_t CCR1_Val7 = 64300;
__IO uint16_t CCR2_Val7 = 63300;


uint16_t downlim=0;
uint16_t uplim=0;
uint16_t downlim2=0;

uint16_t ph0=0;
uint16_t ph1=0;
uint16_t ph2=0;
uint16_t ph3=0;
uint16_t ph4=0;
uint16_t ph5=0;
uint8_t phasepoc = 0;
uint8_t t1h;
uint8_t t1l;
uint8_t t2h;
uint8_t t2l;
uint8_t t3h;
uint8_t t3l;
uint8_t p1h;
uint8_t p1l;
uint16_t tvcan; 
uint8_t i0;
uint8_t i2;
uint8_t i3;
uint8_t firt = 1;
uint8_t comm=0;
uint8_t resnom;
uint8_t resnom2;
uint8_t resnom3;
uint8_t nomperiod3;
uint32_t pao1=0;
uint32_t pao2=0;
uint32_t pao3=0;
uint32_t pao4=0;
uint32_t pao5=0;
uint8_t paoc=0;
uint8_t paocd=0;
uint32_t valtor=6000;    //value for torque
uint32_t valaop=90000;    //value for ao generators power
uint32_t torquem[130];
uint16_t torquec;
uint32_t avpowergen1;
uint32_t avpowergen2;
uint32_t avpowergen3;
uint32_t avpowergen4;
uint32_t avpowergen5;
uint32_t avpowergen6;
uint8_t avpowergenc;
uint16_t timcan1=0;        //timer of 50Hz for CAN communication
uint8_t torq50=1;
uint16_t petap=0;        //indicator for number of stage
uint32_t tcommt=0;
uint8_t aostep=2;
uint32_t narab=0;
uint8_t swaogen=0;
uint8_t aod=0;
uint8_t aodc;
uint8_t paostep = 0;
uint8_t cti2;
int32_t diff=0; 
uint8_t tor=0;
uint8_t swvgen=0;
uint8_t swvdvig=0;
uint8_t dstep = 1;
uint8_t pstep = 0;
uint16_t tokiso2[5];
uint8_t powert1=2;
uint8_t dstepuf=10; //25
uint8_t dstepf=12;      
uint8_t dstepnf=10;
uint16_t vgstep=1; 
uint8_t flstep = 0;
uint8_t pokvazd=0;
uint16_t timacc=0; 
uint16_t swrpm=0;
int16_t sefstvdv=0; 
int16_t sefstvgen=0; 
uint16_t kdstop=0;
uint16_t swvstop=1;
uint16_t swdstop=1;
uint16_t vdvtok=208;
uint32_t mingn;
uint32_t secgn;
uint32_t mingk;
uint32_t secgk;
uint32_t minmn;
uint32_t secmn;
uint32_t minmk;
uint32_t secmk;
uint32_t tetap=0;
uint32_t temtap=0;
uint8_t nar8;
uint32_t narabt=0;
uint8_t swdvig=0;
uint16_t realrpm=0;
uint16_t oboroti=0;
uint8_t uskor=0;
uint16_t vaz2=240;        //value for second current for engine
uint8_t beg=0;
uint16_t rpmch=0;
uint16_t delfalarm=0;
uint8_t kdvd1=0;
uint8_t kdvd2=1;

uint8_t flagph=0;
uint8_t phnomer=10;
uint16_t tim10value;
uint16_t tempcan2;
uint16_t tempavph1;
uint16_t tempavph2;

uint16_t tempph1;
uint16_t tempph2;
uint16_t tempph3;
uint16_t tempph4;
uint16_t tempph5;
uint16_t tempph6;
uint8_t tempnomph;


uint32_t prog[10][10][10];                                                               //number program; number state; rpm, torque, time; +5 more for comparison
uint8_t nprogram = 1;
uint8_t nstate = 0;
uint16_t staterpm;
uint16_t statetrq;
uint32_t statetme;

uint32_t timetap=0;        //timer for counting stage of examine

uint16_t tim2poc;
uint16_t uskorhz;

uint16_t tim1poc;

uint16_t PrescalerValue = 0;

uint16_t timsefst=0; 
uint16_t rerpmop;
uint16_t rpmopt1;
uint16_t rpmopt2;
uint16_t rpmopt3;
uint8_t rpmopc=0;

uint8_t fullpr=0;
uint8_t shpr1=0;
uint8_t shpr2=0;
uint8_t shpr3=0;
uint8_t shpr4=0;
uint8_t shpr5=0;
uint8_t shpr9=0;

uint8_t ok=0;
GPIO_InitTypeDef  GPIO_InitStructuret;


uint16_t top23;

int16_t phdelay;

uint16_t temt1;
uint16_t temt2;
uint16_t temt3;

uint16_t test10=400;
uint16_t test11=500;
int16_t test12;

uint8_t pokgrpm;
uint8_t nomperiod;
uint8_t nomperiod2;
uint16_t kdvValue =25200;
uint16_t vdvValue = 0;
uint16_t vgenValue =11000;
uint16_t aogen =23000;
uint8_t relaogen=0;
uint16_t generator=8500;
uint32_t torqued;       //sent data

uint16_t rpm = 0;
uint16_t vdvcurrent = 34000;

uint8_t ukot=0;
uint8_t ukotc=0;
uint8_t toku3=0;
uint8_t rpmc=0;
uint8_t tokdcc=0;

uint8_t endch=0;


uint16_t voltagedv;
uint16_t tokiso;
uint16_t optrones;

uint16_t rpmop;
uint16_t tokdc;
uint16_t torque;
uint16_t toku;
uint16_t optrones23;
uint16_t toku2;
uint8_t pokop=0;
uint8_t pokuart=0;

uint32_t commt=0;

int32_t compvar=0;
uint8_t pokprob=0;
uint8_t check=0;
uint8_t endacc=0;

uint16_t vdvdel=0;
uint16_t dvdel=0;
uint16_t vgendel=0;
uint16_t vaogendel=0;
uint16_t ukotva=0;
uint16_t igen=0;
uint16_t iaogen=0;
uint16_t ivdv=0;
uint16_t ivgen=0;
uint16_t torqye=0;
uint16_t rpmzad=0;


uint8_t varch[10][4];
uint8_t varchc[20];


uint16_t phcountd=0;

uint16_t t1;
uint16_t t2;
uint16_t t3;
uint16_t p1;

uint16_t t1temp;
uint16_t t2temp;
uint16_t t3temp;
uint16_t p1temp;

uint16_t t1sum;
uint16_t t2sum;
uint16_t t3sum;
uint16_t p1sum;


uint8_t a1;
uint8_t b1;
uint8_t c1;
uint16_t flagmes;
uint16_t flagtmes;
uint16_t flagmesc;
uint8_t t1m[80];
uint8_t t2m[80];
uint8_t t3m[80];
uint8_t p1m[80];
uint8_t t1c;
uint8_t t2c;
uint8_t t3c;
uint8_t p1c;
uint8_t ic;
uint8_t numprog=2;
uint8_t nomperiod2;


uint8_t fifon;
uint8_t fifon2;
uint8_t typetr;
uint8_t stoppd=0;

uint8_t torqch=0;
uint8_t torqc=0;

uint8_t memop23;

CanTxMsg TxMessage;
CanRxMsg RxMessage;
uint8_t TransmitMailbox = 0;

uint32_t powergen;
uint32_t poweraogen;
uint32_t powerdvig;

uint8_t sefst=0;
uint8_t sefstpok=0;
uint32_t start=0;
uint16_t et;    //etap - number of massive
uint16_t pracc;
uint8_t trans=2;
uint32_t delay=0;

uint16_t avphase=63700; 
uint16_t countmph=0; 
uint16_t mphase[2048]; 
uint16_t mphase1[1024]; 
uint16_t mphase2[1024]; 
uint16_t mphase3[1024]; 
uint16_t mphase4[1024]; 
uint16_t mphase5[1024]; 
uint16_t mphase6[1024]; 
uint32_t sumph1=0;
uint32_t sumph2=0;
uint32_t sumph3=0;
uint32_t sumph4=0;
uint32_t sumph5=0;
uint32_t sumph6=0;
uint16_t countmph1=0; 
uint16_t countmph2=0; 
uint16_t countmph3=0; 
uint16_t countmph4=0; 
uint16_t countmph5=0; 
uint16_t countmph6=0; 
uint16_t avphasem[6];


uint16_t phseq[6]; 
uint8_t countphseq=0; 
uint32_t sumph=0; 
uint8_t pokfullm=1;
uint8_t pokphr;
uint16_t tim10tv; 

uint32_t torquesum; 

uint32_t testspeed1; 
uint32_t testspeed2; 

uint8_t errora=0;
uint8_t errorb=0;

uint8_t pokcheck=0;

/* Private function prototypes -----------------------------------------------*/
void TIM2_Config(void);                                                                 //firing thyristors set transistor 1 dvigatel kotva
void TIM5_Config(void);                                                                 //firing thyristors reset transistor 0 dvigatel kotva

void TIM3_Config(void);                                                                 //firing thyristors set transistor 1 generator
void TIM4_Config(void);                                                                 //firing thyristors reset transistor 0 generator

void TIM1_Config(void);                                                                 //firing thyristors set transistor 1 dvigatel valna
void TIM14_Config(void);                                                                 //firing thyristors reset transistor 0 dvigatel valna


//void phase0(void);                                                                      //exti0
//void phase1(void);                                                                      //exti1
//void phase2(void);                                                                      //exti2
//void phase3(void);                                                                      //exti3
//void phase4(void);                                                                      //exti4
//void phase5(void);                                                                      //exti5




static void EXTILine0_Config(void);                                                     //phaseA pos to neg externall interrupt C0
static void EXTILine2_Config(void);                                                     //phaseB pos to neg externall interrupt C2
static void EXTILine1_Config(void);                                                     //phaseC pos to neg externall interrupt C1 


static void EXTILine3_Config(void);                                                     //phaseA neg to pos externall interrupt C3
static void EXTILine5_Config(void);                                                     //phaseB neg to pos externall interrupt C5
static void EXTILine4_Config(void);                                                     //phaseC neg to pos externall interrupt C4
static void EXTILine10_Config(void);                                                    //PI10 externall interrupt for communication
static void USART_Config(void);                                                         //communication with 2.4
static void CAN_Config(void);                                                         //communication 2.1 - control panel
static void CAN2_Config(void);                                                        //communication 2.1 - 2.2, 2.3



/* Private functions ---------------------------------------------------------*/



/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       files (startup_stm32f40xx.s/startup_stm32f427x.s) before to branch to 
       application main. 
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
     */

  for(delay=0;delay<64000;delay++){
    delay++;
    delay--;
  }
  
    for(testspeed1=0;testspeed1<3000000;testspeed1++){       //3 minutes at 128MHz; 4 Minutes at 96MHz; 24 minutes at 16MHz
    testspeed2=2;
  }
  
//initialization of programs
prog[1][0][0]=1300;                  //program 1 (Mi-17), state 0, rpm
prog[1][0][1]=0;                  //program 1 (Mi-17), state 0, trq  
prog[1][0][2]=6000;                  //program 1 (Mi-17), state 0, tme   2min*60=120sec*50Hz=6000 
prog[1][0][3]=565;                  //program 1 (Mi-17), state 0, rpm tail    


prog[1][1][0]=2589;                  //program 1 (Mi-17), state 1, rpm
prog[1][1][1]=0;                  //program 1 (Mi-17), state 1, trq  
prog[1][1][2]=12000;                  //program 1 (Mi-17), state 1, tme   2min*60=120sec*50Hz=6000 
prog[1][1][3]=1124;                  //program 1 (Mi-17), state 1, rpm tail   
  

prog[1][2][0]=2589;                  //program 1 (Mi-17), state 2, rpm
prog[1][2][1]=710;                  //program 1 (Mi-17), state 2, trq  
prog[1][2][2]=72000;                  //program 1 (Mi-17), state 2, tme   2min*60=120sec*50Hz=6000 
prog[1][2][3]=1124;                  //program 1 (Mi-17), state 2, rpm tail   


prog[1][3][0]=2589;                  //program 1 (Mi-17), state 3, rpm
prog[1][3][1]=1410;                  //program 1 (Mi-17), state 3, trq  
prog[1][3][2]=162000;                  //program 1 (Mi-17), state 3, tme   2min*60=120sec*50Hz=6000 
prog[1][3][3]=1124;                  //program 1 (Mi-17), state 3, rpm tail   



prog[1][4][0]=2589;                  //program 1 (Mi-17), state 4, rpm
prog[1][4][1]=1790;                  //program 1 (Mi-17), state 4, trq  
prog[1][4][2]=177000;                  //program 1 (Mi-17), state 4, tme   2min*60=120sec*50Hz=6000 
prog[1][4][3]=1124;                  //program 1 (Mi-17), state 4, rpm tail   



prog[1][5][0]=2589;                  //program 1 (Mi-17), state 5, rpm
prog[1][5][1]=100;                  //program 1 (Mi-17), state 5, trq  
prog[1][5][2]=192000;                  //program 1 (Mi-17), state 5, tme   2min*60=120sec*50Hz=6000 
prog[1][5][3]=1124;                  //program 1 (Mi-17), state 5, rpm tail   



prog[1][6][0]=2589;                  //program 1 (Mi-17), state 6, rpm
prog[1][6][1]=1320;                  //program 1 (Mi-17), state 6, trq  
prog[1][6][2]=267000;                  //program 1 (Mi-17), state 6, tme   2min*60=120sec*50Hz=6000 
prog[1][6][3]=1124;                  //program 1 (Mi-17), state 6, rpm tail   



prog[1][7][0]=2589;                  //program 1 (Mi-17), state 7, rpm
prog[1][7][1]=1630;                  //program 1 (Mi-17), state 7, trq  
prog[1][7][2]=282000;                  //program 1 (Mi-17), state 7, tme   2min*60=120sec*50Hz=6000 
prog[1][7][3]=1124;                  //program 1 (Mi-17), state 7, rpm tail   



prog[1][8][0]=0;                  //program 1 (Mi-17), state 8, rpm
prog[1][8][1]=0;                  //program 1 (Mi-17), state 8, trq  
prog[1][8][2]=0;                  //program 1 (Mi-17), state 8, tme   2min*60=120sec*50Hz=6000 
prog[1][8][3]=0;                  //program 1 (Mi-17), state 8, rpm tail   





prog[2][0][0]=370;                  //program 2 (Mi-24), state 0, rpmop=1110
prog[2][0][1]=280;                  //program 2 (Mi-24), state 0, trq - Ampers from the generator 
prog[2][0][2]=380000;                  //program 2 (Mi-24), state 0, tme   2min*60=120sec*50Hz=6000 
prog[2][0][3]=565;                  //program 2 (Mi-24), state 0, rpm tail    
prog[2][0][4]=0;                  //swvgen, swdvig, swvdvig
prog[2][0][5]=0;                  //broi etapi



prog[2][1][0]=370;                  //program 2 (Mi-24), state 0, rpmop=1110
prog[2][1][1]=280;                  //program 2 (Mi-24), state 0, trq - Ampers from the generator 
prog[2][1][2]=45000;                  //program 2 (Mi-24), state 0, tme   2min*60=120sec*50Hz=6000 
prog[2][1][3]=565;                  //program 2 (Mi-24), state 0, rpm tail    
prog[2][1][4]=1;                  //swvgen, swdvig, swvdvig

prog[2][2][0]=370;                  //program 2 (Mi-24), state 1, rpm
prog[2][2][1]=330;                  //program 2 (Mi-24), state 1, trq - Ampers from the generator  
prog[2][2][2]=105000;                  //program 2 (Mi-24), state 1, tme   2min*60=120sec*50Hz=6000 
prog[2][2][3]=1110;                  //program 2 (Mi-24), state 1, rpm tail   
prog[2][2][4]=1;                  //swvgen, swdvig, swvdvig  

prog[2][3][0]=370;                  //program 2 (Mi-24), state 2, rpm
prog[2][3][1]=430;                  //program 2 (Mi-24), state 2, trq  
prog[2][3][2]=150000;                  //program 2 (Mi-24), state 2, tme   15min*60=120sec*50Hz=6000 
prog[2][3][3]=1110;                  //program 2 (Mi-24), state 2, rpm tail   
prog[2][3][4]=1;                  //swvgen, swdvig, swvdvig

prog[2][4][0]=370;                  //program 2 (Mi-24), state 3, rpm
prog[2][4][1]=540;                  //program 2 (Mi-24), state 3, trq  
prog[2][4][2]=165000;                  //program 2 (Mi-24), state 3, tme   2min*60=120sec*50Hz=6000 
prog[2][4][3]=1110;                  //program 2 (Mi-24), state 3, rpm tail   
prog[2][4][4]=1;                  //swvgen, swdvig, swvdvig


prog[2][5][0]=370;                  //program 2 (Mi-24), state 4, rpm
prog[2][5][1]=100;                  //program 2 (Mi-24), state 4, trq  
prog[2][5][2]=180000;                  //program 2 (Mi-24), state 4, tme   2min*60=120sec*50Hz=6000 
prog[2][5][3]=1110;                  //program 2 (Mi-24), state 4, rpm tail   
prog[2][5][4]=1;                  //swvgen, swdvig, swvdvig


prog[2][6][0]=370;                  //program 2 (Mi-24), state 5, rpm
prog[2][6][1]=430;                  //program 2 (Mi-24), state 5, trq  
prog[2][6][2]=240000;                  //program 2 (Mi-24), state 5, tme   2min*60=120sec*50Hz=6000 
prog[2][6][3]=1110;                  //program 2 (Mi-24), state 5, rpm tail   
prog[2][6][4]=1;                  //swvgen, swdvig, swvdvig


prog[2][7][0]=370;                  //program 2 (Mi-24), state 6, rpm
prog[2][7][1]=540;                  //program 2 (Mi-24), state 6, trq  
prog[2][7][2]=255000;                  //program 2 (Mi-24), state 6, tme   2min*60=120sec*50Hz=6000 
prog[2][7][3]=1110;                  //program 2 (Mi-24), state 6, rpm tail   
prog[2][7][4]=1;                  //swvgen, swdvig, swvdvig



prog[2][8][0]=370;                  //program 1 (Mi-24), state 7, rpm
prog[2][8][1]=0;                  //program 1 (Mi-24), state 7, trq  
prog[2][8][2]=264000;                  //program 1 (Mi-24), state 7, tme   2min*60=120sec*50Hz=6000 
prog[2][8][3]=1110;                  //program 1 (Mi-24), state 7, rpm tail   
prog[2][8][4]=1;                  //swvgen, swdvig, swvdvig


prog[2][9][0]=370;                  //program 1 (Mi-24), state 8, rpm
prog[2][9][1]=0;                  //program 1 (Mi-24), state 8, trq  
prog[2][9][2]=273000;                  //program 1 (Mi-24), state 8, tme   2min*60=120sec*50Hz=6000 
prog[2][9][3]=1110;                  //program 1 (Mi-24), state 8, rpm tail   
prog[2][9][4]=0;                  //swvgen, swdvig, swvdvig, start   













  
    CAN_Config();
    CAN2_Config();
//    USART_Config();    
    EXTILine0_Config();                                                                 //configure C0 as externall interrupt phaseA pos to neg
    EXTILine2_Config();                                                                 //configure C2 as externall interrupt phaseB pos to neg
    EXTILine1_Config();                                                                 //configure C1 as externall interrupt phaseC pos to neg   
    
 
    EXTILine3_Config();                                                                 //configure C3 as externall interrupt phaseA neg to pos
    EXTILine5_Config();                                                                 //configure C5 as externall interrupt phaseB neg to pos
    EXTILine4_Config();                                                                 //configure C4 as externall interrupt phaseC neg to pos   
 
    EXTILine10_Config();                                                                //PI10 externall interrupt for communication      
    
    
    TIM2_Config();                                                                  //firing thyristors set transistor 1 dvigatel kotva
    TIM5_Config();                                                                   //firing thyristors reset transistor 0 dvigatel kotva
    
    
    TIM3_Config();                                                                 //firing thyristors set transistor 1
    TIM4_Config();                                                                 //firing thyristors reset transistor 0    
    
  //  TIM1_Config();                                                                 //firing thyristors set transistor 1 valna
//    TIM14_Config();                                                                 //count averaged phase prolong


   

  
  /* -----------------------------------------------------------------------
    TIM3 Configuration: Output Compare Timing Mode:
    
    In this example TIM3 input clock (TIM3CLK) is set to 2 * APB1 clock (PCLK1), 
    since APB1 prescaler is different from 1.   
      TIM3CLK = 2 * PCLK1  
      PCLK1 = HCLK / 4 
      => TIM3CLK = HCLK / 2 = SystemCoreClock /2
          
    To get TIM3 counter clock at 6 MHz, the prescaler is computed as follows:
       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
       Prescaler = ((SystemCoreClock /2) /6 MHz) - 1
                                              
    CC1 update rate = TIM3 counter clock / CCR1_Val = 146.48 Hz
    ==> Toggling frequency = 73.24 Hz
    
    C2 update rate = TIM3 counter clock / CCR2_Val = 219.7 Hz
    ==> Toggling frequency = 109.8 Hz
    
    CC3 update rate = TIM3 counter clock / CCR3_Val = 439.4 Hz
    ==> Toggling frequency = 219.7 Hz
    
    CC4 update rate = TIM3 counter clock / CCR4_Val = 878.9 Hz
    ==> Toggling frequency = 439.4 Hz

    Note: 
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
     Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
     function to update SystemCoreClock variable value. Otherwise, any configuration
     based on this variable will be incorrect.    
  ----------------------------------------------------------------------- */   

      /* GPIOG Peripheral clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

  /* Configure PORTE in input pushpull mode */
  GPIO_InitStructuret.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructuret.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructuret.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructuret.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOE, &GPIO_InitStructuret);
  
      /* GPIOG Peripheral clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  /* Configure PORTF in input pushpull mode */
  GPIO_InitStructuret.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructuret.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructuret.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructuret.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOF, &GPIO_InitStructuret);  
  
  
  

  
        /* GPIOD Peripheral clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);                                 //port

  /* Configure PORTD in output pushpull mode - firing thyristors */
  GPIO_InitStructuret.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructuret.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructuret.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructuret.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructuret);                                               //port
  
        /* GPIOG Peripheral clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);                                 //port

  /* Configure part of PORTG in output pushpull mode - firing thyristors */
  GPIO_InitStructuret.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
  GPIO_InitStructuret.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructuret.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructuret.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOG, &GPIO_InitStructuret);         
  
        /* GPIOG Peripheral clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);                                 //port

  /* Configure part of PORTG in output pushpull mode - firing thyristors */
  GPIO_InitStructuret.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_11 | GPIO_Pin_12;        //relays for ao gens and alarm
  GPIO_InitStructuret.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructuret.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructuret.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOH, &GPIO_InitStructuret);      
  
  
          /* GPIOG Peripheral clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);                                 //port

  /* Configure part of PORTG in output pushpull mode - firing thyristors 
  GPIO_InitStructuret.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructuret.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructuret.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructuret.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStructuret);         
  GPIO_SetBits(GPIOB, GPIO_Pin_6);
  GPIO_SetBits(GPIOB, GPIO_Pin_7);
    GPIO_SetBits(GPIOB, GPIO_Pin_6);
    */
    
    
  
/*TIMER3 configuration */
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
  
  
//   /* Compute the prescaler value */
//  PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / 10000000) - 1;                   
//  /* Prescaler configuration */
  PrescalerValue =3;    //3
  TIM_PrescalerConfig(TIM3, PrescalerValue, TIM_PSCReloadMode_Immediate);               //prescaler=7 - 84MHz/7 = 12000000/300 = 40000  
  
  /* Output Compare Timing Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val3;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM3, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Disable);  
  
  /* Output Compare Timing Mode configuration: Channel2 */
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val3;

  TIM_OC2Init(TIM3, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);  
  
  /* Output Compare Timing Mode configuration: Channel3 */
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val3;

  TIM_OC3Init(TIM3, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Disable);

  /* Output Compare Timing Mode configuration: Channel4 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR4_Val3;

  TIM_OC4Init(TIM3, &TIM_OCInitStructure);

  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Disable);  
  
  
  
  
  
  /*TIMER4 configuration */
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);                                       //timer
  
  
//   /* Compute the prescaler value */
//  PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / 10000000) - 1;                   
//  /* Prescaler configuration */
  PrescalerValue =3;            //3
  TIM_PrescalerConfig(TIM4, PrescalerValue, TIM_PSCReloadMode_Immediate);               //timer, prescaler=7 - 84MHz/7 = 12000000/300 = 40000  
  
  /* Output Compare Timing Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val4;                                            //ccr1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM4, &TIM_OCInitStructure);                                              //timer

  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Disable);                                    //timer
  
  /* Output Compare Timing Mode configuration: Channel2 */
 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val4;                                            //ccr2

  TIM_OC2Init(TIM4, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Disable);  
  
  /* Output Compare Timing Mode configuration: Channel3 */
   TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val4;

  TIM_OC3Init(TIM4, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Disable);

  /* Output Compare Timing Mode configuration: Channel4 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR4_Val4;

  TIM_OC4Init(TIM4, &TIM_OCInitStructure);

  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Disable);  
  
  
    /* TIM Interrupts enable */
//  TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
  //TIM_ITConfig(TIM3, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE);
  
  /* TIM Interrupts enable */
  TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);    
  
  /* TIM Interrupts enable */
  TIM_ITConfig(TIM4, TIM_IT_CC1, ENABLE);     
  
  
    /* TIM3 enable counter */
  TIM_Cmd(TIM3, ENABLE);  
   TIM_Cmd(TIM4, ENABLE);  

    

   
     
/*TIMER2 configuration */
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);                                       //timer
  
  
//   /* Compute the prescaler value */
//  PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / 10000000) - 1;                   
//  /* Prescaler configuration */
  PrescalerValue =1;            //1
  TIM_PrescalerConfig(TIM2, PrescalerValue, TIM_PSCReloadMode_Immediate);               //timer, prescaler=7 - 84MHz/7 = 12000000/300 = 40000  
  
  /* Output Compare Timing Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val2;                                            //ccr1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM2, &TIM_OCInitStructure);                                              //timer

  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);                                    //timer
  
  //  Output Compare Timing Mode configuration: Channel1 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val2;                                            //ccr1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC2Init(TIM2, &TIM_OCInitStructure);                                              //timer

  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);                                    //timer  
  
  //  Output Compare Timing Mode configuration: Channel1 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val2;                                            //ccr1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC3Init(TIM2, &TIM_OCInitStructure);                                              //timer, ocinit

  TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Disable);                                    //timer, ocpreload    
  
  
  
  
  
  /*TIMER5 configuration */
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);                                       //timer
  
  
//   /* Compute the prescaler value */
//  PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / 10000000) - 1;                   
//  /* Prescaler configuration */
  PrescalerValue =1;            //1
  TIM_PrescalerConfig(TIM5, PrescalerValue, TIM_PSCReloadMode_Immediate);               //timer, prescaler=7 - 84MHz/7 = 12000000/300 = 40000  
  
  /* Output Compare Timing Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val5;                                            //ccr1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM5, &TIM_OCInitStructure);                                              //timer

  TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Disable);                                    //timer
  
  //  Output Compare Timing Mode configuration: Channel1 
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR2_Val5;                                            //ccr1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC2Init(TIM5, &TIM_OCInitStructure);                                              //timer

  TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Disable);                                    //timer   
  
 //NEW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-----START
 
 /*TIMER14 configuration */
  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65535;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM14, &TIM_TimeBaseStructure);                                       //timer
  
  
//   /* Compute the prescaler value */
//  PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / 10000000) - 1;                   
//  /* Prescaler configuration */
  PrescalerValue =1;            //1
  TIM_PrescalerConfig(TIM14, PrescalerValue, TIM_PSCReloadMode_Immediate);               //timer, prescaler=7 - 84MHz/7 = 12000000/300 = 40000  
  
  /* Output Compare Timing Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR1_Val7;                                            //ccr1
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM14, &TIM_OCInitStructure);                                              //timer

  TIM_OC1PreloadConfig(TIM14, TIM_OCPreload_Disable);                                    //timer
  
   //NEW!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-----STOP
  
  
    /* TIM Interrupts enable */
//  TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
  //TIM_ITConfig(TIM3, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE);
  
  /* TIM Interrupts enable */
  
  TIM_ITConfig(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3, ENABLE);   
  
 // TIM_ITConfig(TIM14, TIM_IT_CC1, ENABLE);  
  
  /* TIM Interrupts enable */
  
  TIM_ITConfig(TIM5, TIM_IT_CC1 | TIM_IT_CC2, ENABLE);     
//  TIM_ITConfig(TIM5, TIM_IT_CC1, ENABLE);
  

  /* TIM2 enable counter */
  TIM_Cmd(TIM2, ENABLE);  
  TIM_Cmd(TIM5, ENABLE);  
  
   /* TIM14 enable counter 
  TIM_SetCompare1(TIM14, 65000);
  TIM_Cmd(TIM14, ENABLE); */
  
//  for(testspeed1=0;testspeed1<1000000000;testspeed1++){       //3 minutes at 128MHz; 4 Minutes at 96MHz; 24 minutes at 16MHz
 //   testspeed2=2;
//  }

   
    
  while (1)
  {
   

    if((torqch==1) && (stoppd<1) && (endch==0)){
      
      if(typetr==24){
        if(torqued>21000){
          torqc++;
        }
        else{
          torqc=0;
        }
        if(torqc>18){
          timetap=589999;
          stoppd=1;
          pokprob=7;    //pokazatel
        }
        
        if((timetap>9000) && (endch<1)){
          if((tokiso>850) || (tokiso<600)){
          ukotc++;
        }
        else{
          ukotc=0;
        }
        if(ukotc>12){
          timetap=589999;
          stoppd=1;
          pokprob=8;    //pokazatel
        }
          
        }
        
        if((timetap>5000) && (endch<1)){
          if((vdvcurrent>300) || (vdvcurrent<200)){
          ukot++;
        }
        else{
          ukot=0;
        }
        if(ukot>12){
          timetap=589999;
          stoppd=1;
          pokprob=9;    //pokazatel
        }
        
         if(toku2>642){
          toku3++;
        }
        else{
          toku3=0;
        }
        if(toku3>6){
          timetap=589999;
          stoppd=1;
          pokprob=10;    //pokazatel
        }
          
        if((rpmop>405) || (rpmop<300)){         //405;333
          rpmc++;
        }
        else{
          rpmc=0;
        }
        if(rpmc>12){
          timetap=589999;
          stoppd=1;
          pokprob=5;    //pokazatel
        }
        
        if(tokdc>280){
          tokdcc++;
        }
        else{
          tokdcc=0;
        }
        if(tokdcc>6){
          timetap=589999;
          stoppd=1;
          pokprob=6;    //pokazatel
        }
        
        }
          
        
      }
      if(typetr==17){
        if(torqued>15030){
          torqc++;
        }
        else{
          torqc=0;
        }
        if(torqc>5){
          timetap=589999;
          stoppd=1;
          pokprob=7;    //pokazatel
        }
        
        if((timetap>9000) && (endch<1)){
          if((tokiso>890) || (tokiso<670)){
          ukotc++;
        }
        else{
          ukotc=0;
        }
        if(ukotc>5){
          timetap=589999;
          stoppd=1;
          pokprob=8;    //pokazatel
        }
          
        }
        
         if((timetap>5000) && (endch<1)){
          if((vdvcurrent>420) || (vdvcurrent<340)){
          ukot++;
        }
        else{
          ukot=0;
        }
        if(ukot>12){
          timetap=589999;
          stoppd=1;
          pokprob=9;    //pokazatel
        }
        
         if(toku2>355){
          toku3++;
        }
        else{
          toku3=0;
        }
        if(toku3>12){
          timetap=589999;
          stoppd=1;
          pokprob=10;    //pokazatel
        }
        
        if((rpmop>405) || (rpmop<300)){
          rpmc++;
        }
        else{
          rpmc=0;
        }
        if(rpmc>12){
          timetap=589999;
          stoppd=1;
          pokprob=5;    //pokazatel
        }
        
         if(tokdc>240){
          tokdcc++;
        }
        else{
          tokdcc=0;
        }
        if(tokdcc>6){
          timetap=589999;
          stoppd=1;
          pokprob=6;    //pokazatel
        }
          
        }
        
      }
      
     torqch=0; 
      
    }
    
    
 /*   if(check==1){
      compvar=abs(vdvdel-vgenValue);    //vazb dvig
      if(compvar>300){
        varchc[0]++;    //counter
        if(varchc[0]>9){    //counter
          pokprob=5;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[0]=0;    //counter
      }
      
      compvar=abs(dvdel-kdvValue);    //kotva dvig
      if(compvar>500){
        varchc[1]++;    //counter
        if(varchc[1]>9){    //counter
          pokprob=6;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[1]=0;    //counter
      }
      
      compvar=abs(vgendel-generator);    //vazb gen
      if(compvar>300){
        varchc[2]++;    //counter
        if(varchc[2]>9){    //counter
          pokprob=7;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[2]=0;    //counter
      }
      
      compvar=abs(vaogendel-aogen);    //vazb ao gen
      if(compvar>300){
        varchc[3]++;    //counter
        if(varchc[3]>9){    //counter
          pokprob=8;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[3]=0;    //counter
      }
      
      compvar=abs(ukotva-tokiso);    //naprez kotva
      if(compvar>70){
        varchc[4]++;    //counter
        if(varchc[4]>9){    //counter
          pokprob=9;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[4]=0;    //counter
      }
      
      compvar=abs(igen-toku2);    //tok gen
      if(compvar>90){
        varchc[5]++;    //counter
        if(varchc[5]>9){    //counter
          pokprob=10;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[5]=0;    //counter
      }
      
      compvar=abs(iaogen-a1);    //tok ao gen
      if(compvar>30){
        varchc[6]++;    //counter
        if(varchc[6]>9){    //counter
          pokprob=11;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[6]=0;    //counter
      }
      
      compvar=abs(ivdv-vdvcurrent);    //vazb dv
      if(compvar>50){
        varchc[7]++;    //counter
        if(varchc[7]>9){    //counter
          pokprob=12;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[7]=0;    //counter
      }
      
      compvar=abs(ivgen-tokdc);    //vazb gen
      if(compvar>20){
        varchc[8]++;    //counter
        if(varchc[8]>9){    //counter
          pokprob=13;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[8]=0;    //counter
      }
      
      compvar=abs(torqye-torqued);    //vart.mom.
      if(compvar>3000){
        varchc[9]++;    //counter
        if(varchc[9]>9){    //counter
          pokprob=14;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[9]=0;    //counter
      }
      
      compvar=abs(rpmzad-rpmop);    //rpm
      if(compvar>80){
        varchc[10]++;    //counter
        if(varchc[10]>9){    //counter
          pokprob=15;    //pokazatel
          timetap=289999;
          stoppd=1;
          pokcheck=0;
        }          
      }
      else{
        varchc[10]=0;    //counter
      }
      
      
      check=0;
    }*/
    
    commt++;
    if(commt>3000000){}
    if(relaogen){GPIO_SetBits(GPIOH, GPIO_Pin_12);}
    if(relaogen==0){GPIO_ResetBits(GPIOH, GPIO_Pin_12);}    
    
    
    if((typetr==17) && (prog[trans][et][4]==1)){
    if(optrones23!= 109){
      timetap=589999;
      pokop=1;
      memop23=optrones23;
    }    
    }
    if((typetr==24) && (prog[trans][et][4]==1)){
    if(optrones23!= 61){
      timetap=589999;
      pokop=1;
      memop23=optrones23;
    }    
    }    
    
    if(prog[trans][et][4]==0){
      if((optrones23 == 109) || (optrones23 == 61)){
        if(sefst==1){
          pokop=1;
        }
        if(sefstpok>0){
          pokop=1;
        }
      
    }   
      else{
       pokop=1;
      } 

    }    
    
    
  top23=optrones23;
  top23=top23&64;
  if(top23==64){typetr=17;}
  else{typetr=24;}  
      
    
    
        if((CAN_MessagePending(CAN1, fifon)) > 0) {

     CAN_Receive(CAN1, fifon, &RxMessage);

     if (RxMessage.StdId == 0x15){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
         prog[trans][et][4]=1;
         fullpr=1;
         pokgrpm=10;
         uskorhz=9000;
         endacc=9;      //1
         pracc=6100;
       }
     }
     
     if (RxMessage.StdId == 0x16){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
//         prog[trans][et][4]=1;
//         fullpr=1;
       }
     }     
     
     
     if (RxMessage.StdId == 0x14){
       if(RxMessage.Data[0]==99 && RxMessage.Data[7]==79)
       {
         timetap=589990;
         stoppd=1;
       }
     }


    
     if (RxMessage.StdId == 0x56){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
         prog[trans][et][4]=1;
         shpr1=1;
       }
     }
     
     if (RxMessage.StdId == 0x57){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
         /*
          prog[trans][et][4]=1; 
          shpr2=1;
          pokgrpm=2;    //opashen val
          uskorhz=9000;
          endacc=9;
          pracc=30000;  */
          
       }
     }       
     if (RxMessage.StdId == 0x58){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
         prog[trans][et][4]=1;
         shpr3=1;       //1-va prirab
         pokgrpm=4;
         uskorhz=15000;
         endacc=4;
         pracc=15000;
       }
     }
     
     if (RxMessage.StdId == 0x59){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
                   
         
         prog[trans][et][4]=1;
         shpr4=1;       //3-ta prirab
         pokgrpm=4;
         uskorhz=15000;
         endacc=4;
         pracc=15000;   
         
       }
     } 
  
     if (RxMessage.StdId == 0x55){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
          prog[trans][et][4]=1; 
          shpr9=1;
          pokgrpm=10;    //opashen val
          uskorhz=9000;
          endacc=9;
          pracc=30000;
                  
       }
     }   
  
   
  
     if (RxMessage.StdId == 0x60){
       if(RxMessage.Data[0]==88 && RxMessage.Data[7]==73)
       {
         prog[trans][et][4]=1; 
         shpr5=1;       //2-ra prirab
         pokgrpm=4;
         uskorhz=15000;
         endacc=4;
         pracc=15000;
       }
     }   
  
     } 
  
  
        if((CAN_MessagePending(CAN2, fifon2)) > 0) {

     CAN_Receive(CAN2, fifon2, &RxMessage);

     if (RxMessage.StdId == 0x22){
       tempcan2=(RxMessage.Data[0]<<8);
       vdvcurrent=tempcan2+RxMessage.Data[1];
       tempcan2=(RxMessage.Data[2]<<8);
       tokiso=tempcan2+RxMessage.Data[3];
       tempcan2=(RxMessage.Data[4]<<8);
       rpm=tempcan2+RxMessage.Data[5];

       //optrones=RxMessage.Data[7];       
     }
     
     if (RxMessage.StdId == 0x23){
       tempcan2=(RxMessage.Data[0]<<8);
       torque=tempcan2+RxMessage.Data[1];
       tempcan2=(RxMessage.Data[2]<<8);
       toku2=tempcan2+RxMessage.Data[3];
       tempcan2=(RxMessage.Data[4]<<8);
       rpmop=tempcan2+RxMessage.Data[5];
       tokdc=RxMessage.Data[6];
       optrones23=RxMessage.Data[7];         
     }     
     
    if (RxMessage.StdId == 0x24){
       t1temp=RxMessage.Data[0];
       t2temp=RxMessage.Data[1];
       t3temp=RxMessage.Data[2];
       p1temp=RxMessage.Data[3];
       a1=RxMessage.Data[4];
       b1=RxMessage.Data[5];
       c1=RxMessage.Data[6];
              
       if(timsefst ==900){
/*     transferd to 2.4   
       t1c++;
       if(t1c>49){t1c=0;}
       t1=0;
       for(ic=0;ic<50;ic++){
         t1=t1+t1m[ic];
       }
       t1=t1/50;
*/       
        
        
        t1sum=t1sum+(t1temp-t1m[t1c]);
        t1=t1sum>>6; 
        t1m[t1c]=t1temp;
        t1c++;
        if(t1c>63){t1c=0;}
        
        
         
       temt1=t1;
       if(temt1>253){temt1=0;t1=0;}
       if(temt1>30){
       temt1=temt1-30;
       temt1=temt1/10;
       t1=t1-temt1;
       }
      if(typetr==24){ 
       if((t1>115) && (stoppd==0) && (prog[trans][et][4]==1)){
         varchc[15]++;    //counter
        if(varchc[15]>120){    //counter
         timetap=589999;
         stoppd=1;
         errora=1;
         pokcheck=0;
        }
       }
       else{
         varchc[15]=0;
       }
    }
    
      if(typetr==24){ 
       if((t1>115) && (stoppd==0) && (prog[trans][et][4]==0)){
         varchc[15]++;    //counter
        if(varchc[15]>250){    //counter
         timetap=589999;
         stoppd=1;
         errora=1;
         pokcheck=0;
        }
       }
       else{
         varchc[15]=0;
       }
    }    
    
    
    
    
       }

       if(timsefst ==900){
/*     transferd to 2.4          
       t2c++;
       if(t2c>49){t2c=0;}
       t2=0;
       for(ic=0;ic<50;ic++){
         t2=t2+t2m[ic];
       }
       t2=t2/50;  
*/            
         
      
         
        t2sum=t2sum+(t2temp-t2m[t2c]);
        t2=t2sum>>6; 
        

        
        t2m[t2c]=t2temp;
    
        
        t2c++;
        if(t2c>63){t2c=0;}
        
         
       temt2=t2; 
       if(temt2>250){temt2=0;t2=0;}
       if(temt2>30){
       temt2=temt2-30;
       temt2=temt2/10;
       t2=t2-temt2;       
       }
       t2=t2+4;
       if((t2>115) && (stoppd==0) && (prog[trans][et][4]==1)){
        varchc[16]++;    //counter
        if(varchc[16]>120){    //counter
         timetap=589999;
         stoppd=1;
         errora=2;
         pokcheck=0;
        }
       }
       else{
         varchc[16]=0;
       }
       
        if((t2>115) && (stoppd==0) && (prog[trans][et][4]==0)){
        varchc[16]++;    //counter
        if(varchc[16]>250){    //counter
         timetap=589999;
         stoppd=1;
         errora=2;
         pokcheck=0;
        }
       }
       else{
         varchc[16]=0;
       }      
       
       
       }
       
       if(timsefst ==900){
/*     transferd to 2.4          
       t3c++;
       if(t3c>49){t3c=0;}
       t3=0;
       for(ic=0;ic<50;ic++){
         t3=t3+t3m[ic];
       }
       t3=t3/50;
*/            
        t3sum=t3sum+(t3temp-t3m[t3c]);
        t3=t3sum>>6; 
        t3m[t3c]=t3temp;
        t3c++;
        if(t3c>63){t3c=0;}
        
         
       temt3=t3; 
       if(temt3>248){temt3=0;t3=0;}
       if(temt3>30){
       temt3=temt3-30;
       temt3=temt3/10;
       t3=t3-temt3;
       }
       t3=t3+5;
       if((t3>115) && (stoppd==0) && (prog[trans][et][4]==1)){
         varchc[17]++;    //counter
        if(varchc[17]>120){    //counter
         timetap=589999;
         stoppd=1;
         errora=3;
         pokcheck=0;
        }
       }
       else{
         varchc[17]=0;
       }
       
       if((t3>115) && (stoppd==0) && (prog[trans][et][4]==0)){
         varchc[17]++;    //counter
        if(varchc[17]>250){    //counter
         timetap=589999;
         stoppd=1;
         errora=3;
         pokcheck=0;
        }
       }
       else{
         varchc[17]=0;
       }
       
       
       }

       if(timsefst ==900){
/*     transferd to 2.4          
       p1c++;
       if(p1c>49){p1c=0;}
       p1=0;
       for(ic=0;ic<50;ic++){
         p1=p1+p1m[ic];
       }
       p1=p1/50; 
*/            
        p1sum=p1sum+(p1temp-p1m[p1c]);
        p1=p1sum>>6; 
        p1m[p1c]=p1temp;
        p1c++;
        if(p1c>63){p1c=0;}
           
         
      if(typetr==24){  
       if((p1>60) && (stoppd==0) && (prog[trans][et][4]==1)){
          varchc[18]++;    //counter
        if(varchc[18]>9){    //counter
         timetap=589999;
         stoppd=1;
         errora=4;
         pokcheck=0;
        }
       }
       else{
         varchc[18]=0;
       }
    }
    
       if(typetr==24){  
       if((p1>60) && (stoppd==0) && (prog[trans][et][4]==0)){
          varchc[18]++;    //counter
        if(varchc[18]>250){    //counter
         timetap=589999;
         stoppd=1;
         errora=4;
         pokcheck=0;
        }
       }
       else{
         varchc[18]=0;
       }
    }   
    
    
    
    
       }       

        a1=USART_ReceiveData(USART1);           //current generators
 
        b1=USART_ReceiveData(USART1);

        c1=USART_ReceiveData(USART1); 
       
     } 
     
     }   

  }
}



static void USART_Config(void)
{
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure1;

  /* Peripheral Clock Enable -------------------------------------------------*/
  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOB, ENABLE);
  
  /* Enable USART clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

   
  /* USARTx GPIO configuration -----------------------------------------------*/
  /* Connect USART pins to AF7 */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

  /* Configure USART Tx and Rx as alternate function push-pull */
  GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_UP;
  
  GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOB, &GPIO_InitStructure1);
  
  GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_7;
  GPIO_Init(GPIOB, &GPIO_InitStructure1);
 
  /* USARTx configuration ----------------------------------------------------*/
  /* Enable the USART OverSampling by 8 */
  USART_OverSampling8Cmd(USART1, ENABLE); 
  
  /* USARTx configured as follow:
        - BaudRate = 5250000 baud
           - Maximum BaudRate that can be achieved when using the Oversampling by 8
             is: (USART APB Clock / 8) 
             Example: 
                - (USART3 APB1 Clock / 8) = (42 MHz / 8) = 5250000 baud
                - (USART1 APB2 Clock / 8) = (84 MHz / 8) = 10500000 baud
           - Maximum BaudRate that can be achieved when using the Oversampling by 16
             is: (USART APB Clock / 16) 
             Example: (USART3 APB1 Clock / 16) = (42 MHz / 16) = 2625000 baud
             Example: (USART1 APB2 Clock / 16) = (84 MHz / 16) = 5250000 baud
        - Word Length = 8 Bits
        - one Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */ 
  USART_InitStructure.USART_BaudRate = 921600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  /* When using Parity the word length must be configured to 9 bits */
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART1, &USART_InitStructure);

          
  /* Enable USART */
  USART_Cmd(USART1, ENABLE);
} 


static void CAN_Config(void)
{
  CAN_InitTypeDef        CAN_InitStructure;
  CAN_FilterInitTypeDef  CAN_FilterInitStructure;

  GPIO_InitTypeDef  GPIO_InitStructure;

  /* CAN GPIOs configuration **************************************************/

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  /* Connect CAN pins to AF9 */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_CAN1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_CAN1);

  /* Configure CAN RX and TX pins */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* CAN configuration ********************************************************/
  /* Enable CAN clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

  /* CAN register init */
  CAN_DeInit(CAN1);

  /* CAN cell init */
  CAN_InitStructure.CAN_TTCM = DISABLE;
  CAN_InitStructure.CAN_ABOM = DISABLE;
  CAN_InitStructure.CAN_AWUM = DISABLE;
  CAN_InitStructure.CAN_NART = DISABLE;
  CAN_InitStructure.CAN_RFLM = DISABLE;
  CAN_InitStructure.CAN_TXFP = DISABLE;
  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;

  /* CAN Baudrate = 1 MBps (CAN clocked at 30 MHz) */
  CAN_InitStructure.CAN_BS1 = CAN_BS1_6tq;
  CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
  CAN_InitStructure.CAN_Prescaler = 2;
  CAN_Init(CAN1, &CAN_InitStructure);

  /* CAN filter init */

  CAN_FilterInitStructure.CAN_FilterNumber = 0;

  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;

  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(&CAN_FilterInitStructure);

  /* Transmit Structure preparation */
  TxMessage.StdId = 0x11;
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 4;
  //TxMessage.Data[0] = 0xCA;
  //TxMessage.Data[1] = 0xFE;
  //TransmitMailbox = CAN_Transmit(CANx, &TxMessage);
 //while((CAN_TransmitStatus(CANx, TransmitMailbox)  !=  CANTXOK)
 //while((CAN_MessagePending(CANx, CAN_FIFO0) < 1) 
  //RxMessage.StdId = 0x00;
  //RxMessage.IDE = CAN_ID_STD;
  //RxMessage.DLC = 0;
  //RxMessage.Data[0] = 0x00;
 // RxMessage.Data[1] = 0x00;
  //CAN_Receive(CANx, CAN_FIFO0, &RxMessage);
  //if (RxMessage.StdId != 0x11) 
  
  
}


static void CAN2_Config(void)
{
  CAN_InitTypeDef        CAN_InitStructure;
  CAN_FilterInitTypeDef  CAN_FilterInitStructure;

  GPIO_InitTypeDef  GPIO_InitStructure;

  /* CAN GPIOs configuration **************************************************/

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Connect CAN pins to AF9 */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource12, GPIO_AF_CAN2);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_CAN2);

  /* Configure CAN RX and TX pins */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* CAN configuration ********************************************************/
  /* Enable CAN clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);

  /* CAN register init */
  CAN_DeInit(CAN2);

  /* CAN cell init */
  CAN_InitStructure.CAN_TTCM = DISABLE;
  CAN_InitStructure.CAN_ABOM = DISABLE;
  CAN_InitStructure.CAN_AWUM = DISABLE;
  CAN_InitStructure.CAN_NART = DISABLE;
  CAN_InitStructure.CAN_RFLM = DISABLE;
  CAN_InitStructure.CAN_TXFP = DISABLE;
  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;

  /* CAN Baudrate = 1 MBps (CAN clocked at 30 MHz) */
  CAN_InitStructure.CAN_BS1 = CAN_BS1_6tq;
  CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
  CAN_InitStructure.CAN_Prescaler = 2;
  CAN_Init(CAN2, &CAN_InitStructure);

  /* CAN filter init */

  CAN_FilterInitStructure.CAN_FilterNumber = 14;

  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;

  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(&CAN_FilterInitStructure);

  /* Transmit Structure preparation */
  TxMessage.StdId = 0x11;
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 4;
  //TxMessage.Data[0] = 0xCA;
  //TxMessage.Data[1] = 0xFE;
  //TransmitMailbox = CAN_Transmit(CANx, &TxMessage);
 //while((CAN_TransmitStatus(CANx, TransmitMailbox)  !=  CANTXOK)
 //while((CAN_MessagePending(CANx, CAN_FIFO0) < 1) 
  //RxMessage.StdId = 0x00;
  //RxMessage.IDE = CAN_ID_STD;
  //RxMessage.DLC = 0;
  //RxMessage.Data[0] = 0x00;
 // RxMessage.Data[1] = 0x00;
  //CAN_Receive(CANx, CAN_FIFO0, &RxMessage);
  //if (RxMessage.StdId != 0x11) 
  
  
}

void TIM3_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  /* Enable the TIM3 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  }

void TIM4_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM4 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

  /* Enable the TIM4 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  }

void TIM2_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  }

void TIM5_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM4 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);

  /* Enable the TIM4 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  }



void TIM1_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);

  /* Enable the TIM3 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  }

void TIM14_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM4 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);

  /* Enable the TIM4 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM8_TRG_COM_TIM14_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 7;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 8;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  }


void phase0(void)
{
        
     TIM_SetCounter(TIM2, 0);
    
    
    
    
      tcommt=commt;
      commt=0;

    GPIO_ResetBits(GPIOH, GPIO_Pin_3);
     
    
     
//     if(pokuart==1){                                                                     //communication with 2.4 - t1
//       flagmes=1;
//       USART_SendData(USART1, flagmes);
//       pokuart=0;
//     }
     
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
       
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
  TxMessage.StdId = 0x10;     
  TxMessage.Data[0] = t1h;
  TxMessage.Data[1] = t1l;  
  TxMessage.Data[2] = t2h;
  TxMessage.Data[3] = t2l;  
  TxMessage.Data[4] = t3h;
  TxMessage.Data[5] = t3l;
  TxMessage.Data[6] = p1h;       
  TxMessage.Data[7] = p1l;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage);      
  
     }
     

     
 //     Start communication - vazb.tok, rpm  */
/*     i0=0;
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
    optrones23 =GPIO_ReadInputData(GPIOF); 
   
      Stop communication - vazb.tok, rpm */   
   
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

       nomperiod=0;
       nomperiod2=0;
       nomperiod3=0;
       pokuart=1;
        
   

  }

void phase1(void)
{
     
    TIM_SetCounter(TIM3, 0);
    TIM_SetCounter(TIM2, 0);   
   
    
    
    tcommt=commt;
      commt=0;

    GPIO_ResetBits(GPIOH, GPIO_Pin_3);
      
     
//     if(pokuart==1){                                                                     //communication with 2.4 - t2
//       flagmes=2;
//       USART_SendData(USART1, flagmes);
//       pokuart=0;
//     }    
    
           
 //    Start communication - napr.dv., optroni  */
          
/*     i0=1;
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
    optrones =GPIO_ReadInputData(GPIOE);
   
      Stop communication - napr.dv., optroni */   
   

   

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
       pokuart=1;
       
        TxMessage.RTR = CAN_RTR_DATA;
        TxMessage.IDE = CAN_ID_STD;
        TxMessage.DLC = 8;
        TxMessage.StdId = 0x22;     
        TxMessage.Data[0] = 22;
        TxMessage.Data[1] = 0;  
        TxMessage.Data[2] = 0;
        TxMessage.Data[3] = 0;  
        TxMessage.Data[4] = 0;
        TxMessage.Data[5] = 0;
        TxMessage.Data[6] = 0;       
        TxMessage.Data[7] = 22;  
        TransmitMailbox = CAN_Transmit(CAN2, &TxMessage);     
    
}

void phase2(void)
{
    
    TIM_SetCounter(TIM2, 0);    
   
      
    tcommt=commt;
      commt=0;
        
          GPIO_ResetBits(GPIOH, GPIO_Pin_3);
      

      
//     if(pokuart==1){                                                                     //communication with 2.4 - t3
//       flagmes=3;
//       USART_SendData(USART1, flagmes);
//       pokuart=0;
//     }      
      

  //    Start communication - tok, optroni  */
          
 /*      i0=0;
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
    optrones =GPIO_ReadInputData(GPIOE);
   
    Stop communication - tok, optroni */   
   
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
      pokuart=1;
 
      
       
}

void phase3(void)
{

    TIM_SetCounter(TIM2, 0);    
 
  
       
    tcommt=commt;
      commt=0;

      GPIO_ResetBits(GPIOH, GPIO_Pin_3);
      
      
//     if(pokuart==1){                                                                     //communication with 2.4 - p1
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
       tvcan=pao5/2000;
           }
           if((petap==3) || (petap==4) || (petap==6) || (petap==7)){
       tvcan=pao5/1428;
           }
       t3h=0;
       //tvcan=vdvcurrent;
       t3l=(tvcan&0xFF);     
           

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
       
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
  TxMessage.StdId = 0x11;     
  TxMessage.Data[0] = t1h;
  TxMessage.Data[1] = t1l;  
  TxMessage.Data[2] = t2h;
  TxMessage.Data[3] = t2l;  
  TxMessage.Data[4] = t3h;
  TxMessage.Data[5] = t3l;
  TxMessage.Data[6] = p1h;       
  TxMessage.Data[7] = p1l;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage);
 
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
      
      
       Start communication 2.3 - tokdc, rpmop  */
          
/*     i0=0;
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
     rpmop=GPIO_ReadInputData(GPIOF);
      Stop communication - tokdc, rpmop */    
   
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
   
   
            
  
   
 //  if(oboroti>8000){swvgen=1;}          //5100
   
 //  if(tor==0){                                                      
 //torquem[torquec]=torque;
//torqued=(torquem[0]+torquem[1]+torquem[2]+torquem[3]+torquem[4]+torquem[5]+torquem[6]+torquem[7]+torquem[8]+torquem[9]+torquem[10]+torquem[11]+torquem[12]+torquem[13]+torquem[14]+torquem[15]+torquem[16]+torquem[17]+torquem[18]+torquem[19]+torquem[20]+torquem[21]+torquem[22]+torquem[23]+torquem[24]+torquem[25]+torquem[26]+torquem[27]+torquem[28]+torquem[29]+torquem[30]+torquem[31]+torquem[32]+torquem[33]+torquem[34]+torquem[35]+torquem[36]+torquem[37]+torquem[38]+torquem[39]+torquem[40]+torquem[41]+torquem[42]+torquem[43]+torquem[44]+torquem[45]+torquem[46]+torquem[47])/48;  
  
     
     
 //   }
 //  tor++;
 //  if(tor>1){tor=0;}
   
 torquesum=torquesum+(torque- torquem[torquec]);
 torquem[torquec]=torque;
 torqued=torquesum>>7;
  torquec++; 
 if(torquec>127){

   torquec=0;
 /*   if(swvgen==1){
     
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
     
      if(toku2<valtor){                            //130
        generator=generator-vgstep;
        if(generator<600){generator=600;}
      }
      
         
      if(toku2>valtor){generator=generator+vgstep;}             //130
             
      if(generator>26100){generator=26100;}       
     
     
      
 
   }  */
   
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
      pokuart=1;
       
      
  
}

void phase4(void)
{
      
      TIM_SetCounter(TIM3, 0);
      TIM_SetCounter(TIM2, 0);  
      
    
    
          GPIO_ResetBits(GPIOH, GPIO_Pin_3);
          
      tcommt=commt;
      commt=0;
      
      
//      if(pokuart==1){                                                                     //communication with 2.4 - current generators
//       flagmes=5;
//       USART_SendData(USART1, flagmes);
//       pokuart=0;
//     }              
      
     
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
      
        TxMessage.RTR = CAN_RTR_DATA;
        TxMessage.IDE = CAN_ID_STD;
        TxMessage.DLC = 8;
        TxMessage.StdId = 0x23;     
        TxMessage.Data[0] = 23;
        TxMessage.Data[1] = 0;  
        TxMessage.Data[2] = 0;
        TxMessage.Data[3] = 0;  
        TxMessage.Data[4] = 0;
        TxMessage.Data[5] = 0;
        TxMessage.Data[6] = 0;       
        TxMessage.Data[7] = 23;  
        TransmitMailbox = CAN_Transmit(CAN2, &TxMessage);     
       
    
    
    
    
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
          torq50=81;   //100+50
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
          torq50=111;   //100+50
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
          torq50=159;   //100+50    
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
          torq50=240;   //100+50  
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
          torq50=159;   //100+50   
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
          torq50=240;   //100+50
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
      
             
          
          
          if(shpr2){                    //209kg-60min, no generators, 10 min acceleration
        if(timetap==9000){      //3 min from the begining
          petap=1;   
          swvgen=1;
          valtor=233730;         //valtor=11500;
          swaogen=0;
          torq50=159;   //159+50    
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
          
    //krai opashen val Mi-8      
          
  
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
        
        if(timetap==111000){
          vgstep=20;
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
         mingn=mingn+errora+ok;
         minmn=timacc/3000;
         secmn=minmn*3000;
         secmn=timacc-secmn;
         secmn=secmn/50;
         minmk=endacc-minmn;
         secmk=59-secmn;
       }
       if(timacc>49999){
         
         mingn=40+pokprob;
         mingn=mingn+errora+ok;
         //pokprob=0;
       }
       if(timetap>0){
         if(timetap<uskorhz){
           minmn=timetap/3000;
           secmn=minmn*3000;
           secmn=timetap-secmn;
           secmn=secmn/50;       
           minmk=pokgrpm-minmn;
           secmk=59-secmn;    
           mingk=0;
         }
         else{
           minmn=(timetap-tetap)/3000;
           secmn=minmn*3000;
           secmn=(timetap-tetap)-secmn;
           secmn=secmn/50;       
           minmk=((temtap-timetap)-1)/3000;
           secmk=59-secmn;  
           mingk=1;
           if(ok==80){
             mingk=2;
           }
         }
                 
       }
       
       narabt=narab;
       narabt=narabt/3000;
       secgk=narabt;
       nar8=secgk;

       
       if(pokop==0){    
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
  TxMessage.StdId = 0x22;     
  TxMessage.Data[0] = mingn;
  TxMessage.Data[1] = torq50;  
  TxMessage.Data[2] = mingk;
  TxMessage.Data[3] = nar8;  
  TxMessage.Data[4] = minmn;
  TxMessage.Data[5] = secmn;
  TxMessage.Data[6] = minmk;       
  TxMessage.Data[7] = secmk;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage);
     }           
     
     else{
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
  TxMessage.StdId = 0x33;     
  TxMessage.Data[0] = mingn;
  TxMessage.Data[1] = secgn;  
  TxMessage.Data[2] = mingk;
  TxMessage.Data[3] = nar8;  
  TxMessage.Data[4] = sefst;
  TxMessage.Data[5] = sefstpok;
  TxMessage.Data[6] = prog[trans][et][4];       
  TxMessage.Data[7] = optrones23;  
  TransmitMailbox = CAN_Transmit(CAN1, &TxMessage);       
 pokop=0;      
              
     }
     }
     
   
      
//       Start communication 2.3 - toku, torque  */
     
 
      
/*      i0=1;
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
     torque=GPIO_ReadInputData(GPIOF);
   
     Stop communication - toku, torque */         
 
   
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
     pokuart=1;
     
     
    
}

void phase5(void)
{
      
      TIM_SetCounter(TIM2, 0); 
      
       

          GPIO_ResetBits(GPIOH, GPIO_Pin_3);
          
      tcommt=commt;
      commt=0;
      
      

      
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
 
       Start communication 2.3 - toku2, optrones23  */
          
/*      i0=0;
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
     rpm=GPIO_ReadInputData(GPIOE);
   
     Stop communication - toku2, optrones23 */       
    
        TxMessage.RTR = CAN_RTR_DATA;
        TxMessage.IDE = CAN_ID_STD;
        TxMessage.DLC = 8;
        TxMessage.StdId = 0x24;     
        TxMessage.Data[0] = 24;
        TxMessage.Data[1] = 0;  
        TxMessage.Data[2] = 0;
        TxMessage.Data[3] = 0;  
        TxMessage.Data[4] = 0;
        TxMessage.Data[5] = 0;
        TxMessage.Data[6] = 0;       
        TxMessage.Data[7] = 24;  
        TransmitMailbox = CAN_Transmit(CAN2, &TxMessage);       
 
   
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
    
    
    
    if((delfalarm<300) && (swvdvig==1)&& (sefst==2)){
      GPIO_SetBits(GPIOH, GPIO_Pin_11);
      delfalarm++;
    }
    if(delfalarm>299){
      GPIO_ResetBits(GPIOH, GPIO_Pin_11);
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

static void EXTILine0_Config(void)                                                     //phaseA pos to neg externall interrupt C0
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;
  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);                                 //port
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure PC0 pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;                                             //pin
  GPIO_Init(GPIOC, &GPIO_InitStructure);                                                //port

  /* Connect EXTI Line0 to PC0 pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource0);                         //port, pin

  /* Configure EXTI Line0 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;                                            //line
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;                                      //exti? ?????????????????????????????????????????????
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

static void EXTILine2_Config(void)                                                     //phaseB pos to neg externall interrupt C2
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;
  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);                                 //port
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure PC2 pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                                             //pin
  GPIO_Init(GPIOC, &GPIO_InitStructure);                                                //port

  /* Connect EXTI Line2 to PC2 pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource2);                         //port, pin

  /* Configure EXTI Line2 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line2;                                            //line
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;                                      //exti? ?????????????????????????????????????????????
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

static void EXTILine1_Config(void)                                                     //phaseC pos to neg externall interrupt C1
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;
  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);                                 //port
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure PC1 pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;                                             //pin
  GPIO_Init(GPIOC, &GPIO_InitStructure);                                                //port

  /* Connect EXTI Line1 to PC1 pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource1);                         //port, pin

  /* Configure EXTI Line1 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line1;                                            //line
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line1 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;                                      //exti? ?????????????????????????????????????????????
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


static void EXTILine3_Config(void)                                                     //phaseA neg to pos externall interrupt C3
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;
  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);                                 //port
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure PC3 pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                                             //pin
  GPIO_Init(GPIOC, &GPIO_InitStructure);                                                //port

  /* Connect EXTI Line3 to PC3 pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource3);                         //port, pin

  /* Configure EXTI Line3 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line3;                                            //line
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line3 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;                                      //exti? ?????????????????????????????????????????????
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

static void EXTILine5_Config(void)                                                     //phaseB neg to pos externall interrupt C5
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;
  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);                                 //port
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure PC5 pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;                                             //pin
  GPIO_Init(GPIOC, &GPIO_InitStructure);                                                //port

  /* Connect EXTI Line5 to PC5 pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource5);                         //port, pin

  /* Configure EXTI Line5 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line5;                                            //line
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line5 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;                                      //exti? ?????????????????????????????????????????????
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

static void EXTILine4_Config(void)                                                    //phaseC neg to pos externall interrupt C4
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;
  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);                                 //port
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure PC4 pin as inpuvet floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;                                             //pin
  GPIO_Init(GPIOC, &GPIO_InitStructure);                                                //port

  /* Connect EXTI Line4 to PC4 pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource4);                         //port, pin

  /* Configure EXTI Line4 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line4;                                            //line
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI Line4 Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;                                      //exti? ?????????????????????????????????????????????
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}



static void EXTILine10_Config(void)                                                    //PI10 externall interrupt for communication and PI9 as output
{
//  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;
//  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Enable GPIOC clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);                                 //port
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure PI10 pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;                                             //pin
  GPIO_Init(GPIOI, &GPIO_InitStructure);                                                //port
  
  /* Configure PI11 pin as input floating */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;                                             //pin
  GPIO_Init(GPIOI, &GPIO_InitStructure);                                                //port  
  
  
        /* Configure PI1 pin as output */
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;                                             //pin 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOI, &GPIO_InitStructure);                                                //port
  
      /* Configure PI0 pin as output - type of message*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;                                             //pin 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOI, &GPIO_InitStructure);                                                //port
    
      /* Configure PI2 pin as output - type of message*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;                                             //pin 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOI, &GPIO_InitStructure);                                                //port  
  
      /* Configure PI3 pin as output - type of message*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;                                             //pin 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructuret.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOI, &GPIO_InitStructure);                                                //port  
  
 
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


}




#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

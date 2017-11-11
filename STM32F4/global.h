




#ifndef GLOBAL_H // header guards 
#define GLOBAL_H   // 

extern uint8_t NCS;





extern uint8_t nomperiod;
extern uint8_t nomperiod2;

extern uint16_t rpm;
extern uint16_t vdvcurrent;
extern uint16_t kdvValue;
extern uint16_t vdvValue;
extern uint16_t vgenValue;
extern uint16_t aogen;
extern uint8_t relaogen;
extern uint8_t typetr;

extern uint32_t prog[10][10][10];                                                               //number program; number state; rpm, torque, time; 
extern uint8_t nprogram;
extern uint8_t nstate;
extern uint16_t staterpm;
extern uint16_t statetrq;
extern uint32_t statetme;


extern uint16_t voltagedv;
extern uint16_t optrones;
extern uint16_t tokiso;
extern uint16_t rpmop;
extern uint16_t tokdc;
extern uint16_t torque;
extern uint16_t toku;
extern uint16_t optrones23;
extern uint16_t toku2;

extern uint16_t t1;
extern uint16_t t2;
extern uint16_t t3;
extern uint16_t p1;
extern uint16_t t1temp;
extern uint16_t t2temp;
extern uint16_t t3temp;
extern uint16_t p1temp;
extern uint16_t t1sum;
extern uint16_t t2sum;
extern uint16_t t3sum;
extern uint16_t p1sum;
extern uint8_t a1;
extern uint8_t b1;
extern uint8_t c1;
extern uint16_t flagmes;
extern uint16_t flagtmes;
extern uint16_t flagmesc;
extern uint8_t t1m[80];
extern uint8_t t2m[80];
extern uint8_t t3m[80];
extern uint8_t p1m[80];
extern uint8_t t1c;
extern uint8_t t2c;
extern uint8_t t3c;
extern uint8_t p1c;
extern uint8_t numprog;

extern CanTxMsg TxMessage;
extern CanRxMsg RxMessage;
extern CanTxMsg TxMessage1;
extern CanRxMsg RxMessage1;
extern CanTxMsg TxMessage2;
extern CanRxMsg RxMessage2;
extern CanTxMsg TxMessage3;
extern CanRxMsg RxMessage3;
extern CanTxMsg TxMessage4;
extern CanRxMsg RxMessage4;
extern CanTxMsg TxMessage5;
extern CanRxMsg RxMessage5;
extern CanTxMsg TxMessage6;
extern CanRxMsg RxMessage6;


extern uint8_t cancod;
extern uint8_t canrcod;
extern uint8_t cantcod;

extern uint8_t cancod10;
extern uint8_t canrcod10;
extern uint8_t cantcod10;

extern uint8_t cancod11;
extern uint8_t canrcod11;
extern uint8_t cantcod11;

extern uint8_t cancod22;
extern uint8_t canrcod22;
extern uint8_t cantcod22;

extern uint8_t can2cod;
extern uint8_t can2rcod;
extern uint8_t can2tcod;

extern uint8_t can2cod24;
extern uint8_t can2rcod24;
extern uint8_t can2tcod24;

extern uint8_t can2cod23;
extern uint8_t can2rcod23;
extern uint8_t can2tcod23;

extern uint8_t can2cod22;
extern uint8_t can2rcod22;
extern uint8_t can2tcod22;


extern uint8_t TransmitMailbox;
extern uint8_t TransmitMailbox2;


extern uint16_t rerpmop;
extern uint16_t rpmopt1;
extern uint16_t rpmopt2;
extern uint16_t rpmopt3;
extern uint8_t rpmopc;
extern uint32_t start;
extern uint16_t et;
extern uint8_t trans;
extern uint32_t commt;
extern uint32_t powergen;
extern uint32_t powerdvig;
extern uint32_t poweraogen;
extern uint32_t timetap;        //timer for counting stage of examine
extern uint8_t pokop;
extern uint8_t fullpr;
extern uint8_t shpr1;
extern uint8_t shpr2;
extern uint8_t shpr3;
extern uint8_t shpr4;
extern uint8_t shpr5;
extern uint8_t shpr9;
extern uint8_t sefst;
extern uint8_t sefstpok;
extern uint8_t stoppd;
extern uint8_t errora;
extern uint8_t errorb;
extern uint16_t generator;
extern uint32_t torquesum;       
extern uint32_t torqued;       //sent data
extern uint8_t pokprob;
extern uint8_t check;
extern uint16_t vdvdel;
extern uint16_t dvdel;
extern uint16_t vgendel;
extern uint16_t vaogendel;
extern uint16_t ukotva;
extern uint16_t igen;
extern uint16_t iaogen;
extern uint16_t ivdv;
extern uint16_t ivgen;
extern uint16_t torqye;
extern uint8_t pokuart;
extern uint16_t rpmzad;
extern uint8_t endacc;
extern uint16_t pracc;
extern uint8_t ok;
extern uint8_t pokcheck;
extern uint8_t pokgrpm;
extern uint16_t uskorhz;
extern uint8_t torqch;
extern uint8_t endch;
extern uint16_t timsefst; 

extern uint16_t ph0;
extern uint16_t ph1;
extern uint16_t ph2;
extern uint16_t ph3;
extern uint16_t ph4;
extern uint16_t ph5;
extern uint8_t phasepoc;
extern uint8_t t1h;
extern uint8_t t1l;
extern uint8_t t2h;
extern uint8_t t2l;
extern uint8_t t3h;
extern uint8_t t3l;
extern uint8_t p1h;
extern uint8_t p1l;
extern uint16_t tvcan; 
extern uint8_t i0;
extern uint8_t i2;
extern uint8_t i3;
extern uint8_t firt;
extern uint8_t comm;
extern uint8_t resnom;
extern uint8_t resnom2;
extern uint8_t resnom3;
extern uint8_t nomperiod3;
extern uint32_t pao1;
extern uint32_t pao2;
extern uint32_t pao3;
extern uint32_t pao4;
extern uint32_t pao5;
extern uint8_t paoc;
extern uint8_t paocd;
extern uint32_t valtor;    //value for torque
extern uint32_t valaop;    //value for ao generators power
extern uint32_t torquem[130];
extern uint16_t torquec;
extern uint32_t avpowergen1;
extern uint32_t avpowergen2;
extern uint32_t avpowergen3;
extern uint32_t avpowergen4;
extern uint32_t avpowergen5;
extern uint32_t avpowergen6;
extern uint8_t avpowergenc;
extern uint16_t timcan1;        //timer of 50Hz for CAN communication
extern uint8_t torq50;
extern uint16_t petap;        //indicator for number of stage
extern uint32_t tcommt;
extern uint8_t aostep;
extern uint32_t narab;
extern uint8_t swaogen;
extern uint8_t aod;
extern uint8_t aodc;
extern uint8_t paostep;
extern uint8_t cti2;
extern int32_t diff; 
extern uint8_t tor;
extern uint8_t swvgen;
extern uint8_t swvdvig;
extern uint8_t dstep;
extern uint8_t pstep;
extern uint16_t tokiso2[5];
extern uint8_t powert1;
extern uint8_t dstepuf; //25
extern uint8_t dstepf;      
extern uint8_t dstepnf;
extern uint16_t vgstep; 
extern uint8_t flstep;
extern uint8_t pokvazd;
extern uint16_t timacc; 
extern uint16_t swrpm;
extern int16_t sefstvdv; 
extern int16_t sefstvgen; 
extern uint16_t kdstop;
extern uint16_t swvstop;
extern uint16_t swdstop;
extern uint16_t vdvtok;
extern uint32_t mingn;
extern uint32_t secgn;
extern uint32_t mingk;
extern uint32_t secgk;
extern uint32_t minmn;
extern uint32_t secmn;
extern uint32_t minmk;
extern uint32_t secmk;
extern uint32_t tetap;
extern uint32_t temtap;
extern uint8_t nar8;
extern uint32_t narabt;
extern uint8_t swdvig;
extern uint16_t realrpm;
extern uint16_t oboroti;
extern uint8_t uskor;
extern uint16_t vaz2;        //value for second current for engine
extern uint8_t beg;
extern uint16_t rpmch;
extern uint16_t delfalarm;
extern uint8_t kdvd1;
extern uint8_t kdvd2;
extern uint8_t flagph;
extern uint8_t phnomer;
extern uint16_t tim10value;
extern uint16_t tim10tv; 
extern uint16_t avphase;
extern uint16_t countmph; 
extern uint16_t mphase[2048]; 
extern uint16_t phseq[6]; 
extern uint8_t countphseq; 
extern uint32_t sumph; 
extern uint8_t pokfullm;
extern uint8_t pokphr;
extern uint16_t tim10tv; 
extern uint16_t tempavph1;
extern uint16_t tempavph2;
extern uint16_t tempph1;
extern uint16_t tempph2;
extern uint16_t tempph3;
extern uint16_t tempph4;
extern uint16_t tempph5;
extern uint16_t tempph6;
extern uint16_t mphase1[512]; 
extern uint16_t mphase2[512]; 
extern uint16_t mphase3[512]; 
extern uint16_t mphase4[512]; 
extern uint16_t mphase5[512]; 
extern uint16_t mphase6[512]; 







#endif



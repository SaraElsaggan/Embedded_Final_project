#ifndef WDGM_H
#define WDGM_H

//extern uint32 last_execution_time;


typedef enum {OK = 0, NOK = 1}WDGM_StatusType;
typedef enum {eshta = 0, m4_eshta = 1}stuckType;
void WDGM_Init(void);
void WDGM_MainFunction(void);
WDGM_StatusType WDGM_PovideSuppervisionStatus(void);
void  WDGM_AlivenessIndication(void);
#endif

#ifndef WDGM_H
#define WDGM_H

extern uint32 last_execution_time;


typedef enum {OK = 0, NOK = 1}WDGM_StatusType;
void WDGM_Init(void);
void WDGM_MainFunction(void);
WDGM_StatusType WDGM_PovideSuppervisionStatus(void);
void  WDGM_AlivenessIndication(void);
#endif
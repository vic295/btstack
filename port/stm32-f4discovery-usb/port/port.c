#define __BTSTACK_FILE__ "port.c"

// include STM32 first to avoid warning about redefinition of UNUSED
#include "stm32f4xx_hal.h"
#include "main.h"

#include "port.h"
#include <stdio.h>

#ifdef ENABLE_SEGGER_RTT
#include "SEGGER_RTT.h"
#endif

int btstack_main(int argc, char ** argv);
void port_main(void){
	printf("hallo\n");
}

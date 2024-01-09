#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdint.h>

//handle the optimize -O0 checking for main argument
__asm(".global __ARM_use_no_argv");

extern char string_user[256];
volatile extern uint32_t index;
volatile extern uint32_t process;

#endif /* !__MAIN_H__ */

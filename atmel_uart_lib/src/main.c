/*!
 * \file    main.c
 * \author  your name (you@domain.com)
 * \brief   brief description of what program does
 * \version 0.1
 * \date    2023-06-26
 */

#define  F_CPU 32000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "clock.h"
#include "serialF0.h"
#include "uart.h"


/*!
 * \brief  main starting point of the program.
 * \return int (with embedded this will never happen)
 */
int main()
{
    USART_data_t usart_data;

    /////////////////////
    //  Initialization //
    /////////////////////
    init_clock();
    init_uart(&usart_data);
    init_stream(F_CPU);

    // Enable global interrupts
    sei();

    char c;

    ///////////////////////////////
    //  Enter endless while-loop //
    ///////////////////////////////
    printf("Entering never ending while loop now.\n");
    while (1) {
        // Naive passthrough, maybe this doesn't work
        if (USART_RXBufferData_Available(&usart_data)) {
            c = USART_RXBuffer_GetByte(&usart_data);
            printf("%c", c);
        }
    }
}

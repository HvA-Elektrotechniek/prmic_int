#ifndef UART_H_
#define UART_H_

#include "usart_driver.h"
#include "avr_compiler.h"

#define USARTE0_ENABLE

void init_uart(USART_data_t *);

#ifdef USARTC0_ENABLE
#define USART USARTC0
#define USART_PORT PORTC
#define USART_PIN_TX_bm PIN3_bm
#define USART_PIN_RX_bm PIN2_bm
#define USART_RXC_vect USARTC0_RXC_vect
#define USART_DRE_vect USARTC0_DRE_vect
#endif /* USARTC0_ENABLE */

#ifdef USARTC1_ENABLE
#define USART USARTC1
#define USART_PORT PORTC
#define USART_PIN_TX_bm PIN7_bm
#define USART_PIN_RX_bm PIN6_bm
#define USART_RXC_vect USARTC1_RXC_vect
#define USART_DRE_vect USARTC1_DRE_vect
#endif /* USARTC1_ENABLE */

#ifdef USARTD0_ENABLE
#define USART USARTD0
#define USART_PORT PORTD
#define USART_PIN_TX_bm PIN3_bm
#define USART_PIN_RX_bm PIN2_bm
#define USART_RXC_vect USARTD0_RXC_vect
#define USART_DRE_vect USARTD0_DRE_vect
#endif /* USARTD0_ENABLE */

#ifdef USARTD1_ENABLE
#define USART USARTD1
#define USART_PORT PORTD
#define USART_PIN_TX_bm PIN7_bm
#define USART_PIN_RX_bm PIN6_bm
#define USART_RXC_vect USARTD1_RXC_vect
#define USART_DRE_vect USARTD1_DRE_vect
#endif /* USARTF0_ENABLE */

#ifdef USARTE0_ENABLE
#define USART USARTE0
#define USART_PORT PORTE
#define USART_PIN_TX_bm PIN3_bm
#define USART_PIN_RX_bm PIN2_bm
#define USART_RXC_vect USARTE0_RXC_vect
#define USART_DRE_vect USARTE0_DRE_vect
#endif /* USARTE0_ENABLE */

#ifdef USARTE1_ENABLE
#define USART USARTE1
#define USART_PORT PORTE
#define USART_PIN_TX_bm PIN7_bm
#define USART_PIN_RX_bm PIN6_bm
#define USART_RXC_vect USARTE1_RXC_vect
#define USART_DRE_vect USARTE1_DRE_vect
#endif /* USARTE1_ENABLE */

#ifdef USARTF0_ENABLE
#define USART USARTF0
#define USART_PORT PORTF
#define USART_PIN_TX_bm PIN3_bm
#define USART_PIN_RX_bm PIN2_bm
#define USART_RXC_vect USARTF0_RXC_vect
#define USART_DRE_vect USARTF0_DRE_vect
#endif /* USARTF0_ENABLE */

#endif /* UART_H_ */

#include "uart.h"

USART_data_t *usart_data_ptr;

void init_uart(USART_data_t *ud_ptr)
{
    usart_data_ptr = ud_ptr;

	USART_PORT.DIRSET = USART_PIN_TX_bm;
	USART_PORT.DIRCLR = USART_PIN_RX_bm;

	/* Use USART and initialize buffers. */
	USART_InterruptDriver_Initialize(usart_data_ptr, &USART,
                                     USART_DREINTLVL_LO_gc);

	/* USART, 8 Data bits, No Parity, 1 Stop bit. */
	USART_Format_Set(usart_data_ptr->usart, USART_CHSIZE_8BIT_gc,
                     USART_PMODE_DISABLED_gc, false);

	/* Enable RXC interrupt. */
	USART_RxdInterruptLevel_Set(usart_data_ptr->usart, USART_RXCINTLVL_LO_gc);

    // Set baudrate with the following macro:
    //   USART_Baudrate_Set(_usart, _bselValue, _bScaleFactor)
    // See Excel sheet for the bsel and bScale parameters:
    //   230400 baud, no double clock: bscale=-7 bsel=983
	USART_Baudrate_Set(&USART, 983, -7);

	/* Enable both RX and TX. */
	USART_Rx_Enable(usart_data_ptr->usart);
	/* USART_Tx_Enable(usart_data_ptr->usart); */

	/* Enable PMIC interrupt level low. */
	PMIC.CTRL |= PMIC_LOLVLEN_bm;
}



/*! \brief Receive complete interrupt service routine.
 *
 *  Receive complete interrupt service routine.
 *  Calls the common receive complete handler with pointer to the correct USART
 *  as argument.
 */
ISR(USART_RXC_vect)
{
	USART_RXComplete(usart_data_ptr);
}


/*! \brief Data register empty  interrupt service routine.
 *
 *  Data register empty  interrupt service routine.
 *  Calls the common data register empty complete handler with pointer to the
 *  correct USART as argument.
 */
ISR(USART_DRE_vect)
{
	USART_DataRegEmpty(usart_data_ptr);
}

/* Simple USART demo:
 *
 * transmit some characters over to a PC from NUCLEO STM32L432KCU6
 * pin PB6 is used as the TX Pin, hook up to a USB to TTL Serial Cable
 * no hardware control
 */
#include "FreeRTOS.h"
#include "task.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/gpio.h>

extern void vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName);

void
vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName) {
	(void)pxTask;
	(void)pcTaskName;
	for(;;);
}

static inline void
uart_putc(char ch) {
	usart_send_blocking(USART1,ch);
}

static void
task1(void *args) {

		int c = '0' - 1;

		for (;;) {
			vTaskDelay(pdMS_TO_TICKS(500)); //500ms Delay
			if ( ++c >= 'Z' ) {
				uart_putc(c);
				uart_putc('\r');
				uart_putc('\n');
				c = '0' - 1;
			} else	{
				uart_putc(c);
			}
		}
}

static void uart_setup(void) {

	 rcc_periph_clock_enable(RCC_USART1);
	 usart_set_baudrate(USART1, 9600);
	 usart_set_mode(USART1, USART_MODE_TX);
	 usart_set_databits(USART1, 8);
	 usart_set_stopbits(USART1, USART_STOPBITS_1);
	 usart_set_parity(USART1, USART_PARITY_NONE);
	 usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);
	 usart_enable(USART1);
}

static void gpio_setup(void)
{
	/* Setup USART1 TX pin as alternate function. */
	gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO6);
	gpio_set_af(GPIOB, GPIO_AF7, GPIO6);
}

int
main(void) {

	rcc_periph_clock_enable(RCC_GPIOB);

	gpio_setup();
	uart_setup();

	xTaskCreate(task1,"LED",100,NULL,configMAX_PRIORITIES-1,NULL);
	vTaskStartScheduler();

	for (;;);

	return 0;
}

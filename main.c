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
			gpio_toggle(GPIOB,GPIO3);
			vTaskDelay(pdMS_TO_TICKS(1000)); //500ms Delay
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

static void clock_setup(void)
{
	/* FIXME - this should eventually become a clock struct helper setup */
	rcc_osc_on(RCC_HSI16);

	flash_prefetch_enable();
	flash_set_ws(4);
	flash_dcache_enable();
	flash_icache_enable();
	/* 16MHz / 4 = > 4 * 40 = 160MHz VCO => 80MHz main pll  */
	rcc_set_main_pll(RCC_PLLCFGR_PLLSRC_HSI16, 4, 40,
			0, 0, RCC_PLLCFGR_PLLR_DIV2);
	rcc_osc_on(RCC_PLL);
	/* either rcc_wait_for_osc_ready() or do other things */

	/* Enable clocks for the ports we need */

	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_USART1);


	rcc_set_sysclk_source(RCC_CFGR_SW_PLL); /* careful with the param here! */
	rcc_wait_for_sysclk_status(RCC_PLL);
	/* FIXME - eventually handled internally */
	rcc_ahb_frequency = 80e6;
	rcc_apb1_frequency = 80e6;
	rcc_apb2_frequency = 80e6;
}

int
main(void) {


  clock_setup();
	gpio_setup();
	uart_setup();
	gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP , GPIO3);
	xTaskCreate(task1,"LED",100,NULL,configMAX_PRIORITIES-1,NULL);
	vTaskStartScheduler();

	for (;;);

	return 0;
}


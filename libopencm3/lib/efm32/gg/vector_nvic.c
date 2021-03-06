/* This file is part of the libopencm3 project.
 *
 * It was generated by the irq2nvic_h script.
 *
 * This part needs to get included in the compilation unit where
 * blocking_handler gets defined due to the way #pragma works.
 */


/** @defgroup CM3_nvic_isrdecls_EFM32GG User interrupt service routines (ISR) defaults for EFM32 Giant Gecko series
    @ingroup CM3_nvic_isrdecls

    @{*/

void dma_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpio_even_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer0_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart0_rx_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart0_tx_isr(void) __attribute__((weak, alias("blocking_handler")));
void usb_isr(void) __attribute__((weak, alias("blocking_handler")));
void acmp01_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0_isr(void) __attribute__((weak, alias("blocking_handler")));
void dac0_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c0_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c1_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpio_odd_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer1_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer2_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer3_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart1_rx_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart1_tx_isr(void) __attribute__((weak, alias("blocking_handler")));
void lesense_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart2_rx_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart2_tx_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart0_rx_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart0_tx_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart1_rx_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart1_tx_isr(void) __attribute__((weak, alias("blocking_handler")));
void leuart0_isr(void) __attribute__((weak, alias("blocking_handler")));
void leuart1_isr(void) __attribute__((weak, alias("blocking_handler")));
void letimer0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pcnt0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pcnt1_isr(void) __attribute__((weak, alias("blocking_handler")));
void pcnt2_isr(void) __attribute__((weak, alias("blocking_handler")));
void rtc_isr(void) __attribute__((weak, alias("blocking_handler")));
void burtc_isr(void) __attribute__((weak, alias("blocking_handler")));
void cmu_isr(void) __attribute__((weak, alias("blocking_handler")));
void vcmp_isr(void) __attribute__((weak, alias("blocking_handler")));
void lcd_isr(void) __attribute__((weak, alias("blocking_handler")));
void msc_isr(void) __attribute__((weak, alias("blocking_handler")));
void aes_isr(void) __attribute__((weak, alias("blocking_handler")));
void ebi_isr(void) __attribute__((weak, alias("blocking_handler")));

/**@}*/

/* Initialization template for the interrupt vector table. This definition is
 * used by the startup code generator (vector.c) to set the initial values for
 * the interrupt handling routines to the chip family specific _isr weak
 * symbols. */

#define IRQ_HANDLERS \
    [NVIC_DMA_IRQ] = dma_isr, \
    [NVIC_GPIO_EVEN_IRQ] = gpio_even_isr, \
    [NVIC_TIMER0_IRQ] = timer0_isr, \
    [NVIC_USART0_RX_IRQ] = usart0_rx_isr, \
    [NVIC_USART0_TX_IRQ] = usart0_tx_isr, \
    [NVIC_USB_IRQ] = usb_isr, \
    [NVIC_ACMP01_IRQ] = acmp01_isr, \
    [NVIC_ADC0_IRQ] = adc0_isr, \
    [NVIC_DAC0_IRQ] = dac0_isr, \
    [NVIC_I2C0_IRQ] = i2c0_isr, \
    [NVIC_I2C1_IRQ] = i2c1_isr, \
    [NVIC_GPIO_ODD_IRQ] = gpio_odd_isr, \
    [NVIC_TIMER1_IRQ] = timer1_isr, \
    [NVIC_TIMER2_IRQ] = timer2_isr, \
    [NVIC_TIMER3_IRQ] = timer3_isr, \
    [NVIC_USART1_RX_IRQ] = usart1_rx_isr, \
    [NVIC_USART1_TX_IRQ] = usart1_tx_isr, \
    [NVIC_LESENSE_IRQ] = lesense_isr, \
    [NVIC_USART2_RX_IRQ] = usart2_rx_isr, \
    [NVIC_USART2_TX_IRQ] = usart2_tx_isr, \
    [NVIC_UART0_RX_IRQ] = uart0_rx_isr, \
    [NVIC_UART0_TX_IRQ] = uart0_tx_isr, \
    [NVIC_UART1_RX_IRQ] = uart1_rx_isr, \
    [NVIC_UART1_TX_IRQ] = uart1_tx_isr, \
    [NVIC_LEUART0_IRQ] = leuart0_isr, \
    [NVIC_LEUART1_IRQ] = leuart1_isr, \
    [NVIC_LETIMER0_IRQ] = letimer0_isr, \
    [NVIC_PCNT0_IRQ] = pcnt0_isr, \
    [NVIC_PCNT1_IRQ] = pcnt1_isr, \
    [NVIC_PCNT2_IRQ] = pcnt2_isr, \
    [NVIC_RTC_IRQ] = rtc_isr, \
    [NVIC_BURTC_IRQ] = burtc_isr, \
    [NVIC_CMU_IRQ] = cmu_isr, \
    [NVIC_VCMP_IRQ] = vcmp_isr, \
    [NVIC_LCD_IRQ] = lcd_isr, \
    [NVIC_MSC_IRQ] = msc_isr, \
    [NVIC_AES_IRQ] = aes_isr, \
    [NVIC_EBI_IRQ] = ebi_isr

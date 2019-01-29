#ifndef _ALTERA_HPS_0_H_
#define _ALTERA_HPS_0_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'soc_system' in
 * file './soc_system.sopcinfo'.
 */

/*
 * This file contains macros for module 'hps_0' and devices
 * connected to the following masters:
 *   h2f_axi_master
 *   h2f_lw_axi_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'pio_key', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_KEY_'.
 * The prefix is the slave descriptor.
 */
#define PIO_KEY_COMPONENT_TYPE altera_avalon_pio
#define PIO_KEY_COMPONENT_NAME pio_key
#define PIO_KEY_BASE 0x0
#define PIO_KEY_SPAN 16
#define PIO_KEY_END 0xf
#define PIO_KEY_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_KEY_CAPTURE 0
#define PIO_KEY_DATA_WIDTH 4
#define PIO_KEY_DO_TEST_BENCH_WIRING 0
#define PIO_KEY_DRIVEN_SIM_VALUE 0
#define PIO_KEY_EDGE_TYPE NONE
#define PIO_KEY_FREQ 100000000
#define PIO_KEY_HAS_IN 1
#define PIO_KEY_HAS_OUT 0
#define PIO_KEY_HAS_TRI 0
#define PIO_KEY_IRQ_TYPE NONE
#define PIO_KEY_RESET_VALUE 0

/*
 * Macros for device 'pio_sw', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_SW_'.
 * The prefix is the slave descriptor.
 */
#define PIO_SW_COMPONENT_TYPE altera_avalon_pio
#define PIO_SW_COMPONENT_NAME pio_sw
#define PIO_SW_BASE 0x10
#define PIO_SW_SPAN 16
#define PIO_SW_END 0x1f
#define PIO_SW_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_SW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_SW_CAPTURE 0
#define PIO_SW_DATA_WIDTH 10
#define PIO_SW_DO_TEST_BENCH_WIRING 0
#define PIO_SW_DRIVEN_SIM_VALUE 0
#define PIO_SW_EDGE_TYPE NONE
#define PIO_SW_FREQ 100000000
#define PIO_SW_HAS_IN 1
#define PIO_SW_HAS_OUT 0
#define PIO_SW_HAS_TRI 0
#define PIO_SW_IRQ_TYPE NONE
#define PIO_SW_RESET_VALUE 0

/*
 * Macros for device 'pio_led', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_LED_'.
 * The prefix is the slave descriptor.
 */
#define PIO_LED_COMPONENT_TYPE altera_avalon_pio
#define PIO_LED_COMPONENT_NAME pio_led
#define PIO_LED_BASE 0x20
#define PIO_LED_SPAN 16
#define PIO_LED_END 0x2f
#define PIO_LED_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LED_CAPTURE 0
#define PIO_LED_DATA_WIDTH 10
#define PIO_LED_DO_TEST_BENCH_WIRING 0
#define PIO_LED_DRIVEN_SIM_VALUE 0
#define PIO_LED_EDGE_TYPE NONE
#define PIO_LED_FREQ 100000000
#define PIO_LED_HAS_IN 0
#define PIO_LED_HAS_OUT 1
#define PIO_LED_HAS_TRI 0
#define PIO_LED_IRQ_TYPE NONE
#define PIO_LED_RESET_VALUE 1023

/*
 * Macros for device 'pio_vga_addr', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_VGA_ADDR_'.
 * The prefix is the slave descriptor.
 */
#define PIO_VGA_ADDR_COMPONENT_TYPE altera_avalon_pio
#define PIO_VGA_ADDR_COMPONENT_NAME pio_vga_addr
#define PIO_VGA_ADDR_BASE 0x30
#define PIO_VGA_ADDR_SPAN 16
#define PIO_VGA_ADDR_END 0x3f
#define PIO_VGA_ADDR_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_VGA_ADDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_VGA_ADDR_CAPTURE 0
#define PIO_VGA_ADDR_DATA_WIDTH 19
#define PIO_VGA_ADDR_DO_TEST_BENCH_WIRING 0
#define PIO_VGA_ADDR_DRIVEN_SIM_VALUE 0
#define PIO_VGA_ADDR_EDGE_TYPE NONE
#define PIO_VGA_ADDR_FREQ 100000000
#define PIO_VGA_ADDR_HAS_IN 0
#define PIO_VGA_ADDR_HAS_OUT 1
#define PIO_VGA_ADDR_HAS_TRI 0
#define PIO_VGA_ADDR_IRQ_TYPE NONE
#define PIO_VGA_ADDR_RESET_VALUE 0

/*
 * Macros for device 'pio_vga_data', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_VGA_DATA_'.
 * The prefix is the slave descriptor.
 */
#define PIO_VGA_DATA_COMPONENT_TYPE altera_avalon_pio
#define PIO_VGA_DATA_COMPONENT_NAME pio_vga_data
#define PIO_VGA_DATA_BASE 0x40
#define PIO_VGA_DATA_SPAN 16
#define PIO_VGA_DATA_END 0x4f
#define PIO_VGA_DATA_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_VGA_DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_VGA_DATA_CAPTURE 0
#define PIO_VGA_DATA_DATA_WIDTH 8
#define PIO_VGA_DATA_DO_TEST_BENCH_WIRING 0
#define PIO_VGA_DATA_DRIVEN_SIM_VALUE 0
#define PIO_VGA_DATA_EDGE_TYPE NONE
#define PIO_VGA_DATA_FREQ 100000000
#define PIO_VGA_DATA_HAS_IN 0
#define PIO_VGA_DATA_HAS_OUT 1
#define PIO_VGA_DATA_HAS_TRI 0
#define PIO_VGA_DATA_IRQ_TYPE NONE
#define PIO_VGA_DATA_RESET_VALUE 0

/*
 * Macros for device 'pio_vga_we', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_VGA_WE_'.
 * The prefix is the slave descriptor.
 */
#define PIO_VGA_WE_COMPONENT_TYPE altera_avalon_pio
#define PIO_VGA_WE_COMPONENT_NAME pio_vga_we
#define PIO_VGA_WE_BASE 0x50
#define PIO_VGA_WE_SPAN 16
#define PIO_VGA_WE_END 0x5f
#define PIO_VGA_WE_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_VGA_WE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_VGA_WE_CAPTURE 0
#define PIO_VGA_WE_DATA_WIDTH 1
#define PIO_VGA_WE_DO_TEST_BENCH_WIRING 0
#define PIO_VGA_WE_DRIVEN_SIM_VALUE 0
#define PIO_VGA_WE_EDGE_TYPE NONE
#define PIO_VGA_WE_FREQ 100000000
#define PIO_VGA_WE_HAS_IN 0
#define PIO_VGA_WE_HAS_OUT 1
#define PIO_VGA_WE_HAS_TRI 0
#define PIO_VGA_WE_IRQ_TYPE NONE
#define PIO_VGA_WE_RESET_VALUE 0


#endif /* _ALTERA_HPS_0_H_ */

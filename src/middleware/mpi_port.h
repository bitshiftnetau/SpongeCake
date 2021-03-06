/*
 * mpi_port.h
 *
 *  Created on: Nov 27, 2018
 *      Author: access
 *
 *      Description: This file contains compile time switches for any HALs that need including
 *
 *      Datatypes: All USART peripheral structs should be typedef'd to the following
 *
 *      		- USART_data  		= data struct
 *      		- USART_frameconf 	= frame conig struct i.e. 9th bits, any extra bits in the USART tx/rx register that enable on the fly configuration
 *      		- USART_error		= error struct
 *      		- USART_periphconf  = configuration struct for the whole USART peripheral
 *
 */

#ifndef MPI_PORT_H_
#define MPI_PORT_H_

#include <stdint.h>
#include "mpi_types.h"

#define HOST_INTERFACE_ARRAY  32


/*****************************************************************
 -----------------------------------------------------------------
 *
 *  MAPPING CMSIS LAYERS TO MIDDLEWARE CUSTOM LAYER
 *
 *  Build an array of defines, then place the vendor-build defines 
 *  into another array, use a for loop to iterate over them and
 *  assign 1:1???
 *
 *  As for passing functions into the middleware layer, have a set
 *  of structs with function pointers for members that point to a 
 *  particular chips HAL functions. These structs need to be 
 *  fairly generic, so attempt to account for various common
 *  configurations that vendors ship with their silicon. 
 *
 *  Order the struct members as they are found in the reference
 *  manual.
 *
 *  Separate out the structs for the following:
 *
 *    - Core processor i.e. Cortex M0,0+,1,3,4
 *    - Core peripherals
 *    - Vendor Peripherals (do not make a typedef for every vendor
 *      rather, a single typedef and several different instances)
 *    - Maybe consider having a high-level struct which can act 
 *      as a class for different chips. 
 *  
 -----------------------------------------------------------------
 ****************************************************************/ 

/*******************************************************************
 *
 * @brief MPI_CORE_MCU
 *
 * @description simple info struct for core processor interface
 *
 * @param _nvic_init - point to vector interrupt init fn 
 *
 * @param _systick_init - point to systick init fn
 *
 * @param _systick_handler - point to systick handler fn
 *
 ******************************************************************/

typedef struct MPI_CORE_MCU{

  /*
   * Fn pointers for mcu
   */

  int_callback _nvic_init;
  int_callback _systick_init;
  void_callback _systick_handler;

}MPI_core_mcuconf;

/******************************************************************
 *
 * @brief MPI_INTERRUPT
 *
 * @description struct for holding interrupt handler tasks - use 
 * with RTOS when creating tasks for interrupts. 
 *
 * @param _*_handler - point to the relevant handlers
 *
 */

typedef struct MPI_INTERRUPT{

  /*
   * Fn pointers for interrupt handlers
   *
   */

  int_callback _rmu_handler;
  int_callback _emu_handler;
  int_callback _cmu_handler;
  int_callback _wdog_handler;
  int_callback _prs_handler;
  int_callback _i2c_handler;
  int_callback _usart_handler;
  int_callback _leuart_handler;
  int_callback _timer_handler;
  int_callback _rtc_handler;
  int_callback _pcnt_handler;
  int_callback _acmp_handler;
  int_callback _vcmp_handler;
  int_callback _adc_handler;
  int_callback _idac_handler;
  int_callback _aes_handler;
  int_callback _gpio_handler;

}MPI_interrupt;


typedef struct MPI_CORE_PERIPH{

  /*
   * Fn pointers for core peripherals
   */

  /*
   * 
   * SRAM
   * MSC
   * debug interface
   * DMA controller: flash, RAM 
   * 
   */

  int_callback _mcs_init;
  int_callback _dma_init;
  int_callback _dbg_init;
  int_callback _mcs_data;
  int_callback _dma_data;
  int_callback _dbg_data;

}MPI_core_periphconf;



typedef struct MPI_PERIPH_PERIPHCONF{

  /*
   * Fn pointers for vendor peripherals
   *
   */
  
  int_callback _rmu_init;
  int_callback _emu_init;
  int_callback _cmu_init;
  int_callback _wdog_init;
  int_callback _prs_init;
  int_callback _i2c_init;
  int_callback _usart_init;
  int_callback _leuart_init;
  int_callback _timer_init;
  int_callback _rtc_init;
  int_callback _pcnt_init;
  int_callback _acmp_init;
  int_callback _vcmp_init;
  int_callback _adc_init;
  int_callback _idac_init;
  int_callback _aes_init;
  int_callback _gpio_init;
      
  int_callback _rmu_data;
  int_callback _emu_data;
  int_callback _cmu_data;
  int_callback _wdog_data;
  int_callback _prs_data;
  int_callback _i2c_data;
  int_callback _usart_data;
  int_callback _leuart_data;
  int_callback _rtc_data;
  int_callback _pcnt_data;
  int_callback _acmp_data;
  int_callback _vcmp_data;
  int_callback _adc_data;
  int_callback _idac_data;
  int_callback _aes_data;
  int_callback _gpio_data;

  int_callback _rmu_config_reg;
  int_callback _emu_config_reg;
  int_callback _cmu_config_reg;
  int_callback _wdog_config_reg;
  int_callback _prs_config_reg;
  int_callback _i2c_config_reg;
  int_callback _usart_config_reg;
  int_callback _leuart_config_reg;
  int_callback _timer_config_reg;
  int_callback _rtc_config_reg;
  int_callback _pcnt_config_reg;
  int_callback _acmp_config_reg;
  int_callback _vcmp_config_reg;  
  int_callback _adc_config_reg;
  int_callback _idac_config_reg;
  int_callback _aes_config_reg;
  int_callback _gpio_config_reg;

  int_callback _rmu_query_reg;
  int_callback _emu_query_reg;
  int_callback _cmu_query_reg;
  int_callback _wdog_query_reg;
  int_callback _prs_query_reg;
  int_callback _i2c_query_reg;
  int_callback _usart_query_reg;
  int_callback _leuart_query_reg;
  int_callback _timer_query_reg;
  int_callback _rtc_query_reg;
  int_callback _pcnt_query_reg;
  int_callback _acmp_query_reg;
  int_callback _vcmp_query_reg;  
  int_callback _adc_query_reg;
  int_callback _idac_query_reg;
  int_callback _aes_query_reg;
  int_callback _gpio_query_reg;

  int_callback _timer_delay;

}MPI_periph_periphconf;

typedef MPI_periph_periphconf host_periph_struct;

typedef struct {
  int_callback _dev_init;
  int_callback _dev_reg_dump;
  int_callback _dev_data;
  int_callback _dev_config_reg;
  int_callback _dev_query_reg;
  int_callback _dev_wakeup;
  int_callback _dev_sleep;
  int_callback _dev_mode_level;
  int_callback _dev_reset;
  int_callback _dev_off;
}MPI_ext_dev_interface;

/****************************************************************
 * @brief MPI_SILICON 
 *
 * @description An instance of this struct should point to the 
 * relevant functions in the HAL of your host chip.
 *
 * @param: model - model of the chip
 * 
 * @param: revision - hardware revision number
 * 
 * @param: mmap - memory map i.e. base addresses
 * 
 * @param: interrupt_handlers - this should point to an instance of the 
 * MPI_interrupt struct declared below.
 * 
 * @param: _core_mcuconf - point to instance of MPI_core_mcuconf 
 * declared below
 * 
 * @param: _core_periphconf - point to instance of MPI_core_periphconf
 * declared below
 * 
 * @param: _periph_periphconf - point to instance of MPI_periph_periphconf
 * declared below
 *
 */

/******************************************
 *
 * The following struct instances should 
 * be assigned to dev_data members below 
 *
 * The dev_data pointer array should
 * be sent through the middleware layer
 * into the HAL. Currently all MPI layer
 * functions have a void pointer which 
 * corresponds to this struct member. 
 *
 *****************************************/

#define PERIPH_TABLE_LEN 8 

typedef struct MPI_HOST{

  char model[16];
  char revision[8];
  //int_callback mmap;
  int_callback interrupt_handlers;
  MPI_core_mcuconf _core_mcuconf;
  MPI_core_periphconf _core_periphconf;
  MPI_periph_periphconf _periph_periphconf;
  void* MPI_status[PERIPH_TABLE_LEN];
  void* MPI_conf[PERIPH_TABLE_LEN];
  void* MPI_data[PERIPH_TABLE_LEN]; // middleware layer data struct as defined as standard

}MPI_host;


typedef struct MPI_SLAVE{

  char model[16];
  char revision[8];
  int_callback interupt_handlers;
  MPI_core_mcuconf _core_mcuconf;
  MPI_core_periphconf _core_periphconf;
  MPI_periph_periphconf _periph_periphconf;
  void* MPI_data[12]; // middleware layer data struct as defined as standard

}MPI_slave;


typedef struct MPI_EXT_DEV{

  char model[16];
  char revision[8];
  MPI_ext_dev_interface _interface;
  void* MPI_data[12];
  void* MPI_status[12];
  void* MPI_conf[12];
  
}MPI_ext_dev;

/*******************************************************************
 *
 *  Think of all the different types of system info you are going
 *  to want from these devices upon an external query from the 
 *  cloud. Put them here.
 *
 *  NOTE: This is NOT the place for application layer info
 *
 ******************************************************************/

/*
 * Include the configuration file for this application
 *
 * Configuration is done through including configuration files. 
 * These configuration files are merely a list of includes to 
 * relevant hardware files.
 *
 * We are doing it this way, so that different configurations
 * can be set and tracked in code. This way we can name our files
 * to match release and version numbers, thus improving CI/CD 
 * efforts and lowering the level of guess-work when tracking
 * bugs and building for release/debug. 
 *
 */

#endif /* MPI_PORT_H_ */

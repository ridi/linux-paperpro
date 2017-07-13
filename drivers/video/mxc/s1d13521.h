/*===============================================================================
**  Generic Header information generated by 13521CFG.EXE (Build 4)
**  (C)SEIKO EPSON CORPORATION 2002-2007. All rights reserved.
**
**  DISPLAYS      WxH         FREQ    SUBTYPE
**  ------------- ----------- ------- -------------------------------------------
** *LCD1=Parallel 800x600     NA      EPD Panel
**
**  DIMENSIONS  WxHxBPP @ STRIDE       START   SADDR     ADDITIONAL
**  ----------- ---------------------- ------- --------- -----------------------
** *Main        800x600x4 @ 800        NA      000EA600h LUTAuto=on
**
**  CLOCKS        FREQ        SOURCE
**  ------------- ----------- ---------------------------------------------------
**  INCLK         132.000 MHz PLL
**  SYSCLK         66.000 MHz PLL/2
**  PCLK           26.400 MHz PLL/5
**  SPICLK         13.200 MHz SYSCLK/5
**  I2CCLK          4.125 MHz PLL/16
**  SDRAMCLK      132.000 MHz PLL
**  SDRAMREFCLK    63.954 KHz CLKI/516
**
**  This file defines the configuration environment and registers,
**  which can be used by any software, such as display drivers.
**
**  Note: If you transfer this file to any non-PC system, use ASCII
**  mode (not BINARY) to maintain system-specific line terminators.
**===============================================================================*/
#ifndef __S1D13521_H__
  #define __S1D13521_H__

  #include "ntx_s1d13521fb.h"


//#define IMX233_EPD
#define _S1D13522_

#ifdef IMX233_EPD
void gpio_epd_init(void);
void gpio_epd_cmd_write(unsigned short w);
void gpio_epd_data_write(unsigned short w);
unsigned short gpio_epd_data_read(void);
unsigned short gpio_epd_hrdy(void);
int gpio_epd_data_write_buffer (unsigned short *pBuffer, int length);

#define EPD_WRITE_CMD(a)	gpio_epd_cmd_write(a)
#define EPD_WRITE_DATA(a)	gpio_epd_data_write(a)
#define EPD_READ_DATA()		gpio_epd_data_read()
#endif

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //
  //
  //
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  /////////////////////////////////////////////////////////////////////////
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////
  #define _EPSON_REG_STATUS							0x00a
  	#define _EPSON_REG_STATUS_PLL_LOCK				0x0001
  	#define _EPSON_REG_STATUS_SDRAM_INITED			0x0002
  	#define _EPSON_REG_STATUS_DPE_BUSY				0x0004
  	#define _EPSON_REG_STATUS_HOST_MEM_BUSY			0x0008
  	#define _EPSON_REG_STATUS_SDRAM_BUSY			0x0010
  	#define _EPSON_REG_STATUS_HOST_BUS_BUSY			0x0020
  	#define _EPSON_REG_STATUS_SPI_BUSY				0x0040
  	#define _EPSON_REG_STATUS_I2C_BUSY				0x0080
  	#define _EPSON_REG_STATUS_PWR_SEQ				0x0100
  	#define _EPSON_REG_STATUS_SDRAM_SELF_REFRESH	0x0200
  	#define _EPSON_REG_STATUS_PM_STATE				0x0c00
  	  #define _EPSON_REG_STATUS_PM_STATE_UNINIT		0x0000
  	  #define _EPSON_REG_STATUS_PM_STATE_RUN		0x0400
  	  #define _EPSON_REG_STATUS_PM_STATE_STANDBY	0x0800
  	  #define _EPSON_REG_STATUS_PM_STATE_SLEEP		0x0c00
  	#define _EPSON_REG_STATUS_OSC_BYPASS			0x1000
  	#define _EPSON_REG_STATUS_PM_BUSY				0x4000
  	#define _EPSON_REG_STATUS_3W_BUSY				0x8000

  /////////////////////////////////////////////////////////////////////////
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////
  #define _EPSON_REG_WRITE_IMAGE					0x154

  /////////////////////////////////////////////////////////////////////////
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////
  #define _EPSON_REG_SPI_READ_DATA					0x200
  #define _EPSON_REG_SPI_WRITE_DATA					0x202
    #define _EPSON_REG_SPI_WRITE_DATA_ENABLE		_BIT8
  #define _EPSON_REG_SPI_CONTROL					0x204
    #define _EPSON_REG_SPI_CONTROL_ENBALE			_BIT0
    #define _EPSON_REG_SPI_CONTROL_DISBALE			0
    #define _EPSON_REG_SPI_CONTROL_CLK_POL			_BIT1
    #define _EPSON_REG_SPI_CONTROL_CLK_PHASE		_BIT2
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER		(_BIT3+_BIT4+_BIT5)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_2_1	(0 << 3)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_3_1	(1 << 3)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_4_1	(2 << 3)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_5_1	(3 << 3)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_6_1	(4 << 3)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_7_1	(5 << 3)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_8_1	(6 << 3)
    #define _EPSON_REG_SPI_CONTROL_CLK_DIVIDER_9_1	(7 << 3)
    #define _EPSON_REG_SPI_CONTROL_SPEED_HIGH		_BIT6
    #define _EPSON_REG_SPI_CONTROL_ACCESS_BY_DPE	_BIT7
    #define _EPSON_REG_SPI_CONTROL_ACCESS_BY_HOST	0
  #define _EPSON_REG_SPI_STATUS						0x206
    #define _EPSON_REG_SPI_STATUS_READ_READY		_BIT0
    #define _EPSON_REG_SPI_STATUS_READ_OVERRUN		_BIT1
    #define _EPSON_REG_SPI_STATUS_WRITE_EMPTY		_BIT2
    #define _EPSON_REG_SPI_STATUS_BUSY				_BIT3
  #define _EPSON_REG_SPI_CS_CONTROL					0x208
    #define _EPSON_REG_SPI_CS_CONTROL_ENABLE		_BIT0

  /////////////////////////////////////////////////////////////////////////
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////
  #define _EPSON_REG_THERMAL_SENSOR_CFG				0x210
  #define _EPSON_REG_THERMAL_SENSOR_STATUS			0x212
    #define _EPSON_REG_THERMAL_SENSOR_STATUS_BUSY	_BIT0
    #define _EPSON_REG_THERMAL_SENSOR_STATUS_ID		_BIT1
    #define _EPSON_REG_THERMAL_SENSOR_STATUS_SCL	_BIT4
    #define _EPSON_REG_THERMAL_SENSOR_STATUS_SDA	_BIT5
  #define _EPSON_REG_THERMAL_SENSOR_TRIGGER			0x214
    #define _EPSON_REG_THERMAL_SENSOR_TRIGGER_READ	_BIT0
  #define _EPSON_REG_THERMAL_SENSOR_DATA			0x216

  /////////////////////////////////////////////////////////////////////////
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////
  #define _EPSON_REG_SOURCE_DRV_CFG					0x30c

  /////////////////////////////////////////////////////////////////////////
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////
  #define _EPSON_REG_GATE_DRV_CFG					0x30e

  /////////////////////////////////////////////////////////////////////////
  //
  //
  //
  /////////////////////////////////////////////////////////////////////////
  #define _EPSON_REG_DPE_CONTROL						0x330
    #define _EPSON_REG_DPE_CONTROL_LUT_FORMAT_P2N		(0 << 0)
    #define _EPSON_REG_DPE_CONTROL_LUT_FORMAT_P3N		(2 << 0)
    #define _EPSON_REG_DPE_CONTROL_LUT_FORMAT_P4N		(4 << 0)
    #define _EPSON_REG_DPE_CONTROL_LUT_FORMAT_P5N		(6 << 0)

    #define _EPSON_REG_DPE_CONTROL_AUTO_WAVEFORM_OFF	(0 << 6)
    #define _EPSON_REG_DPE_CONTROL_AUTO_WAVEFORM_ON		(1 << 6)
    #define _EPSON_REG_DPE_CONTROL_AUTO_LUT_OFF			(0 << 7)
    #define _EPSON_REG_DPE_CONTROL_AUTO_LUT_ON			(1 << 7)

    #define _EPSON_REG_DPE_CONTROL_LAST_WAVEFORM_MODE 	(0xf << 8)

    #define _EPSON_REG_DPE_CONTROL_RESET_OFF			(0 << 15)
    #define _EPSON_REG_DPE_CONTROL_RESET_ON				(1 << 15)

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //
  //
  //
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  #define S1D_13521

  #define S1D_DISPLAY_BPP                 4
// #define S1D_DISPLAY_BPP                 8
#if 1
//  #define S1D_DISPLAY_SCANLINE_BYTES      600
  #define S1D_DISPLAY_FRAME_RATE          0
//  #define S1D_PHYSICAL_REG_ADDR           0x00000000L
  #define S1D_PHYSICAL_REG_ADDR           0xA0000000L
  #define S1D_PHYSICAL_REG_SIZE           90L
  #define S1D_PHYSICAL_VMEM_REQUIRED      640000L
  #define S1D_PALETTE_SIZE                256
  #define S1D_POWER_DELAY_OFF             0
  #define S1D_POWER_DELAY_ON              0
  #define S1D_HWBLT
  #define S1D_SWBLT
#endif
  #define S1D_DISPLAY_PCLK                26400000L

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //
  //
  //
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#if 0
  #define BS60_INIT_LUTIDXFMT     		(_EPSON_REG_DPE_CONTROL_LUT_FORMAT_P4N | \
  																		 _EPSON_REG_DPE_CONTROL_AUTO_LUT_ON)
#endif


  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //
  //
  //
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  #define WF_MODE_INIT            		0
  #define WF_MODE_MU              		1
  #define WF_MODE_GU              		2
  #define WF_MODE_GC              		3
  #define WF_MODE_PU              		4

  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  //
  //
  //
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  typedef unsigned short S1D_INDEX;
  typedef unsigned short S1D_VALUE;

  #define S1D_INSTANTIATE_REGISTERS(scope_prefix,variable_name)  \
  scope_prefix S1D_VALUE variable_name[] =  \
        { \
        INIT_SYS_RUN,   0,                                    \
        INIT_DSPE_CFG,  5,      _INIT_HSIZE,                  \
                                _INIT_VSIZE,                  \
                                _INIT_SDRV_CFG,               \
                                _INIT_GDRV_CFG,               \
                                _INIT_LUTIDXFMT,              \
        INIT_DSPE_TMG,  5,      _INIT_FSLEN,                  \
                                (_INIT_FELEN<<8)|_INIT_FBLEN,	\
                                _INIT_LSLEN,									\
                                (_INIT_LELEN<<8)|_INIT_LBLEN,	\
                                _INIT_PIXCLKDIV,							\
        RD_WFM_INFO,    2,      _WAVE_FORM_BASE, 0,						\
        UPD_GDRV_CLR,   0,																		\
        WAIT_DSPE_TRG,  0,																		\
        INIT_ROTMODE,   1,      (_INIT_ROTMODE << 8)			\
        }

#if 0	// for s1d13522 auto boot mode.
  #define S1D13522_INSTANTIATE_REGISTERS(scope_prefix_1,s1d13522_variable_name)  \
  scope_prefix_1 S1D_VALUE s1d13522_variable_name[] =  \
        { \
        INIT_SYS_RUN,   0,                                    \
        INIT_DSPE_CFG,  5,      _INIT_HSIZE,                  \
                                _INIT_VSIZE,                  \
                                _INIT_SDRV_CFG,               \
                                _INIT_GDRV_CFG,               \
                                _INIT_LUTIDXFMT,              \
        INIT_DSPE_TMG,  5,      _INIT_FSLEN,                  \
                                (_INIT_FELEN<<8)|_INIT_FBLEN,	\
                                _INIT_LSLEN,									\
                                (_INIT_LELEN<<8)|_INIT_LBLEN,	\
                                _INIT_PIXCLKDIV,							\
        RD_WFM_INFO,    2,      _S1D13522_WAVE_FORM_BASE, _S1D13522_WAVE_FORM_BASE_H,			\
        UPD_GDRV_CLR,   0,																		\
        WAIT_DSPE_TRG,  0,																		\
        INIT_ROTMODE,   1,      (_INIT_ROTMODE << 8)			\
        }
#endif


#endif	// __S1D13521_H__

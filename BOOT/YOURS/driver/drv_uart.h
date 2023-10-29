#ifndef __DRV_UART_H__
#define __DRV_UART_H__

#include "config.h"
#include "global.h"
#include "util_queue.h"
#include "stm32h7xx_hal_uart.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _DRV_UART_RET {
	DRV_UART_RET_FAILED = -1,
	DRV_UART_RET_OK = 0,
	DRV_UART_RET_TIMEOUT,
} DRV_UART_RET;

typedef enum _DRV_UART_CH_E {
#if (CONF_UART_CH1_USED == 1)
	DRV_UART_CH1 = 0,
#endif
#if (CONF_UART_CH2_USED == 1)
	DRV_UART_CH2,
#endif
#if (CONF_UART_CH3_USED == 1)
	DRV_UART_CH3,
#endif
#if (CONF_UART_CH4_USED == 1)
	DRV_UART_CH4,
#endif
#if (CONF_UART_CH5_USED == 1)
	DRV_UART_CH5,
#endif
#if (CONF_UART_CH6_USED == 1)
	DRV_UART_CH6,
#endif
#if (CONF_UART_CH7_USED == 1)
	DRV_UART_CH7,
#endif
#if (CONF_UART_CH8_USED == 1)
	DRV_UART_CH8,
#endif
	DRV_UART_MAX_CHANNELS,
} DRV_UART_CH_E;

typedef enum _DRV_UART_STOPBIT_E {
	DRV_UART_STOPBITS_0_5 = 0,
	DRV_UART_STOPBITS_1,
	DRV_UART_STOPBITS_1_5,
	DRV_UART_STOPBITS_2
} DRV_UART_STOPBIT_E;

typedef enum _DRV_UART_HWCTRL_E {
	DRV_UART_HWCTRL_NONE = 0,
	DRV_UART_HWCTRL_RTS,
	DRV_UART_HWCTRL_CTS,
	DRV_UART_HWCTRL_RTS_CTS,
} DRV_UART_HWCTRL_E;

typedef enum _DRV_UART_STATE_E {
	DRV_UART_S_NOT_USED = 0,
	DRV_UART_S_IDLE,
	DRV_UART_S_RUNNING
} DRV_UART_STATE_E;

typedef int32_t (*p_uart_recv_cb)(uint8_t *p_data, uint32_t size);

typedef struct _DRV_UART_CONFIG_S {
	DRV_UART_CH_E		channel;
	DRV_UART_STOPBIT_E	stopbit;
	DRV_UART_HWCTRL_E	hwctrl;
	uint32_t			baudrate;
	p_uart_recv_cb		recv_func;
	uint8_t				is_hw_rs485;
} DRV_UART_CONFIG_S;

typedef struct _DRV_UART_INSTANCE_S {
	uint8_t				state;
	DRV_UART_CONFIG_S	config;
	UART_HandleTypeDef	handle;
	uint8_t				rxbyte;
	QUEUE2048_S			rxq;
} DRV_UART_INSTANCE_S;

int32_t drv_uart_init(DRV_UART_CONFIG_S *p_config);
int32_t drv_uart_deinit(DRV_UART_CH_E channel);
int32_t drv_uart_pop_byte(DRV_UART_CH_E channel, uint8_t *p_buf);
int32_t drv_uart_read_bytes(DRV_UART_CH_E channel, uint8_t *p_buf, uint16_t length, uint32_t timeout_ms);
int32_t drv_uart_write_byte(DRV_UART_CH_E channel, uint8_t byte);
int32_t drv_uart_write_data(DRV_UART_CH_E channel, uint8_t *p_data, uint16_t size);

#ifdef __cplusplus
}
#endif

#endif //__DRV_UART_H__

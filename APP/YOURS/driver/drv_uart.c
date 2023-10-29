#include "drv_uart.h"

static DRV_UART_INSTANCE_S s_uart_inst[DRV_UART_MAX_CHANNELS];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	DRV_UART_CH_E  _channel;

	if(0){
	}
#if (CONF_UART_CH1_USED == 1)
//	else if (huart->Instance == USART1) {
	else if (huart->Instance == LPUART1) {
		_channel = DRV_UART_CH1;
	}
#endif
#if (CONF_UART_CH2_USED == 1)
	else if (huart->Instance == USART2) {
		_channel = DRV_UART_CH2;
	}
#endif
#if (CONF_UART_CH3_USED == 1)
	else if (huart->Instance == USART3) {
		_channel = DRV_UART_CH3;
	}
#endif
#if (CONF_UART_CH4_USED == 1)
	else if (huart->Instance == UART4) {
		_channel = DRV_UART_CH4;
	}
#endif
#if (CONF_UART_CH5_USED == 1)
	else if (huart->Instance == UART4) {
		_channel = DRV_UART_CH4;
	}
#endif
#if (CONF_UART_CH6_USED == 1)
	else if (huart->Instance == USART6) {
		_channel = DRV_UART_CH6;
	}
#endif
#if (CONF_UART_CH7_USED == 1)
	else if (huart->Instance == UART7) {
		_channel = DRV_UART_CH7;
	}
#endif
#if (CONF_UART_CH8_USED == 1)
	else if (huart->Instance == UART8) {
		_channel = DRV_UART_CH8;
	}
#endif
	else{
		_channel = 0;
	}

	QUEUE_IN(s_uart_inst[_channel].rxq, s_uart_inst[_channel].rxbyte);
	if( NULL != s_uart_inst[_channel].config.recv_func ){
		s_uart_inst[_channel].config.recv_func(&s_uart_inst[_channel].rxbyte, 1);
	}
}

#if (CONF_UART_CH1_USED == 1)
//void USART1_IRQHandler(void)
//{
//	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH1].handle);
//	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH1].handle, &s_uart_inst[DRV_UART_CH1].rxbyte, 1) ){
//		//CRITICAL.
//		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH1].handle, &s_uart_inst[DRV_UART_CH1].rxbyte, 1);
//	}
//}
void LPUART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH1].handle);
	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH1].handle, &s_uart_inst[DRV_UART_CH1].rxbyte, 1) ){
		//CRITICAL.
		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH1].handle, &s_uart_inst[DRV_UART_CH1].rxbyte, 1);
	}
}
#endif


#if (CONF_UART_CH2_USED == 1)
void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH2].handle);
	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH2].handle, &s_uart_inst[DRV_UART_CH2].rxbyte, 1) ){
		//CRITICAL.
		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH2].handle, &s_uart_inst[DRV_UART_CH2].rxbyte, 1);
	}
}
#endif

#if (CONF_UART_CH3_USED == 1)
void USART3_IRQHandler(void)
{
	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH3].handle);
	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH3].handle, &s_uart_inst[DRV_UART_CH3].rxbyte, 1) ){
		//CRITICAL.
		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH3].handle, &s_uart_inst[DRV_UART_CH3].rxbyte, 1);
	}
}
#endif

#if (CONF_UART_CH4_USED == 1)
void UART4_IRQHandler(void)
{
	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH4].handle);
	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH4].handle, &s_uart_inst[DRV_UART_CH4].rxbyte, 1) ){
		//CRITICAL.
		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH4].handle, &s_uart_inst[DRV_UART_CH4].rxbyte, 1);
	}
}
#endif

#if (CONF_UART_CH6_USED == 1)
void USART6_IRQHandler(void)
{
	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH6].handle);
	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH6].handle, &s_uart_inst[DRV_UART_CH6].rxbyte, 1) ){
		//CRITICAL.
		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH6].handle, &s_uart_inst[DRV_UART_CH6].rxbyte, 1);
	}
}
#endif

#if (CONF_UART_CH7_USED == 1)
void UART7_IRQHandler(void)
{
	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH7].handle);
	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH7].handle, &s_uart_inst[DRV_UART_CH7].rxbyte, 1) ){
		//CRITICAL.
		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH7].handle, &s_uart_inst[DRV_UART_CH7].rxbyte, 1);
	}
}
#endif

#if (CONF_UART_CH8_USED == 1)
void UART8_IRQHandler(void)
{
	HAL_UART_IRQHandler(&s_uart_inst[DRV_UART_CH8].handle);
	if( HAL_OK != HAL_UART_Receive_IT(&s_uart_inst[DRV_UART_CH8].handle, &s_uart_inst[DRV_UART_CH8].rxbyte, 1) ){
		//CRITICAL.
		UART_Start_Receive_IT(&s_uart_inst[DRV_UART_CH8].handle, &s_uart_inst[DRV_UART_CH8].rxbyte, 1);
	}
}
#endif


static void error_handler(void)
{
	__disable_irq();
	while (1) {
	}
}

static void _uart_dev_init(DRV_UART_INSTANCE_S *p_inst)
{
	switch(p_inst->config.channel){
#if (CONF_UART_CH1_USED == 1)
	case DRV_UART_CH1:
//		p_inst->handle.Instance = USART1;
//		HAL_NVIC_EnableIRQ(USART1_IRQn);
		p_inst->handle.Instance = LPUART1;
		HAL_NVIC_EnableIRQ(LPUART1_IRQn);
		break;
#endif
#if (CONF_UART_CH2_USED == 1)
	case DRV_UART_CH2:
		p_inst->handle.Instance = USART2;
		HAL_NVIC_EnableIRQ(USART2_IRQn);
		break;
#endif
#if (CONF_UART_CH3_USED == 1)
	case DRV_UART_CH3:
		p_inst->handle.Instance = USART3;
		HAL_NVIC_EnableIRQ(USART3_IRQn);
		break;
#endif
#if (CONF_UART_CH4_USED == 1)
	case DRV_UART_CH4:
		p_inst->handle.Instance = UART4;
		HAL_NVIC_EnableIRQ(UART4_IRQn);
		break;
#endif
#if (CONF_UART_CH5_USED == 1)
	case DRV_UART_CH5:
		p_inst->handle.Instance = UART5;
		HAL_NVIC_EnableIRQ(UART5_IRQn);
		break;
#endif
#if (CONF_UART_CH6_USED == 1)
	case DRV_UART_CH6:
		p_inst->handle.Instance = USART6;
		HAL_NVIC_EnableIRQ(USART6_IRQn);
		break;
#endif
#if (CONF_UART_CH7_USED == 1)
	case DRV_UART_CH7:
		p_inst->handle.Instance = UART7;
		HAL_NVIC_EnableIRQ(UART7_IRQn);
		break;
#endif
#if (CONF_UART_CH8_USED == 1)
	case DRV_UART_CH8:
		p_inst->handle.Instance = UART8;
		HAL_NVIC_EnableIRQ(UART8_IRQn);
		break;
#endif
	default:
		error_handler();
		break;
	}

	p_inst->handle.Init.BaudRate = p_inst->config.baudrate;
	p_inst->handle.Init.WordLength = UART_WORDLENGTH_8B;
	switch(p_inst->config.stopbit){
#if defined(BOARD_NUCLEO_F429ZI)
	case DRV_UART_STOPBITS_1:
		p_inst->handle.Init.StopBits = UART_STOPBITS_1;
		break;
	case DRV_UART_STOPBITS_2:
		p_inst->handle.Init.StopBits = UART_STOPBITS_2;
		break;
#else
	case DRV_UART_STOPBITS_0_5:
		p_inst->handle.Init.StopBits = UART_STOPBITS_0_5;
		break;
	case DRV_UART_STOPBITS_1:
		p_inst->handle.Init.StopBits = UART_STOPBITS_1;
		break;
	case DRV_UART_STOPBITS_1_5:
		p_inst->handle.Init.StopBits = UART_STOPBITS_1_5;
		break;
	case DRV_UART_STOPBITS_2:
		p_inst->handle.Init.StopBits = UART_STOPBITS_2;
		break;
#endif  /* BOARD_NUCLEO_F429ZI */
	default:
		p_inst->handle.Init.StopBits = UART_STOPBITS_1;
		break;
	}
	p_inst->handle.Init.Parity = UART_PARITY_NONE;
	p_inst->handle.Init.Mode = UART_MODE_TX_RX;
	switch(p_inst->config.hwctrl){
	case DRV_UART_HWCTRL_NONE:
		p_inst->handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		break;
	case DRV_UART_HWCTRL_RTS:
		p_inst->handle.Init.HwFlowCtl = UART_HWCONTROL_RTS;
		break;
	case DRV_UART_HWCTRL_CTS:
		p_inst->handle.Init.HwFlowCtl = UART_HWCONTROL_CTS;
		break;
	case DRV_UART_HWCTRL_RTS_CTS:
		p_inst->handle.Init.HwFlowCtl = UART_HWCONTROL_RTS_CTS;
		break;
	default:
		p_inst->handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		break;
	}
	p_inst->handle.Init.OverSampling = UART_OVERSAMPLING_16;

	if( p_inst->config.is_hw_rs485 ){
		if (HAL_RS485Ex_Init(&p_inst->handle, UART_DE_POLARITY_HIGH, 0, 0) != HAL_OK){
			error_handler();
		}
		else{
			HAL_UART_Receive_IT(&p_inst->handle, &p_inst->rxbyte, 1);
			p_inst->state = DRV_UART_S_RUNNING;
		}
	}
	else{
		if (HAL_UART_Init(&p_inst->handle) != HAL_OK) {
			error_handler();
		}
		else{
			HAL_UART_Receive_IT(&p_inst->handle, &p_inst->rxbyte, 1);
			p_inst->state = DRV_UART_S_RUNNING;
		}
	}
}

int32_t drv_uart_init(DRV_UART_CONFIG_S *p_config)
{
	ASSERT(p_config);
	ASSERT(DRV_UART_MAX_CHANNELS > p_config->channel);

	if( DRV_UART_S_NOT_USED == s_uart_inst[p_config->channel].state ){
		memset(&s_uart_inst[p_config->channel], 0x0, sizeof(DRV_UART_INSTANCE_S));
		memcpy(&s_uart_inst[p_config->channel].config, p_config, sizeof(DRV_UART_CONFIG_S));
		_uart_dev_init(&s_uart_inst[p_config->channel]);
	}

	return 0;
}

int32_t drv_uart_deinit(DRV_UART_CH_E channel)
{
	int32_t ret = DRV_UART_RET_FAILED;

	ASSERT(DRV_UART_MAX_CHANNELS > channel);

	if( DRV_UART_S_RUNNING == s_uart_inst[channel].state ){
		s_uart_inst[channel].state = DRV_UART_S_NOT_USED;
		HAL_UART_DeInit(&s_uart_inst[channel].handle);
		ret = DRV_UART_RET_OK;
	}
	else{
	}

	return ret;
}

int32_t drv_uart_pop_byte(DRV_UART_CH_E channel, uint8_t *p_buf)
{
	int32_t ret=0;

	ASSERT(p_buf);
	ASSERT(DRV_UART_MAX_CHANNELS > channel);

	if( DRV_UART_S_RUNNING == s_uart_inst[channel].state ){
		if(TRUE == QUEUE_OUT(s_uart_inst[channel].rxq, p_buf[0])){
			ret = DRV_UART_RET_OK;
		}
		else{
			ret = DRV_UART_RET_FAILED;
		}
	}
	else{
		ret = DRV_UART_RET_FAILED;
	}

	return ret;
}

int32_t drv_uart_read_bytes(DRV_UART_CH_E channel, uint8_t *p_buf, uint16_t length, uint32_t timeout_ms)
{
	int32_t ret=0;
	uint32_t tickstart=0;
	uint16_t remain=0;

	ASSERT(p_buf);
	ASSERT(DRV_UART_MAX_CHANNELS > channel);

	if( DRV_UART_S_RUNNING == s_uart_inst[channel].state ){
		remain = length;
		tickstart = HAL_GetTick();
		while( 0 < remain ){
			if(TRUE == QUEUE_OUT(s_uart_inst[channel].rxq, p_buf[length-remain])){
				remain -= 1;
			}

			if( HAL_GetTick() >= (tickstart + timeout_ms)){
				break;
			}
		}

		if( 0 >= remain ){
			ret = DRV_UART_RET_OK;
		}
		else{
			ret = DRV_UART_RET_TIMEOUT;
		}
	}
	else{
		ret = DRV_UART_RET_FAILED;
	}

	return ret;
}

int32_t drv_uart_write_byte(DRV_UART_CH_E channel, uint8_t byte)
{
	uint8_t _byte = byte;
	int32_t	ret = 0;

	ASSERT(DRV_UART_MAX_CHANNELS > channel);

	//FIXME.think non-blocking method
	if( HAL_UART_Transmit(&s_uart_inst[channel].handle, &_byte, 1, 1000) == HAL_OK ){
		ret = DRV_UART_RET_OK;
	}
	else{
		ret = DRV_UART_RET_FAILED;
	}

	return ret;
}

int32_t drv_uart_write_data(DRV_UART_CH_E channel, uint8_t *p_data, uint16_t size)
{
	int32_t	ret = 0;

	ASSERT(p_data);
	ASSERT(DRV_UART_MAX_CHANNELS > channel);

	if( HAL_UART_Transmit(&s_uart_inst[channel].handle, p_data, size, 1000) == HAL_OK ){
		ret = size;
	}
	else{
		ret = 0;
	}

	return ret;
}

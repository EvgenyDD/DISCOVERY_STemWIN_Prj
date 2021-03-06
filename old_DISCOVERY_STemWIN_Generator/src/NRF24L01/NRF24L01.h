#ifndef NRF24L01_H
#define NRF24L01_H

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_spi.h"

///irq = pd2

//SPI chip enable pin
#define NRF24L01_CSN_RCC		RCC_AHB1Periph_GPIOA
#define NRF24L01_CSN_PORT		GPIOA
#define NRF24L01_CSN_PIN		GPIO_Pin_8

//Chip enable for transmitting
#define NRF24L01_CE_RCC			RCC_AHB1Periph_GPIOA
#define NRF24L01_CE_PORT		GPIOA
#define NRF24L01_CE_PIN			GPIO_Pin_15


#define NRF24L01_CE_LOW			NRF24L01_CE_PORT->BSRRH = NRF24L01_CE_PIN
#define NRF24L01_CE_HIGH		NRF24L01_CE_PORT->BSRRL = NRF24L01_CE_PIN
#define NRF24L01_CSN_LOW		NRF24L01_CSN_PORT->BSRRH = NRF24L01_CSN_PIN
#define NRF24L01_CSN_HIGH		NRF24L01_CSN_PORT->BSRRL = NRF24L01_CSN_PIN

//NRF24L01+ registers
#define NRF24L01_REG_CONFIG			0x00	//Configuration Register
#define NRF24L01_REG_EN_AA			0x01	//Enable �Auto Acknowledgment� Function
#define NRF24L01_REG_EN_RXADDR		0x02	//Enabled RX Addresses
#define NRF24L01_REG_SETUP_AW		0x03	//Setup of Address Widths (common for all data pipes)
#define NRF24L01_REG_SETUP_RETR		0x04	//Setup of Automatic Retransmission
#define NRF24L01_REG_RF_CH			0x05	//RF Channel
#define NRF24L01_REG_RF_SETUP		0x06	//RF Setup Register	
#define NRF24L01_REG_STATUS			0x07	//Status Register
#define NRF24L01_REG_OBSERVE_TX		0x08	//Transmit observe register
#define NRF24L01_REG_RPD			0x09	
#define NRF24L01_REG_RX_ADDR_P0		0x0A	//Receive address data pipe 0. 5 Bytes maximum length.
#define NRF24L01_REG_RX_ADDR_P1		0x0B	//Receive address data pipe 1. 5 Bytes maximum length.
#define NRF24L01_REG_RX_ADDR_P2		0x0C	//Receive address data pipe 2. Only LSB
#define NRF24L01_REG_RX_ADDR_P3		0x0D	//Receive address data pipe 3. Only LSB
#define NRF24L01_REG_RX_ADDR_P4		0x0E	//Receive address data pipe 4. Only LSB
#define NRF24L01_REG_RX_ADDR_P5		0x0F	//Receive address data pipe 5. Only LSB
#define NRF24L01_REG_TX_ADDR		0x10	//Transmit address. Used for a PTX device only
#define NRF24L01_REG_RX_PW_P0		0x11	
#define NRF24L01_REG_RX_PW_P1		0x12	
#define NRF24L01_REG_RX_PW_P2		0x13	
#define NRF24L01_REG_RX_PW_P3		0x14	
#define NRF24L01_REG_RX_PW_P4		0x15	
#define NRF24L01_REG_RX_PW_P5		0x16	
#define NRF24L01_REG_FIFO_STATUS	0x17	//FIFO Status Register
#define NRF24L01_REG_DYNPD			0x1C	//Enable dynamic payload length
#define NRF24L01_REG_FEATURE		0x1D

//Registers default values
#define NRF24L01_REG_DEFAULT_VAL_CONFIG			0x08	
#define NRF24L01_REG_DEFAULT_VAL_EN_AA			0x3F	
#define NRF24L01_REG_DEFAULT_VAL_EN_RXADDR		0x03	
#define NRF24L01_REG_DEFAULT_VAL_SETUP_AW		0x03	
#define NRF24L01_REG_DEFAULT_VAL_SETUP_RETR		0x03	
#define NRF24L01_REG_DEFAULT_VAL_RF_CH			0x02	
#define NRF24L01_REG_DEFAULT_VAL_RF_SETUP		0x0E	
#define NRF24L01_REG_DEFAULT_VAL_STATUS			0x0E	
#define NRF24L01_REG_DEFAULT_VAL_OBSERVE_TX		0x00	
#define NRF24L01_REG_DEFAULT_VAL_RPD			0x00
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P0_0	0xE7
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P0_1	0xE7
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P0_2	0xE7
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P0_3	0xE7
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P0_4	0xE7
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P1_0	0xC2
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P1_1	0xC2
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P1_2	0xC2
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P1_3	0xC2
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P1_4	0xC2
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P2		0xC3	
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P3		0xC4	
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P4		0xC5
#define NRF24L01_REG_DEFAULT_VAL_RX_ADDR_P5		0xC6
#define NRF24L01_REG_DEFAULT_VAL_TX_ADDR_0		0xE7
#define NRF24L01_REG_DEFAULT_VAL_TX_ADDR_1		0xE7
#define NRF24L01_REG_DEFAULT_VAL_TX_ADDR_2		0xE7
#define NRF24L01_REG_DEFAULT_VAL_TX_ADDR_3		0xE7
#define NRF24L01_REG_DEFAULT_VAL_TX_ADDR_4		0xE7
#define NRF24L01_REG_DEFAULT_VAL_RX_PW_P0		0x00
#define NRF24L01_REG_DEFAULT_VAL_RX_PW_P1		0x00
#define NRF24L01_REG_DEFAULT_VAL_RX_PW_P2		0x00
#define NRF24L01_REG_DEFAULT_VAL_RX_PW_P3		0x00
#define NRF24L01_REG_DEFAULT_VAL_RX_PW_P4		0x00
#define NRF24L01_REG_DEFAULT_VAL_RX_PW_P5		0x00
#define NRF24L01_REG_DEFAULT_VAL_FIFO_STATUS	0x11
#define NRF24L01_REG_DEFAULT_VAL_DYNPD			0x00
#define NRF24L01_REG_DEFAULT_VAL_FEATURE		0x00

//Configuration register
#define NRF24L01_MASK_RX_DR		6
#define NRF24L01_MASK_TX_DS		5
#define NRF24L01_MASK_MAX_RT	4
#define NRF24L01_EN_CRC			3
#define NRF24L01_CRCO			2
#define NRF24L01_PWR_UP			1
#define NRF24L01_PRIM_RX		0

//Enable auto acknowledgment
#define NRF24L01_ENAA_P5		5
#define NRF24L01_ENAA_P4		4
#define NRF24L01_ENAA_P3		3
#define NRF24L01_ENAA_P2		2
#define NRF24L01_ENAA_P1		1
#define NRF24L01_ENAA_P0		0

//Enable rx addresses
#define NRF24L01_ERX_P5			5
#define NRF24L01_ERX_P4			4
#define NRF24L01_ERX_P3			3
#define NRF24L01_ERX_P2			2
#define NRF24L01_ERX_P1			1
#define NRF24L01_ERX_P0			0

//Setup of address width
#define NRF24L01_AW				0 //2 bits

//Setup of auto re-transmission
#define NRF24L01_ARD			4 //4 bits
#define NRF24L01_ARC			0 //4 bits

//RF setup register
#define NRF24L01_PLL_LOCK		4
#define NRF24L01_RF_DR_LOW		5
#define NRF24L01_RF_DR_HIGH		3
#define NRF24L01_RF_DR			3
#define NRF24L01_RF_PWR			1 //2 bits   

//General status register
#define NRF24L01_RX_DR			6
#define NRF24L01_TX_DS			5
#define NRF24L01_MAX_RT			4
#define NRF24L01_RX_P_NO		1 //3 bits
#define NRF24L01_TX_FULL		0

//Transmit observe register
#define NRF24L01_PLOS_CNT		4 //4 bits
#define NRF24L01_ARC_CNT		0 //4 bits

//FIFO status
#define NRF24L01_TX_REUSE		6
#define NRF24L01_FIFO_FULL		5
#define NRF24L01_TX_EMPTY		4
#define NRF24L01_RX_FULL		1
#define NRF24L01_RX_EMPTY		0

//Dynamic length
#define NRF24L01_DPL_P0			0
#define NRF24L01_DPL_P1			1
#define NRF24L01_DPL_P2			2
#define NRF24L01_DPL_P3			3
#define NRF24L01_DPL_P4			4
#define NRF24L01_DPL_P5			5

//Transmitter power
#define NRF24L01_M18DBM			0 //-18 dBm
#define NRF24L01_M12DBM			1 //-12 dBm
#define NRF24L01_M6DBM			2 //-6 dBm
#define NRF24L01_0DBM			3 //0 dBm

//Data rates
#define NRF24L01_2MBPS			0
#define NRF24L01_1MBPS			1
#define NRF24L01_250KBPS		2

/* Configuration */
#define NRF24L01_CONFIG			((1 << NRF24L01_EN_CRC) | (0 << NRF24L01_CRCO))

//Instruction Mnemonics
#define NRF24L01_REGISTER_MASK				0x1F

#define NRF24L01_READ_REGISTER_MASK(reg)	(0x00 | (NRF24L01_REGISTER_MASK & reg)) //Last 5 bits will indicate reg. address
#define NRF24L01_WRITE_REGISTER_MASK(reg)	(0x20 | (NRF24L01_REGISTER_MASK & reg)) //Last 5 bits will indicate reg. address
#define NRF24L01_R_RX_PAYLOAD_MASK			0x61
#define NRF24L01_W_TX_PAYLOAD_MASK			0xA0
#define NRF24L01_FLUSH_TX_MASK				0xE1
#define NRF24L01_FLUSH_RX_MASK				0xE2
#define NRF24L01_REUSE_TX_PL_MASK			0xE3
#define NRF24L01_ACTIVATE_MASK				0x50 
#define NRF24L01_R_RX_PL_WID_MASK			0x60
#define NRF24L01_NOP_MASK					0xFF

//Clear interrupt flags
#define NRF24L01_CLEAR_INTERRUPTS	NRF24L01_WriteBit(7, 4, Bit_SET); \
									NRF24L01_WriteBit(7, 5, Bit_SET); \
									NRF24L01_WriteBit(7, 6, Bit_SET)

//Flush FIFOs
#define NRF24L01_FLUSH_TX	NRF24L01_CSN_LOW; \
							SPI_Send(NRF24L01_FLUSH_TX_MASK); \
							NRF24L01_CSN_HIGH

#define NRF24L01_FLUSH_RX	NRF24L01_CSN_LOW; \
							SPI_Send(NRF24L01_FLUSH_RX_MASK); \
							NRF24L01_CSN_HIGH

#define NRF24L01_TRANSMISSON_OK 			0
#define NRF24L01_MESSAGE_LOST   			1


typedef enum {
	NRF24L01_Transmit_Status_Lost = 0,		//Message is lost, reached max retransmissions
	NRF24L01_Transmit_Status_Ok = 1,		//Message sent successfully
	NRF24L01_Transmit_Status_Sending = 0xFF	//Message is still sending
} NRF24L01_Transmit_Status_t;

typedef enum {
	NRF24L01_DataRate_2M,		// 2Mbps
	NRF24L01_DataRate_1M,		// 1Mbps
	NRF24L01_DataRate_250k		// 250kbps
} NRF24L01_DataRate_t;

typedef enum {
	NRF24L01_OutputPower_M18dBm,// -18dBm
	NRF24L01_OutputPower_M12dBm,// -12dBm
	NRF24L01_OutputPower_M6dBm,	// -6dBm
	NRF24L01_OutputPower_0dBm	// 0dBm
} NRF24L01_OutputPower_t;


/* SPI */
uint8_t SPI_Send(uint8_t);
void SPI_WriteMass(uint8_t*, uint16_t);
void SPI_ReadMass(uint8_t*, uint8_t, uint16_t);
void SPI_WrRdMass(uint8_t*, uint8_t*, uint16_t);

/* NRF24L01 */
uint8_t NRF24L01_Init(uint8_t, uint8_t);

void NRF24L01_SetChannel(uint8_t);
void NRF24L01_SetRF(NRF24L01_DataRate_t, NRF24L01_OutputPower_t);

void NRF24L01_SetMyAddress(uint8_t*);
void NRF24L01_SetPipe2Address(uint8_t);
void NRF24L01_SetPipe3Address(uint8_t);
void NRF24L01_SetPipe4Address(uint8_t);
void NRF24L01_SetPipe5Address(uint8_t);

void NRF24L01_SetTxAddress(uint8_t*);
uint8_t NRF24L01_GetRetransmissionsCount();

void NRF24L01_PowerUpTx();
void NRF24L01_PowerUpRx();
void NRF24L01_PowerDown();

NRF24L01_Transmit_Status_t NRF24L01_GetTransmissionStatus(void);
void NRF24L01_Transmit(uint8_t*);
void NRF24L01_GetData(uint8_t*);
uint8_t NRF24L01_DataReady();


uint8_t NRF24L01_GetStatus();
void NRF24L01_WriteBit(uint8_t, uint8_t, BitAction);
uint8_t NRF24L01_ReadBit(uint8_t, uint8_t);
uint8_t NRF24L01_ReadRegister(uint8_t);
void NRF24L01_ReadRegisterMulti(uint8_t, uint8_t*, uint8_t);
void NRF24L01_WriteRegister(uint8_t, uint8_t);
void NRF24L01_WriteRegisterMulti(uint8_t, uint8_t*, uint8_t);
void NRF24L01_SoftwareReset();
uint8_t NRF24L01_RxFifoEmpty();

#endif


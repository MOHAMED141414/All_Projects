/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: I2C  *********************************/
/************ Layer: MCAL********************************/
/********************************************************/


#ifndef IIC_PRIVATE_H_
#define IIC_PRIVATE_H_
#define TWDR   	*((volatile u8*)0x23)
#define TWAR   	*((volatile u8*)0x22)
#define TWSR   	*((volatile u8*)0x21)
#define TWBR   	*((volatile u8*)0x20)
#define TWCR   	*((volatile u8*)0x56)


#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave


#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7







#endif /* IIC_PRIVATE_H_ */
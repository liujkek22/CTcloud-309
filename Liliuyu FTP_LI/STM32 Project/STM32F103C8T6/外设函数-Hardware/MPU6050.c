#include "stm32f10x.h"                  // Device header
#include "MPU6050_Reg.h"
#include "IIC.h"

#define MUP6050_ADDRESS 0xD0
//注释为硬件IIC部分

void MPU6050_WaitEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT)//封装监测函数，增加超时监测部分
{
	uint32_t TimeOut;
	TimeOut = 10000;
	while(I2C_CheckEvent(I2Cx,I2C_EVENT)!= SUCCESS)//超时监测部分
	{
		TimeOut--;
		if(TimeOut == 0)
		{
			break;
		}
	}
}

void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data)//RegAddress模块的寄存器地址，Data对应变量
{
//	IIC_Start();
	I2C_GenerateSTART(I2C2, ENABLE);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT);//监测EV5(主机模式选择)事件
//	IIC_SendByte(MUP6050_ADDRESS);//发送从机地址
	I2C_Send7bitAddress(I2C2,MUP6050_ADDRESS,I2C_Direction_Transmitter);
//	IIC_ReceiveAck();
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED);//监测EV6(发送完成置标志位)事件
//	IIC_SendByte(RegAddress);
	I2C_SendData(I2C2,RegAddress);
//	IIC_ReceiveAck();
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTING);//监测EV8(字节正在发送)事件
//	IIC_SendByte(Data);
	I2C_SendData(I2C2,Data);
//	IIC_ReceiveAck();//单一字节
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTED);//监测EV8_2(字节发送完毕)事件
//	IIC_Stop();
	I2C_GenerateSTOP(I2C2, ENABLE);
}

uint8_t MPU6050_ReadReg(uint8_t RegAddress)
{
	uint8_t Data;
//	IIC_Start();
//	IIC_SendByte(MUP6050_ADDRESS);
//	IIC_ReceiveAck();//接收应答位
//	IIC_SendByte(RegAddress);
//	IIC_ReceiveAck();//定位位置	
	I2C_GenerateSTART(I2C2, ENABLE);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT);//监测EV5(主机模式选择)事件	
	I2C_Send7bitAddress(I2C2,MUP6050_ADDRESS,I2C_Direction_Transmitter);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED);//监测EV6(发送完成置标志位)事件
	I2C_SendData(I2C2,RegAddress);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTED);//监测EV8(字节正在发送)事件
	
//	IIC_Start();
//	IIC_SendByte(MUP6050_ADDRESS | 0x01);//读取数据
//	IIC_ReceiveAck();
//	Data = IIC_ReceiveByte();
//	IIC_SendAck(0);//给出接收应答
//	IIC_Stop();
	I2C_GenerateSTART(I2C2, ENABLE);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT);//监测EV5(主机模式选择)事件
	I2C_Send7bitAddress(I2C2 ,MUP6050_ADDRESS, I2C_Direction_Receiver);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED);//监测EV6(发送完成置标志位)事件
	I2C_AcknowledgeConfig(I2C2, DISABLE);
	I2C_GenerateSTOP(I2C2,ENABLE);
	MPU6050_WaitEvent(I2C2,I2C_EVENT_MASTER_BYTE_RECEIVED);//监测EV7(接收完成置标志位)事件
	Data = I2C_ReceiveData(I2C2);
	
	I2C_AcknowledgeConfig(I2C2, ENABLE);//给出接收应答
	
	return Data;
}



void MPU6050_Init(void)
{
//	IIC_Init();
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Iitstructure;
	GPIO_Iitstructure.GPIO_Mode = GPIO_Mode_AF_OD;//复用开漏模式
	GPIO_Iitstructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;//启用1、2引脚
	GPIO_Iitstructure.GPIO_Speed = GPIO_Speed_50MHz;//引脚速度50MHz
	GPIO_Init(GPIOB,&GPIO_Iitstructure);
	
	I2C_InitTypeDef I2C_InitStructure;
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;//I2C模式
	I2C_InitStructure.I2C_ClockSpeed = 50000;//SCL时钟频率，传输速度最大400KHz，现设置50KHz
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;//SCL占空比，在高速模式下需要调整，在标准速度下（100KHz内）调整无变化	
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;//应答位配置
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;//从机模式下的相应地址
	I2C_InitStructure.I2C_OwnAddress1 = 0x00;//IC2从机模式下的响应地址
	I2C_Init(I2C2,&I2C_InitStructure);
	
	I2C_Cmd(I2C2, ENABLE);
	
	MPU6050_WriteReg(MPU6050_PWR_MGMT_1,0x01);//使用MPU6050的陀螺仪时钟
	MPU6050_WriteReg(MPU6050_PWR_MGMT_2,0x00);//六轴不需要唤醒频率
	MPU6050_WriteReg(MPU6050_SMPLRT_DIV,0x09);//10分频
	MPU6050_WriteReg(MPU6050_CONFIG,0x06);//平滑滤波
	MPU6050_WriteReg(MPU6050_GYRO_CONFIG,0x18);//陀螺仪不自测，最大量程
	MPU6050_WriteReg(MPU6050_ACCEL_CONFIG,0x18);//加速度计不自测，最大量程
}

void MPU6050_GetData(int16_t *AccX, int16_t *AccY)
    //,int16_t *AccZ,int16_t *GyroX, int16_t *GyroY,int16_t *GyroZ
{
	uint8_t DataH, DataL;
	
	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);
	*AccX = (DataH << 8) | DataL; //获取16位的数据
	
	DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);
	*AccY = (DataH << 8) | DataL; //获取16位的数据

//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);
//	*AccZ = (DataH << 8) | DataL; //获取16位的数据
//	
//	DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);
//	DataL = MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);
//	*GyroX = (DataH << 8) | DataL; //获取16位的数据

//	DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);
//	DataL = MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);
//	*GyroY = (DataH << 8) | DataL; //获取16位的数据
//	
//	DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);
//	DataL = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);
//	*GyroZ = (DataH << 8) | DataL; //获取16位的数据
	
}

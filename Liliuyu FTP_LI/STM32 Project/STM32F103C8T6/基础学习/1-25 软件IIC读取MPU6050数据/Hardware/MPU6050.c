#include "stm32f10x.h"                  // Device header
#include "IIC.h"
#include "MPU6050_Reg.h"

#define MUP6050_ADDRESS 0xD0


void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data)//RegAddress模块的寄存器地址，Data对应变量
{
	IIC_Start();
	IIC_SendByte(MUP6050_ADDRESS);
	IIC_ReceiveAck();//接收应答位
	IIC_SendByte(RegAddress);
	IIC_ReceiveAck();
	IIC_SendByte(Data);
	IIC_ReceiveAck();//单一字节
	IIC_Stop();
}

uint8_t MPU6050_ReadReg(uint8_t RegAddress)
{
	uint8_t Data;
	IIC_Start();
	IIC_SendByte(MUP6050_ADDRESS);
	IIC_ReceiveAck();//接收应答位
	IIC_SendByte(RegAddress);
	IIC_ReceiveAck();//定位位置
	
	IIC_Start();
	IIC_SendByte(MUP6050_ADDRESS | 0x01);//读取数据
	IIC_ReceiveAck();
	Data = IIC_ReceiveByte();
	IIC_SendAck(0);//给出接收应答
	IIC_Stop();
	
	return Data;
}



void MPU6050_Init(void)
{
	IIC_Init();
	MPU6050_WriteReg(MPU6050_PWR_MGMT_1,0x01);//使用MPU6050的陀螺仪时钟
	MPU6050_WriteReg(MPU6050_PWR_MGMT_2,0x00);//六轴不需要唤醒频率
	MPU6050_WriteReg(MPU6050_SMPLRT_DIV,0x09);//10分频
	MPU6050_WriteReg(MPU6050_CONFIG,0x06);//平滑滤波
	MPU6050_WriteReg(MPU6050_GYRO_CONFIG,0x18);//陀螺仪不自测，最大量程
	MPU6050_WriteReg(MPU6050_ACCEL_CONFIG,0x18);//加速度计不自测，最大量程
}

void MPU6050_GetData(int16_t *AccX, int16_t *AccY,int16_t *AccZ,
					int16_t *GyroX, int16_t *GyroY,int16_t *GyroZ)
{
	uint8_t DataH, DataL;
	
	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);
	*AccX = (DataH << 8) | DataL; //获取16位的数据
	
	DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);
	*AccY = (DataH << 8) | DataL; //获取16位的数据

	DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);
	*AccZ = (DataH << 8) | DataL; //获取16位的数据
	
	DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);
	*GyroX = (DataH << 8) | DataL; //获取16位的数据

	DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);
	*GyroY = (DataH << 8) | DataL; //获取16位的数据
	
	DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);
	DataL = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);
	*GyroZ = (DataH << 8) | DataL; //获取16位的数据
	
}

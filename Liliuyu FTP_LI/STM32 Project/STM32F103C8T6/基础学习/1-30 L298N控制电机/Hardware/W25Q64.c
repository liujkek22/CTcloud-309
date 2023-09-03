#include "stm32f10x.h"                  // Device header
//#include "SPI.h"
#include "W25Q64_Ins.h"
#include "delay.h"

void W25Q64_Init(void)
{
	SPI_InitN();
}

void W25Q64_ReadID(uint8_t *MID, uint16_t *DID) //MID厂商ID DID设备ID
{
	SPI_Start();
	SPI_SwapByte(W25Q64_JEDEC_ID);//发送
	*MID = SPI_SwapByte(W25Q64_DUMMY_BYTE);//接收厂商ID
	*DID = SPI_SwapByte(W25Q64_DUMMY_BYTE);//接收设备ID高八位
	*DID <<= 8;//DID左移8位
	*DID |= SPI_SwapByte(W25Q64_DUMMY_BYTE);//接收设备ID低八位
	SPI_Stop();
}

void W25Q64_WriteEnable(void)//写使能
{
	SPI_Start();
	SPI_SwapByte(W25Q64_WRITE_ENABLE);
	SPI_Stop();
}

void W25Q64_WaitBusy(void)
{
	uint32_t Timeout;
	SPI_Start();
	SPI_SwapByte(W25Q64_READ_STATUS_REGISTER_1);
	Timeout = 100000;
	while((SPI_SwapByte(W25Q64_DUMMY_BYTE) & 0x01) == 0x01)//判断状态寄存器1的最后一位BUSY位是否为1为1则等待
	{
		Timeout--;
		if(Timeout == 0)
		{
			break;
		}//超时退出
	}
	SPI_Stop();
}

void W25Q64_PageProgram(uint32_t Address, uint8_t *DataArray, uint16_t Count)//写数据,基于页编程
{
	uint16_t i;
	
	W25Q64_WriteEnable();
	
	SPI_Start();
	SPI_SwapByte(W25Q64_PAGE_PROGRAM);
	SPI_SwapByte(Address >> 16);
	SPI_SwapByte(Address >> 8);
	SPI_SwapByte(Address);
	for (i = 0; i < Count; i ++)
	{
		SPI_SwapByte(DataArray[i]);
	}
	SPI_Stop();
	
	W25Q64_WaitBusy();
}

void W25Q64_SectorErase(uint32_t Address)//擦除数据
{
	W25Q64_WriteEnable();
	
	SPI_Start();
	SPI_SwapByte(W25Q64_SECTOR_ERASE_4KB);
	SPI_SwapByte(Address >> 16);
	SPI_SwapByte(Address >> 8);
	SPI_SwapByte(Address);
	SPI_Stop();
	
	W25Q64_WaitBusy();
}

void W25Q64_ReadData(uint32_t Address, uint8_t *DataArray, uint32_t Count)//读数据
{
	uint32_t i;
	SPI_Start();
	SPI_SwapByte(W25Q64_READ_DATA);
	SPI_SwapByte(Address >> 16);
	SPI_SwapByte(Address >> 8);
	SPI_SwapByte(Address);
	for (i = 0; i < Count; i ++)
	{
		DataArray[i] = SPI_SwapByte(W25Q64_DUMMY_BYTE);
	}
	SPI_Stop();
}

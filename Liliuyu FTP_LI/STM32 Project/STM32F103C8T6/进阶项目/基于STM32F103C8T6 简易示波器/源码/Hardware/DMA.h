#ifndef _DMA_H_
#define _DMA_H_

void MYDMA_Config(DMA_Channel_TypeDef* DMA_CHx,u32 AddrA,u32 AddrB,u16 cndtr);                //DMA����
void DMA_Transfer(DMA_Channel_TypeDef*DMA_CHx);                                               //DMA����ת��

#endif

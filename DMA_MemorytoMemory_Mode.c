#include "stm32f10x.h"
#include <stdint.h>

static uint16_t tx_data[3],rx_data[3];

//static uint16_t *tx_p=&tx_data,*rx_p=&rx_data;

int main(void){
	
	RCC->AHBENR |= (1<<0); //DMA 1 Enable
	
	DMA1_Channel1->CCR |= (1<<14); //Mem to Mem bit
	DMA1_Channel1->CCR |= (1<<10) | (1<<8); //Msize and Psize 16 bit
	DMA1_Channel1->CCR |= (1<<5); //Circ Bit
	DMA1_Channel1->CCR |= (1<<6) | (1<<7); //Minc and Pinc bit
	
	
	DMA1_Channel1->CNDTR = 3; //amount of data to be transferred
	
	DMA1_Channel1->CPAR = (uint32_t)tx_data;//source address
	DMA1_Channel1->CMAR = (uint32_t)rx_data;//destination address
	
	DMA1_Channel1->CCR |= (1<<0); //Enable channel
	
	while(1){	
	}
	
return 0;	
}

/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */

#include "CA.h"
#include "DC.h"
#include "US.h"
void setup()
{
	/*
	 * init all drivers
	 * init IRQ
	 * init HAL US_driver DC_driver
	 * init block
	 * set state pointer for each block */
	US_init();
	DC_init();
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy) ;
	DC_state = STATE(DC_idle) ;
	printf("Setup completed\n");
}

void main()
{
	setup();
	while(1)
	{
		//call state for each block
		US_state();
		CA_state();
		DC_state();
	}
}

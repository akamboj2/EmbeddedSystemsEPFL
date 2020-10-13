///*
// * "Hello World" example.
// *
// * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
// * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
// * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
// * device in your system's hardware.
// * The memory footprint of this hosted application is ~69 kbytes by default
// * using the standard reference design.
// *
// * For a reduced footprint version of this template, and an explanation of how
// * to reduce the memory footprint for a given application, see the
// * "small_hello_world" template.
// *
// */
//
//#include <stdio.h>
//
//int main()
//{
//  printf("Hello from Nios II!\n");
//
//  return 0;
//}
/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

//#include <stdio.h>
//
//int main()
//{
//  printf("Hello from Nios II!\n");
//
//  return 0;
//}
/*
 * pwm_servo.c
 *
 *  Created on: Nov 17, 2019
 *      Author: Abhi Kamboj
 */
#include <stdio.h>
#include <inttypes.h>
#include "system.h"
#include "io.h"

/* generate_pwm:
* inputs: period in milliseconds, percent duty cycle, and polarity (either 0 or 1).
* sets the Avalon bus registers to output a pwm with these characteristics.
*/
void generate_pwm(int period, double dc, int polarity){
	uint32_t set_period = period*1000000/20; //convert ms to ns and clk period is 20 ns so divide by that
	uint32_t set_dc = set_period*dc;
	uint32_t set_pol = polarity;

	IOWR_32DIRECT(PWM_0_BASE, 0, set_period);
	IOWR_32DIRECT(PWM_0_BASE, 1, set_dc);
	IOWR_32DIRECT(PWM_0_BASE, 2, set_pol);
}

int main()
{
	//this code should repeatedly move the arm of a servo motor back and fourth with a short pause in between
	//the servo should be connected to GPIO_0 pin 1 header of the board and gnd which is GPIO_0 pin 12

	int i =0;
	//generate_pwm(20, .5, 1);
	//while(1){
		IOWR_32DIRECT(PWM_0_BASE, 0, 0xFFFFFFFF);
		printf("%x\n",IORD_32DIRECT(PWM_0_BASE, 0));
		printf("%x\n",IORD_32DIRECT(PWM_0_BASE, 1));
		printf("%x\n",IORD_32DIRECT(PWM_0_BASE, 2));

	//}
//	IOWR_32DIRECT(PWM_0_BASE, 0, 1000000);
//	IOWR_32DIRECT(PWM_0_BASE, 1, 500000);
//	IOWR_32DIRECT(PWM_0_BASE, 2, 1);
//
//	printf("%d\n",IORD_32DIRECT(PWM_0_BASE, 0));
//	printf("%d\n",IORD_32DIRECT(PWM_0_BASE, 1));
//	printf("%d\n",IORD_32DIRECT(PWM_0_BASE, 2));

//	while(1){
//		generate_pwm(20, .05, 1);
//		for (i=0; i<1000000; i++);
//		generate_pwm(20, .1, 1);
//		for(i=0;i<1000000; i++);
//	}
	return 0;
}


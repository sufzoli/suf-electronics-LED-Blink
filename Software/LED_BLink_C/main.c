#include <msp430.h> 

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    P1OUT &= ~0x64;
    P1DIR |= 0x64;
    P1SEL &= ~0x64;

    int colors[3] = {100,0,0};

    int red = 0;
    int green = 0;
    int blue = 10;
    int i,j;
    unsigned char port = 0;

    while(1)
    {
    	for(j=0;j<3;j++)
    	{
    		while(colors[j] > 0)
    		{
    			colors[j]--;
    			colors[(j < 2) ? j+1 : 0]++;
				for(i = 0; i < 256; i++)
				{
					port = 0;
					port |= (colors[0] - i > 0) ? 0x20 : 0;
					port |= (colors[1] - i > 0) ? 0x04 : 0;
					port |= (colors[2] - i > 0) ? 0x40 : 0;
					P1OUT = port;
					__delay_cycles(10);
				}
    		}
    	}
    }
	
	return 0;
}

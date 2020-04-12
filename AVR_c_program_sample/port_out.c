#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
int main(void)
{

uint8_t counter;
DDRA = 0xff;

for(int i=0; i<=255; i++){

    PORTA = i;
    _delay_ms(100);
}

return 0;

}

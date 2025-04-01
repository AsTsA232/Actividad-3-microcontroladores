/*GPIO functional description (p.158)
Memory and bus architecture (p.46)

*/

//user defined libs
#include "gpio.h"
#include "timers.h"

int main(void){
	init_gpio();
	inictim2();
	inictim3();
	while(1){
		motoruno1();
		for (int j = 0;j < 65453;j++);
		
		motordos1();
		for (int j = 0;j < 65453;j++);
		
		motoruno2();
		for (int j = 0;j < 65453;j++);
		
		motordos2();
		for (int j = 0;j < 65453;j++);
		
	}
}
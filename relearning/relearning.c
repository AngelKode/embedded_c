#include <stdio.h>


int main() {
	
	
	struct Plano {
		float x;
		float y;
	};

	struct Plano var, *ptr;

	var.x = 10.2;
	var.y = 20.1;
	ptr = &var;

	ptr->x = 5.2;
	ptr->y = 10.4;

	printf_s("%.2f %.2f", var.x, var.y);

	return 0;
}
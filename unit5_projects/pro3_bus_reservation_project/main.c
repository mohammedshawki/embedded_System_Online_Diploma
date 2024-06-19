#include "bus.h"

void main(void)
{
	login();
	//by default all seats are empty so we put the flag = 0 ;
	for(int i=0;i<33;i++)
	{
		no_of_chairs1[i].flag = 0 ;
		no_of_chairs2[i].flag = 0 ;
		no_of_chairs3[i].flag = 0 ;
		no_of_chairs4[i].flag = 0 ;
		no_of_chairs5[i].flag = 0 ;
	}
	while(1){
	int c;
	printf("1- View bus list.\n");
	printf("2- Book tickets\n3- Cancel booking\n4- Checking bus status\n");
	printf("\nEnter your choice: ");
	scanf("%d",&c);
	switch(c) {
	case 1:
		bus_list();
		break ;
	case 2:
		ticket_booking();
		break ;
	case 3:
		ticket_cacelation();
		break ;
	case 4:
		checking_bus_status();
		break;
	default:
		printf("Wrong option...Choose again\n");
		break ;
	}
	}

}

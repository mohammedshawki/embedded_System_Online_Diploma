/*
 * bus.c
 *
 *  Created on: May 5, 2024
 *      Author: smartypc
 */
#include "bus.h"
void login()
{
	printf("\tWELCOME TO ONLINE BUS RESERVATION\n");
	//standard user name and password
	char st_user_name[] = "user" ;
	char st_password[] = "user2001";
	//real data from the user
	char user_name[20], password[20];
	printf("\t==========================================\n");
	printf("username: ");
	gets(user_name);
	printf("password: ");
	gets(password);
	if(strcmp(st_user_name, user_name) == 0 && strcmp(st_password, password) == 0){
		printf("LOGED IN SUCCESFULLY...\n");
		printf("\t==========================================\n");
	}
	else
	{
		printf("invalid username or password...please try again\n");
		login();
		return ;
	}

}
void bus_list()
{
	printf("\n============================================================\n");
	printf("starting point\t destination\t moving time\t cost\n");
	printf("1- Cairo      \t Aswan      \t 12:00 am   \t 500 L.E\n");
	printf("2- Alexandria \t Luxor      \t 12:00 am   \t 750 L.E\n");
	printf("3- Cairo      \t Hurghada   \t 6:00  am    \t 500 L.E\n");
	printf("4- Cairo      \t Alamein    \t 6:00  am    \t 400 L.E\n");
	printf("5- Alexandria \t Dahab      \t 12:00 am   \t 800 L.E\n");
	printf("\n============================================================\n");
}

void ticket_booking()
{
	int seat_number, count ;
	int bus ;
	bus_list();
	printf("\n choose your bus: ");
	scanf("%d",&bus);
	passenger_t* ptr;
	switch (bus) {
	case 1:
		ptr = no_of_chairs1;
		for(int i=1;i<=33;i++,ptr++)
		{
			if(ptr->flag == 0){   //if flag = 0 that means the seat is free and we can book it
				if(i<10)
					printf("0%d: Empty\t",i);
				else
					printf("%d: Empty\t",i);
			}
			else{
				if(i<10)
					printf("0%d: booked\t",i);
				else
					printf("%d: booked\t",i);
			}
			if(i%4 == 0)
				printf("\n");
		}
		printf("\nEnter the number of seats you need to book: ");
		scanf("%d",&count);
		for(int j=0;j<count;j++)
		{
			passenger_t* temp_ptr1 ;
			printf("%d- Enter the seat number: ",j+1);
			scanf("%d",&seat_number);
			int temp = seat_number - 1 ;
			//set pointer to the seat number
			temp_ptr1 = no_of_chairs1 + temp ;
			//check if the seat is empty or booked
			if(temp_ptr1->flag == 1){
				printf("sorry, someone booked this seat before..try again\n");
				break ;
			}
			temp_ptr1->seat_number = seat_number ;
			printf("Enter your first name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr1->first_name);
			printf("Enter your second name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr1->second_name);
			printf("Enter the phone number: ");
			scanf("%ld",&temp_ptr1->phone_number);
			printf("Reservation >> Done\n");
			printf("Your id is 10%d\n",seat_number);
			printf("\t==========================================\n");
			temp_ptr1->flag = 1 ;
		}
		break;
	case 2:
		ptr = no_of_chairs2 ;
		for(int i=1;i<=33;i++,ptr++)
		{
			if(ptr->flag == 0){   //if flag = 0 that means the seat is free and we can book it
				if(i<10)
					printf("0%d: Empty\t",i);
				else
					printf("%d: Empty\t",i);
			}
			else{
				if(i<10)
					printf("0%d: booked\t",i);
				else
					printf("%d: booked\t",i);
			}
			if(i%4 == 0)
				printf("\n");
		}
		printf("\nEnter the number of seats you need to book: ");
		scanf("%d",&count);
		for(int j=0;j<count;j++)
		{
			passenger_t* temp_ptr2 ;
			printf("%d- Enter the seat number: ",j+1);
			scanf("%d",&seat_number);
			int temp = seat_number - 1 ;
			//set pointer to the seat number
			temp_ptr2 = no_of_chairs2 + temp ;
			temp_ptr2->seat_number = seat_number ;
			printf("Enter your first name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr2->first_name);
			printf("Enter your second name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr2->second_name);
			printf("Enter the phone number: ");
			scanf("%ld",&temp_ptr2->phone_number);
			printf("Reservation >> Done\n");
			printf("Your id is 20%d\n",seat_number);
			printf("\t==========================================\n");
			temp_ptr2->flag = 1 ;
		}
		break;
	case 3:
		ptr = no_of_chairs3 ;
		for(int i=1;i<=33;i++,ptr++)
		{
			if(ptr->flag == 0){   //if flag = 0 that means the seat is free and we can book it
				if(i<10)
					printf("0%d: Empty\t",i);
				else
					printf("%d: Empty\t",i);
			}
			else{
				if(i<10)
					printf("0%d: booked\t",i);
				else
					printf("%d: booked\t",i);
			}
			if(i%4 == 0)
				printf("\n");
		}
		printf("\nEnter the number of seats you need to book: ");
		scanf("%d",&count);
		for(int j=0;j<count;j++)
		{
			passenger_t* temp_ptr3 ;
			printf("%d- Enter the seat number: ",j+1);
			scanf("%d",&seat_number);
			int temp = seat_number - 1 ;
			//set pointer to the seat number
			temp_ptr3 = no_of_chairs3 + temp ;
			temp_ptr3->seat_number = seat_number ;
			printf("Enter your first name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr3->first_name);
			printf("Enter your second name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr3->second_name);
			printf("Enter the phone number: ");
			scanf("%ld",&temp_ptr3->phone_number);
			printf("Reservation >> Done\n");
			printf("Your id is 30%d\n",seat_number);
			temp_ptr3->flag = 1 ;
		}
		break;
	case 4:
		ptr = no_of_chairs4 ;
		for(int i=1;i<=33;i++,ptr++)
		{
			if(ptr->flag == 0){   //if flag = 0 that means the seat is free and we can book it
				if(i<10)
					printf("0%d: Empty\t",i);
				else
					printf("%d: Empty\t",i);
			}
			else{
				if(i<10)
					printf("0%d: booked\t",i);
				else
					printf("%d: booked\t",i);
			}
			if(i%4 == 0)
				printf("\n");
		}
		printf("\nEnter the number of seats you need to book: ");
		scanf("%d",&count);
		for(int j=0;j<count;j++)
		{
			passenger_t* temp_ptr4 ;
			printf("%d- Enter the seat number: ",j+1);
			scanf("%d",&seat_number);
			int temp = seat_number - 1 ;
			//set pointer to the seat number
			temp_ptr4 = no_of_chairs4 + temp ;
			temp_ptr4->seat_number = seat_number ;
			printf("Enter your first name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr4->first_name);
			printf("Enter your second name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr4->second_name);
			printf("Enter the phone number: ");
			scanf("%ld",&temp_ptr4->phone_number);
			printf("Reservation >> Done\n");
			printf("Your id is 40%d\n",seat_number);
			printf("\t==========================================\n");
			temp_ptr4->flag = 1 ;
		}
		break;
	case 5:
		ptr = no_of_chairs5 ;
		for(int i=1;i<=33;i++,ptr++)
		{
			if(ptr->flag == 0){   //if flag = 0 that means the seat is free and we can book it
				if(i<10)
					printf("0%d: Empty\t",i);
				else
					printf("%d: Empty\t",i);
			}
			else{
				if(i<10)
					printf("0%d: booked\t",i);
				else
					printf("%d: booked\t",i);
			}
			if(i%4 == 0)
				printf("\n");
		}
		printf("\nEnter the number of seats you need to book: ");
		scanf("%d",&count);
		for(int j=0;j<count;j++)
		{
			passenger_t* temp_ptr5 ;
			printf("%d- Enter the seat number: ",j+1);
			scanf("%d",&seat_number);
			int temp = seat_number - 1 ;
			//set pointer to the seat number
			temp_ptr5 = no_of_chairs5 + temp ;
			temp_ptr5->seat_number = seat_number ;
			printf("Enter your first name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr5->first_name);
			printf("Enter your second name: ");
			fflush(stdin); fflush(stdout);
			gets(temp_ptr5->second_name);
			printf("Enter the phone number: ");
			scanf("%ld",&temp_ptr5->phone_number);
			printf("Reservation >> Done\n");
			printf("Your id is 50%d\n",seat_number);
			printf("\t==========================================\n");
			temp_ptr5->flag = 1 ;
		}
		break;
	default:
		printf("Wrong choice (choose again)\n");
		ticket_booking();
		break;
	}
	return ;
}
void ticket_cacelation()
{
	int n ;
	long phone;
	bus_list();
	printf("\n choose your bus: ");
	scanf("%d",&n);
	passenger_t* phone_ptr;
	switch (n) {
	case 1:
		printf("\nPlease enter you phone number:");
		scanf("%ld",&phone);
		phone_ptr = no_of_chairs1 ;
		for(int i=0;i<33;i++,phone_ptr++)
		{
			if(phone_ptr->phone_number == phone){
				printf("we find your number, Cancellation is done successfully\n");
				phone_ptr->flag = 0 ;
				break ;
			}
			else
			{
				if(i<32)
					continue;
				else
					printf("Sorry, we don't find your number...if there is any problem, Contact us\n");
			}
		}
		break ;
	case 2:
		printf("\nPlease enter you phone number:");
		scanf("%ld",&phone);
		phone_ptr = no_of_chairs2 ;
		for(int i=0;i<33;i++,phone_ptr++)
		{
			if(phone_ptr->phone_number == phone){
				printf("we find your number, Cancellation is done successfully\n");
				phone_ptr->flag = 0 ;
				break ;
			}
			else
			{
				if(i<32)
					continue;
				else
					printf("Sorry, we don't find your number...if there is any problem, Contact us\n");
			}
		}
		break ;
	case 3:
		printf("\nPlease enter you phone number:");
		scanf("%ld",&phone);
		phone_ptr = no_of_chairs3 ;
		for(int i=0;i<33;i++,phone_ptr++)
		{
			if(phone_ptr->phone_number == phone){
				printf("we find your number, Cancellation is done successfully\n");
				phone_ptr->flag = 0 ;
				break ;
			}
			else
			{
				if(i<32)
					continue;
				else
					printf("Sorry, we don't find your number...if there is any problem, Contact us\n");
			}
		}
		break ;
	case 4 :
		printf("\nPlease enter you phone number:");
		scanf("%ld",&phone);
		phone_ptr = no_of_chairs4 ;
		for(int i=0;i<33;i++,phone_ptr++)
		{
			if(phone_ptr->phone_number == phone){
				printf("we find your number, Cancellation is done successfully\n");
				phone_ptr->flag = 0 ;
				break ;
			}
			else
			{
				if(i<32)
					continue;
				else
					printf("Sorry, we don't find your number...if there is any problem, Contact us\n");
			}
		}
		break ;
	case 5:
		printf("\nPlease enter you phone number:");
		scanf("%ld",&phone);
		passenger_t* phone_ptr = no_of_chairs5 ;
		for(int i=0;i<33;i++,phone_ptr++)
		{
			if(phone_ptr->phone_number == phone){
				printf("we find your number, Cancellation is done successfully\n");
				phone_ptr->flag = 0 ;
				break ;
			}
			else
			{
				if(i<32)
					continue;
				else
					printf("Sorry, we don't find your number...if there is any problem, Contact us\n");
			}
		}
		break ;

	default:
		printf("wrong number\n");
		break ;
	}
	return ;
}
void checking_bus_status()
{
	printf("\nThe bus is ready in the time\n\n");
}


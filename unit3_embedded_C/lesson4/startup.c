#include "Platform_Types.h"
void Reset_Handler ();
extern int main(void);
extern unsigned int _stack_top ;
void Default_Handler () 
{
	Reset_Handler();
}
//booking 1024B
static unsigned long Stack_top[256]; 
void NMI_Handler () __attribute__((weak, alias ("Default_Handler")));; 
void H_fault_Handler () __attribute__((weak, alias ("Default_Handler")));; 

//global arr >>>>> .Data......if we put it at 0x08000000 so we moved it to flash memory (.Text) 
void (* g_p_fn_Vectors[])()  __attribute__((section(".Vectors"))) = 
{
	(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler
};
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler()
{
	//copy data sec from flash to ram
	unsigned int Data_Size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_data ;
	for(int i =0; i<Data_Size ; i++)
	{
		 *((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}
	unsigned int Bss_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for(int i =0; i<Bss_Size; i++)
	{
		 *((unsigned char*)P_dst++) = (unsigned char)0 ;
	}
	main();
}

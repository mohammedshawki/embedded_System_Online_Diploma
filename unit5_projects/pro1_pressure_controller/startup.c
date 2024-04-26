extern unsigned int _stack_top ;
extern int main(void) ;
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler();

void Default_handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak,alias("Default_handler"))) ;;
void H_fault_Handler() __attribute__((weak,alias("Default_handler"))) ;;

unsigned int vectors[] __attribute__((section(".vectors")))= 
{
	(unsigned int)&_stack_top,
	(unsigned int) &Reset_Handler,
	(unsigned int) &NMI_Handler,
	(unsigned int) &H_fault_Handler
};

void Reset_Handler()
{
	// clac data size
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_data ;
	for(int i=0;i<data_size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}
	//init bss 
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for(int i=0;i<bss_size;i++)
	{
		*((unsigned char* )P_dst++) = (unsigned char)0;
	}
	//call main
	main();
}
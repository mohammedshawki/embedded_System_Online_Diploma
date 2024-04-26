MEMORY
{
	FLASH(RX) : ORIGIN = 0x00000000, LENGTH = 512M 
	SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 512M 
}
SECTIONS
{
	.text :
	{
		*(.vectors) *(.text) *.(rodata)
		. = ALIGN(4);
		_E_text = . ;
	}> FLASH
	.data :
	{
		_S_data = . ;
		*(.data)
		. = ALIGN(4);
		_E_data = . ;
	}> SRAM AT> FLASH 
	.bss :
	{
		_S_bss = . ;
		*(.bss)
		. = ALIGN(4);
		_E_bss = . ;
		. = . + 0x1000 ;
		_stack_top = . ;
	}> SRAM


}
ENTRY(reset)
MEMORY
{
	Mem (rwx) : ORIGIN = 0X00000000, LENGTH = 64M
}
SECTIONS
{
	. = 0x10000;
	.reset . :
	{
		startup.o(.text)
	}> Mem
	.text :
	{
		*(.text)
	}> Mem
	.data :
	{
		*(.data)
	}> Mem
	.bss :
	{
		*(.bss) *(COMMENT)
	}> Mem
	. = . +0X1000;
	stack_top = . ;
}
 /***********************************************
 *  File		: spi.c
 *	Module		: SPI
 *	Target		: ATMEGA32
 *	Author		: ahmed
 *  Description	:
 *
 *************************************************/
#include "spi.h"

void spi_vidMasterInit(void)
{
	/*	configure SPI MOSI Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN5, OUTPUT);
	/*	configure SPI SS Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN4, OUTPUT);
	/*	configure SPI SCK Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN7, OUTPUT);
	/*	configure SPI MISO Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN6, INPUT);
	/*	initialize SPI SS pin with HIGH (No slave selected) */
	dio_vidWriteChannel(DIO_PORTB, DIO_PIN4, STD_HIGH);
	/*	enable SPI Module	*//*	enable SPI Module in Master mode	*/
	/*	set SCK frequency by F_CPU/16	*//*	Set SPI Speed	1MHZ*/

	SPI_SPCR_REG |= (1<<SPI_SPE_BIT_NO) |(1<<SPI_MSTR_BIT_NO)
			|SPI_SCK_FREQ_FCPU_DIV_16;

	SPI_SPSR_REG = 0;
	SET_BIT(SPI_SPCR_REG,5);
	SET_BIT(SPI_SPCR_REG,3);
	SET_BIT(SPI_SPCR_REG,2);
//	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
//	SET_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
//	SPI_SPCR_REG |= SPI_SCK_FREQ_FCPU_DIV_16;
	//
}

void spi_vidSlaveInit(void)
{
	/*	configure SPI MOSI Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN5, INPUT);
	/*	configure SPI SS Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN4, INPUT);
	/*	configure SPI SCK Pin as input	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN7, INPUT);
	/*	configure SPI MISO Pin as output	*/
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN6, OUTPUT);



	/*	enable SPI Module	*/

	SET_BIT(SPI_SPCR_REG,SPI_SPE_BIT_NO);
	/*	enable SPI Module in Slave mode	*/
	CLEAR_BIT(SPI_SPCR_REG,SPI_MSTR_BIT_NO);
	//SPI_SPSR_REG = 0;

	//SPI_SPCR_REG = 0x40;
	SET_BIT(SPI_SPCR_REG,5);
	SET_BIT(SPI_SPCR_REG,3);
	SET_BIT(SPI_SPCR_REG,2);
}

void spi_MasterWrite(u8 data)
{
	u8 loc_flush_byte;

	dio_vidWriteChannel(DIO_PORTB, DIO_PIN4, STD_LOW);
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}
		/*	flush the data register	*/
	dio_vidWriteChannel(DIO_PORTB, DIO_PIN4, STD_HIGH);
	loc_flush_byte = SPI_SPDR_REG;
	(void)loc_flush_byte;  //to suppress warning

}

u8 spi_u8MasterRead(void)
{
	u8 loc_dummy_byte=0xFF;
	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = loc_dummy_byte;
	/*	wait until byte received	*/
	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}
		/*	read the data register	*/
	return SPI_SPDR_REG;
}

u8 spi_u8MasterTranseve(u8 data)
{
	u8 o;
	dio_vidWriteChannel(DIO_PORTB, DIO_PIN4, STD_LOW);
	while(CHECK_BIT(SPI_SPSR_REG,6) ==1);

	/*	load SPI data register with a byte to send	*/
	SPI_SPDR_REG = data;
	/*	wait until byte sent	*/

	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}
	/*	flush the data register	*/
	o =SPI_SPDR_REG;
	dio_vidWriteChannel(DIO_PORTB, DIO_PIN4, STD_HIGH);
	return o;
}

u8 spi_u8SlaveRead(void)
{
	u8 g;
	/*	wait until byte received	*/
	//SPI_SPDR_REG =0x5a;
	while(CHECK_BIT(SPI_SPSR_REG,6) == 1);

	while(CHECK_BIT(SPI_SPSR_REG,SPI_SPIF_BIT_NO) == 0)
	{
		;
	}
		/*	read the data register	*/

	g =SPI_SPDR_REG;
	SPI_SPDR_REG = 0x22;
	return g ;
}

void spi_vidSlaveWrite(u8 data)
{
	SPI_SPDR_REG = data;
}

/*******************************************************************************
* This file provides the functions for the ADC module 
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/
// This file is written for PIC16F887, if other model of PIC is uses, please modify accordingly


#include <htc.h>
#include "system.h"
#include "adc.h"



/*******************************************************************************
* PUBLIC FUNCTION: adc_initialize
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Initialize the ADC module.
*
*******************************************************************************/
void adc_initialize(void)
{
	// A/D Conversion Clock = FOSC/32.
	ADCS1 = 1;
	ADCS0 = 0;
	
	// Set AN as analog pin
	ANS0 = 1;
	
	// Configure the result to be right justified, will take as 10-bit ADC
	ADFM = 1;
	
	VCFG1 = 0;

	VCFG0 = 0;
	
	// Turn Off ADC module by default
	ADON = 0;
}

	
/*******************************************************************************
* PUBLIC FUNCTION: adc_on
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Activate ADC module
*
*******************************************************************************/
void adc_on(void)
{
	// Turn On ADC module
	ADON = 1;
}




/*******************************************************************************
* PUBLIC FUNCTION: adc_off
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Deactivate ADC module
*
*******************************************************************************/
void adc_off(void)
{
	// Turn Off ADC module, to save power
	ADON = 0;
}



/*******************************************************************************
* PUBLIC FUNCTION: ui_adc_read
*
* PARAMETERS:
* ~ void
*
* RETURN:
* ~ The ADC result in 16-bit
*
* DESCRIPTIONS:
* Convert and read the result of the ADC from ANO.
*
*******************************************************************************/
unsigned int ui_adc_read(void)
{
	unsigned int pot = 0;
	// Select the ADC channel on AN0 for SK40C
	CHS2 = 0;
	CHS1 = 0;
	CHS0 = 0;
	
	// Delay 1mS to fully charge the holding capacitor in the ADC module.
	__delay_ms(1);
	
	// Start the conversion and wait for it to complete.
	GODONE = 1;
	while (GODONE == 1);
	
	// Return 10-bit ADC result.
	pot = (unsigned int)ADRESH << 8;
	pot = pot + ADRESL;
	return pot;
}	

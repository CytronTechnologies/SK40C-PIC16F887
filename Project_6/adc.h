/*******************************************************************************
* This file provides the functions for the ADC module on PTK40A using PIC16F877A
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/



#ifndef _ADC_H
#define _ADC_H



/*******************************************************************************
* PUBLIC FUNCTION PROTOTYPES                                                   *
*******************************************************************************/

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
extern void adc_initialize(void);




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
extern void adc_on(void);



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
extern void adc_off(void);


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
extern unsigned int ui_adc_read(void);


#endif

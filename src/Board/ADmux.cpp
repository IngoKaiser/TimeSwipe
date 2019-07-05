//ADC-DAC mux:


#include "ADmux.h"
#include "sam.h"

CADmux::CADmux()
{
	//setup gain pins: PB14,PB15
    PORT->Group[1].DIRSET.reg=(1L<<14);
    PORT->Group[1].DIRSET.reg=(1L<<15);
    SetGain(typeADgain::gainX1);
    
    //setup ADC/DAC cntr pins:
    //DAC control switch PIN PB04:
    PORT->Group[1].DIRSET.reg=(1L<<4);  //18.04.19
    //PORT->Group[1].OUTCLR.reg=(1L<<4);  //18.04.19
    SetDACmode(typeDACmode::ExtDACs); //27.05.2019 - set to default state

    //ADC control measure switch PIN PB13:
    PORT->Group[1].DIRSET.reg=(1L<<13); //19.04.19
    PORT->Group[1].OUTCLR.reg=(1L<<13);
    m_bADmesEnabled=false; //18.06.2019

    //24.04.2019: set UBR PC07 pin to zero:
    PORT->Group[2].DIRSET.reg=(1L<<7);
    PORT->Group[2].OUTCLR.reg=(1L<<7);
    m_UBRVoltage=false; //!!! 07.05.2019

}
void CADmux::EnableADmes(bool how)
{
    m_bADmesEnabled=how; //18.06.2019
	if(how)
		PORT->Group[1].OUTSET.reg=(1L<<13);	//on
	else
		PORT->Group[1].OUTCLR.reg=(1L<<13); //off
		
}
void CADmux::SetUBRvoltage(bool how)
{
    m_UBRVoltage=how;
    if(how)
        PORT->Group[2].OUTSET.reg=(1L<<7);
    else
        PORT->Group[2].OUTCLR.reg=(1L<<7);

}

void CADmux::SetDACmode(typeDACmode mode)
{
    m_CurDACmode=mode;
    if(typeDACmode::ExtDACs==mode)
    {
        PORT->Group[1].OUTCLR.reg=(1L<<4);
    }
    else
    {
        PORT->Group[1].OUTSET.reg=(1L<<4);
    }
}

void CADmux::SetGain(typeADgain gain)
{
	unsigned int pval=PORT->Group[1].OUT.reg; //cur val
    unsigned int set=0;

    m_CurGain=gain;
    switch(gain)
    {
		case typeADgain::gainX1:
			set=0;
		break;
		
        case typeADgain::gainX2:
            set=(1L<<15);
        break;

        case typeADgain::gainX4:
            set=(1L<<14);
        break;

        case typeADgain::gainX8:
            set=(1L<<14)|(1<<15);
    }

    unsigned int pset=(~((1L<<14)|(1<<15))&pval)|set;

    //set port:
    PORT->Group[1].OUT.reg=pset;
}

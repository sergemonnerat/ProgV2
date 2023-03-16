/*
------------------------------------------------------------
Copyright 2003-20xx Haute �cole ARC Ing�ni�rie, Switzerland. 
All rights reserved.
------------------------------------------------------------
Nom du fichier : 	mAd.h	
Auteur et Date :	Monnerat Serge 20.1.20xx

But : Module permettant l'acc�s au convertisseur A/D

Modifications
Date		Faite	Ctrl		Description
------------------------------------------------------------
*/

#ifndef __mAd__
#define __mAd__

#include "def.h"

// ADC input value enum
typedef enum
{
	kTemp=0,
	kP1=1,
	kP2=2
}ADCInputEnum;

//-----------------------------------------------------------------------
// ADC setup
//-----------------------------------------------------------------------
void mAd_Setup(void);

//-----------------------------------------------------------------------
// ADC module open
//-----------------------------------------------------------------------
void mAd_Open(void);

//-----------------------------------------------------------------------
// ADC module close
//-----------------------------------------------------------------------
void mAd_Close(void);

//-----------------------------------------------------------------------
// Start et lecture du r�sultat
//-----------------------------------------------------------------------
UInt16 mAd_Read(ADCInputEnum aAdcInp);

#endif

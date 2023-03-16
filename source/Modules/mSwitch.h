/*
 * mSwitch.h
 *
 *  Created on: Mar 21, 2014
 *      Author: serge.monnerat
 */

#ifndef MSWITCH_H_
#define MSWITCH_H_

#include"def.h"

// Enum�r� des interrupteurs (SW0 � Sw7 sur le sch�ma)
typedef enum
{
	kSw1=0,
	kSw2=1,
	kSw3=2,
	kSw4=3,
	kSw5=4,
	kSw6=5,
	kSw7=6,
	kSw8=7
}SwitchEnum;

// Enum�r� des boutons poussoirs (SW0...SW3 sur le sch�ma)
typedef enum
{
	kPushButSW1=0,
	kPushButSW2=1,
	kPushButSW3=2,
	kPushButSW4=3
}PushButEnum;

//-----------------------------------------------------------------------------
// Configuration des ports IO utilis�s par les interrupteurs et les poussoirs
//-----------------------------------------------------------------------------
void mSwitch_Setup(void);

//-------------------------------------------------------------------------
// Lecture des interrupteurs
// aSwitchNb: quel interrupteur veut-on lire
// Retour: �tat du switch
//-------------------------------------------------------------------------
bool mSwitch_ReadSwitch(SwitchEnum aSwitch);

//-------------------------------------------------------------------------
// Lecture des boutons poussoir
// aPushButNb: quel boutons poussoir veut-on lire
// Retour: �tat du bouton poussoir
//-------------------------------------------------------------------------
bool mSwitch_ReadPushBut(PushButEnum aPushButNb);

#endif /* MSWITCH_H_ */

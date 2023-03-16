/*
------------------------------------------------------------
Copyright 2003-20xx Haute �cole ARC Ing�ni�rie, Switzerland. 
All rights reserved.
------------------------------------------------------------
Nom du fichier : 	gMBox.h	
Auteur et Date :	Monnerat Serge 8.5.20xx

But : Gestionnaire responsable de l'�changes des donn�es
      entre gestionnaire

Modifications
Date		Faite	Ctrl		Description
------------------------------------------------------------
*/


#ifndef __GMBOX__
#define __GMBOX__

#include "def.h"

//-----------------------------------------------------------------------------
// Structure du gestionnaire Input
//-----------------------------------------------------------------------------

#define kNbOfSw 8

typedef struct
{
  bool SwitchTab[kNbOfSw];  // Tableau de l'�tat des interrupteurs
  float TempCarte;
	float P1;
	float P2;
}InputStruct;

extern InputStruct gInput;

//-----------------------------------------------------------------------------
// Structure du gestionnaire Compute
//-----------------------------------------------------------------------------

#define kNbOfErr 8
 
typedef struct
{
  bool ErrTab[kNbOfErr];  // Tableau de l'�tat des erreurs
  float TempCarte;
	float P1;
	float P2;
}ComputeStruct;

extern ComputeStruct gCompute;


#endif

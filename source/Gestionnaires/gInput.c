/*
------------------------------------------------------------
Copyright 2003-20xx Haute �cole ARC Ing�ni�rie, Switzerland. 
All rights reserved.
------------------------------------------------------------
Nom du fichier :	gInput.c
Auteur et Date :	Monnerat Serge 8.5.20xx

Description dans le fichier gInput.h
------------------------------------------------------------
*/


#include "gInput.h"
#include "gMBox.h"
#include "mSwitch.h"
#include "mAd.h"

//-----------------------------------------------------------------------------
// Configuration du gestionnaire
//-----------------------------------------------------------------------------
void gInput_Setup(void)
{
}

//-----------------------------------------------------------------------------
// Ex�cution du gestionnaire
//-----------------------------------------------------------------------------
void gInput_Execute(void)
{
  SwitchEnum i;
  
  // Lecture des interrupteurs
  for(i=kSw1;i<=kSw8;i++)
    {
      gInput.SwitchTab[i]= mSwitch_ReadSwitch(i);
    }
  
  // Lecture des entr�es analogiques
  gInput.TempCarte=mAd_Read(kTemp);
  gInput.P1=mAd_Read(kP1);
  gInput.P2=mAd_Read(kP2);
}

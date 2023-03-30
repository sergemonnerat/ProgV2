/*
------------------------------------------------------------
Copyright 2003-20xx Haute �cole ARC Ing�ni�rie, Switzerland. 
All rights reserved.
------------------------------------------------------------
Nom du fichier :	gCompute.c
Auteur et Date :	Monnerat Serge 8.5.20xx

Description dans le fichier gCompute.h
------------------------------------------------------------
*/


#include "gCompute.h"
#include "gMBox.h"

//-----------------------------------------------------------------------------
// Configuration du gestionnaire
//-----------------------------------------------------------------------------
void gCompute_Setup(void)
{
}

//-----------------------------------------------------------------------------
// Ex�cution du gestionnaire
//-----------------------------------------------------------------------------
void gCompute_Execute(void)
{
  unsigned int i;
  
  // Lecture des interrupteurs et affectation des erreurs
  for(i=0;i<kNbOfErr;i++)
    {
      gCompute.ErrTab[i]= gInput.SwitchTab[i];
    }
  
  // Conversion des entr�es analogiques,10mV par degr�: Umes/0.01, Umes*100
  gCompute.TempCarte=(gInput.TempCarte*(3.3/4096.0))*100.0;
  gCompute.P1=(float)(gInput.P1*(3.3/4096.0));
  gCompute.P2=(float)(gInput.P2*(3.3/4096.0));
}

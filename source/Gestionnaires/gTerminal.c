/*
------------------------------------------------------------
Copyright 2003-20xx Haute école ARC Ingéniérie, Switzerland. 
All rights reserved.
------------------------------------------------------------
Nom du fichier :	gTerminal.c
Auteur et Date :	Monnerat Serge 11.01.20xx

Description dans le fichier gTerminal.h
------------------------------------------------------------
*/


#include "mRs232.h"
#include "gMBox.h"
#include "gTerminal.h"
#include "stdio.h"

// Etat possible du terminal
typedef enum
{
  kTerminalInit,
  kPrintMenu,
  kWaitChar 
}TerminalStateEnum;

static TerminalStateEnum sTerminalState;

//-----------------------------------------------------------------------------
// Configuration du gestionnaire
//-----------------------------------------------------------------------------
void gTerminal_Setup(void)
{
  // Initialisation de la machine d'état
  sTerminalState=kTerminalInit;
}


//-----------------------------------------------------------------------------
// Exécution du gestionnaire
//-----------------------------------------------------------------------------
void gTerminal_Execute(void)
{
  UInt8 aRs232Buff[200];
  UInt8 aByte;
  UInt8 aByteCounter;
  UInt8 i;
  Int8 aAnaTab[5];
  
  // Machine d'état de la gestion du Terminal Windows
  switch (sTerminalState)
    {
      // Etat de départ dans lequel on attend un caractère (n'importe lequel)
      case kTerminalInit:
      
      // Contrôle si un caractère est reçu
      if(mRs232_ReadDataFromBuffer(aRs232Buff)==false)
        {
          // Prochain état
          sTerminalState=kPrintMenu;
        }
      break;
      
      // Affichage du menu
      case kPrintMenu:
        
        // Envoi de la commande permettant de remettre le curseur en haut à gauche
        // de l'écran --> ESC[H --> ESC = 0x1B
        mRs232_WriteChar(0x1B);
        mRs232_WriteChar('[');
        mRs232_WriteChar('H');
        
        // Ecriture du texte de base du terminal
        // Si l'on veut les caractères accentués il faut sélectionner
        // l'émulation TTY dans le terminal windows 
        mRs232_WriteString("*** Centrale d'alarme ***\r\n\n");
				mRs232_WriteString("Visualisation de l'état des erreurs, veuillez introduire le\r\n");
				mRs232_WriteString("numéro de l'erreur (0 à 7) ou visualisation des entrées analogiques (A):");
				// Envoi de la commande permettant d'effacer les caractères jusqu'au bout de la ligne
				//  --> ESC[K --> ESC = 0x1B
				mRs232_WriteChar(0x1B);
				mRs232_WriteChar('[');
				mRs232_WriteChar('K');
              
        aByteCounter=0;
        
        // Prochain état
        sTerminalState=kWaitChar;
      
      break;
      
      // Attente d'un caractère et affichage de l'état d'une alarme
      case kWaitChar:
      
        // Contrôle si un caractère est reçu
      	aByteCounter=0;
      	while(mRs232_ReadDataFromBuffer(&aByte)==false)
          {
            // Enregistrement du byte dans le buffer
            aRs232Buff[aByteCounter]=aByte;
            
            // Compteur de bytes reçus
            aByteCounter++;  
          }
      
				// Contrôle si un caractère entre 0 et 7 a été reçu 
				for(i=0;i<aByteCounter;i++)
					{
						if((aRs232Buff[i]>=0x30)&&(aRs232Buff[i]<=0x37))
							{
								mRs232_WriteChar(aRs232Buff[i]);
								mRs232_WriteString("\r\n\n");
								mRs232_WriteString("L'alarme ");
								mRs232_WriteChar(aRs232Buff[i]);
								if(gCompute.ErrTab[aRs232Buff[i]-0x30]==true)
									{
										mRs232_WriteString(" est ON ");
										// Envoi de la commande permettant d'effacer les caractères jusqu'au bout de la ligne
										//  --> ESC[K --> ESC = 0x1B
										mRs232_WriteChar(0x1B);
										mRs232_WriteChar('[');
										mRs232_WriteChar('K');
									}
								else
									{
										mRs232_WriteString(" est OFF");
										// Envoi de la commande permettant d'effacer les caractères jusqu'au bout de la ligne
										//  --> ESC[K --> ESC = 0x1B
										mRs232_WriteChar(0x1B);
										mRs232_WriteChar('[');
										mRs232_WriteChar('K');
									}
								
								// Envoi de la commande permettant d'effacer les lignes suivants la ligne courantes
								// Permet d'effacer les info des entrées analogiques
								//  --> ESC[J --> ESC = 0x1B
								mRs232_WriteChar(0x1B);
								mRs232_WriteChar('[');
								mRs232_WriteChar('J');
								
								// Prochain état
								sTerminalState=kPrintMenu;
							}
          
          // Caractère A --> Affichage des entrées analogiques
					if(aRs232Buff[i]=='A')
						{
							
							mRs232_WriteString("\r\n\nLa température de la carte est de ");
							sprintf(aAnaTab,"%4.1f",gCompute.TempCarte);
							mRs232_WriteString(aAnaTab);
							mRs232_WriteString(" degrés");
							// Envoi de la commande permettant d'effacer les caractères jusqu'au bout de la ligne
							//  --> ESC[K --> ESC = 0x1B
							mRs232_WriteChar(0x1B);
							mRs232_WriteChar('[');
							mRs232_WriteChar('K');
							mRs232_WriteString("\r\nLa valeur de P1 est de ");
							sprintf(aAnaTab,"%03.1f",gCompute.P1);
							mRs232_WriteString(aAnaTab);
							mRs232_WriteString(" V");
							// Envoi de la commande permettant d'effacer les caractères jusqu'au bout de la ligne
							//  --> ESC[K --> ESC = 0x1B
							mRs232_WriteChar(0x1B);
							mRs232_WriteChar('[');
							mRs232_WriteChar('K');
							mRs232_WriteString("\r\nLa valeur de P2 est de ");
							sprintf(aAnaTab,"%03.1f",gCompute.P2);
							mRs232_WriteString(aAnaTab);
							mRs232_WriteString(" V");
							// Envoi de la commande permettant d'effacer les caractères jusqu'au bout de la ligne
							//  --> ESC[K --> ESC = 0x1B
							mRs232_WriteChar(0x1B);
							mRs232_WriteChar('[');
							mRs232_WriteChar('K');
				
							// Prochain état
							sTerminalState=kPrintMenu;
						}
        }

      break;
    }
}

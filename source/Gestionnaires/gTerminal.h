/*
------------------------------------------------------------
Copyright 2003-20xx Haute école ARC Ingéniérie, Switzerland. 
All rights reserved.
------------------------------------------------------------
Nom du fichier : 	gTermminal.h	
Auteur et Date :	Monnerat Serge 8.5.20xx

But : Gestionnaire gérant la comm. Rs232 avec un terminal

Modifications
Date		Faite	Ctrl		Description
------------------------------------------------------------
*/

#ifndef GTERMINAL_H_
#define GTERMINAL_H_

//-----------------------------------------------------------------------------
// Configuration du gestionnaire
//-----------------------------------------------------------------------------
void gTerminal_Setup(void);

//-----------------------------------------------------------------------------
// Exécution du gestionnaire
//-----------------------------------------------------------------------------
void gTerminal_Execute(void);


#endif

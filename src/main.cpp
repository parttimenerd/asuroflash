/***************************************************************************
             Con_Flash.cpp  -  Console Flash Applikation for ASURO
                             -------------------
    begin                : Die Aug 12 10:16:57 CEST 2003
    copyright            : (C) 2003 DLR RM by Jan Grewe
    email                : jan.grewe@dlr.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 +   any later version.                                                    *
 *                                                                         *
 ***************************************************************************/

/***************************************************************************
	Ver      date       Author        comment
	--------------------------------------------------------------------------
	1.0   12.08.2003    Jan Grewe     build
 ***************************************************************************/ 
#include "ANSIAsuro.h"

#include <stdio.h>
#include <string.h>

#include <iostream>


CANSIAsuro Asuro;

int main(int argc, char* argv[])
{
    std::cout << LICENSE << std::endl;
    std::cout << std::endl << ASUROAbout << std::endl;
    std::cout << "Linux Version" << std::endl << std::endl;
    Asuro.m_ASUROIniPath[0] = '\0';
    strcat(Asuro.m_ASUROIniPath,"AsuroFl.ini");

    if (argc != 3) {
        std::cout << "too many arguments !!" << std::endl << std::endl;
        std::cout << "usage : " << argv[0] << " [port, e.g. /dev/ttyUSB0] [hex file]\n";
        // Write no ini File
        Asuro.m_ASUROIniPath[0] = '\0';
        return -1;
    }
    /*if (argc == 1) {
        if (Asuro.InitCAsuro() == false) {
            std::cout << "Can't find ini file !!" << std::endl << std::endl;
            std::cout << "usage : " << argv[0];
            showHelp();
            // Write no ini File
            Asuro.m_ASUROIniPath[0] = '\0';
            return -1;
        }
        else {
            std::cout << "Start ASURO Flash on " << Asuro.m_ASUROCOMPort <<
                " flashing " << Asuro.m_ASUROfileName << std::endl;
            Asuro.InitCAsuro();
        }
    }*/
    if (argc == 3) {
		strcpy(Asuro.m_ASUROCOMPort,argv[1]);
		strcpy(Asuro.m_ASUROfileName,argv[2]);
    }
	Asuro.Programm();
	return 0;
}

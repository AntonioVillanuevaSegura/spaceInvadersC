#include "menus.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
menus::menus(){//Constructor de la clase ,carga letras lineas ...
	wxString directorio;
	wxImage img;
	for (char num=0;num<10;num++){//Carga imagenes correspondientes a los numeros
		directorio=dir+".xpm";
		img.LoadFile(directorio, wxBITMAP_TYPE_XPM);//Carga una imagen
		imagenes.push_back(img);
	}
}
/********************************************************************************/
wxBitmap menus::asciiToimage(char c){//Una ascii una imagen 
	wxBitmap img;
	return img;
}



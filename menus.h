#ifndef MENUS_H
#define MENUS_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>//wxPoint
#include <vector> 
#include <wx/dcmemory.h>


using namespace std;
#define dir "./spaceInvaders/"
/********************************************************************************/
/********************************************************************************/
class menus{
	vector <wxImage> imagenes;//Carga imagenes disponibles 
	
	public:
	menus();//Constructor de la clase ,carga letras lineas ...
	void cargaFicheros(wxString directorio) ;//Carga la lista de nombres de ficheros a cargar 
	wxBitmap asciiToimage(char c);//Una letra a una imagen
};

/***************************  DEFINICIONES  *************************************/
#include "menus.cpp"
/********************************************************************************/
#endif

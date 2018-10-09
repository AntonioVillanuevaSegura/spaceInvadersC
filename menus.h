#ifndef MENUS_H
#define MENUS_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>//wxPoint
#include <vector> 
#include <wx/dcmemory.h>


using namespace std;
#define dir "./spaceInvaders/"
struct base {wxImage img;char ref;};//Estructura con referencias del tipo de elemento
/********************************************************************************/
/********************************************************************************/
class menus{
	vector <base> imagenes;//Carga imagenes disponibles 
    wxImage caracter;//cargar  imagenes 
    wxBitmap resize;	
	int factor;//factor de ampliacion en la reescala    
	
	public:
	menus();//Constructor de la clase ,carga letras lineas ...
	void cargaFicheros(wxString directorio) ;//Carga la lista de nombres de ficheros a cargar 
	wxBitmap asciiToimage(char c);//Una ascii  devuelve su imagen correspondiente
	void stringToImage(wxString texto,wxDC& dc);//"SCORE<1> HI-SCORE SCORE<2>"
	void cargaImagenes(char c);//Carga imagenes en el vector desde su char correspondiente
	wxImage resized(wxImage caracter);//Reescala marciano , la base es el tamano real en xpm	
};

/***************************  DEFINICIONES  *************************************/
#include "menus.cpp"
/********************************************************************************/
#endif

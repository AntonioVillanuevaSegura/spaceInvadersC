#ifndef MENUS_H
#define MENUS_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>//wxPoint
#include <vector> 
#include <wx/dcmemory.h>
#include <string>


using namespace std;
#define dir "./spaceInvaders/"
struct base {wxImage img;wxString ref;};//Estructura con referencias del tipo de elemento
/********************************************************************************/
/********************************************************************************/
class menus{
	vector <base> imagenes;//Carga imagenes disponibles 
    wxImage caracter;//cargar  imagenes 
    wxBitmap resize;	
	int factorPto;//factor de ampliacion en la reescala    
	int factorA;//factor de ampliacion en la reescala 	
	public:
	menus();//Constructor de la clase ,carga letras lineas ...
	void cargaFicheros(wxString directorio) ;//Carga la lista de nombres de ficheros a cargar 
	wxBitmap asciiToimage(char c);//Una ascii  devuelve su imagen correspondiente
	void stringToImage(wxString texto,wxDC& dc,int x=0,int y=0);//"SCORE<1> HI-SCORE SCORE<2>"
	void cargaImagenes(wxString c);//Carga imagenes en el vector desde su char correspondiente
	wxImage resized(wxImage caracter);//Reescala marciano , la base es el tamano real en xpm	
	void scores(int A,int B,wxDC& dc,int x=0,int y=0);//Escribe scores
};

/***************************  DEFINICIONES  *************************************/
#include "menus.cpp"
/********************************************************************************/
#endif

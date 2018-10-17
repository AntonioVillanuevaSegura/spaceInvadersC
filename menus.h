#ifndef MENUS_H
#define MENUS_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>//wxPoint
#include <vector> 
#include <wx/dcmemory.h>
#include <string>
#include <wx/dir.h> //ver directorios ficheros

using namespace std;
#define DIRECTORIO "./spaceInvaders/"
struct base {wxImage img;wxString ref;};//Estructura con referencias del tipo de elemento
/********************************************************************************/
/********************************************************************************/
class menus{
	vector <base> imagenes;//Carga imagenes disponibles 	
    wxImage caracter;//cargar  imagenes 	
	
	public:
	menus();//Constructor de la clase ,carga imagenes 
	wxBitmap asciiToimage(wxString nombre);//Una ascii  devuelve su imagen correspondiente
	void stringToImage(wxString texto,wxDC& dc,int x=40,int y=0);//"SCORE<1> HI-SCORE SCORE<2>"	
	void scores(int A,int B,wxDC& dc,int x=0,int y=0);//Escribe scores
	void dibujaLinea(int x,int y,int xx,int yy,wxDC& dc);//Dibuja una linea de origen x,y y fin xx,yy
	bool cargaImagenes();//Carga imagenes juego ... 88 imagenes  
	wxImage buscaImagen(wxString nombre);//Busca en el vector de imagenes por su nombre 
	
	void pantallaJuego(int scoreA,int scoreB ,wxDC& dc);//Dibuja textos pantalla principal
};

/***************************  DEFINICIONES  *************************************/
#include "menus.cpp"
/********************************************************************************/
#endif

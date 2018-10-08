//Define un marciano ,su(s) imagenes ,vida ,posicion 
/***************************  DECLARACIONES *************************************/
/********************************************************************************/
#ifndef MARCIANOS_H
#define MARCIANOS_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>//wxPoint
#include <vector> 
#include <wx/dcmemory.h>
using namespace std;
#define dir "./spaceInvaders/"

/********************************************************************************/
/********************************************************************************/
class Marciano{
	
    wxImage marciano;//cargar  imagenes 
    wxBitmap resize;
	wxPoint pt;//Posicion marciano
	bool vivo;//Esta vivo o muerto ?
	int factor;//factor de ampliacion
	
	public:
	
	Marciano();
	Marciano(wxString file, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor 
	wxImage getImagen();
	wxPoint getPosicion();
	void setPosicion();	
	bool getVivo();
	wxImage resized();//Reescala marcianos

};
/***************************  DEFINICIONES  *************************************/
#include "marcianos.cpp"
/********************************************************************************/
#endif

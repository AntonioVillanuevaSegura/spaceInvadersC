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
/********************************************************************************/
/********************************************************************************/
class Marciano{
	protected:
    wxImage marcianoA,marcianoB,explosion;//cargar  imagenes 
    wxBitmap resize;
	wxPoint pt;//Posicion marciano
	wxPoint disparo;//Posicion del disparo
	bool vivo;//Esta vivo o muerto ?
	int factor;//factor de ampliacion en la reescala
	
	public:
	Marciano();
	Marciano(wxImage posA,wxImage posB,wxImage exp, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor B		
	bool getVivo();
	void setVivo(bool estado);//vivo =true o false	
	wxImage getImagen(bool img);//Utiliza imgA o imgB segun bool
	wxPoint getPosicion();
	void DebugMarciano();//Para ver informacion 	
	void setPosicion(wxPoint pto);	
};
/***************************  DEFINICIONES  *************************************/
#include "marcianos.cpp"
/********************************************************************************/
#endif

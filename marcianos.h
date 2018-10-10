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
#define AMPLIACION_IMAGEN 5

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
	Marciano(wxString posA,wxString posB,wxString exp, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor 	
	bool getVivo();
	void setVivo(bool estado);//vivo =true o false	
	wxImage getImagen(bool img);//Utiliza imgA o imgB segun bool
	wxPoint getPosicion();
	void DebugMarciano();//Para ver informacion 	
	void setPosicion(wxPoint pto);	
	wxImage resized(wxImage marciano);//Reescala marcianos	


};
/***************************  DEFINICIONES  *************************************/
#include "marcianos.cpp"
/********************************************************************************/
#endif

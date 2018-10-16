#include "marcianos.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
Marciano::Marciano(wxImage posA,wxImage posB,wxImage exp, wxPoint pt,wxBitmapType format)://Constructor B
marcianoA(posA),marcianoB(posB),explosion(exp)
{
	this->pt=pt;
	vivo=true; 
}
/********************************************************************************/
wxImage Marciano::getImagen(bool img){return img ? marcianoA :marcianoB;}////Utiliza imgA o imgB segun bool
/********************************************************************************/	
wxPoint Marciano::getPosicion(){ return pt;}
/********************************************************************************/
void Marciano::setPosicion(wxPoint pto){this->pt=pto;}
/********************************************************************************/	
bool Marciano::getVivo(){return vivo;}
/********************************************************************************/	
void Marciano::setVivo(bool estado){vivo=estado;}//vivo =true o false

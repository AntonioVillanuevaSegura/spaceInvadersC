#include "marcianos.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
Marciano::Marciano(wxImage posA,wxImage posB,wxImage exp, wxPoint pt,wxBitmapType format)://Constructor B
marcianoA(posA),marcianoB(posB),explosion(exp),persistencia(10)
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
/********************************************************************************/	
bool Marciano::Persistencia() {//Mientras que este activo se muestra la explosion
	if (persistencia-- >0){return true;}
	return false;
}
/********************************************************************************/
void Marciano::setPersistencia(int p){persistencia=p;}//Valor persistencia por defecto

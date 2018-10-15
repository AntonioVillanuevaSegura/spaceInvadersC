#include "marcianos.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/

Marciano::Marciano(wxString posA,wxString posB,wxString exp,  wxPoint pt,wxBitmapType format){//Constructor A
	this->pt=pt;
	vivo=true; 
	marcianoA.LoadFile(posA, format);	//Carga el fichero imagen

	marcianoB.LoadFile(posB, format);	//Carga el fichero imagen

	explosion.LoadFile(exp, format);	//Carga el fichero imagen

    //if (marcianoA.IsOk()){cout<<" OK LOADING IMAGE "<<endl;}
}

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
void Marciano::DebugMarciano(){//Para ver informacion 
	cout <<" x ="<<getPosicion().x<<" , y = "<<getPosicion().y<<" --disp= "<<
	disparo.x<<", "<<disparo.y<<endl;
}

void Marciano::setVivo(bool estado){vivo=estado;}//vivo =true o false

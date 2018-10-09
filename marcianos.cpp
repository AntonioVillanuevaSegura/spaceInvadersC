#include "marcianos.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
Marciano::Marciano(wxString posA,wxString posB,wxString exp,  wxPoint pt,wxBitmapType format){//Constructor
	factor=5;
	this->pt=pt;
	vivo=true; 
	marcianoA.LoadFile(posA, format);	//Carga el fichero imagen
	marcianoA=resized(marcianoA);//Reescala las figuras 
	
	marcianoB.LoadFile(posB, format);	//Carga el fichero imagen
	marcianoB=resized(marcianoB);//Reescala las figuras 
	
	explosion.LoadFile(exp, format);	//Carga el fichero imagen
	explosion=resized(marcianoA);//Reescala las figuras 
	
	
    //if (marcianoA.IsOk()){cout<<" OK LOADING IMAGE "<<endl;}
}
/********************************************************************************/
wxImage Marciano::getImagen(){return pt.x%2!=0 ? marcianoA :marcianoB;}
/********************************************************************************/	
wxPoint Marciano::getPosicion(){ return pt;}
/********************************************************************************/
void Marciano::setPosicion(wxPoint pto){this->pt=pto;}
/********************************************************************************/	
bool Marciano::getVivo(){return vivo;}
/********************************************************************************/	
wxImage Marciano::resized(wxImage marciano){//Reescala marciano , la base es el tamano real en xpm
		//int factor (4); //Multiplica el tamano por este valor 
		resize = wxBitmap( marciano.Scale( marciano.GetWidth () *factor,
											marciano.GetHeight ()*factor
											/*, wxIMAGE_QUALITY_HIGH*/ ) );
       
       marciano=resize.ConvertToImage();
return marciano;//devuelve un wxImage
}
/********************************************************************************/	
void Marciano::DebugMarciano(){//Para ver informacion 
	cout <<" x ="<<getPosicion().x<<" , y = "<<getPosicion().y<<" --disp= "<<
	disparo.x<<", "<<disparo.y<<endl;
}

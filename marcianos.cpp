#include "marcianos.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
Marciano::Marciano(wxString file,  wxPoint pt,wxBitmapType format){//Constructor
	factor=5;
	this->pt=pt;
	vivo=true; 
	marciano.LoadFile(file, format);	//Carga el fichero 
	resized();//Reescala las figuras 
    if (marciano.IsOk()){cout<<" OK LOADING IMAGE "<<endl;}
}
/********************************************************************************/
wxImage Marciano::getImagen(){return marciano;}
/********************************************************************************/	
wxPoint Marciano::getPosicion(){ return pt;}
/********************************************************************************/	
bool Marciano::getVivo(){return vivo;}
/********************************************************************************/	
wxImage Marciano::resized(){//Reescala marciano , la base es el tamano real en xpm
		//int factor (4); //Multiplica el tamano por este valor 
		resize = wxBitmap( marciano.Scale( marciano.GetWidth () *factor,
											marciano.GetHeight ()*factor
											/*, wxIMAGE_QUALITY_HIGH*/ ) );
       
       marciano=resize.ConvertToImage();
return marciano;//devuelve un wxImage
}


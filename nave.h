#ifndef NAVES_H
#define NAVES_H
#include "marcianos.h"
/********************************************************************************/
/********************************************************************************/
class Nave: public Marciano {
	public:
	//Nave (wxString posA,wxString posB,wxString exp, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor de nave 
	Nave();
	Nave(wxImage posA,wxImage posB,wxImage exp, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor B	
};
/***************************  DEFINICIONES  *************************************/
#include "nave.cpp"
/********************************************************************************/
#endif

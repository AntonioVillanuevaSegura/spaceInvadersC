#ifndef DISPAROS_H
#define DISPAROS_H
#include "disparos.h"

#include <wx/wx.h>
#include <vector>

struct bala{wxPoint pto;bool entidad;};
/********************************************************************************/
/********************************************************************************/
class disparos{
	vector <bala> disp;
	
	public:	
	disparos();

	//debe cargar disparos y explosion .... 
	//debe detectar choque de misiles 
	//disparos (wxString p,wxString posB,wxString exp, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor de nave 
};
/***************************  DEFINICIONES  *************************************/
#include "disparos.cpp"
/********************************************************************************/
#endif


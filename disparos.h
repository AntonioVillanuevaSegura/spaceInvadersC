#ifndef DISPAROS_H
#define DISPAROS_H
#include "disparos.h"

#include <wx/wx.h>
#include <vector>

struct bala{wxPoint pto;bool entidad} 
/********************************************************************************/
/********************************************************************************/
class disparos: {
	vector <bala> disp;
	public:
	
	disparos();
	//Nave (wxString posA,wxString posB,wxString exp, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor de nave 
};
/***************************  DEFINICIONES  *************************************/
#include "disparos.cpp"
/********************************************************************************/
#endif


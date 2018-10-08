//motor del juego principal encargado de dibujar y gestionar el juego 
/***************************  DECLARACIONES *************************************/
/********************************************************************************/
#ifndef JUEGO_H
#define JUEGO_H
#include "marcianos.h"

class Juego :public wxPanel{
	public:
	Juego (wxFrame* parent);
	
	//Dibujo
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);
    wxPoint creaPos(int n);//crea coordenadas marciano
		
	private:
    wxImage pantalla;//imagen de la pantalla
    wxBitmap resized;  
    int w, h;//Tamano pantalla
    wxPoint pto;//Ultima coordenada de un marciano
    int creados;//N de marcianos a creas
    int factor ;//factor multiplicador
    vector <Marciano> marcianos;//Vector contiene todos los Marcianos
  
	    DECLARE_EVENT_TABLE()
};
/********************************************************************************/
BEGIN_EVENT_TABLE(Juego, wxPanel)
	EVT_PAINT(Juego::paintEvent)
	EVT_SIZE(Juego::OnSize)
END_EVENT_TABLE()

/***************************  DEFINICIONES  *************************************/
#include "juego.cpp"
/********************************************************************************/
#endif

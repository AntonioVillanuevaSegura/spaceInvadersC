//motor del juego principal encargado de dibujar y gestionar el juego 
/***************************  DECLARACIONES *************************************/
/********************************************************************************/
#ifndef JUEGO_H
#define JUEGO_H
#include "marcianos.h"
#include "menus.h"
#include <wx/timer.h> //timer

const wxPoint PuntoBase(2,2);//Primera coordenada de un marciano

class Juego :public wxPanel{
	public:
	Juego (wxFrame* parent); //Constructor del Juego
	
	//Dibujo
	void OnTimer(wxTimerEvent& event);//Timer
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);
    wxPoint creaPos(wxPoint pto);//crea coordenadas marciano construccion
    bool limites();//Han llegado a la derecha o a la izquierda los marcianos ?
    bool limiteInferior();//Han llegado abajo ? Han ganado los marcianos ?    
		
	private:
	wxTimer m_timer;
    wxImage pantalla;//imagen de la pantalla
    wxBitmap resized;  
    int w, h;//Tamano pantalla
    int score1,score2;//Puntos a enviar a menus 
    wxPoint pto;//Ultima coordenada de un marciano o referencia grupo
    int creados;//N de marcianos a creas
    int factor ;//factor multiplicador
    vector <Marciano> marcianos;//Vector contiene todos los Marcianos
    menus menu;//Intancia del menu de fondo
    bool sentido;//sentido del movimiento de los marcianos
  
	    DECLARE_EVENT_TABLE()
};
/********************************************************************************/
wxWindowIDRef TIMER_ID=wxWindow::NewControlId();//Obtiene un numero ID para el timer

BEGIN_EVENT_TABLE(Juego, wxPanel)
	EVT_TIMER(TIMER_ID, Juego::OnTimer)
	EVT_PAINT(Juego::paintEvent)
	EVT_SIZE(Juego::OnSize)
END_EVENT_TABLE()

/***************************  DEFINICIONES  *************************************/
#include "juego.cpp"
/********************************************************************************/
#endif

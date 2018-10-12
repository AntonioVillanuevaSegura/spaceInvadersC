//motor del juego principal encargado de dibujar y gestionar el juego 
/***************************  DECLARACIONES *************************************/
/********************************************************************************/
#ifndef JUEGO_H
#define JUEGO_H
#include "marcianos.h"
#include "nave.h"
#include "menus.h"
#include <wx/timer.h> //timer
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>
//#include <wx/brush>

const wxPoint PuntoBase(70,160);//Primera coordenada de un marciano

class Juego :public wxPanel{
	public:
	Juego (wxFrame* parent); //Constructor del Juego
	
	//Dibujo
	void OnTimer(wxTimerEvent& event);//Timer
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void OnTecla(wxKeyEvent& event);//Evento teclas ...
    void render(wxDC& dc);
    wxPoint creaPos(wxPoint pto);//crea coordenadas marciano construccion
    bool limites();//Han llegado a la derecha o a la izquierda los marcianos ?
    bool limiteInferior();//Han llegado abajo ? Han ganado los marcianos ?   
	void disparoNave(bool disparo=false);//Gestiona el disparo de la nave
		
	private:
	wxTimer m_timer;
	Nave nave;//Una nave ....	
    wxImage pantalla;//imagen de la pantalla
    wxBitmap resized;  
    int marcianoTimer;
    int w, h;//Tamano pantalla
    int score1,score2;//Puntos a enviar a menus 
    wxPoint pto;//Ultima coordenada de un marciano o referencia grupo
    int creados;//N de marcianos a creas
    int factor ;//factor multiplicador
    vector <Marciano> marcianos;//Vector contiene todos los Marcianos
    //Disparos de los marcianos
    vector <wxPoint> naveDisp;
    vector <wxPoint> marcianoDisp;    
    
    menus menu;//Intancia del menu de fondo
    bool sentido;//sentido del movimiento de los marcianos
    bool imgActual;//imagen que utiliza el marciano imgA o imgB
    void resetMarcianos();//Posicion inicial ,vidas ..
    void ctrlNave(int ctrl);//Controla 1 izq 2 der 3 dispara 
    wxClientDC clienteDC;

  
	    DECLARE_EVENT_TABLE()
};
/********************************************************************************/
wxWindowIDRef TIMER_ID=wxWindow::NewControlId();//Obtiene un numero ID para el timer

BEGIN_EVENT_TABLE(Juego, wxPanel)
	EVT_TIMER(TIMER_ID, Juego::OnTimer)
	EVT_PAINT(Juego::paintEvent)
	EVT_SIZE(Juego::OnSize)
	EVT_CHAR(Juego::OnTecla)//Lee el teclado ...evento
END_EVENT_TABLE()

/***************************  DEFINICIONES  *************************************/
#include "juego.cpp"
/********************************************************************************/
#endif

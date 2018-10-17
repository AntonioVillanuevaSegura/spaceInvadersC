//motor del juego principal encargado de dibujar y gestionar el juego 
/***************************  DECLARACIONES *************************************/
/********************************************************************************/
#ifndef JUEGO_H
#define JUEGO_H
#include "menus.h"
#include "marcianos.h"
#include "nave.h"
#include "disparos.h"
#include <wx/timer.h> //timer
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>
//#include <wx/brush>
//#include <wx/dir.h> //ver directorios ficheros

#define VELOCIDAD_MARCIANOS 30

/****************************************************************************/	
const wxPoint PuntoBase(70,160);//Primera coordenada de un marciano
/****************************************************************************/	
class Juego :public wxPanel{
	public:
	Juego (wxFrame* parent); //Constructor del Juego
		
	private:
	wxTimer m_timer;	
	void OnTimer(wxTimerEvent& event);//Timer 
    int marcianoTimer;
    int velocidadMarcianos;//Cada vez descienden a mas velocidad	
	
	//Dibujo
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);	


    int score1,score2;//Puntos a enviar a menus 
    int vidas1,vidas2;//Vidas de cada jugador empieza a 3
    wxPoint pto;//Ultima coordenada de un marciano o referencia grupo
    
    vector <Marciano> marcianos;//Vector contiene todos los Marcianos
    wxPoint creaPos(wxPoint pto);//crea coordenadas marciano construccion    
    bool limites();//Han llegado a la derecha o a la izquierda los marcianos ?
    bool limiteInferior();//Han llegado abajo ? Han ganado los marcianos ?  
        
    vector <wxPoint> naveDisp;//Disparos nave 
    vector <wxPoint> marcianoDisp;//Disparos marcianos  
    vector <base> gameImg;//Imagenes del juego  
    
    menus *menu;//Intancia del menu de fondo
    bool sentido;//sentido del movimiento de los marcianos
    bool imgActual;//imagen que utiliza el marciano imgA o imgB
    void resetMarcianos();//Posicion inicial ,vidas ..
    
    void OnTecla(wxKeyEvent& event);//Evento teclas ...
    void ctrlNave(int ctrl);//Controla movimiento nave 1 izq 2 der 3 dispara 
    void disparoNave(bool disparo=false);//Gestiona el disparo de la nave
	bool colision(wxPoint a,wxPoint b);//Objetos o puntos en colision ?  
    bool colisionObjeto(Marciano& objeto,vector<wxPoint>& v);//Un objeto marciano o derivado toca un wxPoint	  

    wxClientDC clienteDC;
    
    Nave *nave;//Una nave ....	
  
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

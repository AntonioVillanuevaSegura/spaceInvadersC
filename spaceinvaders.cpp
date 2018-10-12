//Antonio Villanueva Segura  una version de spaceinvaders

#include "juego.h"//Clase con el motor del juego 
using namespace std;

/********************************************************************************/
/********************************************************************************/
// Arranque en wxWidgets 
class Run: public wxApp
{
    wxFrame *frame;
    Juego* panelDibujo;
    
public:

	//Main wxWidgetss
    bool OnInit()
    {
        // Primero inicializamos todos los Handlers graficos 
        wxInitAllImageHandlers();
 
		//Crea el frame
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        frame = new wxFrame(NULL, wxID_ANY, wxT("Space Invaders"), wxPoint(50,50), wxSize(1200,800),wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER);//Frame
        // Panel de dibujo ,llama el constructor de wxImagePanel que carga una imagen ....
        panelDibujo = new Juego( frame);
        sizer->Add(panelDibujo, 1, wxEXPAND,wxFIXED_MINSIZE);//Fondo pantalla ;

        frame->SetSizer(sizer);
        frame->Show();
        return true;
    } 
};
 
IMPLEMENT_APP(Run)

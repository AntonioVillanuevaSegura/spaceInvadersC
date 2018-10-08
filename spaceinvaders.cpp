/*
#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>//wxPoint
#include <vector> 
#include <wx/dcmemory.h>
*/
#include "marcianos.h"//Clase que define el marciano
#include "juego.h"//Clase con el motor del juego 
using namespace std;
//#define dir "./spaceInvaders/"

/********************************************************************************/
/********************************************************************************/
// Arranque en wxWidgets 
class Run: public wxApp
{
    wxFrame *frame;
    Juego* panelDibujo;
public:
    bool OnInit()
    {
        // Primero inicializamos todos los Handlers graficos 
        wxInitAllImageHandlers();
 
		//Crea el frame
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        frame = new wxFrame(NULL, wxID_ANY, wxT("Space Invaders"), wxPoint(50,50), wxSize(800,600));//Frame

        // Panel de dibujo ,llama el constructor de wxImagePanel que carga una imagen ....
        panelDibujo = new Juego( frame);
        sizer->Add(panelDibujo, 1, wxEXPAND);//Fondo pantalla 

        frame->SetSizer(sizer);
 
        frame->Show();
        return true;
    } 
 
};
 
IMPLEMENT_APP(Run)

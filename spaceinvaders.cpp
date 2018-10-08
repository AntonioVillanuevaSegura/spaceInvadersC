//http://computerarcheology.com/Arcade/SpaceInvaders/Code.html
//https://perso.esiee.fr/~perretb/I3FM/POO1/projet/index.html
//http://spaceinvaders.wikia.com/wiki/Space_Invaders
//http://gamecodeschool.com/android/coding-a-space-invaders-game

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
        frame = new wxFrame(NULL, wxID_ANY, wxT("Space Invaders"), wxPoint(50,50), wxSize(1000,800),wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER);//Frame

        // Panel de dibujo ,llama el constructor de wxImagePanel que carga una imagen ....
        panelDibujo = new Juego( frame);
        sizer->Add(panelDibujo, 1, wxEXPAND,wxFIXED_MINSIZE);//Fondo pantalla 

        frame->SetSizer(sizer);
 
        frame->Show();
        return true;
    } 
 
};
 
IMPLEMENT_APP(Run)

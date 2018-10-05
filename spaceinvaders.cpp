#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>//wxPoint
#include <vector> 
#include <wx/dcmemory.h>
using namespace std;
#define dir "./spaceInvaders/"
/********************************************************************************/
class Marciano{
	
    wxImage marciano;//cargar dos imagenes 
    wxBitmap resize;
	wxPoint pt;//Posicion marciano
	bool vivo;//Esta vivo o muerto ?
	int factor;//factor de ampliacion
	
	public:
	
	Marciano();
	Marciano(wxString file, wxPoint pt,wxBitmapType format=wxBITMAP_TYPE_XPM);//Constructor 
	wxImage getImagen();
	wxPoint getPosicion();
	void setPosicion();	
	bool getVivo();
	wxImage resized();//Reescala marcianos

};
/********************************************************************************/

Marciano::Marciano(wxString file,  wxPoint pt,wxBitmapType format){//Constructor
	factor=5;
	this->pt=pt;
	vivo=true; 
	marciano.LoadFile(file, format);	//Carga el fichero 
	resized();//Reescala las figuras 
    if (marciano.IsOk()){cout<<" OK LOADING IMAGE "<<endl;}
}
/********************************************************************************/
wxImage Marciano::getImagen(){return marciano;}
/********************************************************************************/	
wxPoint Marciano::getPosicion(){ return pt;}
/********************************************************************************/	
bool Marciano::getVivo(){return vivo;}
/********************************************************************************/	
wxImage Marciano::resized(){//Reescala marciano
		//int factor (4); //Multiplica el tamano por este valor 
		resize = wxBitmap( marciano.Scale( marciano.GetWidth () *factor,
											marciano.GetHeight ()*factor
											/*, wxIMAGE_QUALITY_HIGH*/ ) );
       
       marciano=resize.ConvertToImage();
return marciano;//devuelve un wxImage
}

/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
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
 
/********************************************************************************/
/********************************************************************************/
Juego::Juego (wxFrame* parent):wxPanel(parent){
	//pantalla= wxImage(800,600,false);//Crea un fondo de pantalla 
	factor=10*7;
	pantalla.Create(800,600,true);//Crea un fondo de pantalla negro
	
	for (int n=1;n<=12;n++){//Crea 12
		marcianos.push_back(Marciano(dir"Alien1.xpm",creaPos(n)));//Crea vector marcianos
		//cout <<"pos " <<creaPos(n).x <<","<<creaPos(n).x<<endl;		
		//cout <<"pos x =" <<marcianos[n-1].getPosicion().x<<endl;
		//cout <<"pos y =" <<marcianos[n-1].getPosicion().y<<endl;		
	}
	
	if (pantalla.IsOk()){cout<<" OK FONDO PANTALLA "<<endl;}//test
	
	w = -1;
    h = -1;
}
/********************************************************************************/
	//Dibujo
void Juego::paintEvent(wxPaintEvent & evt){
	wxPaintDC dc(this);
    render(dc);
}
/********************************************************************************/
void Juego::paintNow(){
	
	wxClientDC dc(this);
    render(dc);
}
/********************************************************************************/
void Juego::OnSize(wxSizeEvent& event){
    Refresh();
    event.Skip();	
}
/********************************************************************************/
void Juego::render(wxDC& dc){
	int neww, newh;
    dc.GetSize( &neww, &newh );
    
    //Copia marcianos en la pantalla  wxDC
    for (int n=0;n<=11;n++){
		dc.DrawBitmap(marcianos[n].getImagen(),
		marcianos[n].getPosicion(),true); //ok pinta en dc
	}

}
/********************************************************************************/
wxPoint Juego::creaPos(int n){//crea coordenadas marciano
	int x(n*factor);
	//int y(n*factor);	
	int y(0);
	
	return wxPoint (x,y);
}
/********************************************************************************/
/********************************************************************************/
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
        // Primero inicializamos todos los Handlers 
        wxInitAllImageHandlers();
 
		//Crea el frame
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        //wxFrame (wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos=wxDefaultPosition, const wxSize &size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE, const wxString &name=wxFrameNameStr)
        frame = new wxFrame(NULL, wxID_ANY, wxT("Space Invaders"), wxPoint(50,50), wxSize(800,600));//Frame

        // Panel de dibujo ,llama el constructor de wxImagePanel que carga una imagen
        //panelDibujo = new wxImagePanel( frame, wxT("./spaceInvaders/37.xpm"), wxBITMAP_TYPE_XPM);
        panelDibujo = new Juego( frame);
        sizer->Add(panelDibujo, 1, wxEXPAND);//Fondo pantalla 

        frame->SetSizer(sizer);
 
        frame->Show();
        return true;
    } 
 
};
 
IMPLEMENT_APP(Run)

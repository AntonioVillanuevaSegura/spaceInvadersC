
#include "juego.h"
/********************************************************************************/
/********************************************************************************/
Juego::Juego (wxFrame* parent):wxPanel(parent), m_timer(this, TIMER_ID){
	
	m_timer.Start(1000); // Intervalo de 1 segundo en el timer

	factor=10*7;
	pantalla.Create(800,600,true);//Crea un fondo de pantalla negro
	
	for (int n=1;n<=12;n++){//Crea 1era. linea
		marcianos.push_back(Marciano(dir"Alien3.xpm",dir"Alien3b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=13;n<=24;n++){//Crea 2a. linea
		marcianos.push_back(Marciano(dir"Alien1.xpm",dir"Alien1b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=25;n<=36;n++){//Crea 3a. linea
		marcianos.push_back(Marciano(dir"Alien1.xpm",dir"Alien1b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=37;n<=48;n++){//Crea 4a. linea
		marcianos.push_back(Marciano(dir"Alien0.xpm",dir"Alien0b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	for (int n=49;n<=60;n++){//Crea 5a. linea
		marcianos.push_back(Marciano(dir"Alien0.xpm",dir"Alien0b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}	
	
	
	if (pantalla.IsOk()){cout<<" OK FONDO PANTALLA "<<endl;}//test
	
	w = -1;
    h = -1;
}

void Juego::OnTimer(wxTimerEvent& event) //TIMER 1 SEGUNDO
{
   for (auto et:marcianos){
		//dc.DrawBitmap(et.getImagen(),et.getPosicion()*factor,true);
		//Mueve marciano

	}
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
    
    //Copia marcianos desde el vector hasta la pantalla  wxDC
    for (auto et:marcianos){
		dc.DrawBitmap(et.getImagen(),et.getPosicion()*factor,true);
	}
}
/********************************************************************************/
wxPoint Juego::creaPos(wxPoint pt){//crea coordenadas marciano

	if (pt.x<12){ pt.x++; }
	else {
		pt.x=1 ;//Coordenada x del primer marciano
		pt.y++;}//Salta una linea
		
	//La correccion la efectuamos en el momento de imprimir la imagen en render 	
	//pt.x*=factor;//correccion en funcion del factor de ampliacion
	//pt.y*=factor;//correccion en funcion del factor de ampliacion

	return pt;
}


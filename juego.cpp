
#include "juego.h"
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


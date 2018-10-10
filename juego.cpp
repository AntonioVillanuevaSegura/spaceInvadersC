
#include "juego.h"


/********************************************************************************/
/********************************************************************************/
Juego::Juego (wxFrame* parent):wxPanel(parent), m_timer(this, TIMER_ID){ //Constructor del Juego
	
	
	//parent->SetForegroundColour(wxColour(* wxBLACK));
	//parent->SetBackgroundColour(wxColour(* wxBLACK));	

	m_timer.Start(1000); // Intervalo de 1 segundo en el timer	
	pto=PuntoBase;//Primer marciano posicion 

	factor=SEPARACION_OBJETOS_B;//Factor de adaptacion ,ampliacion 
	
	//pantalla.Create(1200,800,false);//Crea un fondo de pantalla negro
	
	//Crea un vector de marcianos con sus coordenadas	
	//Crea 11 marcianos por linea 11*5= 55 total
	for (int n=1;n<=11;n++){//Crea 1era. linea
		marcianos.push_back( Marciano(dir"Alien3.xpm",dir"Alien3b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}

	for (int n=12;n<=22;n++){//Crea 2a. linea
		marcianos.push_back(Marciano(dir"Alien1.xpm",dir"Alien1b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=23;n<=33;n++){//Crea 3a. linea
		marcianos.push_back(Marciano(dir"Alien1.xpm",dir"Alien1b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=34;n<=44;n++){//Crea 4a. linea
		marcianos.push_back(Marciano(dir"Alien0.xpm",dir"Alien0b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	for (int n=45;n<=55;n++){//Crea 5a. linea
		marcianos.push_back(Marciano(dir"Alien0.xpm",dir"Alien0b.xpm",dir"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}	

	pto=PuntoBase;//Reset punto de referencia 
	
	//if (pantalla.IsOk()){cout<<" OK FONDO PANTALLA "<<endl;}//test
	
	//w = -1;
    //h = -1;
}

void Juego::OnTimer(wxTimerEvent& event) //TIMER 1 SEGUNDO
{
	int x(0),y(0);	
	
	if (limites()){//Los marcianos estan en el limite <-der o izq -> ?
		//incrementa y 
		for (auto& et:marcianos){//lee el vector de marcianos por referencia !!!!		
			x=et.getPosicion().x;//Obtiene X del marciano corriente 		
			y= et.getPosicion().y;//Obitiene Y del marciano corriente
		
			//Nueva posicion en Y marciano bajan
			et.setPosicion(wxPoint(x,++y));//Actualiza solo Y 
		}
		//cambia el sentido de la marcha
		sentido=!sentido;		
	}
	
   for (auto& et:marcianos){//lee el vector de marcianos por referencia !!!!
		//Mueve marciano izq. o der.
		x=et.getPosicion().x;//Obtiene X del marciano corriente 		
		y= et.getPosicion().y;//Obitiene Y del marciano corriente
		
		//Nueva posicion del marciano en funcion del sentido
		et.setPosicion(sentido ? wxPoint(x+1,y) : wxPoint(x-1,y));
	}
	paintNow();
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
   // dc.Clear();

 // dc.SetBrush(*wxBLACK);
  dc.SetBackground( *wxBLACK );
  //dc.SetPen( *wxWHITE );
  dc.Clear();

   
    //Copia informacion de fondo score
    menu.stringToImage("score<1> hi-score score<2>",dc);//escribe texto scores
    menu.scores(222,333,dc,2,1);   //escribe scores ... valor valor dc x y

    //Copia marcianos desde el vector hasta la pantalla  wxDC
    for (auto et:marcianos){
		dc.DrawBitmap(et.getImagen(),et.getPosicion()*factor,true);//Dibuja con el factor de ampliacion
	}
}
/********************************************************************************/
wxPoint Juego::creaPos(wxPoint pt){//crea coordenadas marciano solo al inicio

	if (pt.x<PuntoBase.x+11){ pt.x++; }//linea de marcianos hasta 11 
	else {
		pt.x=PuntoBase.x+1 ;//Coordenada x del primer marciano mas su incremento
		pt.y++;}//Salta una linea

	return pt;
}
/********************************************************************************/
bool Juego::limites(){//Han llegado a la derecha o a la izquierda los marcianos ?
	//Analiza la primera linea de marcianos ha llegado al limite izq. o derch.
	if (marcianos[0].getPosicion().x <=0 || marcianos[10].getPosicion().x >PuntoBase.x+12){
		return true;
	} 
	return false;
}
/********************************************************************************/
bool Juego::limiteInferior(){//Han llegado abajo ? Han ganado los marcianos ? 
		//Analiza la primera linea de marcianos ha llegado al limite izq. o derch.
		
		//SE TIENE QUE DEFINIR .....!!!
		
		
	if (marcianos[0].getPosicion().x <=0 || marcianos[10].getPosicion().x >PuntoBase.x+12){
		return true;
	} 
	return false;
	
}


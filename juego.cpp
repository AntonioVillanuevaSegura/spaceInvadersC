#include "juego.h"

/********************************************************************************/
/********************************************************************************/
Juego::Juego (wxFrame* parent):wxPanel(parent), m_timer(this, TIMER_ID),
nave(DIRECTORIO"PlayerSprite.xpm",DIRECTORIO"PlayerSprite0.xpm",DIRECTORIO"PlayerSprite1.xpm",wxPoint(600,675)),clienteDC(this) //Inicializa la nave 
{ //Constructor del Juego
	
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	//m_timer.Start(1000); // Intervalo de 1 segundo en el timer	
	m_timer.Start(4); // Intervalo de 1 segundo en el timer	
	pto=PuntoBase;//Primer marciano posicion 
	cargaImagenes();//Carga todas las imagenes del juego ...

	//Crea un vector de marcianos con sus coordenadas .Crea 11 marcianos de 80x80 por linea 


	for (int n=1;n<=11;n++){//Crea 1era. linea
		marcianos.push_back( Marciano(DIRECTORIO"Alien3.xpm",DIRECTORIO"Alien3b.xpm",DIRECTORIO"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos	
	}

	for (int n=12;n<=22;n++){//Crea 2a. linea
		marcianos.push_back(Marciano(DIRECTORIO"Alien1.xpm",DIRECTORIO"Alien1b.xpm",DIRECTORIO"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=23;n<=33;n++){//Crea 3a. linea
		marcianos.push_back(Marciano(DIRECTORIO"Alien1.xpm",DIRECTORIO"Alien1b.xpm",DIRECTORIO"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=34;n<=44;n++){//Crea 4a. linea
		marcianos.push_back(Marciano(DIRECTORIO"Alien0.xpm",DIRECTORIO"Alien0b.xpm",DIRECTORIO"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}
	for (int n=45;n<=55;n++){//Crea 5a. linea
		marcianos.push_back(Marciano(DIRECTORIO"Alien0.xpm",DIRECTORIO"Alien0b.xpm",DIRECTORIO"AlienExplode.xpm",pto=creaPos(pto)));//Crea vector marcianos		
	}	

	pto=PuntoBase;//Reset punto de referencia 
	
}
/********************************************************************************/
void Juego::OnTimer(wxTimerEvent& event) //TIMER 1 SEGUNDO
{
	int x(0),y(0);	
	
	if (marcianoTimer>1000){marcianoTimer=0;}//reset inicial
	if (marcianoTimer<30){marcianoTimer++;} //El tiempo marciano va mas lento que una bala 
	
	else{
		marcianoTimer=0;//Reset
		
		imgActual=!imgActual;//Imagen a utilizar la A o la B , brazo arriba o abajo 
	
		if (limites()){//Los marcianos estan en el limite <-der o izq -> ?		
			sentido = !(sentido); //cambia el sentido de la marcha	DER IZQ	
			//incrementa y  descienden
			for (auto& et:marcianos){//lee el vector de marcianos por referencia !!!!		
				x=et.getPosicion().x;//Obtiene X del marciano corriente 		
				y= et.getPosicion().y;//Obitiene Y del marciano corriente
		
				//Nueva posicion en Y marciano bajan
				et.setPosicion(wxPoint(x,y+10));//Actualiza solo Y 
			}
		}
	
		if (limiteInferior()){resetMarcianos();} //Han llegado abajo reseteamos los marcianos	
	
		for (auto& et:marcianos){//lee el vector de marcianos por referencia !!!!
			
			//Mueve marciano izq. o der.
			x=et.getPosicion().x;//Obtiene X del marciano corriente 		
			y= et.getPosicion().y;//Obitiene Y del marciano corriente
		
			//Nueva posicion del marciano en funcion del sentido
			et.setPosicion(sentido ? wxPoint(x-10,y) : wxPoint(x+10,y));
		}
		
	}
	
	disparoNave(false);//Mira el vector de disparos
		
	paintNow();//parpadeo ....
}
/********************************************************************************/
	//Dibujo
void Juego::paintEvent(wxPaintEvent & evt){
	wxPaintDC dc(this);// only to be used in paint events. use wxClientDC to paint outside the paint event
    render(dc);
}
/********************************************************************************/
void Juego::paintNow(){
	
	//wxClientDC dc(this);//  use wxClientDC to paint outside the paint event	
    //render(dc);
	render(clienteDC);
}
/********************************************************************************/
void Juego::OnSize(wxSizeEvent& event){
    Refresh();
    event.Skip();	
}
/********************************************************************************/
void Juego::render(wxDC& dc){


	dc.SetBackground( *wxBLACK );//FONDO PANTALLA NEGRO
	wxBrush brocha(*wxBLACK,wxBRUSHSTYLE_SOLID );
	dc.SetBrush (brocha);
	dc.Clear();
		
    //Dibuja informacion de fondo de pantalla score ...
    menu.stringToImage("score<1> hi-score score<2>",dc);//escribe texto scores 1a. linea
    menu.scores(111,222,dc,160,80);   //escribe scores ... valor valor dc x y 2a. linea
    menu.dibujaLinea(0,740,1200,740,dc);//Linia divisora inferior 
    //wxString mystring = wxString::Format(wxT("%i"),myint);
    menu.stringToImage(wxString::Format(wxT("%i"),3)+"PP",dc,0,750);//escribe texto scores 1a. linea    
	menu.stringToImage (wxString ("credit "+(wxString::Format(wxT("%i"),14))),
	dc,700,750);//escribe texto scores 1a. linea      
	
	//Dibuja disparo
	if (!naveDisp.empty()){//Si hay disparos en el vector
		for (auto disp:naveDisp){//lee el vector de disparos
			dc.DrawPoint(disp);//...los dibuja ..
		}
	}


    //Dibuja nave en la pantalla wxDC
	dc.DrawBitmap(nave.getImagen(true),nave.getPosicion(),true);	
	
    //Dibuja marcianos .Desde el vector hasta la pantalla  wxDC
    for (auto et:marcianos){dc.DrawBitmap(et.getImagen(imgActual),et.getPosicion(),true);}
   
    
       // for (auto img:imagenes) {dc.DrawBitmap(img,(pto=creaPos(pto)),true);}
      // dc.DrawBitmap(imagenes[2],80,80,true);
    Refresh();
}
/********************************************************************************/
wxPoint Juego::creaPos(wxPoint pt){//crea coordenadas marciano solo al inicio
	//cada marciano mide 80x80 ,hay 11, la primera posicion sera 

	if (pt.x<PuntoBase.x+80*11){ pt.x+=80; }//linea de marcianos hasta 11 
	else {
		pt.x=PuntoBase.x+80 ;//Coordenada x del primer marciano mas su incremento
		pt.y+=80;}//Salta una linea

	return pt;
}
/********************************************************************************/
bool Juego::limites(){//Han llegado a la derecha o a la izquierda los marcianos ?
	//Analiza la primera linea de marcianos ha llegado al limite izq. o derch.
	
	if (marcianos[0].getPosicion().x <=2 || marcianos[10].getPosicion().x >=(1200-80)){
		return true;
	}
	return false;
}
/********************************************************************************/
bool Juego::limiteInferior(){//Han llegado abajo ? Han ganado los marcianos ? 
	//Analiza  marciano inferior para analizar y 
					
	if (marcianos[44].getPosicion().y > PuntoBase.y + 80*10){return true;}	 
	return false;	
}
/********************************************************************************/
void Juego::resetMarcianos(){//Posicion inicial marcianos,vidas ..
	
	pto=PuntoBase;//Primer marciano posicion 	
	
	for (auto& et:marcianos){//lee el vector de marcianos por referencia !!!!						
			et.setPosicion(pto=creaPos(pto));//Actualiza solo Y 
			et.setVivo(true);//todos vivos
		}
				
		//cambia el sentido de la marcha
		sentido=true;	
}
/********************************************************************************/
void Juego::OnTecla(wxKeyEvent& event){//Evento teclas ...
	//int flags=0;
	if (event.GetKeyCode()==WXK_LEFT){ctrlNave(1);}//->
	if (event.GetKeyCode()==WXK_RIGHT){ctrlNave(2);}//<-
	if (event.GetKeyCode()==WXK_SPACE  ||
	event.GetKeyCode()==WXK_UP){ctrlNave(3);}//Espacio
}
/********************************************************************************/
void Juego::ctrlNave(int ctrl){//Controla 1 izq 2 der 3 dispara 
	wxPoint tmp(nave.getPosicion());
	switch (ctrl){
		case 1:tmp.x-=5;break;//izq.
		case 2:tmp.x+=5;break;//derch.
		case 3:disparoNave(true);break;//disparo	
	}
	//analisis limites de la nave 0-1200 
	if (tmp.x<=0){tmp.x=0;}
	if (tmp.x>=(1200-80)){tmp.x=(1200-80);}	
	
	nave.setPosicion (tmp);
	paintNow();
}
/********************************************************************************/
void Juego::disparoNave(bool disparo){//Gestiona el disparo de la nave
	//lee el vector de disparo
	//mira si colisiona
	//mira su fin
	//destruye pop
	if (disparo) { //introduce un disparo en el vector
		naveDisp.push_back (nave.getPosicion());
		disparo=false;}
		
	if (!naveDisp.empty()){//hay disparos en el vector ?
		
		//mira todo el vector bucle 
		for (auto& disp:naveDisp){//lee el vector de disparos referencia !!!!
			disp.y-=10;//decrementa y 
			if (disp.y<=70){naveDisp.pop_back();}//ver si ha llegado al final y==0
		
		//ver si colisiona con marciano
		
		}
	} 
	
 }
/********************************************************************************/
void Juego::cargaImagenes(){//Carga imagenes juego ... 88 imagenes  
	wxImage tmp;//una imagen temporal
	wxDir dir(DIRECTORIO);//Directorio de imagenes

	if ( !dir.IsOpened() ){cout <<" ERROR IMAGENES " ;exit (0);return;}//Error directorio immagen !!!!
	
	//wxString filename;
	wxString filename=DIRECTORIO;
	wxString filespec="*.xpm";//Extension a cargar
	int flags=wxDIR_DEFAULT;
	
	bool cont = dir.GetFirst(&filename, filespec, flags);//Numero de ficheros a cargar

	while ( cont )
	{
		//cout <<filename<<endl;//Nombre ficheros
		cont = dir.GetNext(&filename);//Existe otro fichero ?
		
		tmp.LoadFile(DIRECTORIO"*.xpm", wxBITMAP_TYPE_XPM); 		
		imagenes.push_back( base{tmp,filename});	//Carga el fichero imagen		
	}
}
/********************************************************************************/
wxImage Juego::buscaImagen(wxString nombre){//Busca en el vector de imagenes por su nombre 
	for (auto img:imagenes){//Recorre el vector de imagenes,nombre
		if(img.ref==nombre){return img.img;}//Si en cuentra la imagen , la devuelve
	}
	return imagenes[0].img;//No imagen  0 ...un asterisco
 }

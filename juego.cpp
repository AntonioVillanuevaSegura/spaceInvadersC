#include "juego.h"

/********************************************************************************/
/********************************************************************************/
Juego::Juego (wxFrame* parent):wxPanel(parent), m_timer(this, TIMER_ID),clienteDC(this)
{ //Constructor del Juego
	
	SetBackgroundStyle(wxBG_STYLE_PAINT);	
	m_timer.Start(4); // Intervalo timer 1000=1s
	pto=PuntoBase;//Primer marciano posicion 
	cargaImagenes();//Carga todas las imagenes del juego ...
	//Inicializa menus
	menu=new menus(gameImg);

	//Crea un vector de marcianos con sus coordenadas .Crea 11 marcianos de 80x80 por linea 

	for (int n=1;n<=11;n++){//Crea 1era. linea
		marcianos.push_back( Marciano(buscaImagen("Alien3.xpm"),buscaImagen("Alien3b.xpm"),buscaImagen("AlienExplode.xpm"),pto=creaPos(pto)));//Crea vector marcianos	
	}


	for (int n=12;n<=22;n++){//Crea 2a. linea
		marcianos.push_back(Marciano(buscaImagen("Alien1.xpm"),buscaImagen("Alien1b.xpm"),buscaImagen("AlienExplode.xpm"),pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=23;n<=33;n++){//Crea 3a. linea
		marcianos.push_back(Marciano(buscaImagen("Alien1.xpm"),buscaImagen("Alien1b.xpm"),buscaImagen("AlienExplode.xpm"),pto=creaPos(pto)));//Crea vector marcianos		
	}
	
	for (int n=34;n<=44;n++){//Crea 4a. linea
		marcianos.push_back(Marciano(buscaImagen("Alien0.xpm"),buscaImagen("Alien0b.xpm"),buscaImagen("AlienExplode.xpm"),pto=creaPos(pto)));//Crea vector marcianos		
	}

	for (int n=45;n<=55;n++){//Crea 5a. linea
		marcianos.push_back(Marciano(buscaImagen("Alien0.xpm"),buscaImagen("Alien0b.xpm"),buscaImagen("AlienExplode.xpm"),pto=creaPos(pto)));//Crea vector marcianos		
	}		
	
	//Construye la nave 
	nave=new Nave(buscaImagen("PlayerSprite.xpm"),buscaImagen("PlayerSprite0.xpm"),buscaImagen("PlayerSprite1.xpm"),wxPoint(600,675)); //Inicializa la nave 

	pto=PuntoBase;//Reset punto de referencia 
	
}
/********************************************************************************/
void Juego::OnTimer(wxTimerEvent& event) //TIMER 1 SEGUNDO
{
	int x(0),y(0);	
	
	if (marcianoTimer>1000){marcianoTimer=0;}//reset inicial
	if (marcianoTimer<30){marcianoTimer++;} //El tiempo marciano va mas lento que una bala 
	
	else{
		/*
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
		*/
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
		
	/****************************************************************************/	
    //Dibuja informacion de fondo de pantalla score ...
    menu->stringToImage("score<1> hi-score score<2>",dc);//escribe texto scores 1a. linea
    menu->scores(111,222,dc,160,80);   //escribe scores ... valor valor dc x y 2a. linea
    menu->dibujaLinea(0,740,1200,740,dc);//Linia divisora inferior 
    //wxString mystring = wxString::Format(wxT("%i"),myint);
    menu->stringToImage(wxString::Format(wxT("%i"),3)+"PP",dc,0,750);//escribe texto scores 1a. linea    
	menu->stringToImage (wxString ("credit "+(wxString::Format(wxT("%i"),14))),
	dc,700,750);//escribe texto scores 1a. linea      

	/****************************************************************************/		
	
	//Dibuja disparo
	if (!naveDisp.empty()){//Si hay disparos en el vector
		for (auto disp:naveDisp){//lee el vector de disparos								
			dc.DrawBitmap(buscaImagen("PlayerShotSpr.xpm"),disp);//dibuja disparo
		}
	}

	/****************************************************************************/	
	
    //Dibuja nave en la pantalla wxDC
	dc.DrawBitmap(nave->getImagen(true),nave->getPosicion(),true);	
	
	/****************************************************************************/	
	
    //Dibuja marcianos .Desde el vector hasta la pantalla  wxDC
    for (auto& et:marcianos){
		
		//Disparo de nave toca marciano ?
		if (colisionObjeto(et,naveDisp)  && et.getVivo()){ //Ha tocado el marciano
			dc.DrawBitmap(buscaImagen("AlienExplode.xpm"),et.getPosicion()) ;//Explosion donde esta el marciano			
			et.setVivo(false);//Esta muerto ....
			//destruye el misil
			naveDisp.pop_back();
			cout <<" Muerto "<<endl;
		}			

		if (et.getVivo()){//Si esta vivo se muestra la imagen
			dc.DrawBitmap(et.getImagen(imgActual),et.getPosicion(),true);
		}
					
	}   
      
	/****************************************************************************/	      
	
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
void Juego::ctrlNave(int ctrl){//Controla movimiento nave 1 izq 2 der 3 dispara 
	wxPoint tmp(nave->getPosicion());
	switch (ctrl){
		case 1:tmp.x-=5;break;//izq.
		case 2:tmp.x+=5;break;//derch.
		case 3:disparoNave(true);break;//disparo	
	}
	//analisis limites de la nave 0-1200 
	if (tmp.x<=0){tmp.x=0;}
	if (tmp.x>=(1200-80)){tmp.x=(1200-80);}	
	
	nave->setPosicion (tmp);
	paintNow();
}
/********************************************************************************/
void Juego::disparoNave(bool disparo){//Gestiona el disparo de la nave
	//lee el vector de disparo
	//mira su fin
	//destruye pop
	if (disparo) { //introduce un disparo en el vector
		naveDisp.push_back (nave->getPosicion());
		naveDisp.back().x+=40;//Acceso ultimo elemento disparo ,central en la nave
		disparo=false;}
		
	if (!naveDisp.empty()){//hay disparos en el vector ?
		
		//recorre todo el vector bucle decrementado la posicion
		for (auto& disp:naveDisp){//lee el vector de disparos referencia !!!!
			disp.y-=10;//decrementa y 
			if (disp.y<=70){
				naveDisp.pop_back();}//ver si ha llegado al final y==0		
		}
	} 	
 }
/********************************************************************************/
void Juego::cargaImagenes(){//Carga imagenes juego ... 88 imagenes  
	wxImage img;//una imagen temporal
	wxDir dir(DIRECTORIO);//Directorio de imagenes

	if ( !dir.IsOpened() ){cout <<" ERROR IMAGENES " ;exit (0);return;}//Error directorio immagen !!!!
	
	//wxString filename;
	wxString filename=DIRECTORIO;
	wxString filespec="*.xpm";//Extension a cargar
	int flags=wxDIR_DEFAULT;
	
	bool cont = dir.GetFirst(&filename, filespec, flags);

	while ( cont )
	{
		//cout <<"Fichero cargado = "<<filename<<endl;//Nombre ficheros
		cont = dir.GetNext(&filename);//bool .Existe otro fichero ?
		
		img.LoadFile(DIRECTORIO+filename, wxBITMAP_TYPE_XPM); //Carga imagen xpm 
		
		/*
		if (img.IsOk()) {cout <<" ok "<<endl;}	 //Carga correcta ?............................	
		else {cout <<" NO CARGADO "<<endl;}
		*/
		gameImg.push_back( base {img,filename} );	//Carga el fichero imagen		
	}
}
/********************************************************************************/
wxImage Juego::buscaImagen(wxString nombre){//Busca en el vector de imagenes por su nombre 
	if (nombre==" ")
	for (auto& img:gameImg){//Recorre el vector de imagenes,nombre
		if((img.ref).Cmp(nombre)==0){return img.img;}//Si en cuentra la imagen , la devuelve
	} 
	
	return gameImg[0].img;//No imagen  0 ...un asterisco space.xpm 
 }
/********************************************************************************/

bool Juego::colisionObjeto (Marciano& objeto,vector<wxPoint>& v){//Un objeto marciano o derivado toca un wxPoint

	if (v.empty() ){return false;}//No hay disparos 


	for (auto disparo:v){//recorre el vector de disparos 
		
		if ( colision(objeto.getPosicion(),disparo)) {return true;}
	}

	return false;
}

/********************************************************************************/
bool Juego::colision(wxPoint a,wxPoint b){//Objetos o puntos en colision 
	//La base del marciano es a 80x40 ,hay un margen de 10 pixels +o- a cada lado
	//Si el disparo esta dentro del cuadrado 80x40 esta tocado
 
	if ( (b.x) >= (a.x+10) && b.x <=(a.x+70) && //x los bordes no son la imagen
		 (b.y) >= (a.y) && b.y <= (a.y+40) //y
		){return true;}
	
	return false;
}
 

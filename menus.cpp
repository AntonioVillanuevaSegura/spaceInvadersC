#include "menus.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
/********************************************************************************/
menus::menus(){//Constructor de la clase ,carga imagenes 
	cargaImagenes();	
}
/********************************************************************************/
wxBitmap menus::asciiToimage(wxString nombre){//Una ascii  devuelve su imagen correspondiente
	nombre+=".xpm";
	for (auto& img:imagenes){//Recorre el vector de imagenes,nombre
		if((img.ref).Cmp(nombre)==0){return img.img;}//Si en cuentra la imagen , la devuelve
	}
	return imagenes[0].img;//No imagen  0 ...un asterisco
}
/********************************************************************************/
void menus::stringToImage(wxString texto,wxDC& dc,int x,int y){//"SCORE<1> HI-SCORE SCORE<2>"

	for (char letra:texto){
		x+=40;
		if (!(letra==' ')) {
			dc.DrawBitmap(asciiToimage(letra),(x),y,true);//letra o numero 		
		}else {
			dc.DrawBitmap(asciiToimage("space"),(x),y,true);//Espacio	
		}
	}
}
/********************************************************************************/
void menus::scores(int A,int B,wxDC& dc,int x,int y){//Escribe scores
	stringToImage(to_string(A),dc,x,y);
	stringToImage(to_string(B),dc,x+700,y);	
}
/********************************************************************************/
void menus::dibujaLinea(int x,int y,int xx,int yy,wxDC& dc){//Dibuja una linea de origen x,y y fin xx,yy
	wxPen lapiz(*wxWHITE_PEN);//Crea uun lapiz blanco
	lapiz.SetWidth(7);	
	dc.SetPen(lapiz);//Lapiz blanco	
	dc.DrawLine(x,y,xx,yy);//Linea
}

/********************************************************************************/
bool menus::cargaImagenes(){//Carga imagenes juego ... 88 imagenes  
	wxImage img;//una imagen temporal
	wxDir dir(DIRECTORIO);//Directorio de imagenes

	if ( !dir.IsOpened() ){//Test directorio imagenes 
		cout <<" Error directorio "<<DIRECTORIO<<endl;
		 return false;}//Error directorio immagen !!!!
	
	wxString filename=DIRECTORIO;
	wxString filespec="*.xpm";//Extension de imagenes a cargar
	int flags=wxDIR_DEFAULT;
	
	bool cont = dir.GetFirst(&filename, filespec, flags);

	while ( cont )
	{
		cont = dir.GetNext(&filename);//bool .Existe otro fichero ?
		
		img.LoadFile(DIRECTORIO+filename, wxBITMAP_TYPE_XPM); //Carga imagen xpm 		

		if (img.IsOk()) {cout <<filename<< "load ok "<<endl;}	 //Carga correcta ?............................	
		else {cout <<filename<< " load problem ! "<<endl;}

		imagenes.push_back( base {img,filename} );	//Carga el fichero imagen		
	}
	
	return true ;
}

/********************************************************************************/

wxImage menus::buscaImagen(wxString nombre){//Busca en el vector de imagenes por su nombre 
		
	for (auto& img:imagenes){//Recorre el vector de imagenes,nombre
		if((img.ref).Cmp(nombre)==0){return img.img;}//Si en cuentra la imagen , la devuelve
	} 
	
	return imagenes[0].img;//No imagen  0 ...un asterisco space.xpm 
 }
 
 /********************************************************************************/
 void menus::pantallaJuego(int scoreA,int scoreB ,wxDC& dc){//Dibuja textos pantalla principal
	     //Dibuja informacion de fondo de pantalla score ...
    stringToImage("score<1> hi-score score<2>",dc);//escribe texto scores 1a. linea
    scores(scoreA,scoreB,dc,160,80);   //escribe scores ... valor valor dc x y 2a. linea
    dibujaLinea(0,740,1200,740,dc);//Linia divisora inferior 
    
   //stringToImage(wxString::Format(wxT("%i"),3)+"PP",dc,0,750);//escribe texto scores 1a. linea    
    // stringToImage(wxString::Format(wxT("%i"),3),dc,0,750);//texto numero de vidas ,naves
     dc.DrawBitmap(buscaImagen("PlayerSprite.xpm"),80*3,750,true);
    
	stringToImage (wxString ("credit "+(wxString::Format(wxT("%i"),14))),dc,700,750);//escribe texto  
 }

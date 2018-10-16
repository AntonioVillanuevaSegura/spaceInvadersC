#include "menus.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
menus::menus(vector<base> v):imagenes(v){//Constructor de la clase ,carga letras lineas ...	
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

#include "menus.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
menus::menus(){//Constructor de la clase ,carga letras lineas ...
	
	for (char num='0';num<='9';num++){//Carga numeros 0 - 9
		cargaImagenes(string (1, num));

	}
	
	for (char letras='a';letras<='z';letras++){//Carga letras A- Z
		cargaImagenes(string (1, letras));
	}
	
	for (char signos='<';signos<='>';signos++){//Carga signos < = >
		cargaImagenes(string (1, signos));
	}
	
	cargaImagenes(string (1, '-'));//Carga una raya 
	cargaImagenes("space");//Carga una raya 	

	cargaImagenes("PlayerSprite");//Carga la nave 
}
/********************************************************************************/
void menus::cargaImagenes(wxString c){//Carga imagenes en el vector desde su char correspondiente
	wxString directorio(DIRECTORIO); //"./spaceInvaders/"
	wxImage img;
		directorio+=c;
		directorio+=".xpm";		
		
		img.LoadFile(directorio, wxBITMAP_TYPE_XPM);//Carga una imagen

		if (c=="space"){c=' ';}// chapuza carga el espacio
		if (c=="PlayerSprite"){c='P';}//chapuza carga la nave 
		
		imagenes.push_back(base{img,c});//Guarda una imagen y su referencia
}
/********************************************************************************/
wxBitmap menus::asciiToimage(char c){//Una ascii  devuelve su imagen correspondiente
	for (auto img:imagenes){
		if(img.ref==c){return img.img;}
	}
	return imagenes[0].img;//No imagen  0 
}
/********************************************************************************/
void menus::stringToImage(wxString texto,wxDC& dc,int x,int y){//"SCORE<1> HI-SCORE SCORE<2>"
	for (char letra:texto){
		letra!='P' ? x+=40 : x+=90;//Si es una nave la base en x es mayor el doble
		dc.DrawBitmap(asciiToimage(letra),(x),y,true);		
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

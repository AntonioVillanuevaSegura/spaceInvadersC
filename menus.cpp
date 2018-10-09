#include "menus.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
menus::menus(){//Constructor de la clase ,carga letras lineas ...
	factorPto=10*4;//Factor de adaptacion ,ampliacion
	factorA=5;//Factor de adaptacion ,ampliacion	
	
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
}
/********************************************************************************/
void menus::cargaImagenes(wxString c){//Carga imagenes en el vector desde su char correspondiente
	wxString directorio(dir); //"./spaceInvaders/"
	wxImage img;
		directorio+=c;
		directorio+=".xpm";		
		cout <<" directorio leido "<<directorio<<endl;//debug
		img.LoadFile(directorio, wxBITMAP_TYPE_XPM);//Carga una imagen
		
		img=resized(img);//Reescalar la imagen 
		
		if (c=="space"){c=' ';}// chapuza 
		
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

wxImage menus::resized(wxImage caracter){//Reescala marciano , la base es el tamano real en xpm
		resize = wxBitmap( caracter.Scale( caracter.GetWidth () *factorA,
											caracter.GetHeight ()*factorA
											/*, wxIMAGE_QUALITY_HIGH*/ ) );       
       caracter=resize.ConvertToImage();
return caracter;//devuelve un wxImage
}
/********************************************************************************/
void menus::stringToImage(wxString texto,wxDC& dc){//"SCORE<1> HI-SCORE SCORE<2>"
	int x(0),y(0);
	for (char letra:texto){
		//cout <<letra<<endl;//debug
		dc.DrawBitmap(asciiToimage(letra),(++x)*factorPto,y*factorPto,true);
		//dc.DrawBitmap(imagenes[0].img,wxPoint(0,0),true);
	}
}
/********************************************************************************/

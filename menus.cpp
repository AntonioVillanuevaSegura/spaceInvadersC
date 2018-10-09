#include "menus.h"
/***************************  DEFINICIONES  *************************************/
/********************************************************************************/
menus::menus(){//Constructor de la clase ,carga letras lineas ...
	factor=5;//factor ampliacion
	for (char num='0';num<='9';num++){//Carga numeros 0 - 9
		cargaImagenes(num);
	}
	
	for (char letras='a';letras<='z';letras++){//Carga letras A- Z
		cargaImagenes(letras);
	}
	
	for (char signos='<';signos<='>';signos++){//Carga signos < = >
		cargaImagenes(signos);
	}
	
	cargaImagenes('-');//Carga una raya 
}
/********************************************************************************/
void menus::cargaImagenes(char c){//Carga imagenes en el vector desde su char correspondiente
	wxString directorio(dir); //"./spaceInvaders/"
	wxImage img;
		directorio+=c;
		directorio+=".xpm";		
		//cout <<directorio<<endl;//debug
		img.LoadFile(directorio, wxBITMAP_TYPE_XPM);//Carga una imagen
		
		img=resized(img);//Reescalar la imagen 
		
		imagenes.push_back(base{img,c});//Guarda una imagen y su referencia
}
/********************************************************************************/
wxBitmap menus::asciiToimage(char c){//Una ascii  devuelve su imagen correspondiente

	for (auto img:imagenes){
		if(img.ref==c){return img.img;}
	}
	return imagenes[0].img;
}
/********************************************************************************/

wxImage menus::resized(wxImage caracter){//Reescala marciano , la base es el tamano real en xpm
		resize = wxBitmap( caracter.Scale( caracter.GetWidth () *factor,
											caracter.GetHeight ()*factor
											/*, wxIMAGE_QUALITY_HIGH*/ ) );       
       caracter=resize.ConvertToImage();
return caracter;//devuelve un wxImage
}
/********************************************************************************/
void menus::stringToImage(wxString texto,wxDC& dc){//"SCORE<1> HI-SCORE SCORE<2>"
	int x(0),y(0);
	for (char letra:texto){
		//cout <<letra<<endl;//debug
		dc.DrawBitmap(asciiToimage(letra),(++x)*factor,y*factor,true);
		//dc.DrawBitmap(imagenes[0].img,wxPoint(0,0),true);
	}
}
/********************************************************************************/

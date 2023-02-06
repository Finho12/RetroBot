#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream>

#define ESC    	27
#define QtdRobos 9
#define QtdRobosPulando 8
#define QtdRobosMag 7
#define QtdRobosEscada 2
#define QtdFundo 9

/* variáveis globais */
int GlbLar, GlbAlt;
int GlbBtnLar, GlbBtnAlt;

void *Fundo[QtdFundo];
unsigned char *R[QtdRobos], *RM[QtdRobos];
unsigned char *RE[QtdRobos], *REM[QtdRobos];
unsigned char *PU[QtdRobosPulando], *PUM[QtdRobosPulando];
unsigned char *PUE[QtdRobosPulando], *PUEM[QtdRobosPulando];
unsigned char *ME[QtdRobosMag], *MEM[QtdRobosMag];
unsigned char *MEI[QtdRobosMag], *MEIM[QtdRobosMag];
unsigned char *E[QtdRobosEscada], *EM[QtdRobosEscada];
unsigned char *C, *CM;
unsigned char *Escada, *EscadaM;
unsigned char *Magnetismo, *MagnetismoM;

int tam, tamFundo, xRobo, yRobo, tamCaixa, tamMagnetismo, tamEscada;


/* funções usadas neste programa */
void TelaInicial();
void Creditos();
void Tela1();
void Tela2();
void Tela3();
void Tela4();
void Tela5();
void Tela6();
void Tela7();
//void PreparaImg();

void AlteraCorImg(unsigned char *P, int Tam, int Cor) {
  int i;
  for(i=0; i < Tam; i++)
    if (i > 23 and i % 4 < 3)
      P[i] = Cor;
}



void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk) {
// Tam é o tamanho dos ponteiros da imagem e da máscara
// Img é o ponteiro que aponta para o vetor que contém a imagem capturada com getimage(..)
// Msk é o ponteiro que será transformado em máscara
  int i;
  unsigned char B, G, R;
  B = Img[24];
  G = Img[25];
  R = Img[26];
  for(i=24; i < Tam; i+=4) {
    if (Img[i]==B and Img[i+1]==G and Img[i+2]==R) {
      Img[i] = 0;
      Img[i+1] = 0;
      Img[i+2] = 0;
      Msk[i] = 255;
      Msk[i+1] = 255;
      Msk[i+2] = 255;
    }
    else {
      Msk[i] = 0;
      Msk[i+1] = 0;
      Msk[i+2] = 0;
      
    }
  }
}


int main() {
	int pgD, i;
	GlbLar = 1280;
	GlbAlt = 720;
	GlbBtnLar = 250;
	GlbBtnAlt = 80;
	void *FundoTemp;
  
  
  
	initwindow(GlbLar, GlbAlt, "Retrobot", 0, 0, false);
	
	
	
	// Carrega os arquivos mp3
  	mciSendString("open .\\sons\\trilhasonora1.mp3 type MPEGVideo alias trilha1", NULL, 0, 0); 
  	mciSendString("open .\\sons\\trilhasonora2.mp3 type MPEGVideo alias trilha2", NULL, 0, 0);   

  	mciSendString("play trilha1 repeat", NULL, 0, 0);
  	
  	
	
	tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
	FundoTemp = malloc(tam);
	readimagefile(".\\imagens\\Tela1.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, FundoTemp);

  /* transfere execução para a função TelaInicial() */
  
  	putimage(0, 0, Fundo, COPY_PUT);
  	if (pgD == 1) pgD = 2; else pgD=1;
	setactivepage(pgD);
	
	tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  	for(i = 0; i <= QtdFundo; i++)
  	{
  		Fundo[i] = malloc(tam);
  	}
  	//Fundo = malloc(tam);
	readimagefile(".\\imagens\\Tela1.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[0]);
	readimagefile(".\\imagens\\Tela2.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[1]);
	readimagefile(".\\imagens\\Tela3.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[2]);
	readimagefile(".\\imagens\\Tela4.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[3]);
	readimagefile(".\\imagens\\Tela5.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[4]);
	readimagefile(".\\imagens\\Tela6.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[5]);
	readimagefile(".\\imagens\\Tela7.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[6]);
	readimagefile(".\\imagens\\Tela8.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[7]);
	readimagefile(".\\imagens\\Tela9.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo[8]);
  
	tamEscada = imagesize(0, 0, 40, 300);
	tamFundo = imagesize(0, 0, 1280, 720);
	tam = imagesize(0, 0, 70, 80);
	tamMagnetismo = imagesize(0, 0, 20, 20);
	
	for(i = 0; i <= QtdRobos; i++)
  	{
  		/*R[i] = malloc(tam);
  		RM[i] = malloc(tam);*/
  		R[i] = (unsigned char *)malloc(tam);
  		RM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobos; i++)
  	{
  		RE[i] = (unsigned char *)malloc(tam);
  		REM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosPulando; i++)
  	{
  		PU[i] = (unsigned char *)malloc(tam);
  		PUM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosPulando; i++)
  	{
  		PUE[i] = (unsigned char *)malloc(tam);
  		PUEM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosMag; i++)
  	{
  		ME[i] = (unsigned char *)malloc(tam);
  		MEM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosMag; i++)
  	{
  		MEI[i] = (unsigned char *)malloc(tam);
  		MEIM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosEscada; i++)
  	{
  		E[i] = (unsigned char *)malloc(tam);
  		EM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
  	
  	Magnetismo = (unsigned char *)malloc(tamMagnetismo);
  	MagnetismoM = (unsigned char *)malloc(tamMagnetismo);
	
	tamCaixa = imagesize(0, 0, 50, 50);
	C = (unsigned char *)malloc(tam);
  	CM = (unsigned char *)malloc(tam);
	
	
	
	readimagefile(".\\imagens\\EscadaF1.bmp", 0, 0, 40, 300);
  	getimage(0, 0, 40, 300, Escada);
  	getimage(0, 0, 40, 300, EscadaM);
  	
  	readimagefile(".\\imagens\\Magnetismo.bmp", 0, 0, 20, 20);
  	getimage(0, 0, 20, 20, Magnetismo);
  	getimage(0, 0, 20, 20, MagnetismoM);
	
  	readimagefile(".\\imagens\\ParLD.bmp", 0, 0, 70, 80); // carrega a imagem
  	getimage(0, 0, 70, 80, R[0]); // captura para o ponteiro R
  	getimage(0, 0, 70, 80, RM[0]); // captura para a máscara RM (a mesma imagem de R, que depois será manipulada na rotina PreparaImg)
  	
  	/*tam = imagesize(0, 0, 99, 150);
  	R[1] = (unsigned char *)malloc(tam);
  	RM[1] = (unsigned char *)malloc(tam);*/
  	readimagefile(".\\imagens\\And1.bmp", 0, 0, 70, 80); 
  	getimage(0, 0, 70, 80, R[1]); 
  	getimage(0, 0, 70, 80, RM[1]);
  	
  	//tam = imagesize(0, 0, 70, 85);
  	readimagefile(".\\imagens\\And2.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, R[2]); 
  	getimage(0, 0, 70, 80, RM[2]);
  	
  	readimagefile(".\\imagens\\And3.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, R[3]); 
  	getimage(0, 0, 70, 80, RM[3]);
  	
  	readimagefile(".\\imagens\\And4.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, R[4]); 
  	getimage(0, 0, 70, 80, RM[4]);
  	
  	readimagefile(".\\imagens\\And5.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, R[5]); 
  	getimage(0, 0, 70, 80, RM[5]);
  	
  	readimagefile(".\\imagens\\And6.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, R[6]); 
  	getimage(0, 0, 70, 80, RM[6]);
  	
  	readimagefile(".\\imagens\\And7.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, R[7]); 
  	getimage(0, 0, 70, 80, RM[7]);
  	
  	readimagefile(".\\imagens\\And8.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, R[8]); 
  	getimage(0, 0, 70, 80, RM[8]);
  	
  	
  	//Imgs Pra esquerda
  	
  	readimagefile(".\\imagens\\ParLE.bmp", 0, 0, 70, 80); // carrega a imagem
  	getimage(0, 0, 70, 80, RE[0]); // captura para o ponteiro R
  	getimage(0, 0, 70, 80, REM[0]); // captura para a máscara RM (a mesma imagem de R, que depois será manipulada na rotina PreparaImg)
  	
  	readimagefile(".\\imagens\\invAnd1.bmp", 0, 0, 70, 80); 
  	getimage(0, 0, 70, 80, RE[1]); 
  	getimage(0, 0, 70, 80, REM[1]);
  	
  	readimagefile(".\\imagens\\invAnd2.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, RE[2]); 
  	getimage(0, 0, 70, 80, REM[2]);
  	
  	readimagefile(".\\imagens\\invAnd3.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, RE[3]); 
  	getimage(0, 0, 70, 80, REM[3]);
  	
  	readimagefile(".\\imagens\\invAnd4.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, RE[4]); 
  	getimage(0, 0, 70, 80, REM[4]);
  	
  	readimagefile(".\\imagens\\invAnd5.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, RE[5]); 
  	getimage(0, 0, 70, 80, REM[5]);
  	
  	readimagefile(".\\imagens\\invAnd6.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, RE[6]); 
  	getimage(0, 0, 70, 80, REM[6]);
  	
  	readimagefile(".\\imagens\\invAnd7.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, RE[7]); 
  	getimage(0, 0, 70, 80, REM[7]);
  	
  	readimagefile(".\\imagens\\invAnd8.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, RE[8]); 
  	getimage(0, 0, 70, 80, REM[8]);
  	
  	
  	
  	readimagefile(".\\imagens\\Caixa.bmp", 0, 0, 50, 50);
  	getimage(0, 0, 50, 50, C);
  	getimage(0, 0, 50, 50, CM);
  	
  	
  	
  	readimagefile(".\\imagens\\Pul1.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[0]);
  	getimage(0, 0, 70, 80, PUM[0]);
  	
  	readimagefile(".\\imagens\\Pul2.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[1]);
  	getimage(0, 0, 70, 80, PUM[1]);
  	
  	readimagefile(".\\imagens\\Pul3.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[2]);
  	getimage(0, 0, 70, 80, PUM[2]);
  	
  	readimagefile(".\\imagens\\Pul4.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[3]);
  	getimage(0, 0, 70, 80, PUM[3]);
  	
  	readimagefile(".\\imagens\\Pul5.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[4]);
  	getimage(0, 0, 70, 80, PUM[4]);
  	
  	readimagefile(".\\imagens\\Pul6.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[5]);
  	getimage(0, 0, 70, 80, PUM[5]);
  	
  	readimagefile(".\\imagens\\Pul7.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[6]);
  	getimage(0, 0, 70, 80, PUM[6]);
  	
  	readimagefile(".\\imagens\\Pul8.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PU[7]);
  	getimage(0, 0, 70, 80, PUM[7]);
  	
  	
  	//Pulo Esqueda
  	
  	readimagefile(".\\imagens\\invPul1.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[0]);
  	getimage(0, 0, 70, 80, PUEM[0]);
  	
  	readimagefile(".\\imagens\\invPul2.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[1]);
  	getimage(0, 0, 70, 80, PUEM[1]);
  	
  	readimagefile(".\\imagens\\invPul3.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[2]);
  	getimage(0, 0, 70, 80, PUEM[2]);
  	
  	readimagefile(".\\imagens\\invPul4.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[3]);
  	getimage(0, 0, 70, 80, PUEM[3]);
  	
  	readimagefile(".\\imagens\\invPul5.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[4]);
  	getimage(0, 0, 70, 80, PUEM[4]);
  	
  	readimagefile(".\\imagens\\invPul6.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[5]);
  	getimage(0, 0, 70, 80, PUEM[5]);
  	
  	readimagefile(".\\imagens\\invPul7.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[6]);
  	getimage(0, 0, 70, 80, PUEM[6]);
  	
  	readimagefile(".\\imagens\\invPul8.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, PUE[7]);
  	getimage(0, 0, 70, 80, PUEM[7]);
  	
  	
  	//Magnetismo Escalando
  	
  	readimagefile(".\\imagens\\Mag1.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, ME[0]);
  	getimage(0, 0, 70, 80, MEM[0]);
  	
  	readimagefile(".\\imagens\\Mag2.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, ME[1]);
  	getimage(0, 0, 70, 80, MEM[1]);
  	
  	readimagefile(".\\imagens\\Mag3.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, ME[2]);
  	getimage(0, 0, 70, 80, MEM[2]);
  	
  	readimagefile(".\\imagens\\Mag4.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, ME[3]);
  	getimage(0, 0, 70, 80, MEM[3]);
  	
  	readimagefile(".\\imagens\\Mag5.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, ME[4]);
  	getimage(0, 0, 70, 80, MEM[4]);
  	
  	readimagefile(".\\imagens\\Mag6.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, ME[5]);
  	getimage(0, 0, 70, 80, MEM[5]);
  	
  	readimagefile(".\\imagens\\Mag7.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, ME[6]);
  	getimage(0, 0, 70, 80, MEM[6]);
  	
  	
  	
  	// Magnetismo Escalando Esquerda
  	
  	readimagefile(".\\imagens\\InvMag1.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, MEI[0]);
  	getimage(0, 0, 70, 80, MEIM[0]);
  	
  	readimagefile(".\\imagens\\InvMag2.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, MEI[1]);
  	getimage(0, 0, 70, 80, MEIM[1]);
  	
  	readimagefile(".\\imagens\\InvMag3.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, MEI[2]);
  	getimage(0, 0, 70, 80, MEIM[2]);
  	
  	readimagefile(".\\imagens\\InvMag4.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, MEI[3]);
  	getimage(0, 0, 70, 80, MEIM[3]);
  	
  	readimagefile(".\\imagens\\InvMag5.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, MEI[4]);
  	getimage(0, 0, 70, 80, MEIM[4]);
  	
  	readimagefile(".\\imagens\\InvMag6.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, MEI[5]);
  	getimage(0, 0, 70, 80, MEIM[5]);
  	
  	readimagefile(".\\imagens\\InvMag7.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, MEI[6]);
  	getimage(0, 0, 70, 80, MEIM[6]);
  	
  	
  	// Escada
  	
  	readimagefile(".\\imagens\\EscD.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, E[0]);
  	getimage(0, 0, 70, 80, EM[0]);
  	
  	readimagefile(".\\imagens\\EscE.bmp", 0, 0, 70, 80);
  	getimage(0, 0, 70, 80, E[1]);
  	getimage(0, 0, 70, 80, EM[1]);
	
	
	
	
	for(i = 0; i < QtdRobos; i++)
  	{
  		PreparaImg(tam, RE[i], REM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobos; i++)
  	{
  		PreparaImg(tam, R[i], RM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosPulando; i++)
  	{
  		PreparaImg(tam, PU[i], PUM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosPulando; i++)
  	{
  		PreparaImg(tam, PUE[i], PUEM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosMag; i++)
  	{
  		PreparaImg(tam, ME[i], MEM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosMag; i++)
  	{
  		PreparaImg(tam, MEI[i], MEIM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosEscada; i++)
  	{
  		PreparaImg(tam, E[i], EM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	
	PreparaImg(tam, PU[1], PUM[1]);
	PreparaImg(tamEscada, Escada, EscadaM);
	PreparaImg(tamMagnetismo, Magnetismo, MagnetismoM);
  
  //TelaInicial();
  Tela1();
  //Tela2();
  //Tela3();
  //Tela4();
  //Tela5();
  //Tela6();
  
  /* finaliza área gráfica */
  closegraph();
  return(0);
}

void TelaInicial() {
  bool Fim = false;
  int pg = 1;
  POINT P;
  HWND janela;
  
  bool btnJogarSelecionado = false; 
  bool btnCreditosSelecionado = false; 
  bool btnSairSelecionado = false;
  
  int tam;
  void *Fundo;
  void *btnJogar, *btnJogarSel;
  void *btnCreditos, *btnCreditosSel;
  void *btnSair, *btnSairSel;
  /* carga da imagem de fundo */
  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\ImgRetrobot.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);
  
  cleardevice();
  
  /* carga da imagem dos botões */
  cleardevice();
  tam = imagesize(0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  btnJogar = malloc(tam);
  readimagefile(".\\imagens\\btnjogar.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogar);
  btnJogarSel = malloc(tam);
  readimagefile(".\\imagens\\btnjogarsel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogarSel);
  btnCreditos = malloc(tam);
  readimagefile(".\\imagens\\btncreditos.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditos);
  btnCreditosSel = malloc(tam);
  readimagefile(".\\imagens\\btncreditossel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditosSel);
  btnSair = malloc(tam);
  readimagefile(".\\imagens\\btnsair.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSair);
  btnSairSel = malloc(tam);
  readimagefile(".\\imagens\\btnsairsel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSairSel);
  
  janela = GetForegroundWindow(); // Obtém o Handle da janela gráfica
  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    if (btnJogarSelecionado)
      putimage(900, 400, btnJogarSel, COPY_PUT); // retângulo do botão 900, 400, 900+GlbBtnLar-1, 400+GlbBtnAlt-1
    else
      putimage(900, 400, btnJogar, COPY_PUT);
    if (btnCreditosSelecionado)
      putimage(900, 500, btnCreditosSel, COPY_PUT);
    else
      putimage(900, 500, btnCreditos, COPY_PUT);
    if (btnSairSelecionado)
      putimage(900, 600, btnSairSel, COPY_PUT);
    else
      putimage(900, 600, btnSair, COPY_PUT);
      
    /*settextstyle(1, 0, 8);
    outtextxy(getmaxx() / 3, 100, "Retrobot");*/
      
    setvisualpage(pg);
    /* Verifica movimento do mouse independente de haver clique */
    if (GetCursorPos(&P)) // captura a posição do mouse. A variável P é carregada com coordenadas físicas de tela
      if (ScreenToClient(janela, &P)) { // Converte as coordenadas físicas de tela para as coordenadas 
  
        /* configura a troca da imagem do botão quando o mouse está sobre ele */
        btnJogarSelecionado = false; // botão jogar
        if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 400 <= P.y && P.y <= 400+GlbBtnAlt-1)
          btnJogarSelecionado = true;
        btnCreditosSelecionado = false; // botão créditos
        if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 500 <= P.y && P.y <= 500+GlbBtnAlt-1)
          btnCreditosSelecionado = true;
        btnSairSelecionado = false; // botão sair
        if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 600 <= P.y && P.y <= 600+GlbBtnAlt-1)
          btnSairSelecionado = true;

        /* verifica se o mouse foi pressionado na área de algum botão */          
        if(GetKeyState(VK_LBUTTON)&0x80) {
          // botão jogar
          if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 400 <= P.y && P.y <= 400+GlbBtnAlt-1)
            Tela1();    
          // botão créditos
          else if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 500 <= P.y && P.y <= 500+GlbBtnAlt-1)
            Creditos();
          // botão sair
          else if (900 <= P.x && P.x <= 900+GlbBtnLar-1 && 600 <= P.y && P.y <= 600+GlbBtnAlt-1)
            Fim = true;
        }
      }
  }  
}

void Creditos() {
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false;
  int pg = 1;
	
	

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\ImgCreditos.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);

  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    /*setbkcolor(0);
    settextstyle(1, 0, 8);
    outtextxy(getmaxx() / 3, 100, "Creditos");*/
    setvisualpage(pg);
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
    }
  }
}

void Tela1() {
	int pg = 1;
	int pgT = 1;
	char tecla = 0;
	char s[50];
	int  x, y, raio;
	double passox, passoy;
	x = 100;
	y = 100;
	raio = 18; 
	passox = 3;
	passoy = 1;
	strcpy(s, "pressione Esc para Sair");
	bool andaDireita = false, andaEsquerda = false, MostraCaixa = true, pulaRobo = false, AgarraMagnetismo = false,
		 DesceEscada = false, SobeEscada = false;
	int iRobo, i, iRoboPula;
	int LadoRobo; // Em direção a esquerda = 0, Em direção a direita = 1
	int PiscaCaixa = 0;
	
	int ELipse[6];
	
	unsigned char *R[QtdRobos], *RM[QtdRobos];
	unsigned char *RE[QtdRobos], *REM[QtdRobos];
	unsigned char *C, *CM;
	unsigned char *PU[QtdRobosPulando], *PUM[QtdRobosPulando];
	unsigned char *PUE[QtdRobosPulando], *PUEM[QtdRobosPulando];
	unsigned char *Escada, *EscadaM;
	unsigned char *Magnetismo, *MagnetismoM;
	unsigned char *ME[QtdRobosMag], *MEM[QtdRobosMag];
	unsigned char *MEI[QtdRobosMag], *MEIM[QtdRobosMag];
	unsigned char *E[QtdRobosEscada], *EM[QtdRobosEscada];
	int tam, tamFundo, xRobo, yRobo, tamCaixa, tamMagnetismo, tamEscada;
	void *FundoTemp;
	
	
	
  
  	//char tecla = 0;
	int posXrobo = 100;
	int posYrobo = 100;
	
	/*void *R;  // esta variável é um vetor dinâmico que contém o sprite
	void *RM; // esta variável é um vetor dinâmico que contém a máscara*/
	
	
	
	/*void **R[QtdRobos], **RM[QtdRobos];
	R = (void **)malloc(sizeof(void *) * QtdRobos);
	RM = (void **)malloc(sizeof(void *) * QtdRobos);*/
	void *T; //Img Fundo
	int FPS;
	unsigned long long gt1, gt2;
	int PosMag1[4];
	int PosObs1[4];
	int PosObs2[4];
	int PosObs3[4];
	int posXimg;	
	int Min (int a, int b);
	int Max (int a, int b);
	int RoboAgarra = 0;
	int iRoboEscalaMag;
	int LadoMagnetismo = 1;
	int DescendoEscada = 0;
	int SubindoEscada = 0;
	int iAgarraMagnetismo;


  	cleardevice();

  	tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
	FundoTemp = malloc(tam);
	readimagefile(".\\imagens\\Tela1.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, FundoTemp);

  /* transfere execução para a função TelaInicial() */
  
  	putimage(0, 0, Fundo, COPY_PUT);
  	if (pgT == 1) pgT = 2; else pgT=1;
	setactivepage(pgT);

  	tam = imagesize(0, 0, 75, 90);
  	tamEscada = imagesize(0, 0, 40, 300);
  	tamFundo = imagesize(0, 0, 1280, 720);
  	tam = imagesize(0, 0, 75, 90);
  	tamMagnetismo = imagesize(0, 0, 20, 20);
  	
  	for(i = 0; i <= QtdRobos; i++)
  	{
  		/*R[i] = malloc(tam);
  		RM[i] = malloc(tam);*/
  		R[i] = (unsigned char *)malloc(tam);
  		RM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobos; i++)
  	{
  		RE[i] = (unsigned char *)malloc(tam);
  		REM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosPulando; i++)
  	{
  		PU[i] = (unsigned char *)malloc(tam);
  		PUM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosPulando; i++)
  	{
  		PUE[i] = (unsigned char *)malloc(tam);
  		PUEM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosMag; i++)
  	{
  		ME[i] = (unsigned char *)malloc(tam);
  		MEM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosMag; i++)
  	{
  		MEI[i] = (unsigned char *)malloc(tam);
  		MEIM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	for(i = 0; i <= QtdRobosEscada; i++)
  	{
  		E[i] = (unsigned char *)malloc(tam);
  		EM[i] = (unsigned char *)malloc(tam);
  		//std::cout << i << std::endl;
	}
	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
  	
  	Magnetismo = (unsigned char *)malloc(tamMagnetismo);
  	MagnetismoM = (unsigned char *)malloc(tamMagnetismo);
	
	tamCaixa = imagesize(0, 0, 50, 50);
	C = (unsigned char *)malloc(tam);
  	CM = (unsigned char *)malloc(tam);
  	
  	
  	putimage(0, 0, Fundo, COPY_PUT);
  	
  	readimagefile(".\\imagens\\EscadaF1.bmp", 0, 0, 40, 300);
  	getimage(0, 0, 40, 300, Escada);
  	getimage(0, 0, 40, 300, EscadaM);
  	
  	readimagefile(".\\imagens\\Magnetismo.bmp", 0, 0, 20, 20);
  	getimage(0, 0, 20, 20, Magnetismo);
  	getimage(0, 0, 20, 20, MagnetismoM);
	
  	readimagefile(".\\imagens\\ParLD.bmp", 0, 0, 75, 90); // carrega a imagem
  	getimage(0, 0, 75, 90, R[0]); // captura para o ponteiro R
  	getimage(0, 0, 75, 90, RM[0]); // captura para a máscara RM (a mesma imagem de R, que depois será manipulada na rotina PreparaImg)
  	
  	/*tam = imagesize(0, 0, 99, 150);
  	R[1] = (unsigned char *)malloc(tam);
  	RM[1] = (unsigned char *)malloc(tam);*/
  	readimagefile(".\\imagens\\And1.bmp", 0, 0, 75, 90); 
  	getimage(0, 0, 75, 90, R[1]); 
  	getimage(0, 0, 75, 90, RM[1]);
  	
  	//tam = imagesize(0, 0, 70, 85);
  	readimagefile(".\\imagens\\And2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[2]); 
  	getimage(0, 0, 75, 90, RM[2]);
  	
  	readimagefile(".\\imagens\\And3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[3]); 
  	getimage(0, 0, 75, 90, RM[3]);
  	
  	readimagefile(".\\imagens\\And4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[4]); 
  	getimage(0, 0, 75, 90, RM[4]);
  	
  	readimagefile(".\\imagens\\And5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[5]); 
  	getimage(0, 0, 75, 90, RM[5]);
  	
  	readimagefile(".\\imagens\\And6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[6]); 
  	getimage(0, 0, 75, 90, RM[6]);
  	
  	readimagefile(".\\imagens\\And7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[7]); 
  	getimage(0, 0, 75, 90, RM[7]);
  	
  	readimagefile(".\\imagens\\And8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, R[8]); 
  	getimage(0, 0, 75, 90, RM[8]);
  	
  	
  	//Imgs Pra esquerda
  	
  	readimagefile(".\\imagens\\ParLE.bmp", 0, 0, 75, 90); // carrega a imagem
  	getimage(0, 0, 75, 90, RE[0]); // captura para o ponteiro R
  	getimage(0, 0, 75, 90, REM[0]); // captura para a máscara RM (a mesma imagem de R, que depois será manipulada na rotina PreparaImg)
  	
  	readimagefile(".\\imagens\\invAnd1.bmp", 0, 0, 75, 90); 
  	getimage(0, 0, 75, 90, RE[1]); 
  	getimage(0, 0, 75, 90, REM[1]);
  	
  	readimagefile(".\\imagens\\invAnd2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[2]); 
  	getimage(0, 0, 75, 90, REM[2]);
  	
  	readimagefile(".\\imagens\\invAnd3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[3]); 
  	getimage(0, 0, 75, 90, REM[3]);
  	
  	readimagefile(".\\imagens\\invAnd4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[4]); 
  	getimage(0, 0, 75, 90, REM[4]);
  	
  	readimagefile(".\\imagens\\invAnd5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[5]); 
  	getimage(0, 0, 75, 90, REM[5]);
  	
  	readimagefile(".\\imagens\\invAnd6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[6]); 
  	getimage(0, 0, 75, 90, REM[6]);
  	
  	readimagefile(".\\imagens\\invAnd7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[7]); 
  	getimage(0, 0, 75, 90, REM[7]);
  	
  	readimagefile(".\\imagens\\invAnd8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, RE[8]); 
  	getimage(0, 0, 75, 90, REM[8]);
  	
  	
  	
  	readimagefile(".\\imagens\\Caixa.bmp", 0, 0, 50, 50);
  	getimage(0, 0, 50, 50, C);
  	getimage(0, 0, 50, 50, CM);
  	
  	
  	
  	readimagefile(".\\imagens\\Pul1.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[0]);
  	getimage(0, 0, 75, 90, PUM[0]);
  	
  	readimagefile(".\\imagens\\Pul2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[1]);
  	getimage(0, 0, 75, 90, PUM[1]);
  	
  	readimagefile(".\\imagens\\Pul3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[2]);
  	getimage(0, 0, 75, 90, PUM[2]);
  	
  	readimagefile(".\\imagens\\Pul4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[3]);
  	getimage(0, 0, 75, 90, PUM[3]);
  	
  	readimagefile(".\\imagens\\Pul5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[4]);
  	getimage(0, 0, 75, 90, PUM[4]);
  	
  	readimagefile(".\\imagens\\Pul6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[5]);
  	getimage(0, 0, 75, 90, PUM[5]);
  	
  	readimagefile(".\\imagens\\Pul7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[6]);
  	getimage(0, 0, 75, 90, PUM[6]);
  	
  	readimagefile(".\\imagens\\Pul8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PU[7]);
  	getimage(0, 0, 75, 90, PUM[7]);
  	
  	
  	//Pulo Esqueda
  	
  	readimagefile(".\\imagens\\invPul1.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[0]);
  	getimage(0, 0, 75, 90, PUEM[0]);
  	
  	readimagefile(".\\imagens\\invPul2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[1]);
  	getimage(0, 0, 75, 90, PUEM[1]);
  	
  	readimagefile(".\\imagens\\invPul3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[2]);
  	getimage(0, 0, 75, 90, PUEM[2]);
  	
  	readimagefile(".\\imagens\\invPul4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[3]);
  	getimage(0, 0, 75, 90, PUEM[3]);
  	
  	readimagefile(".\\imagens\\invPul5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[4]);
  	getimage(0, 0, 75, 90, PUEM[4]);
  	
  	readimagefile(".\\imagens\\invPul6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[5]);
  	getimage(0, 0, 75, 90, PUEM[5]);
  	
  	readimagefile(".\\imagens\\invPul7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[6]);
  	getimage(0, 0, 75, 90, PUEM[6]);
  	
  	readimagefile(".\\imagens\\invPul8.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, PUE[7]);
  	getimage(0, 0, 75, 90, PUEM[7]);
  	
  	
  	//Magnetismo Escalando
  	
  	readimagefile(".\\imagens\\Mag1.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, ME[0]);
  	getimage(0, 0, 75, 90, MEM[0]);
  	
  	readimagefile(".\\imagens\\Mag2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, ME[1]);
  	getimage(0, 0, 75, 90, MEM[1]);
  	
  	readimagefile(".\\imagens\\Mag3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, ME[2]);
  	getimage(0, 0, 75, 90, MEM[2]);
  	
  	readimagefile(".\\imagens\\Mag4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, ME[3]);
  	getimage(0, 0, 75, 90, MEM[3]);
  	
  	readimagefile(".\\imagens\\Mag5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, ME[4]);
  	getimage(0, 0, 75, 90, MEM[4]);
  	
  	readimagefile(".\\imagens\\Mag6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, ME[5]);
  	getimage(0, 0, 75, 90, MEM[5]);
  	
  	readimagefile(".\\imagens\\Mag7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, ME[6]);
  	getimage(0, 0, 75, 90, MEM[6]);
  	
  	
  	
  	// Magnetismo Escalando Esquerda
  	
  	readimagefile(".\\imagens\\InvMag1.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, MEI[0]);
  	getimage(0, 0, 75, 90, MEIM[0]);
  	
  	readimagefile(".\\imagens\\InvMag2.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, MEI[1]);
  	getimage(0, 0, 75, 90, MEIM[1]);
  	
  	readimagefile(".\\imagens\\InvMag3.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, MEI[2]);
  	getimage(0, 0, 75, 90, MEIM[2]);
  	
  	readimagefile(".\\imagens\\InvMag4.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, MEI[3]);
  	getimage(0, 0, 75, 90, MEIM[3]);
  	
  	readimagefile(".\\imagens\\InvMag5.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, MEI[4]);
  	getimage(0, 0, 75, 90, MEIM[4]);
  	
  	readimagefile(".\\imagens\\InvMag6.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, MEI[5]);
  	getimage(0, 0, 75, 90, MEIM[5]);
  	
  	readimagefile(".\\imagens\\InvMag7.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, MEI[6]);
  	getimage(0, 0, 75, 90, MEIM[6]);
  	
  	
  	// Escada
  	
  	readimagefile(".\\imagens\\EscD.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, E[0]);
  	getimage(0, 0, 75, 90, EM[0]);
  	
  	readimagefile(".\\imagens\\EscE.bmp", 0, 0, 75, 90);
  	getimage(0, 0, 75, 90, E[1]);
  	getimage(0, 0, 75, 90, EM[1]);
  	
  	for(i = 0; i < QtdRobos; i++)
  	{
  		PreparaImg(tam, RE[i], REM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobos; i++)
  	{
  		PreparaImg(tam, R[i], RM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosPulando; i++)
  	{
  		PreparaImg(tam, PU[i], PUM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosPulando; i++)
  	{
  		PreparaImg(tam, PUE[i], PUEM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosMag; i++)
  	{
  		PreparaImg(tam, ME[i], MEM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosMag; i++)
  	{
  		PreparaImg(tam, MEI[i], MEIM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	for(i = 0; i < QtdRobosEscada; i++)
  	{
  		PreparaImg(tam, E[i], EM[i]); // configura as cores branca e preta em cada pixel para formar o recorte
	}
	
	PreparaImg(tamEscada, Escada, EscadaM);
	PreparaImg(tamMagnetismo, Magnetismo, MagnetismoM);
  	
  	
  	iRobo = 0;
  	xRobo = 105;
	yRobo = 500 - 90;
	posXimg = 0;
	LadoRobo = 1;
	iRoboPula = 0;
	iRoboEscalaMag = 0;

	while(tecla != ESC) {
		
		if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    
	    cleardevice();
  		
		
		putimage(0, 0, Fundo[0], COPY_PUT);
		
		putimage(1100, 400, EscadaM, AND_PUT);
		putimage(1100, 400, Escada, OR_PUT);
		
		
    	/*if(MostraCaixa)
    	{
    		//std::cout << PiscaCaixa << std::endl;
    		if(PiscaCaixa == 0){
    			putimage(300, 450, C, COPY_PUT);
			}
			else{
				if(PiscaCaixa % 2 == 0)
				{
					putimage(300, 450, C, COPY_PUT);
				}
				else{
					
				}
				PiscaCaixa++;
				//std::cout << "E" << std::endl;
				delay(50);
			}
			if(PiscaCaixa >= 10){ MostraCaixa = false; }
		}*/
		
    	//putimage(300, 450, C, COPY_PUT);
    	
    	//putimage(200, 485, CM, OR_PUT);
    	
    	putimage(600, 280, MagnetismoM, AND_PUT);
		putimage(600, 280, Magnetismo, OR_PUT);
		
		putimage(530, 158, MagnetismoM, AND_PUT);
		putimage(530, 158, Magnetismo, OR_PUT);
		
		//DesceEscada = true;
		if(DesceEscada == true)
		{
			if(DescendoEscada == 1)
			{
				putimage(1085, 410, EM[0], AND_PUT);
				putimage(1085, 410, E[0], OR_PUT);
			}
			else if(DescendoEscada == 2)
			{
				putimage(1085, 430, EM[1], AND_PUT);
				putimage(1085, 430, E[1], OR_PUT);
			}
			else if(DescendoEscada == 3)
			{
				putimage(1085, 450, EM[0], AND_PUT);
				putimage(1085, 450, E[0], OR_PUT);
			}
			else if(DescendoEscada == 4)
			{
				putimage(1085, 480, EM[1], AND_PUT);
				putimage(1085, 480, E[1], OR_PUT);
			}
			else if(DescendoEscada == 5)
			{
				putimage(1085, 510, EM[0], AND_PUT);
				putimage(1085, 510, E[0], OR_PUT);
			}
			else if(DescendoEscada == 6)
			{
				putimage(1085, 540, EM[1], AND_PUT);
				putimage(1085, 540, E[1], OR_PUT);
			}
			else if(DescendoEscada == 7)
			{
				putimage(1085, 570, EM[0], AND_PUT);
				putimage(1085, 570, E[0], OR_PUT);
			}
			else if(DescendoEscada == 8)
			{
				putimage(1085, 600, EM[1], AND_PUT);
				putimage(1085, 600, E[1], OR_PUT);
			}
			else if(DescendoEscada == 9)
			{
				putimage(1085, 610, EM[0], AND_PUT);
				putimage(1085, 610, E[0], OR_PUT);
		 	
				
				DesceEscada = false;
				xRobo = 1045;
				yRobo = 610;
			}
			if(DescendoEscada == 9){ 
				DescendoEscada = 0; 
			}
			else{
				DescendoEscada++;
			}
			
			delay(50);
		}
		else if(SobeEscada == true)
		{
			if(SubindoEscada == 1)
			{
				putimage(1085, 610, EM[0], AND_PUT);
				putimage(1085, 610, E[0], OR_PUT);
			}
			else if(SubindoEscada == 2)
			{
				putimage(1085, 600, EM[1], AND_PUT);
				putimage(1085, 600, E[1], OR_PUT);
			}
			else if(SubindoEscada == 3)
			{
				putimage(1085, 570, EM[0], AND_PUT);
				putimage(1085, 570, E[0], OR_PUT);
			}
			else if(SubindoEscada == 4)
			{
				putimage(1085, 540, EM[1], AND_PUT);
				putimage(1085, 540, E[1], OR_PUT);
			}
			else if(SubindoEscada == 5)
			{
				putimage(1085, 510, EM[0], AND_PUT);
				putimage(1085, 510, E[0], OR_PUT);
			}
			else if(SubindoEscada == 6)
			{
				putimage(1085, 480, EM[1], AND_PUT);
				putimage(1085, 480, E[1], OR_PUT);
			}
			else if(SubindoEscada == 7)
			{
				putimage(1085, 450, EM[0], AND_PUT);
				putimage(1085, 450, E[0], OR_PUT);
			}
			else if(SubindoEscada == 8)
			{
				putimage(1085, 430, EM[1], AND_PUT);
				putimage(1085, 430, E[1], OR_PUT);
			}
			else if(SubindoEscada == 9)
			{
				putimage(1085, 410, EM[0], AND_PUT);
				putimage(1085, 410, E[0], OR_PUT);
		 	
				SubindoEscada == 0;
				
				SobeEscada = false;
				xRobo = 1040;
				yRobo = 410;
			}
			if(SubindoEscada == 9){ 
				SubindoEscada = 0; 
			}
			else{
				SubindoEscada++;
			}
			delay(50);
		}
		
		
    	//DesceEscada = true;
    	if(AgarraMagnetismo == false && DesceEscada == false && SobeEscada == false)
    	{
    		if(andaDireita == true)
	    	{
	    		
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, RM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, R[iRobo], OR_PUT);
				}
				xRobo += 20;
				
				
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				delay(10);
			}
			else if(andaEsquerda == true)
			{
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, REM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, RE[iRobo], OR_PUT);
				}
				if((xRobo - 10) <= 0 )
				{
					xRobo = -10;
				} 
				else{
					xRobo -= 20;
				}
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				delay(10);
			}
			else
	    	{
	    		if(pulaRobo == false)
	    		{
	    			if(LadoRobo == 1)
		    		{
		    			putimage(xRobo, yRobo, RM[0], AND_PUT);
						putimage(xRobo, yRobo, R[0], OR_PUT);
					}
					else if(LadoRobo == 0)
					{
						putimage(xRobo, yRobo, REM[0], AND_PUT);
						putimage(xRobo, yRobo, RE[0], OR_PUT);
					}
				}
			}
			if(pulaRobo == true && iRoboPula >= 0)
			{
				//Efeito Sonoro Pulo
				if(iRoboPula == 1){
					sndPlaySound(".\\sons\\som_pulo.wav", SND_ASYNC);
				}
				
				if(LadoRobo == 1)
				{
					putimage(xRobo, yRobo, PUM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PU[iRoboPula - 1], OR_PUT);
				}
				else if(LadoRobo == 0)
				{
					putimage(xRobo, yRobo, PUEM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PUE[iRoboPula - 1], OR_PUT);
				}

				if(yRobo <=20)
				{
					yRobo = 10;
				}
				else if(yRobo >= 0)
				{
					if(iRoboPula >= 5 && not(yRobo == 610))
					{
						yRobo += 20;
					}
					else if(yRobo == 610)
					{ }
					else
					{
						yRobo -= 20;
					}
				}
				iRoboPula++;
				if(iRoboPula > QtdRobosPulando){
					iRoboPula = 0;
					pulaRobo = false; }
				delay(10);
			}
		}
		else if(AgarraMagnetismo == true && DesceEscada == false && SobeEscada == false)
		{
			if(LadoMagnetismo == 1)
			{
				if(iRoboEscalaMag == 1)
				{
					putimage(490, yRobo, MEM[0], AND_PUT);
					putimage(490, yRobo, ME[0], OR_PUT);
				}
				else if(iRoboEscalaMag == 2)
				{
					putimage(505, 370, MEM[1], AND_PUT);
					putimage(505, 370, ME[1], OR_PUT);
				}
				else if(iRoboEscalaMag == 3)
				{
					putimage(530, 310, MEM[2], AND_PUT);
					putimage(530, 310, ME[2], OR_PUT);
				}
				else if(iRoboEscalaMag == 4)
				{
					putimage(540, 280, MEM[3], AND_PUT);
					putimage(540, 280, ME[3], OR_PUT);
				}
				else if(iRoboEscalaMag == 5)
				{
					putimage(548, 270, MEM[4], AND_PUT);
					putimage(548, 270, ME[4], OR_PUT);
				}
				else if(iRoboEscalaMag == 6)
				{
					putimage(555, 240, MEM[5], AND_PUT);
					putimage(555, 240, ME[5], OR_PUT);
				}
				else if(iRoboEscalaMag == 7)
				{
					putimage(580, 210, MEM[6], AND_PUT);
					putimage(580, 210, ME[6], OR_PUT);
					
					AgarraMagnetismo = false;
					xRobo = 590;
					yRobo = 210;
				}
				iRoboEscalaMag++;
				iAgarraMagnetismo++;
				if (iAgarraMagnetismo > iRoboEscalaMag)
				{
					iAgarraMagnetismo = 0;
				}
				//Efeito Sonoro Magnetismo
				if(iAgarraMagnetismo == 1)
				{				
	    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
				}
			}
			else if(LadoMagnetismo == 0)
			{
				if(iRoboEscalaMag == 1)
				{
					putimage(600, 210, MEIM[0], AND_PUT);
					putimage(600, 210, MEI[0], OR_PUT);
				}
				else if(iRoboEscalaMag == 2)
				{
					putimage(585, 210, MEIM[1], AND_PUT);
					putimage(585, 210, MEI[1], OR_PUT);
				}
				else if(iRoboEscalaMag == 3)
				{
					putimage(570, 190, MEIM[2], AND_PUT);
					putimage(570, 190, MEI[2], OR_PUT);
				}
				else if(iRoboEscalaMag == 4)
				{
					putimage(555, 170, MEIM[3], AND_PUT);
					putimage(555, 170, MEI[3], OR_PUT);
				}
				else if(iRoboEscalaMag == 5)
				{
					putimage(530, 150, MEIM[4], AND_PUT);
					putimage(530, 150, MEI[4], OR_PUT);
				}
				else if(iRoboEscalaMag == 6)
				{
					putimage(525, 120, MEIM[5], AND_PUT);
					putimage(525, 120, MEI[5], OR_PUT);
				}
				else if(iRoboEscalaMag == 7)
				{
					putimage(500, 90, MEIM[6], AND_PUT);
					putimage(500, 90, MEI[6], OR_PUT);
					
					AgarraMagnetismo = false;
					xRobo = 490;
					yRobo = 90;
				}
				iRoboEscalaMag++;
				iAgarraMagnetismo++;
				if (iAgarraMagnetismo > iRoboEscalaMag)
				{
					iAgarraMagnetismo = 0;
				}
				//Efeito Sonoro Magnetismo				
				if(iAgarraMagnetismo == 1)
				{
	    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
				}
			}
			delay(50);
		}
		
		
    	
    	
    	if(not((xRobo >= 570 && xRobo <= 750) && (yRobo >= 200 && yRobo <= 220)) && not(yRobo >= 410)
			&& not((xRobo >= 370 && xRobo <= 510) && (yRobo >= 90 && yRobo <= 100)) )
    	{
    		//std::cout << "Entrou1" << std::endl;
    		if(pulaRobo == false && AgarraMagnetismo == false)
			{
				yRobo += 40;
			}
		}
    	
    	
    	
    	andaEsquerda = false;
    	if(GetKeyState(0x41)&0x80)  // A
		{
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			//xRobo -= 10;
			if(not((xRobo >= 400 && xRobo <= 560) && (yRobo - 180 - 20 <= 0)) 
			&& not((yRobo >= 300) && (xRobo >= 700 && xRobo <= 770))
			&& not((yRobo >= 550 && yRobo <= 610) && (xRobo >= 880 && xRobo <= 900))
			&& not((xRobo >= 750 && xRobo <= 780) && (yRobo - 500 <= 0)))
			{
				andaEsquerda = true;
			}
			else if(xRobo >= 400 && yRobo == 90)
			{
				andaEsquerda = true;
			}
			else
			{
				
			}
			LadoRobo = 0;
		}
		andaDireita = false;
    	if(GetKeyState(0x44)&0x80)     // D
		{
			//xRobo += 7;
			//xRobo += 10;
			/*std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;*/
			if(xRobo >= 1280)
			{
				Tela2();
			}
			if(not(yRobo >= 340 && (xRobo + 55 >= 700 && xRobo <= 760))
			&& not((xRobo >= 370 && xRobo <= 560) && ((yRobo + 90) >= 190 && (yRobo + 90) <= 200 ))
			&& not((yRobo >= 550 && yRobo <= 610) && (xRobo >= 1145 && xRobo <= 1155))
			&& not((yRobo >= 300) && (xRobo >= 700 && xRobo <= 760)))
			{
				andaDireita = true;
			}
			/*else{
			}*/
			LadoRobo = 1;
		}
    	if(GetKeyState(0x53)&0x80)   // S Agachar
    	{
    		//PiscaCaixa += 1;
    		if((xRobo == 1090 || xRobo == 1085 || xRobo == 1080 ) && yRobo == 410)
			{
				DesceEscada = true;
				DescendoEscada == 1;
			}
		}
		//pulaRobo = false;
		if(GetKeyState(0x57)&0x80)   // W Pular
    	{
    		if(xRobo == 1085 && yRobo == 610 && SobeEscada == false)
    		{
    			SobeEscada = true;
    			SubindoEscada = 1;
			}
    		else{
    			if( (((xRobo >= 570 && xRobo <= 750) && (yRobo == 210)) || yRobo >= 410
				|| ((xRobo >= 370 && xRobo <= 510) && (yRobo == 90))) && SobeEscada == false
				)
				{
					pulaRobo = true;
    				if(iRoboPula == 0){ iRoboPula = 1; };
				}
			}
		}
		if(GetKeyState(0x4b)&0x80)   // K Agarrar magnetismo
    	{
    		
    		if(LadoRobo == 1)
    		{
    			if((xRobo >= 465 && xRobo <= 545) && yRobo >= 410 && AgarraMagnetismo == false)
	    		{
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
			}
			else if(LadoRobo == 0)
			{
				if((xRobo >= 570 && xRobo <= 630) && (yRobo >= 205 && yRobo <= 220) && AgarraMagnetismo == false)
	    		{
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}
			}
    		//PiscaCaixa += 1;
		}
		if(GetKeyState(0x4c)&0x80)   // L Disparar o braço na direção
    	{
    		//PiscaCaixa += 1;
		}



		setvisualpage(pg);
	
	    delay(100);
	
	    fflush(stdin);
	    if (kbhit())
	      tecla = getch();   
	}
	
	closegraph();	  	
}

void Tela2() {
	
	int pg = 1;
	char tecla = 0;
	char s[50];
	int  x, y, raio;
	double passox, passoy;
	x = 100;
	y = 100;
	raio = 18; 
	passox = 3;
	passoy = 1;
	strcpy(s, "pressione Esc para Sair");
	bool andaDireita = false, andaEsquerda = false, MostraCaixa = true, pulaRobo = false, AgarraMagnetismo = false,
		 DesceEscada = false, SobeEscada = false;
	int iRobo, i, iRoboPula;
	int LadoRobo; // Em direção a esquerda = 0, Em direção a direita = 1
	int PiscaCaixa = 0;
	
	int ELipse[6];
	unsigned char *Escada, *EscadaM;
	
  
  	//char tecla = 0;
	int posXrobo = 100;
	int posYrobo = 100;

	void *T; //Img Fundo
	int FPS;
	unsigned long long gt1, gt2;
	int PosMag1[4];
	int PosObs1[4];
	int PosObs2[4];
	int PosObs3[4];
	int posXimg;	
	int Min (int a, int b);
	int Max (int a, int b);
	int RoboAgarra = 0;
	int iRoboEscalaMag;
	int LadoMagnetismo = 1;
	int DescendoEscada = 0;
	int SubindoEscada = 0;
	int iAgarraMagnetismo;
	
	/*readimagefile(".\\imagens\\Tela2.bmp", 0, 0, GlbLar-1, GlbAlt-1);
	getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);*/
	
  	
  	cleardevice();
  	putimage(0, 0, Fundo[1], COPY_PUT);
  	
  	
  	tamEscada = imagesize(0, 0, 40, 180);
  	
  	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
  	
  	readimagefile(".\\imagens\\EscadaF2.bmp", 0, 0, 40, 180);
  	getimage(0, 0, 40, 180, Escada);
  	getimage(0, 0, 40, 180, EscadaM);
	
	
  	PreparaImg(tamEscada, Escada, EscadaM);
  	
  	iRobo = 0;
  	xRobo = 105;
	yRobo = 500 - 80;
	posXimg = 0;
	LadoRobo = 1;
	iRoboPula = 0;
	iRoboEscalaMag = 0;
	
	
  	
  	while(tecla != ESC) {
  		
  		if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    /* Prepara o fundo */
	    cleardevice();
  		
	
		putimage(0, 0, Fundo[1], COPY_PUT);
		
		
		/*PosObs2[0] = 400;
		PosObs2[1] = 460;
		PosObs2[2] = 660;
		PosObs2[3] = 500;
		bar(PosObs2[0], PosObs2[1], PosObs2[2], PosObs2[3]);*/
		
		
		putimage(1200, 320, EscadaM, AND_PUT);
		putimage(1200, 320, Escada, OR_PUT);
		
		putimage(675, 280, MagnetismoM, AND_PUT);
		putimage(675, 280, Magnetismo, OR_PUT);
		
		
		
		if(SobeEscada == true)
		{
			//std::cout << "Entrou Aqui213212313" << std::endl;
			if(SubindoEscada == 1)
			{
				putimage(1185, 420, EM[0], AND_PUT);
				putimage(1185, 420, E[0], OR_PUT);
			}
			else if(SubindoEscada == 2)
			{
				putimage(1185, 400, EM[1], AND_PUT);
				putimage(1185, 400, E[1], OR_PUT);
			}
			else if(SubindoEscada == 3)
			{
				putimage(1185, 380, EM[0], AND_PUT);
				putimage(1185, 380, E[0], OR_PUT);
			}
			else if(SubindoEscada == 4)
			{
				putimage(1185, 360, EM[1], AND_PUT);
				putimage(1185, 360, E[1], OR_PUT);
			}
			else if(SubindoEscada == 5)
			{
				putimage(1185, 340, EM[1], AND_PUT);
				putimage(1185, 340, E[1], OR_PUT);
			}
			else if(SubindoEscada == 6)
			{
				putimage(1185, 320, EM[0], AND_PUT);
				putimage(1185, 320, E[0], OR_PUT);
		 	
				SubindoEscada == 0;
				
				SobeEscada = false;
				xRobo = 1125;
				yRobo = 320;
				LadoRobo = 0;
			}
			if(SubindoEscada == 6){ 
				SubindoEscada = 0; 
			}
			else{
				SubindoEscada++;
			}			
			//std::cout << "Entrou Aqui" << std::endl;
			delay(60);
		}
		
		//DesceEscada = true;
    	if(AgarraMagnetismo == false && DesceEscada == false && SobeEscada == false)
    	{
    		if(andaDireita == true)
	    	{
	    		
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, RM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, R[iRobo], OR_PUT);
				}
				
				xRobo += 20;
				
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				delay(10);
			}
			else if(andaEsquerda == true)
			{
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, REM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, RE[iRobo], OR_PUT);
				}
				if((xRobo - 10) <= 0 )
				{
					xRobo = -10;
				} 
				else{
					xRobo -= 20;
				}
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				delay(10);
			}
			else
	    	{
	    		if(pulaRobo == false)
	    		{
	    			if(LadoRobo == 1)
		    		{
		    			putimage(xRobo, yRobo, RM[0], AND_PUT);
						putimage(xRobo, yRobo, R[0], OR_PUT);
					}
					else if(LadoRobo == 0)
					{
						putimage(xRobo, yRobo, REM[0], AND_PUT);
						putimage(xRobo, yRobo, RE[0], OR_PUT);
					}
				}
			}
			if(pulaRobo == true && iRoboPula >= 0)
			{
				/*for(i = 0; i < iRoboPula; i++)
				{*/
				if(iRoboPula == 1){
					sndPlaySound(".\\sons\\som_pulo.wav", SND_ASYNC);
				}
				
				if(LadoRobo == 1)
				{
					putimage(xRobo, yRobo, PUM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PU[iRoboPula - 1], OR_PUT);
				}
				else if(LadoRobo == 0)
				{
					putimage(xRobo, yRobo, PUEM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PUE[iRoboPula - 1], OR_PUT);
				}

				if(yRobo <=20)
				{
					yRobo = 10;
				}
				else if(yRobo >= 0)
				{
					if(iRoboPula >= 5)
					{
						if(not((xRobo >= 365 && xRobo <= 625) && (yRobo >= 380 && yRobo <= 390))
							&& not((xRobo >= 730 && xRobo <= 830) && (yRobo >= 180 && yRobo <= 200))
							&& not((xRobo >= 1070 && xRobo <= 1180) && (yRobo >= 320 && yRobo <= 325)))
						{
							yRobo += 20;
						}
					}
					else
					{
						if(not((xRobo >= 1070 && xRobo <= 1180) && (yRobo >= 300 && yRobo <= 310))
						&& not((xRobo >= 780 && xRobo <= 1180) && (yRobo >= 300 && yRobo <= 310))
						&& not((xRobo >= 645 && xRobo <= 705) && (yRobo >= 300 && yRobo <= 320)))
						{
							yRobo -= 20;
						}
					}
				}
				/*std::cout << "yRobo Pulando é === " << std::endl;
				std::cout << yRobo << std::endl;*/
				iRoboPula++;
				if(iRoboPula > QtdRobosPulando){
					iRoboPula = 0;
					pulaRobo = false; }
				delay(10);
			}
		}
		else if(AgarraMagnetismo == true && DesceEscada == false && SobeEscada == false)
		{
			if(LadoMagnetismo == 1)
			{
				if(iRoboEscalaMag == 1)
				{
					putimage(580, yRobo, MEM[0], AND_PUT);
					putimage(580, yRobo, ME[0], OR_PUT);
				}
				else if(iRoboEscalaMag == 2)
				{
					putimage(590, yRobo, MEM[1], AND_PUT);
					putimage(590, yRobo, ME[1], OR_PUT);
				}
				else if(iRoboEscalaMag == 3)
				{
					putimage(600, 335, MEM[2], AND_PUT);
					putimage(600, 335, ME[2], OR_PUT);
				}
				else if(iRoboEscalaMag == 4)
				{
					putimage(615, 310, MEM[3], AND_PUT);
					putimage(615, 310, ME[3], OR_PUT);
				}
				else if(iRoboEscalaMag == 5)
				{
					putimage(635, 275, MEM[4], AND_PUT);
					putimage(635, 275, ME[4], OR_PUT);
				}
				else if(iRoboEscalaMag == 6)
				{
					putimage(640, 245, MEM[5], AND_PUT);
					putimage(640, 245, ME[5], OR_PUT);
				}
				else if(iRoboEscalaMag == 7)
				{
					putimage(660, 220, MEM[6], AND_PUT);
					putimage(660, 220, ME[6], OR_PUT);
					
					AgarraMagnetismo = false;
					xRobo = 670;
					yRobo = 220;
				}
				iRoboEscalaMag++;
				iAgarraMagnetismo++;
				if (iAgarraMagnetismo > iRoboEscalaMag)
				{
					iAgarraMagnetismo = 0;
				}
				//Efeito Sonoro Magnetismo
				if(iAgarraMagnetismo == 1)
				{				
	    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
				}
			}
			else if(LadoMagnetismo == 0)
			{
				if(iRoboEscalaMag == 1)
				{
					putimage(600, 210, MEIM[0], AND_PUT);
					putimage(600, 210, MEI[0], OR_PUT);
				}
				else if(iRoboEscalaMag == 2)
				{
					putimage(585, 210, MEIM[1], AND_PUT);
					putimage(585, 210, MEI[1], OR_PUT);
				}
				else if(iRoboEscalaMag == 3)
				{
					putimage(570, 190, MEIM[2], AND_PUT);
					putimage(570, 190, MEI[2], OR_PUT);
				}
				else if(iRoboEscalaMag == 4)
				{
					putimage(555, 170, MEIM[3], AND_PUT);
					putimage(555, 170, MEI[3], OR_PUT);
				}
				else if(iRoboEscalaMag == 5)
				{
					putimage(530, 150, MEIM[4], AND_PUT);
					putimage(530, 150, MEI[4], OR_PUT);
				}
				else if(iRoboEscalaMag == 6)
				{
					putimage(525, 120, MEIM[5], AND_PUT);
					putimage(525, 120, MEI[5], OR_PUT);
				}
				else if(iRoboEscalaMag == 7)
				{
					putimage(500, 90, MEIM[6], AND_PUT);
					putimage(500, 90, MEI[6], OR_PUT);
					
					AgarraMagnetismo = false;
					xRobo = 490;
					yRobo = 90;
				}
				iRoboEscalaMag++;
				iAgarraMagnetismo++;
				if (iAgarraMagnetismo > iRoboEscalaMag)
				{
					iAgarraMagnetismo = 0;
				}
				//Efeito Sonoro Magnetismo
				if(iAgarraMagnetismo == 1)
				{				
	    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
				}
			}
			delay(50);
		}
		
		
		if(not(yRobo >= 420)
		&& not((xRobo >= 360 && xRobo <= 625) && (yRobo >= 380 && yRobo <= 390))
		&& not((xRobo >= 645 && xRobo <= 715) && (yRobo >= 220 && yRobo <= 250))
		&& not((xRobo >= 730 && xRobo <= 1180) && (yRobo >= 100 && yRobo <= 200))
		&& not((xRobo >= 1070 && xRobo <= 1180) && (yRobo == 320)))
    	{
    		//std::cout << "Entrou1" << std::endl;
    		if(pulaRobo == false && AgarraMagnetismo == false)
			{
				yRobo += 40;
				if(yRobo > 420)
				{
					yRobo = 420;
				}
				else if((xRobo >= 370 && xRobo <= 605) && (yRobo > 380))
				{
					yRobo = 380;
				}
			}
		}
		
		andaEsquerda = false;
    	if(GetKeyState(0x41)&0x80)  // A
		{
			
			if(not((yRobo >= 400 && yRobo <= 480) && (xRobo <= 655 && xRobo >= 630))
			&& not((xRobo >= 880 && xRobo <= 890) && (yRobo >= 340 && yRobo < 420)))
			{
				andaEsquerda = true;
			}
			
			LadoRobo = 0;
		}
		andaDireita = false;
    	if(GetKeyState(0x44)&0x80)     // D
		{
			/*std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;*/
			
			if(not((yRobo >= 400 && yRobo <= 480) && (xRobo >= 340 && xRobo <= 355))
			&& not((xRobo >= 705 && xRobo <= 745) && (yRobo >= 260 && yRobo <= 400))
			&& not((xRobo >= 1060 && xRobo <= 1070) && (yRobo >= 340 && yRobo < 420))
			&& not((xRobo >= 1185) && (yRobo >= 300))
			&& not((xRobo >= 700 && xRobo <= 720) && yRobo >= 200 && yRobo <= 220)
			&& not((xRobo >= 1130) && yRobo <= 180))
			{
				andaDireita = true;
			}
			LadoRobo = 1;
		}
    	if(GetKeyState(0x53)&0x80)   // S Agachar
    	{
    		//PiscaCaixa += 1;
    		/*if(yRobo + 90 < 490)
			{
	    		yRobo += 10;
    		}*/
		}
		//pulaRobo = false;
		if(GetKeyState(0x57)&0x80)   // W Pular
    	{
    		if((xRobo >= 1180 && xRobo <= 1190) && yRobo == 420 && SobeEscada == false)
    		{
    			SobeEscada = true;
    			SubindoEscada = 1;
			}
    		else if(not((xRobo >= 725 && xRobo <= 870) && (yRobo >= 380))
			&& not((xRobo >= 1085 && xRobo <= 1170) && (yRobo >= 420))
			&& ((yRobo >= 420) || ((xRobo >= 360 && xRobo <= 625) && (yRobo == 380))
			|| ((xRobo >= 645 && xRobo <= 715) && (yRobo == 220))
			|| ((xRobo >= 730 && xRobo <= 1180) && (yRobo == 180))
			|| ((xRobo >= 1070 && xRobo <= 1180) && (yRobo == 320)))
			&& SobeEscada == false)
    		{
    			pulaRobo = true;
    			if(iRoboPula == 0){ iRoboPula = 1; };
			}
			//}
		}
		if(GetKeyState(0x4b)&0x80)   // K Agarrar magnetismo
    	{
    		
    		if(LadoRobo == 1)
    		{
    			if((xRobo >= 530 && xRobo <= 610) && yRobo >= 380 && AgarraMagnetismo == false)
	    		{
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
			}
			else if(LadoRobo == 0)
			{
				if((xRobo >= 570 && xRobo <= 630) && (yRobo >= 205 && yRobo <= 220) && AgarraMagnetismo == false)
	    		{
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}
			}
    		//PiscaCaixa += 1;
		}
		if(GetKeyState(0x4c)&0x80)   // L Disparar o braço na direção
    	{
    		//PiscaCaixa += 1;
		}
		setvisualpage(pg);
		
		delay(100);
	
		fflush(stdin);
		if (kbhit())
	    tecla = getch(); 
	    
  	}	
}







void Tela3() {
	int pg = 1;
	char tecla = 0;
	bool andaDireita = false, andaEsquerda = false, MostraCaixa = true, pulaRobo = false, AgarraMagnetismo = false,
		 DesceEscada = false, SobeEscada = false;
	int iRobo, i, iRoboPula;
	int LadoRobo; // Em direção a esquerda = 0, Em direção a direita = 1
	int PiscaCaixa = 0;
	int ELipse[6];
	int posXrobo = 100;
	int posYrobo = 100;
	int FPS;
	unsigned long long gt1, gt2;
	int PosMag1[4];
	int PosObs1[4];
	int PosObs2[4];
	int PosObs3[4];
	int posXimg;	
	int Min (int a, int b);
	int Max (int a, int b);
	int RoboAgarra = 0;
	int iRoboEscalaMag;
	int LadoMagnetismo = 1;
	int DescendoEscada = 0;
	int SubindoEscada = 0;
	int iAgarraMagnetismo;
	int nMagnetismo = 0;
	unsigned char *Escada, *EscadaM;

  	cleardevice();

  	putimage(0, 0, Fundo[2], COPY_PUT); 	

	/*tamEscada = imagesize(0, 0, 40, 250);
  	
  	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
  	
  	readimagefile(".\\imagens\\EscadaF4.bmp", 0, 0, 40, 250);
  	getimage(0, 0, 40, 250, Escada);
  	getimage(0, 0, 40, 250, EscadaM);
  	
  	PreparaImg(tamEscada, Escada, EscadaM);*/
  	
  	
  	iRobo = 0;
  	xRobo = 105;
	yRobo = 500 - 80;
	posXimg = 0;
	LadoRobo = 1;
	iRoboPula = 0;
	iRoboEscalaMag = 0;
	
	/*xRobo = 500;
	yRobo = 100;*/

	while(tecla != ESC) {
		
		if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    /* Prepara o fundo */
	    cleardevice();
  		
		
		putimage(0, 0, Fundo[2], COPY_PUT);
		
		/*putimage(1195, 445, EscadaM, AND_PUT);
		putimage(1195, 445, Escada, OR_PUT);*/
		
		/*PosObs3[0] = 1000;
		PosObs3[1] = ;
		PosObs3[2] = 800;
		PosObs3[3] = 500;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/

    	
    	
    	/*if(MostraCaixa)
    	{
    		//std::cout << PiscaCaixa << std::endl;
    		if(PiscaCaixa == 0){
    			putimage(300, 450, C, COPY_PUT);
			}
			else{
				if(PiscaCaixa % 2 == 0)
				{
					putimage(300, 450, C, COPY_PUT);
				}
				else{
					
				}
				PiscaCaixa++;
				//std::cout << "E" << std::endl;
				delay(50);
			}
			if(PiscaCaixa >= 10){ MostraCaixa = false; }
		}*/
		
    	//putimage(300, 450, C, COPY_PUT);
    	
    	//putimage(200, 485, CM, OR_PUT);
		
		putimage(420, 300, MagnetismoM, AND_PUT);
		putimage(420, 300, Magnetismo, OR_PUT);
		
		putimage(800, 380, MagnetismoM, AND_PUT);
		putimage(800, 380, Magnetismo, OR_PUT);
		
		putimage(1140, 500, MagnetismoM, AND_PUT);
		putimage(1140, 500, Magnetismo, OR_PUT);
		
		/*if((xRobo == 1090 || xRobo == 1085 || xRobo == 1080 ) && yRobo == 410)
		{
			std::cout << "Entrou aqui ASBDUIAH" << std::endl;
			DesceEscada = true;
			DescendoEscada == 1;
		}*/
		//DesceEscada = true;
		if(DesceEscada == true)
		{
			if(DescendoEscada == 1)
			{
				putimage(1085, 410, EM[0], AND_PUT);
				putimage(1085, 410, E[0], OR_PUT);
			}
			else if(DescendoEscada == 2)
			{
				putimage(1085, 430, EM[1], AND_PUT);
				putimage(1085, 430, E[1], OR_PUT);
			}
			else if(DescendoEscada == 3)
			{
				putimage(1085, 450, EM[0], AND_PUT);
				putimage(1085, 450, E[0], OR_PUT);
			}
			else if(DescendoEscada == 4)
			{
				putimage(1085, 480, EM[1], AND_PUT);
				putimage(1085, 480, E[1], OR_PUT);
			}
			else if(DescendoEscada == 5)
			{
				putimage(1085, 510, EM[0], AND_PUT);
				putimage(1085, 510, E[0], OR_PUT);
			}
			else if(DescendoEscada == 6)
			{
				putimage(1085, 540, EM[1], AND_PUT);
				putimage(1085, 540, E[1], OR_PUT);
			}
			else if(DescendoEscada == 7)
			{
				putimage(1085, 570, EM[0], AND_PUT);
				putimage(1085, 570, E[0], OR_PUT);
			}
			else if(DescendoEscada == 8)
			{
				putimage(1085, 600, EM[1], AND_PUT);
				putimage(1085, 600, E[1], OR_PUT);
			}
			else if(DescendoEscada == 9)
			{
				putimage(1085, 610, EM[0], AND_PUT);
				putimage(1085, 610, E[0], OR_PUT);
		 	
				
				DesceEscada = false;
				xRobo = 1045;
				yRobo = 610;
			}
			if(DescendoEscada == 9){ 
				DescendoEscada = 0; 
			}
			else{
				DescendoEscada++;
			}
			//putimage(xRobo, yRobo, REM[0], AND_PUT);
			//putimage(xRobo, yRobo, RE[0], OR_PUT);
			
			//std::cout << "Entrou Aqui" << std::endl;
			delay(50);
		}
		else if(SobeEscada == true)
		{
			//std::cout << "Entrou Aqui213212313" << std::endl;
			if(SubindoEscada == 1)
			{
				putimage(1085, 610, EM[0], AND_PUT);
				putimage(1085, 610, E[0], OR_PUT);
			}
			else if(SubindoEscada == 2)
			{
				putimage(1085, 600, EM[1], AND_PUT);
				putimage(1085, 600, E[1], OR_PUT);
			}
			else if(SubindoEscada == 3)
			{
				putimage(1085, 570, EM[0], AND_PUT);
				putimage(1085, 570, E[0], OR_PUT);
			}
			else if(SubindoEscada == 4)
			{
				putimage(1085, 540, EM[1], AND_PUT);
				putimage(1085, 540, E[1], OR_PUT);
			}
			else if(SubindoEscada == 5)
			{
				putimage(1085, 510, EM[0], AND_PUT);
				putimage(1085, 510, E[0], OR_PUT);
			}
			else if(SubindoEscada == 6)
			{
				putimage(1085, 480, EM[1], AND_PUT);
				putimage(1085, 480, E[1], OR_PUT);
			}
			else if(SubindoEscada == 7)
			{
				putimage(1085, 450, EM[0], AND_PUT);
				putimage(1085, 450, E[0], OR_PUT);
			}
			else if(SubindoEscada == 8)
			{
				putimage(1085, 430, EM[1], AND_PUT);
				putimage(1085, 430, E[1], OR_PUT);
			}
			else if(SubindoEscada == 9)
			{
				putimage(1085, 410, EM[0], AND_PUT);
				putimage(1085, 410, E[0], OR_PUT);
		 	
				SubindoEscada == 0;
				
				SobeEscada = false;
				xRobo = 1040;
				yRobo = 410;
			}
			if(SubindoEscada == 9){ 
				SubindoEscada = 0; 
			}
			else{
				SubindoEscada++;
			}
			
			delay(50);
		}
		
		
		
		
		
		
		
		
    	//DesceEscada = true;
    	if(AgarraMagnetismo == false && DesceEscada == false && SobeEscada == false)
    	{
    		if(andaDireita == true)
	    	{
	    	
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, RM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, R[iRobo], OR_PUT);
				}
				xRobo += 20;
				
				
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				delay(10);
			}
			else if(andaEsquerda == true)
			{
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, REM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, RE[iRobo], OR_PUT);
				}
				if((xRobo - 10) <= 0 )
				{
					xRobo = -10;
				} 
				else{
					xRobo -= 20;
				}
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				delay(10);
			}
			else
	    	{
	    		if(pulaRobo == false)
	    		{
	    			if(LadoRobo == 1)
		    		{
		    			putimage(xRobo, yRobo, RM[0], AND_PUT);
						putimage(xRobo, yRobo, R[0], OR_PUT);
					}
					else if(LadoRobo == 0)
					{
						putimage(xRobo, yRobo, REM[0], AND_PUT);
						putimage(xRobo, yRobo, RE[0], OR_PUT);
					}
				}
			}
			if(pulaRobo == true && iRoboPula >= 0)
			{
				/*for(i = 0; i < iRoboPula; i++)
				{*/
				if(iRoboPula == 1){
					sndPlaySound(".\\sons\\som_pulo.wav", SND_ASYNC);
				}
				if(LadoRobo == 1)
				{
					putimage(xRobo, yRobo, PUM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PU[iRoboPula - 1], OR_PUT);
				}
				else if(LadoRobo == 0)
				{
					putimage(xRobo, yRobo, PUEM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PUE[iRoboPula - 1], OR_PUT);
				}
				
					//iRoboPula++;
				//}
				/*std::cout << "yRobo Ficou" << std::endl;
				std::cout << yRobo << std::endl;
				std::cout << xRobo << std::endl;*/
				if(yRobo < 0)
				{
					yRobo = 10;
				}
				else if(yRobo >= 0)
				{
					
					//if(iRoboPula >= 5 && not(yRobo == 610))
					/*std::cout << iRoboPula << std::endl;
					std::cout << QtdRobosPulando << std::endl;*/
					if((xRobo >= 765 && xRobo <= 805) && yRobo >= 535 && yRobo <= 545)
					{ }
					else if(((xRobo >= 885 && xRobo <= 1125) && (yRobo >= 440 && yRobo <= 440)))
					{ }
					else if(iRoboPula >= 5)
					{
						if(not(yRobo == 620)
						&& not((xRobo >= 740 && xRobo <= 805) && (yRobo >= 530 && yRobo <= 580))
						&& not((xRobo >= 820 && xRobo <= 865) && (yRobo >= 530 && yRobo <= 580))
						&& not((xRobo >= 960 && xRobo <= 1240) && (yRobo >= 80 && yRobo <= 80)))
						{
							yRobo += 20;
						}
					}
					else
					{
						yRobo -= 20;
					}
					
					/*else if(yRobo == 610)
					{ }*/
					
				}
				iRoboPula++;
				if(iRoboPula > QtdRobosPulando){
					iRoboPula = 0;
					pulaRobo = false; }
				
				delay(10);
			}
		}
		else if(AgarraMagnetismo == true && DesceEscada == false && SobeEscada == false)
		{
			if(LadoMagnetismo == 1)
			{
				if(nMagnetismo == 2)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(700, 620, MEM[0], AND_PUT);
						putimage(700, 620, ME[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(700, 580, MEM[1], AND_PUT);
						putimage(700, 580, ME[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(710, 560, MEM[1], AND_PUT);
						putimage(710, 560, ME[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(720, 520, MEM[2], AND_PUT);
						putimage(720, 520, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{	
						putimage(720, 490, MEM[2], AND_PUT);
						putimage(720, 490, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(725, 460, MEM[3], AND_PUT);
						putimage(725, 460, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{	
						putimage(730, 420, MEM[3], AND_PUT);
						putimage(730, 420, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 8)
					{	
						putimage(735, 400, MEM[3], AND_PUT);
						putimage(735, 400, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 9)
					{
						putimage(755, 370, MEM[4], AND_PUT);
						putimage(755, 370, ME[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 10)
					{
						putimage(760, 348, MEM[5], AND_PUT);
						putimage(760, 348, ME[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 11)
					{
						putimage(775, 320, MEM[6], AND_PUT);
						putimage(775, 320, ME[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 785;
						yRobo = 320;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
				    if (iAgarraMagnetismo > iRoboEscalaMag)
				    {
					    iAgarraMagnetismo = 0;
				    }
				    //Efeito Sonoro Magnetismo
				    if(iAgarraMagnetismo == 1)
				    {				
    	    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
    				}
				}
				
			}
			else if(LadoMagnetismo == 0)
			{
				/*if(iRoboEscalaMag == 1)
				{
					putimage(600, 210, MEIM[0], AND_PUT);
					putimage(600, 210, MEI[0], OR_PUT);
				}
				else if(iRoboEscalaMag == 2)
				{
					putimage(585, 210, MEIM[1], AND_PUT);
					putimage(585, 210, MEI[1], OR_PUT);
				}
				else if(iRoboEscalaMag == 3)
				{
					putimage(570, 190, MEIM[2], AND_PUT);
					putimage(570, 190, MEI[2], OR_PUT);
				}
				else if(iRoboEscalaMag == 4)
				{
					putimage(555, 170, MEIM[3], AND_PUT);
					putimage(555, 170, MEI[3], OR_PUT);
				}
				else if(iRoboEscalaMag == 5)
				{
					putimage(530, 150, MEIM[4], AND_PUT);
					putimage(530, 150, MEI[4], OR_PUT);
				}
				else if(iRoboEscalaMag == 6)
				{
					putimage(525, 120, MEIM[5], AND_PUT);
					putimage(525, 120, MEI[5], OR_PUT);
				}
				else if(iRoboEscalaMag == 7)
				{
					putimage(500, 90, MEIM[6], AND_PUT);
					putimage(500, 90, MEI[6], OR_PUT);
					
					AgarraMagnetismo = false;
					xRobo = 490;
					yRobo = 90;
				}*/
				
				
				
				if(nMagnetismo == 3)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(1185, 620, MEIM[0], AND_PUT);
						putimage(1185, 620, MEI[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(1180, 620, MEIM[1], AND_PUT);
						putimage(1180, 620, MEI[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(1160, 575, MEIM[2], AND_PUT);
						putimage(1160, 575, MEI[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(1145, 545, MEIM[3], AND_PUT);
						putimage(1145, 545, MEI[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(1130, 490, MEIM[4], AND_PUT);
						putimage(1130, 490, MEI[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(1130, 470, MEIM[5], AND_PUT);
						putimage(1130, 470, MEI[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(1105, 440, MEIM[6], AND_PUT);
						putimage(1105, 440, MEI[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 1105;
						yRobo = 440;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
				
			}
			delay(50);
		}
		
		
		if(not((xRobo >= 60 && xRobo <= 565) && (yRobo >= 420))
		&& not((xRobo >= 300 && xRobo <= 400) && (yRobo >= 220 && yRobo <= 240))
		&& not((xRobo >= 420 && xRobo <= 520) && (yRobo == 100))
		&& not((xRobo >= 600 && xRobo <= 700) && (yRobo == 100))
		&& not((xRobo >= 780 && xRobo <= 880) && (yRobo == 100))
		&& not((xRobo >= 960 && xRobo <= 1240) && (yRobo >= 80 && yRobo <= 120)) 
		&& not((xRobo >= 760 && xRobo <= 1280) && (yRobo >= 320 && yRobo <= 340))
		&& not((xRobo >= 640 && xRobo <= 800) && (yRobo >= 620 && yRobo <= 640))
		&& not((xRobo >= 740 && xRobo <= 825) && (yRobo >= 520 && yRobo <= 560))
		&& not((xRobo >= 885 && xRobo <= 1125) && (yRobo >= 440 && yRobo <= 440))
		&& not((xRobo >= 820 && xRobo <= 1240) && (yRobo >= 620)))
    	{
    		//std::cout << "Entrou1" << std::endl;
    		if(pulaRobo == false && AgarraMagnetismo == false)
			{
				if((xRobo >= 780 && xRobo <= 880) && (yRobo == 80) && pulaRobo == false)
				{
					yRobo = 100;
				}
				else{
					yRobo += 40;
				}
			}
			if((xRobo >= 680 && xRobo <= 1240) && (yRobo > 620)){
				yRobo = 620;
			}
			if((xRobo >= 320 && xRobo <= 420) && (yRobo >= 220 && yRobo <= 240)){
				yRobo = 240;
			}
			if((xRobo >= 60 && xRobo <= 565) && (yRobo >= 420 && yRobo <= 440)){
				yRobo = 420;
			}
			if((xRobo >= 760 && xRobo <= 1280) && (yRobo >= 320 && yRobo <= 340)){
				yRobo = 320;
			}
		}
		/*xRobo = 785;
		yRobo = 320;*/
    	
    	
    	
    	andaEsquerda = false;
    	if(GetKeyState(0x41)&0x80)  // A
		{
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			if(not((xRobo >= 830 && xRobo <= 850) && (yRobo >= 560 && yRobo <= 620))
			&& not((xRobo >= 800 && xRobo <= 820) && (yRobo >= 350 && yRobo <= 520))
			&& not((xRobo >= 450 && xRobo <= 585) && (yRobo > 420))
			)
			{
				andaEsquerda = true;
			}
			LadoRobo = 0;
		}
		andaDireita = false;
    	if(GetKeyState(0x44)&0x80)     // D
		{
			//xRobo += 7;
			//xRobo += 10;
			/*std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;*/
			if(xRobo >= 1280)
			{
				Tela4();
			}
			else if(not((xRobo >= 725 && xRobo <= 740) && yRobo >= 570)
			&& not(xRobo >= 1180 && (yRobo >= 420)) && not((xRobo >= 40 && xRobo <= 565) && (yRobo > 420))
			&& not((xRobo >= 745 && xRobo <= 760) && (yRobo >= 350 && yRobo <= 520))
			&& not((xRobo >= 860 && xRobo <= 1140) && (yRobo >= 460 && yRobo <= 540))
			&& not((xRobo >= 980 && xRobo <= 1060) && (yRobo >= 90 && yRobo <= 140))
			)
			{
				andaDireita = true;
			}
			
			LadoRobo = 1;
		}
    	if(GetKeyState(0x53)&0x80)   // S Agachar
    	{
    		//PiscaCaixa += 1;
    		if((xRobo == 1090 || xRobo == 1085 || xRobo == 1080 ) && yRobo == 410)
			{
				std::cout << "Entrou aqui ASBDUIAH" << std::endl;
				DesceEscada = true;
				DescendoEscada == 1;
			}
		}
		//pulaRobo = false;
		if(GetKeyState(0x57)&0x80)   // W Pular
    	{
    		/*if(xRobo == 1085 && yRobo == 610 && SobeEscada == false)
    		{
    			SobeEscada = true;
    			SubindoEscada = 1;
			}
    		else{*/
    		if(((xRobo >= 60 && xRobo <= 565) && (yRobo >= 420))
			|| ((xRobo >= 300 && xRobo <= 400) && (yRobo >= 220 && yRobo <= 240))
			|| ((xRobo >= 420 && xRobo <= 520) && (yRobo == 100))
			|| ((xRobo >= 600 && xRobo <= 700) && (yRobo == 100))
			|| ((xRobo >= 780 && xRobo <= 880) && (yRobo == 100))
			|| ((xRobo >= 960 && xRobo <= 1240) && (yRobo >= 80 && yRobo <= 120))
			|| ((xRobo >= 760 && xRobo <= 1280) && (yRobo >= 320 && yRobo <= 340))
			|| ((xRobo >= 640 && xRobo <= 800) && (yRobo >= 620 && yRobo <= 640))
			|| ((xRobo >= 740 && xRobo <= 825) && (yRobo >= 520 && yRobo <= 560))
			|| ((xRobo >= 885 && xRobo <= 1125) && (yRobo >= 440 && yRobo <= 440))
			|| ((xRobo >= 820 && xRobo <= 1240) && (yRobo >= 620)))
			{
    			pulaRobo = true;
    			if(iRoboPula == 0){ iRoboPula = 1; };
    		}
			//}
		}
		if(GetKeyState(0x4b)&0x80)   // K Agarrar magnetismo
    	{
    		
    		if(LadoRobo == 1)
    		{
    			if((xRobo >= 685 && xRobo <= 725) && yRobo == 620 && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 2;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
				else if((xRobo >= 1165 && xRobo <= 1185) && (yRobo == 620) && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 3;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}
			}
			else if(LadoRobo == 0)
			{
				if((xRobo >= 1165 && xRobo <= 1185) && (yRobo == 620) && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 3;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}
			}
    		//PiscaCaixa += 1;
		}
		if(GetKeyState(0x4c)&0x80)   // L Disparar o braço na direção
    	{
    		//PiscaCaixa += 1;
    		
		}



		setvisualpage(pg);
	
	    delay(100);
	
	    fflush(stdin);
	    if (kbhit())
	      tecla = getch();   
	}
	
	closegraph();	

  	
}







void Tela4() {
	int pg = 1;
	char tecla = 0;
	bool andaDireita = false, andaEsquerda = false, MostraCaixa = true, pulaRobo = false, AgarraMagnetismo = false,
		 DesceEscada = false, SobeEscada = false, Caindo = false;
	int iRobo, i, iRoboPula;
	int LadoRobo; // Em direção a esquerda = 0, Em direção a direita = 1
	int PiscaCaixa = 0;
	int ELipse[6];
	int posXrobo = 100;
	int posYrobo = 100;
	int FPS;
	unsigned long long gt1, gt2;
	int PosMag1[4];
	int PosObs1[4];
	int PosObs2[4];
	int PosObs3[4];
	int posXimg;	
	int Min (int a, int b);
	int Max (int a, int b);
	int RoboAgarra = 0;
	int iRoboEscalaMag;
	int LadoMagnetismo = 1;
	int DescendoEscada = 0;
	int SubindoEscada = 0;
	int iAgarraMagnetismo;
	int nMagnetismo = 0;
	unsigned char *Escada, *EscadaM;

  	cleardevice();

  	putimage(0, 0, Fundo[3], COPY_PUT); 	

	tamEscada = imagesize(0, 0, 40, 250);
  	
  	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
  	
  	readimagefile(".\\imagens\\EscadaF4.bmp", 0, 0, 40, 240);
  	getimage(0, 0, 40, 240, Escada);
  	getimage(0, 0, 40, 240, EscadaM);
  	
  	PreparaImg(tamEscada, Escada, EscadaM);
  	
  	
  	iRobo = 0;
  	xRobo = 100;
	yRobo = 400 - 80;
	posXimg = 0;
	LadoRobo = 1;
	iRoboPula = 0;
	iRoboEscalaMag = 0;
	
	/*xRobo = 500;
	yRobo = 100;*/

	while(tecla != ESC) {
		
		if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    /* Prepara o fundo */
	    cleardevice();
  		
		
		putimage(0, 0, Fundo[3], COPY_PUT);
		
		putimage(155, 460, EscadaM, AND_PUT);
		putimage(155, 460, Escada, OR_PUT);
		
		/*PosObs3[0] = 1000;
		PosObs3[1] = ;
		PosObs3[2] = 800;
		PosObs3[3] = 500;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/

    	
    	
    	/*if(MostraCaixa)
    	{
    		//std::cout << PiscaCaixa << std::endl;
    		if(PiscaCaixa == 0){
    			putimage(300, 450, C, COPY_PUT);
			}
			else{
				if(PiscaCaixa % 2 == 0)
				{
					putimage(300, 450, C, COPY_PUT);
				}
				else{
					
				}
				PiscaCaixa++;
				//std::cout << "E" << std::endl;
				delay(50);
			}
			if(PiscaCaixa >= 10){ MostraCaixa = false; }
		}*/
		
    	//putimage(300, 450, C, COPY_PUT);
    	
    	//putimage(200, 485, CM, OR_PUT);
		
		putimage(400, 280, MagnetismoM, AND_PUT);
		putimage(400, 280, Magnetismo, OR_PUT);
		
		putimage(280, 140, MagnetismoM, AND_PUT);
		putimage(280, 140, Magnetismo, OR_PUT);
		
		/*putimage(1140, 500, MagnetismoM, AND_PUT);
		putimage(1140, 500, Magnetismo, OR_PUT);*/
		
		/*if((xRobo == 1090 || xRobo == 1085 || xRobo == 1080 ) && yRobo == 410)
		{
			std::cout << "Entrou aqui ASBDUIAH" << std::endl;
			DesceEscada = true;
			DescendoEscada == 1;
		}*/
		//DesceEscada = true;
		if(DesceEscada == true)
		{
			if(DescendoEscada == 1)
			{
				putimage(140, 460, EM[0], AND_PUT);
				putimage(140, 460, E[0], OR_PUT);
			}
			else if(DescendoEscada == 2)
			{
				putimage(140, 460, EM[1], AND_PUT);
				putimage(140, 460, E[1], OR_PUT);
			}
			else if(DescendoEscada == 3)
			{
				putimage(140, 480, EM[0], AND_PUT);
				putimage(140, 480, E[0], OR_PUT);
			}
			else if(DescendoEscada == 4)
			{
				putimage(140, 500, EM[1], AND_PUT);
				putimage(140, 500, E[1], OR_PUT);
			}
			else if(DescendoEscada == 5)
			{
				putimage(140, 520, EM[0], AND_PUT);
				putimage(140, 520, E[0], OR_PUT);
			}
			else if(DescendoEscada == 6)
			{
				putimage(140, 540, EM[1], AND_PUT);
				putimage(140, 540, E[1], OR_PUT);
			}
			else if(DescendoEscada == 7)
			{
				putimage(140, 560, EM[0], AND_PUT);
				putimage(140, 560, E[0], OR_PUT);
			}
			else if(DescendoEscada == 8)
			{
				putimage(140, 580, EM[1], AND_PUT);
				putimage(140, 580, E[1], OR_PUT);
			}
			else if(DescendoEscada == 9)
			{
				putimage(140, 600, EM[0], AND_PUT);
				putimage(140, 600, E[0], OR_PUT);
		 	
				
				DesceEscada = false;
				xRobo = 140;
				yRobo = 620;
			}
			if(DescendoEscada == 9){ 
				DescendoEscada = 0; 
			}
			else{
				DescendoEscada++;
			}
			//putimage(xRobo, yRobo, REM[0], AND_PUT);
			//putimage(xRobo, yRobo, RE[0], OR_PUT);
			
			//std::cout << "Entrou Aqui" << std::endl;
			delay(100);
		}
		else if(SobeEscada == true)
		{
			//std::cout << "Entrou Aqui213212313" << std::endl;
			if(SubindoEscada == 1)
			{
				putimage(140, 600, EM[0], AND_PUT);
				putimage(140, 600, E[0], OR_PUT);
			}
			else if(SubindoEscada == 2)
			{
				putimage(140, 580, EM[1], AND_PUT);
				putimage(140, 580, E[1], OR_PUT);
			}
			else if(SubindoEscada == 3)
			{
				putimage(140, 560, EM[0], AND_PUT);
				putimage(140, 560, E[0], OR_PUT);
			}
			else if(SubindoEscada == 4)
			{
				putimage(140, 540, EM[1], AND_PUT);
				putimage(140, 540, E[1], OR_PUT);
			}
			else if(SubindoEscada == 5)
			{
				putimage(140, 520, EM[0], AND_PUT);
				putimage(140, 520, E[0], OR_PUT);
			}
			else if(SubindoEscada == 6)
			{
				putimage(140, 500, EM[1], AND_PUT);
				putimage(140, 500, E[1], OR_PUT);
			}
			else if(SubindoEscada == 7)
			{
				putimage(140, 480, EM[0], AND_PUT);
				putimage(140, 480, E[0], OR_PUT);
			}
			else if(SubindoEscada == 8)
			{
				putimage(140, 460, EM[1], AND_PUT);
				putimage(140, 460, E[1], OR_PUT);
			}
			else if(SubindoEscada == 9)
			{
				putimage(140, 460, EM[0], AND_PUT);
				putimage(140, 460, E[0], OR_PUT);
		 	
				SubindoEscada == 0;
				
				SobeEscada = false;
				xRobo = 180;
				yRobo = 460;
			}
			if(SubindoEscada == 9){ 
				SubindoEscada = 0; 
			}
			else{
				SubindoEscada++;
			}
			
			delay(100);
		}
		
		
		
		
		
		
		
    	//DesceEscada = true;
    	if(AgarraMagnetismo == false && DesceEscada == false && SobeEscada == false)
    	{
    		if(andaDireita == true)
	    	{
	    	
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, RM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, R[iRobo], OR_PUT);
				}
				xRobo += 20;
				
				
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				if(pulaRobo == true){
					delay(20);
				}
				else if(Caindo == true){
					delay(25);
				}
				else{
					delay(70);
				}
			}
			else if(andaEsquerda == true)
			{
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, REM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, RE[iRobo], OR_PUT);
				}
				if((xRobo - 10) <= 0 )
				{
					xRobo = -10;
				} 
				else{
					xRobo -= 20;
				}
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				if(pulaRobo == true){
					delay(20);
				}
				else if(Caindo == true){
					delay(25);
				}
				else{
					delay(70);
				}
			}
			else
	    	{
	    		if(pulaRobo == false)
	    		{
	    			if(LadoRobo == 1)
		    		{
		    			putimage(xRobo, yRobo, RM[0], AND_PUT);
						putimage(xRobo, yRobo, R[0], OR_PUT);
					}
					else if(LadoRobo == 0)
					{
						putimage(xRobo, yRobo, REM[0], AND_PUT);
						putimage(xRobo, yRobo, RE[0], OR_PUT);
					}
				}
			}
			if(pulaRobo == true && iRoboPula >= 0)
			{
				/*for(i = 0; i < iRoboPula; i++)
				{*/
				if(iRoboPula == 1){
					sndPlaySound(".\\sons\\som_pulo.wav", SND_ASYNC);
				}
				if(LadoRobo == 1)
				{
					putimage(xRobo, yRobo, PUM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PU[iRoboPula - 1], OR_PUT);
				}
				else if(LadoRobo == 0)
				{
					putimage(xRobo, yRobo, PUEM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PUE[iRoboPula - 1], OR_PUT);
				}
				
					//iRoboPula++;
				//}
				std::cout << "yRobo Ficou" << std::endl;
				std::cout << yRobo << std::endl;
				std::cout << xRobo << std::endl;
				if(yRobo < 0)
				{
					yRobo = 10;
				}
				else if(yRobo >= 0)
				{
					
					//if(iRoboPula >= 5 && not(yRobo == 610))
					/*std::cout << iRoboPula << std::endl;
					std::cout << QtdRobosPulando << std::endl;*/
					if(iRoboPula >= 5)
					{
						if(not((xRobo >= 10 && xRobo <= 60) && (yRobo >= 560 && yRobo <= 580))
						&& not((xRobo >= 80 && xRobo <= 140) && (yRobo >= 580 && yRobo <= 620))
						&& not((xRobo >= 140 && xRobo <= 280) && (yRobo >= 430 && yRobo <= 440))
						&& not((xRobo >= 360 & xRobo <= 420) && (yRobo >= 420 && yRobo <= 420))
						&& not((xRobo >= 40 && xRobo <= 120) && (yRobo == 80))
						&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo >= 500 && yRobo <= 520))
						&& not((xRobo > 1200) && (yRobo >= 540 && yRobo <= 540))
						)
						{
							yRobo += 20;
						}
					}
					else
					{
						if(not((xRobo >= 10 && xRobo <= 60) && (yRobo >= 560 && yRobo <= 580))
						&& not((xRobo >= 80 && xRobo <= 140) && (yRobo >= 580 && yRobo <= 620))
						&& not((xRobo >= 140 && xRobo <= 280) && (yRobo >= 430 && yRobo <= 440))
						&& not((xRobo >= 40 && xRobo <= 120) && (yRobo == 80))
						&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo >= 500 && yRobo <= 520))
						&& not((xRobo > 1200) && (yRobo >= 540 && yRobo <= 540))
						)
						{
							yRobo -= 20;
						}
					}
					/*else if(yRobo == 610)
					{ }*/
					
				}
				iRoboPula++;
				if(iRoboPula > QtdRobosPulando){
					iRoboPula = 0;
					pulaRobo = false; }
				
				delay(70);
			}
		}
		else if(AgarraMagnetismo == true && DesceEscada == false && SobeEscada == false)
		{
			if(LadoMagnetismo == 1)
			{
				if(nMagnetismo == 2)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(240, 320, MEM[0], AND_PUT);
						putimage(240, 320, ME[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(250, 320, MEM[1], AND_PUT);
						putimage(250, 320, ME[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(290, 290, MEM[2], AND_PUT);
						putimage(290, 290, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(330, 285, MEM[3], AND_PUT);
						putimage(330, 285, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(355, 270, MEM[4], AND_PUT);
						putimage(355, 270, ME[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(360, 250, MEM[5], AND_PUT);
						putimage(360, 250, ME[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(380, 220, MEM[6], AND_PUT);
						putimage(380, 220, ME[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 380;
						yRobo = 220;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
			}
			else if(LadoMagnetismo == 0)
			{
				/*if(iRoboEscalaMag == 1)
				{
					putimage(600, 210, MEIM[0], AND_PUT);
					putimage(600, 210, MEI[0], OR_PUT);
				}
				else if(iRoboEscalaMag == 2)
				{
					putimage(585, 210, MEIM[1], AND_PUT);
					putimage(585, 210, MEI[1], OR_PUT);
				}
				else if(iRoboEscalaMag == 3)
				{
					putimage(570, 190, MEIM[2], AND_PUT);
					putimage(570, 190, MEI[2], OR_PUT);
				}
				else if(iRoboEscalaMag == 4)
				{
					putimage(555, 170, MEIM[3], AND_PUT);
					putimage(555, 170, MEI[3], OR_PUT);
				}
				else if(iRoboEscalaMag == 5)
				{
					putimage(530, 150, MEIM[4], AND_PUT);
					putimage(530, 150, MEI[4], OR_PUT);
				}
				else if(iRoboEscalaMag == 6)
				{
					putimage(525, 120, MEIM[5], AND_PUT);
					putimage(525, 120, MEI[5], OR_PUT);
				}
				else if(iRoboEscalaMag == 7)
				{
					putimage(500, 90, MEIM[6], AND_PUT);
					putimage(500, 90, MEI[6], OR_PUT);
					
					AgarraMagnetismo = false;
					xRobo = 490;
					yRobo = 90;
				}*/
				
				
				
				if(nMagnetismo == 3)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(380, 220, MEIM[0], AND_PUT);
						putimage(380, 220, MEI[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(370, 210, MEIM[1], AND_PUT);
						putimage(370, 210, MEI[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(340, 180, MEIM[2], AND_PUT);
						putimage(340, 180, MEI[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(300, 160, MEIM[3], AND_PUT);
						putimage(300, 160, MEI[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(270, 135, MEIM[4], AND_PUT);
						putimage(270, 135, MEI[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(270, 110, MEIM[5], AND_PUT);
						putimage(270, 110, MEI[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(240, 80, MEIM[6], AND_PUT);
						putimage(240, 80, MEI[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 240;
						yRobo = 80;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
				
			}
			delay(120);
		}
		
		
		/*if(not((xRobo >= 60 && xRobo <= 565) && (yRobo >= 420))
		&& not((xRobo >= 300 && xRobo <= 400) && (yRobo >= 220 && yRobo <= 240))
		&& not((xRobo >= 420 && xRobo <= 520) && (yRobo == 100))
		&& not((xRobo >= 600 && xRobo <= 700) && (yRobo == 100))
		&& not((xRobo >= 780 && xRobo <= 880) && (yRobo == 100))
		&& not((xRobo >= 960 && xRobo <= 1240) && (yRobo >= 80 && yRobo <= 120)) 
		&& not((xRobo >= 760 && xRobo <= 1280) && (yRobo >= 320 && yRobo <= 340))
		&& not((xRobo >= 640 && xRobo <= 800) && (yRobo >= 620 && yRobo <= 640))
		&& not((xRobo >= 740 && xRobo <= 820) && (yRobo >= 520 && yRobo <= 560))
		&& not((xRobo >= 885 && xRobo <= 1125) && (yRobo >= 440 && yRobo <= 440))
		&& not((xRobo >= 820 && xRobo <= 1240) && (yRobo >= 620)))*/
		Caindo = false;
		if(not((xRobo >= -10 && xRobo <= 260) && (yRobo >= 320 && yRobo <= 320))
		&& not((xRobo >= 140 && xRobo <= 260) && (yRobo >= 460 && yRobo <= 480))
		&& not((xRobo >= 10 && xRobo <= 200) && (yRobo >= 620 && yRobo <= 620))
		&& not((xRobo >= 360 && xRobo <= 420) && (yRobo >= 420 && yRobo <= 420))
		&& not((xRobo >= 360 && xRobo <= 420) && (yRobo >= 220 && yRobo <= 220))
		&& not((xRobo >= 20 && xRobo <= 260) && (yRobo >= 80 && yRobo <= 100))
		&& not((xRobo >= 760 && xRobo <= 1060) && (yRobo == 120))
		&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo == 220))
		&& not((xRobo >= 960 && xRobo <= 1060) && (yRobo == 320))
		&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo == 420))
		&& not((xRobo >= 960 && xRobo <= 1060) && (yRobo == 520))
		&& not((xRobo >= 1120 && xRobo <= 1300) && (yRobo == 560))
		)
    	{
    		//std::cout << "Entrou1" << std::endl;
    		if(pulaRobo == false && AgarraMagnetismo == false)
			{
				Caindo = true;
				yRobo += 10;
			}
		}
		/*xRobo = 785;
		yRobo = 320;*/
    	/*PosObs3[0] = 1160;
		PosObs3[1] = 500;
		PosObs3[2] = 1240;
		PosObs3[3] = 520;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		/*PosObs3[0] = 1000;
		PosObs3[1] = 400;
		PosObs3[2] = 1100;
		PosObs3[3] = 420;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		/*PosObs3[0] = 1160;
		PosObs3[1] = 640;
		PosObs3[2] = 1240;
		PosObs3[3] = 660;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
    	
    	andaEsquerda = false;
    	if(GetKeyState(0x41)&0x80)  // A
		{
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			/*if(not((xRobo >= 820 && xRobo <= 840) && (yRobo >= 560 && yRobo <= 620))
			&& not((xRobo >= 800 && xRobo <= 820) && (yRobo >= 350 && yRobo <= 520))
			)*/
			if(not(xRobo <= -10 && yRobo == 320)
			&& not((xRobo >= -10 && xRobo <= 20) && (yRobo >= 580 && yRobo <= 620))
			&& not((xRobo >= 140 && xRobo <= 140) && (yRobo >= 440 && yRobo <= 600))
			&& not((xRobo >= 270 && xRobo <= 280) && ((yRobo >= 340 && yRobo <= 440) || (yRobo >= 460)))
			&& not((xRobo >= 0 && xRobo <= 20) && (yRobo >= 0 && yRobo <= 80))
			&& not((xRobo >= 260 && xRobo <= 260) && (yRobo >= 100 && yRobo <= 200))
			&& not((xRobo >= 140 && xRobo <= 150) && (yRobo <= 60))
			&& not((xRobo >= 480 && xRobo <= 480) && (yRobo >= 140))
			&& not((xRobo >= 900 && xRobo <= 980) && yRobo >= 140)
			&& not((xRobo >= 1080 && xRobo <= 1080) && (yRobo >= 130 && yRobo <= 220))
			&& not((xRobo >= 1080 && xRobo <= 1080) && (yRobo >= 330 && yRobo <= 400))
			&& not((xRobo >= 1080 && xRobo <= 1080) && (yRobo >= 530 && yRobo <= 600))
			 )
			{
				andaEsquerda = true;
			}
			LadoRobo = 0;
		}
		andaDireita = false;
    	if(GetKeyState(0x44)&0x80)     // D
		{
			//xRobo += 7;
			//xRobo += 10;
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			if(xRobo >= 1280)
			{
				Tela5();
			}
			/*if(not((xRobo >= 725 && xRobo <= 760) && yRobo >= 570)
			&& not(xRobo >= 1180 && (yRobo >= 420)) && not((xRobo >= 40 && xRobo <= 565) && (yRobo > 420))
			&& not((xRobo >= 745 && xRobo <= 760) && (yRobo >= 350 && yRobo <= 520))
			&& not((xRobo >= 860 && xRobo <= 1140) && (yRobo >= 460 && yRobo <= 540))
			&& not((xRobo >= 980 && xRobo <= 1060) && (yRobo >= 90 && yRobo <= 140))
			)*/
			if(not((xRobo >= 60 && xRobo <= 70) && (yRobo >= 580 && yRobo < 620))
			&& not((xRobo >= 140 && xRobo <= 150) && (yRobo >= 600 && yRobo <= 620))
			&& not((xRobo >= 360 & xRobo <= 420) && (yRobo > 420 && yRobo <= 500))
			&& not((xRobo >= 400 && xRobo <= 420) && (yRobo >= 140))
			&& not((xRobo >= 340 && xRobo <= 420) && (yRobo >= 240 && yRobo <= 300))
			&& not((xRobo >= 20 && xRobo <= 30) && (yRobo <= 60))
			&& not((xRobo >= 760 && xRobo <= 760) && (yRobo >= 130))
			&& not((xRobo >= 1120 &&  xRobo <= 1120) && (yRobo >= 40 && yRobo <= 120))
			&& not((xRobo >= 1170 && xRobo <= 1180) && (yRobo >= 0 && yRobo <= 530))
			&& not((xRobo >= 1120 && xRobo <= 1130) && (yRobo >= 230 && yRobo <= 300))
			&& not((xRobo >= 1120 && xRobo <= 1130) && (yRobo >= 430 && yRobo <= 500))
			&& not((xRobo >= 1100 && xRobo <= 1110) && (yRobo >= 570))
			)
			{
				andaDireita = true;
			}
			
			LadoRobo = 1;
		}
    	if(GetKeyState(0x53)&0x80)   // S Agachar
    	{
    		//PiscaCaixa += 1;
    		if((xRobo == 140) && yRobo == 460)
			{
				DesceEscada = true;
				DescendoEscada == 1;
			}
		}
		//pulaRobo = false;
		if(GetKeyState(0x57)&0x80)   // W Pular
    	{
    		if(xRobo == 140 && yRobo == 620 && SobeEscada == false)
    		{
    			SobeEscada = true;
    			SubindoEscada = 1;
			}
    		else{
    			if(SobeEscada == false && DesceEscada == false)
    			{
    				pulaRobo = true;
    				if(iRoboPula == 0){ iRoboPula = 1; };
				}
			}
		}
		if(GetKeyState(0x4b)&0x80)   // K Agarrar magnetismo
    	{
    		
    		if(LadoRobo == 1)
    		{
    			if((xRobo >= 200 && xRobo <= 260) && yRobo == 320 && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 2;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
				else if((xRobo >= 1165 && xRobo <= 1185) && (yRobo == 620) && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 3;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}
			}
			else if(LadoRobo == 0)
			{
				//if((xRobo >= 1165 && xRobo <= 1185) && (yRobo == 620) && AgarraMagnetismo == false)
				if((xRobo >= 360 && xRobo <= 420) && yRobo == 220 && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 3;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}
			}
    		//PiscaCaixa += 1;
		}
		if(GetKeyState(0x4c)&0x80)   // L Disparar o braço na direção
    	{
    		//PiscaCaixa += 1;
    		/*xRobo = 100;
			yRobo = 400 - 80;*/
			xRobo = 800;
			yRobo = 120;
		}



		setvisualpage(pg);
	
	    delay(30);
	
	    fflush(stdin);
	    if (kbhit())
	      tecla = getch();   
	}
	
	closegraph();	

  	
}




void Tela5() {
	int pg = 1;
	char tecla = 0;
	bool andaDireita = false, andaEsquerda = false, MostraCaixa = true, pulaRobo = false, AgarraMagnetismo = false,
		 DesceEscada = false, SobeEscada = false, Caindo = false;
	int iRobo, i, iRoboPula;
	int LadoRobo; // Em direção a esquerda = 0, Em direção a direita = 1
	int PiscaCaixa = 0;
	int ELipse[6];
	int posXrobo = 100;
	int posYrobo = 100;
	int FPS;
	unsigned long long gt1, gt2;
	int PosMag1[4];
	int PosObs1[4];
	int PosObs2[4];
	int PosObs3[4];
	int posXimg;	
	int Min (int a, int b);
	int Max (int a, int b);
	int RoboAgarra = 0;
	int iRoboEscalaMag;
	int LadoMagnetismo = 1;
	int DescendoEscada = 0;
	int SubindoEscada = 0;
	int iAgarraMagnetismo;
	int nMagnetismo = 0;
	int nEscada = 0;
	int tamEscada2;
	unsigned char *Escada, *EscadaM;
	unsigned char *Escada2, *Escada2M;

  	cleardevice();

  	putimage(0, 0, Fundo[4], COPY_PUT); 	

	tamEscada = imagesize(0, 0, 45, 300);
  	tamEscada2 = imagesize(0, 0, 45, 700);
  	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
  	
  	Escada2 = (unsigned char *)malloc(tamEscada2);
  	Escada2M = (unsigned char *)malloc(tamEscada2);
  	
  	readimagefile(".\\imagens\\EscadaF5.bmp", 0, 0, 45, 300);
  	getimage(0, 0, 45, 300, Escada);
  	getimage(0, 0, 45, 300, EscadaM);
  	
  	readimagefile(".\\imagens\\EscadaF5D.bmp", 0, 0, 45, 700);
  	getimage(0, 0, 45, 700, Escada2);
  	getimage(0, 0, 45, 700, Escada2M);
  	
  	PreparaImg(tamEscada, Escada, EscadaM);
  	PreparaImg(tamEscada2, Escada2, Escada2M);
  	
  	
  	iRobo = 0;
  	xRobo = 100;
	yRobo = 560;
	posXimg = 0;
	LadoRobo = 1;
	iRoboPula = 0;
	iRoboEscalaMag = 0;
	
	/*xRobo = 500;
	yRobo = 100;*/

	while(tecla != ESC) {
		
		if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    /* Prepara o fundo */
	    cleardevice();
  		
		
		putimage(0, 0, Fundo[4], COPY_PUT);
		
		putimage(875, 400, EscadaM, AND_PUT);
		putimage(875, 400, Escada, OR_PUT);
		
		putimage(1220, 0, Escada2M, AND_PUT);
		putimage(1220, 0, Escada2, OR_PUT);
		
		/*PosObs3[0] = 1000;
		PosObs3[1] = ;
		PosObs3[2] = 800;
		PosObs3[3] = 500;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/

    	
    	
    	/*if(MostraCaixa)
    	{
    		//std::cout << PiscaCaixa << std::endl;
    		if(PiscaCaixa == 0){
    			putimage(300, 450, C, COPY_PUT);
			}
			else{
				if(PiscaCaixa % 2 == 0)
				{
					putimage(300, 450, C, COPY_PUT);
				}
				else{
					
				}
				PiscaCaixa++;
				//std::cout << "E" << std::endl;
				delay(50);
			}
			if(PiscaCaixa >= 10){ MostraCaixa = false; }
		}*/
		
    	//putimage(300, 450, C, COPY_PUT);
    	
    	//putimage(200, 485, CM, OR_PUT);
		
		putimage(300, 480, MagnetismoM, AND_PUT);
		putimage(300, 480, Magnetismo, OR_PUT);
		
		putimage(500, 280, MagnetismoM, AND_PUT);
		putimage(500, 280, Magnetismo, OR_PUT);
		
		/*putimage(1140, 500, MagnetismoM, AND_PUT);
		putimage(1140, 500, Magnetismo, OR_PUT);*/
		
		/*if((xRobo == 1090 || xRobo == 1085 || xRobo == 1080 ) && yRobo == 410)
		{
			std::cout << "Entrou aqui ASBDUIAH" << std::endl;
			DesceEscada = true;
			DescendoEscada == 1;
		}*/
		//DesceEscada = true;
		if(DesceEscada == true)
		{
			if(DescendoEscada == 1)
			{
				putimage(860, 420, EM[0], AND_PUT);
				putimage(860, 420, E[0], OR_PUT);
			}
			else if(DescendoEscada == 2)
			{
				putimage(860, 440, EM[1], AND_PUT);
				putimage(860, 440, E[1], OR_PUT);
			}
			else if(DescendoEscada == 3)
			{
				putimage(860, 460, EM[0], AND_PUT);
				putimage(860, 460, E[0], OR_PUT);
			}
			else if(DescendoEscada == 4)
			{
				putimage(860, 480, EM[1], AND_PUT);
				putimage(860, 480, E[1], OR_PUT);
			}
			else if(DescendoEscada == 5)
			{
				putimage(860, 500, EM[0], AND_PUT);
				putimage(860, 500, E[0], OR_PUT);
			}
			else if(DescendoEscada == 6)
			{
				putimage(860, 530, EM[1], AND_PUT);
				putimage(860, 530, E[1], OR_PUT);
			}
			else if(DescendoEscada == 7)
			{
				putimage(860, 560, EM[0], AND_PUT);
				putimage(860, 560, E[0], OR_PUT);
			}
			else if(DescendoEscada == 8)
			{
				putimage(860, 590, EM[1], AND_PUT);
				putimage(860, 590, E[1], OR_PUT);
			}
			else if(DescendoEscada == 9)
			{
				putimage(860, 610, EM[0], AND_PUT);
				putimage(860, 610, E[0], OR_PUT);
		 	
				
				DesceEscada = false;
				xRobo = 900;
				yRobo = 620;
			}
			if(DescendoEscada == 9){ 
				DescendoEscada = 0; 
			}
			else{
				DescendoEscada++;
			}			
			//std::cout << "Entrou Aqui" << std::endl;
			delay(100);
		}
		else if(SobeEscada == true)
		{
			//std::cout << "Entrou Aqui213212313" << std::endl;
			if(nEscada == 1)
			{
				if(SubindoEscada == 1)
				{
					putimage(860, 610, EM[0], AND_PUT);
					putimage(860, 610, E[0], OR_PUT);
				}
				else if(SubindoEscada == 2)
				{
					putimage(860, 590, EM[1], AND_PUT);
					putimage(860, 590, E[1], OR_PUT);
				}
				else if(SubindoEscada == 3)
				{
					putimage(860, 560, EM[0], AND_PUT);
					putimage(860, 560, E[0], OR_PUT);
				}
				else if(SubindoEscada == 4)
				{
					putimage(860, 530, EM[1], AND_PUT);
					putimage(860, 530, E[1], OR_PUT);
				}
				else if(SubindoEscada == 5)
				{
					putimage(860, 500, EM[0], AND_PUT);
					putimage(860, 500, E[0], OR_PUT);
				}
				else if(SubindoEscada == 6)
				{
					putimage(860, 480, EM[1], AND_PUT);
					putimage(860, 480, E[1], OR_PUT);
				}
				else if(SubindoEscada == 7)
				{
					putimage(860, 460, EM[0], AND_PUT);
					putimage(860, 460, E[0], OR_PUT);
				}
				else if(SubindoEscada == 8)
				{
					putimage(860, 440, EM[1], AND_PUT);
					putimage(860, 440, E[1], OR_PUT);
				}
				else if(SubindoEscada == 9)
				{
					putimage(860, 420, EM[0], AND_PUT);
					putimage(860, 420, E[0], OR_PUT);
			 	
					SubindoEscada = 0;
					
					SobeEscada = false;
					xRobo = 900;
					yRobo = 420;
				}
				SubindoEscada++;
			}
			else if(nEscada == 2)
			{
				if(SubindoEscada == 1)
				{
					putimage(1210, 620, EM[0], AND_PUT);
					putimage(1210, 620, E[0], OR_PUT);
				}
				else if(SubindoEscada == 2)
				{
					putimage(1210, 590, EM[1], AND_PUT);
					putimage(1210, 590, E[1], OR_PUT);
				}
				else if(SubindoEscada == 3)
				{
					putimage(1210, 560, EM[0], AND_PUT);
					putimage(1210, 560, E[0], OR_PUT);
				}
				else if(SubindoEscada == 4)
				{
					putimage(1210, 530, EM[1], AND_PUT);
					putimage(1210, 530, E[1], OR_PUT);
				}
				else if(SubindoEscada == 5)
				{
					putimage(1210, 510, EM[0], AND_PUT);
					putimage(1210, 510, E[0], OR_PUT);
				}
				else if(SubindoEscada == 6)
				{
					putimage(1210, 480, EM[1], AND_PUT);
					putimage(1210, 480, E[1], OR_PUT);
				}
				else if(SubindoEscada == 7)
				{
					putimage(1210, 450, EM[0], AND_PUT);
					putimage(1210, 450, E[0], OR_PUT);
				}
				else if(SubindoEscada == 8)
				{
					putimage(1210, 420, EM[1], AND_PUT);
					putimage(1210, 420, E[1], OR_PUT);
				}
				else if(SubindoEscada == 9)
				{
					putimage(1210, 390, EM[0], AND_PUT);
					putimage(1210, 390, E[0], OR_PUT);
				}
				else if(SubindoEscada == 10)
				{
					putimage(1210, 360, EM[1], AND_PUT);
					putimage(1210, 360, E[1], OR_PUT);
				}
				else if(SubindoEscada == 11)
				{
					putimage(1210, 330, EM[0], AND_PUT);
					putimage(1210, 330, E[0], OR_PUT);
				}
				else if(SubindoEscada == 12)
				{
					putimage(1210, 300, EM[1], AND_PUT);
					putimage(1210, 300, E[1], OR_PUT);
				}
				else if(SubindoEscada == 13)
				{
					putimage(1210, 270, EM[1], AND_PUT);
					putimage(1210, 270, E[1], OR_PUT);
				}
				else if(SubindoEscada == 14)
				{
					putimage(1210, 240, EM[1], AND_PUT);
					putimage(1210, 240, E[1], OR_PUT);
				}
				else if(SubindoEscada == 15)
				{
					putimage(1210, 210, EM[0], AND_PUT);
					putimage(1210, 210, E[0], OR_PUT);
			 	
					SubindoEscada = 0;
					
					SobeEscada = false;
					xRobo = 1160;
					yRobo = 200;
				}
				/*if(SubindoEscada == 15){ 
					SubindoEscada = 0; 
				}
				else{*/
					SubindoEscada++;
				//}
			}
			else if(nEscada == 3)
			{
				if(SubindoEscada == 1)
				{
					putimage(1210, 200, EM[0], AND_PUT);
					putimage(1210, 200, E[0], OR_PUT);
				}
				else if(SubindoEscada == 2)
				{
					putimage(1210, 180, EM[1], AND_PUT);
					putimage(1210, 180, E[1], OR_PUT);
				}
				else if(SubindoEscada == 3)
				{
					putimage(1210, 150, EM[0], AND_PUT);
					putimage(1210, 150, E[0], OR_PUT);
				}
				else if(SubindoEscada == 4)
				{
					putimage(1210, 120, EM[1], AND_PUT);
					putimage(1210, 120, E[1], OR_PUT);
				}
				else if(SubindoEscada == 5)
				{
					putimage(1210, 90, EM[0], AND_PUT);
					putimage(1210, 90, E[0], OR_PUT);
				}
				else if(SubindoEscada == 6)
				{
					putimage(1210, 60, EM[1], AND_PUT);
					putimage(1210, 60, E[1], OR_PUT);
				}
				else if(SubindoEscada == 7)
				{
					putimage(1210, 30, EM[0], AND_PUT);
					putimage(1210, 30, E[0], OR_PUT);
				}
				else if(SubindoEscada == 8)
				{
					putimage(1210, 10, EM[1], AND_PUT);
					putimage(1210, 10, E[1], OR_PUT);
				}
				else if(SubindoEscada == 9)
				{
					putimage(1210, -20, EM[0], AND_PUT);
					putimage(1210, -20, E[0], OR_PUT);
			 	
					SubindoEscada = 0;
					
					SobeEscada = false;
					xRobo = 1210;
					yRobo = -50;
					
					Tela6();
				}
				SubindoEscada++;
			}
			
			
			delay(100);
		}
		
		
    	//DesceEscada = true;
    	if(AgarraMagnetismo == false && DesceEscada == false && SobeEscada == false)
    	{
    		if(andaDireita == true)
	    	{
	    	
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, RM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, R[iRobo], OR_PUT);
				}
				xRobo += 20;
				
				
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				if(pulaRobo == true){
					delay(20);
				}
				else if(Caindo == true){
					delay(25);
				}
				else{
					delay(70);
				}
			}
			else if(andaEsquerda == true)
			{
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, REM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, RE[iRobo], OR_PUT);
				}
				if((xRobo - 10) <= 0 )
				{
					xRobo = -10;
				} 
				else{
					xRobo -= 20;
				}
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				if(pulaRobo == true){
					delay(20);
				}
				else if(Caindo == true){
					delay(25);
				}
				else{
					delay(70);
				}
			}
			else
	    	{
	    		if(pulaRobo == false)
	    		{
	    			if(LadoRobo == 1)
		    		{
		    			putimage(xRobo, yRobo, RM[0], AND_PUT);
						putimage(xRobo, yRobo, R[0], OR_PUT);
					}
					else if(LadoRobo == 0)
					{
						putimage(xRobo, yRobo, REM[0], AND_PUT);
						putimage(xRobo, yRobo, RE[0], OR_PUT);
					}
				}
			}
			if(pulaRobo == true && iRoboPula >= 0)
			{
				/*for(i = 0; i < iRoboPula; i++)
				{*/
				if(iRoboPula == 1){
					sndPlaySound(".\\sons\\som_pulo.wav", SND_ASYNC);
				}
				if(LadoRobo == 1)
				{
					putimage(xRobo, yRobo, PUM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PU[iRoboPula - 1], OR_PUT);
				}
				else if(LadoRobo == 0)
				{
					putimage(xRobo, yRobo, PUEM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PUE[iRoboPula - 1], OR_PUT);
				}
				
					//iRoboPula++;
				//}
				std::cout << "yRobo Ficou" << std::endl;
				std::cout << yRobo << std::endl;
				std::cout << xRobo << std::endl;
				if(yRobo < 0)
				{
					yRobo = 10;
				}
				else if(yRobo >= 0)
				{
					
					//if(iRoboPula >= 5 && not(yRobo == 610))
					/*std::cout << iRoboPula << std::endl;
					std::cout << QtdRobosPulando << std::endl;*/
					if(iRoboPula >= 5)
					{
						/*if(not((xRobo >= 10 && xRobo <= 60) && (yRobo >= 560 && yRobo <= 580))
						&& not((xRobo >= 80 && xRobo <= 140) && (yRobo >= 580 && yRobo <= 620))
						&& not((xRobo >= 140 && xRobo <= 280) && (yRobo >= 430 && yRobo <= 440))
						&& not((xRobo >= 360 & xRobo <= 420) && (yRobo >= 420 && yRobo <= 420))
						&& not((xRobo >= 40 && xRobo <= 120) && (yRobo == 80))
						&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo >= 500 && yRobo <= 520))
						&& not((xRobo > 1200) && (yRobo >= 540 && yRobo <= 540))
						)
						{*/
							yRobo += 20;
						
						//}
					}
					else
					{
						/*if(not((xRobo >= 10 && xRobo <= 60) && (yRobo >= 560 && yRobo <= 580))
						&& not((xRobo >= 80 && xRobo <= 140) && (yRobo >= 580 && yRobo <= 620))
						&& not((xRobo >= 140 && xRobo <= 280) && (yRobo >= 430 && yRobo <= 440))
						&& not((xRobo >= 40 && xRobo <= 120) && (yRobo == 80))
						&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo >= 500 && yRobo <= 520))
						&& not((xRobo > 1200) && (yRobo >= 540 && yRobo <= 540))
						)
						{*/
						if(not((xRobo >= 260 && xRobo <= 360) && (yRobo >= 520 && yRobo <= 520))
						)
						{
							yRobo -= 20;
						}
						//}
					}
					if((xRobo >= 50 && xRobo <= 360) && (yRobo > 560))
					{
						yRobo = 560;
					}
				
					/*else if(yRobo == 610)
					{ }*/
					
				}
				iRoboPula++;
				if(iRoboPula > QtdRobosPulando){
					iRoboPula = 0;
					pulaRobo = false; }
				
				delay(70);
			}
		}
		else if(AgarraMagnetismo == true && DesceEscada == false && SobeEscada == false)
		{
			if(LadoMagnetismo == 1)
			{
				if(nMagnetismo == 2)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(330, 420, MEM[0], AND_PUT);
						putimage(330, 420, ME[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(330, 420, MEM[1], AND_PUT);
						putimage(330, 420, ME[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(360, 370, MEM[2], AND_PUT);
						putimage(360, 370, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(380, 340, MEM[2], AND_PUT);
						putimage(380, 340, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(400, 320, MEM[3], AND_PUT);
						putimage(400, 320, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(430, 290, MEM[3], AND_PUT);
						putimage(430, 290, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(455, 275, MEM[4], AND_PUT);
						putimage(455, 275, ME[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 8)
					{
						putimage(460, 250, MEM[5], AND_PUT);
						putimage(460, 250, ME[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 9)
					{
						putimage(480, 220, MEM[6], AND_PUT);
						putimage(480, 220, ME[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 500;
						yRobo = 220;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
				else if(nMagnetismo == 1)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(190, 560, MEM[0], AND_PUT);
						putimage(190, 560, ME[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(190, 560, MEM[1], AND_PUT);
						putimage(190, 560, ME[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(220, 530, MEM[2], AND_PUT);
						putimage(220, 530, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(240, 500, MEM[3], AND_PUT);
						putimage(240, 500, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(255, 475, MEM[4], AND_PUT);
						putimage(255, 475, ME[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(260, 450, MEM[5], AND_PUT);
						putimage(260, 450, ME[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(290, 420, MEM[6], AND_PUT);
						putimage(290, 420, ME[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 300;
						yRobo = 420;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
			}
			else if(LadoMagnetismo == 0)
			{
				/*if(iRoboEscalaMag == 1)
				{
					putimage(600, 210, MEIM[0], AND_PUT);
					putimage(600, 210, MEI[0], OR_PUT);
				}
				else if(iRoboEscalaMag == 2)
				{
					putimage(585, 210, MEIM[1], AND_PUT);
					putimage(585, 210, MEI[1], OR_PUT);
				}
				else if(iRoboEscalaMag == 3)
				{
					putimage(570, 190, MEIM[2], AND_PUT);
					putimage(570, 190, MEI[2], OR_PUT);
				}
				else if(iRoboEscalaMag == 4)
				{
					putimage(555, 170, MEIM[3], AND_PUT);
					putimage(555, 170, MEI[3], OR_PUT);
				}
				else if(iRoboEscalaMag == 5)
				{
					putimage(530, 150, MEIM[4], AND_PUT);
					putimage(530, 150, MEI[4], OR_PUT);
				}
				else if(iRoboEscalaMag == 6)
				{
					putimage(525, 120, MEIM[5], AND_PUT);
					putimage(525, 120, MEI[5], OR_PUT);
				}
				else if(iRoboEscalaMag == 7)
				{
					putimage(500, 90, MEIM[6], AND_PUT);
					putimage(500, 90, MEI[6], OR_PUT);
					
					AgarraMagnetismo = false;
					xRobo = 490;
					yRobo = 90;
				}*/
				
				
				
				if(nMagnetismo == 3)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(380, 220, MEIM[0], AND_PUT);
						putimage(380, 220, MEI[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(370, 210, MEIM[1], AND_PUT);
						putimage(370, 210, MEI[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(340, 180, MEIM[2], AND_PUT);
						putimage(340, 180, MEI[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(300, 160, MEIM[3], AND_PUT);
						putimage(300, 160, MEI[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(270, 135, MEIM[4], AND_PUT);
						putimage(270, 135, MEI[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(270, 110, MEIM[5], AND_PUT);
						putimage(270, 110, MEI[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(240, 80, MEIM[6], AND_PUT);
						putimage(240, 80, MEI[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 240;
						yRobo = 80;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
				
			}
			delay(120);
		}
		
		Caindo = false;
		
		
		/*if(not((xRobo >= -10 && xRobo <= 260) && (yRobo >= 320 && yRobo <= 320))
		&& not((xRobo >= 140 && xRobo <= 260) && (yRobo >= 460 && yRobo <= 480))
		&& not((xRobo >= 10 && xRobo <= 200) && (yRobo >= 620 && yRobo <= 620))
		&& not((xRobo >= 360 && xRobo <= 420) && (yRobo >= 420 && yRobo <= 420))
		&& not((xRobo >= 360 && xRobo <= 420) && (yRobo >= 220 && yRobo <= 220))
		&& not((xRobo >= 20 && xRobo <= 260) && (yRobo >= 80 && yRobo <= 100))
		&& not((xRobo >= 760 && xRobo <= 1060) && (yRobo == 120))
		&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo == 220))
		&& not((xRobo >= 960 && xRobo <= 1060) && (yRobo == 320))
		&& not((xRobo >= 1120 && xRobo <= 1200) && (yRobo == 420))
		&& not((xRobo >= 960 && xRobo <= 1060) && (yRobo == 520))
		&& not((xRobo >= 1120 && xRobo <= 1300) && (yRobo == 560))
		)
    	{
    		//std::cout << "Entrou1" << std::endl;
    		if(pulaRobo == false && AgarraMagnetismo == false)
			{
				Caindo = true;
				yRobo += 10;
			}
		}*/
		
		if(not((xRobo >= -10 && xRobo <= 260) && (yRobo == 560))
		&& not((xRobo >= 260 && xRobo <= 360) && (yRobo == 420))
		&& not((xRobo >= 480 && xRobo <= 660) && (yRobo == 220))
		&& not((xRobo >= 800 && xRobo <= 1100) && (yRobo == 420))
		&& not((xRobo >= 840 && xRobo <= 1220) && (yRobo == 620))
		&& not((xRobo >= 1160 && xRobo <= 1220 ) && yRobo == 200)
		)
		{
			if(pulaRobo == false && AgarraMagnetismo == false)
			{
				Caindo = true;
				yRobo += 10;
			}
		}
		
		
		/*xRobo = 785;
		yRobo = 320;*/
		
    	/*PosObs3[0] = 1180;
		PosObs3[1] = 280;
		PosObs3[2] = 1220;
		PosObs3[3] = 290;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		/*PosObs3[0] = 300;
		PosObs3[1] = 500;
		PosObs3[2] = 400;
		PosObs3[3] = 520;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		/*PosObs3[0] = 500;
		PosObs3[1] = 300;
		PosObs3[2] = 700;
		PosObs3[3] = 320;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		/*PosObs3[0] = 860;
		PosObs3[1] = 700;
		PosObs3[2] = 1140;
		PosObs3[3] = 710;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
    	
    	andaEsquerda = false;
    	if(GetKeyState(0x41)&0x80)  // A
		{
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			
			/*if(not(xRobo <= -10 && yRobo == 320)
			&& not((xRobo >= -10 && xRobo <= 20) && (yRobo >= 580 && yRobo <= 620))
			&& not((xRobo >= 140 && xRobo <= 140) && (yRobo >= 440 && yRobo <= 600))
			&& not((xRobo >= 270 && xRobo <= 280) && ((yRobo >= 340 && yRobo <= 440) || (yRobo >= 460)))
			&& not((xRobo >= 0 && xRobo <= 20) && (yRobo >= 0 && yRobo <= 80))
			&& not((xRobo >= 260 && xRobo <= 260) && (yRobo >= 100 && yRobo <= 200))
			&& not((xRobo >= 140 && xRobo <= 150) && (yRobo <= 60))
			&& not((xRobo >= 480 && xRobo <= 480) && (yRobo >= 140))
			&& not((xRobo >= 900 && xRobo <= 980) && yRobo >= 140)
			&& not((xRobo >= 1080 && xRobo <= 1080) && (yRobo >= 130 && yRobo <= 220))
			&& not((xRobo >= 1080 && xRobo <= 1080) && (yRobo >= 330 && yRobo <= 400))
			&& not((xRobo >= 1080 && xRobo <= 1080) && (yRobo >= 530 && yRobo <= 600))
			 )*/
			if(not(xRobo <= -10 && yRobo == 560)
			&& not((xRobo >= 260 && xRobo <= 280) && (yRobo >= 570))
			&& not((xRobo >= 360 && xRobo <= 370) && (yRobo >= 430 && yRobo <= 520))
			&& not((xRobo >= 860 && xRobo <= 870) && (yRobo >= 480 && yRobo <= 620))
			&& not((xRobo >= 1160 && xRobo <= 1170) && (yRobo >= 100 && yRobo <= 200))
			)
			{
				andaEsquerda = true;
			}
			LadoRobo = 0;
		}
		andaDireita = false;
    	if(GetKeyState(0x44)&0x80)     // D
		{
			//xRobo += 7;
			//xRobo += 10;
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			if(xRobo >= 1280)
			{
				
				//Tela4();
			}
			/*if(not((xRobo >= 60 && xRobo <= 70) && (yRobo >= 580 && yRobo < 620))
			&& not((xRobo >= 140 && xRobo <= 150) && (yRobo >= 600 && yRobo <= 620))
			&& not((xRobo >= 360 & xRobo <= 420) && (yRobo > 420 && yRobo <= 500))
			&& not((xRobo >= 400 && xRobo <= 420) && (yRobo >= 140))
			&& not((xRobo >= 340 && xRobo <= 420) && (yRobo >= 240 && yRobo <= 300))
			&& not((xRobo >= 20 && xRobo <= 30) && (yRobo <= 60))
			&& not((xRobo >= 760 && xRobo <= 760) && (yRobo >= 130))
			&& not((xRobo >= 1120 &&  xRobo <= 1120) && (yRobo >= 40 && yRobo <= 120))
			&& not((xRobo >= 1170 && xRobo <= 1180) && (yRobo >= 0 && yRobo <= 530))
			&& not((xRobo >= 1120 && xRobo <= 1130) && (yRobo >= 230 && yRobo <= 300))
			&& not((xRobo >= 1120 && xRobo <= 1130) && (yRobo >= 430 && yRobo <= 500))
			&& not((xRobo >= 1100 && xRobo <= 1110) && (yRobo >= 570))
			)*/
			if(not(xRobo == 260 && (yRobo >= 430 && yRobo <= 520))
			&& not((xRobo == 1080) && (yRobo >= 0 && yRobo <= 420))
			&& not((xRobo >= 1200 && xRobo <= 1200) && (yRobo >= 480 && yRobo <= 620))
			&& not((xRobo == 1200) && (yRobo >= 100 && yRobo <= 200))
			)
			{
				andaDireita = true;
			}
			
			LadoRobo = 1;
		}
    	if(GetKeyState(0x53)&0x80)   // S Agachar
    	{
    		//PiscaCaixa += 1;
    		if((xRobo == 860) && yRobo == 420)
			{
				DesceEscada = true;
				DescendoEscada == 1;
			}
		}
		//pulaRobo = false;
		if(GetKeyState(0x57)&0x80)   // W Pular
    	{
    		if(xRobo == 860 && yRobo == 620 && SobeEscada == false)
    		{
    			SobeEscada = true;
    			SubindoEscada = 1;
    			nEscada = 1;
			}
			else if(xRobo == 1200 && yRobo == 620 && SobeEscada == false)
			{
				SobeEscada = true;
    			SubindoEscada = 1;
    			nEscada = 2;
			}
			else if(xRobo == 1200 && yRobo == 200 && SobeEscada == false)
			{
				SobeEscada = true;
    			SubindoEscada = 1;
    			nEscada = 3;
			}
    		else{
    			if(SobeEscada == false && DesceEscada == false)
    			{
    				pulaRobo = true;
    				if(iRoboPula == 0){ iRoboPula = 1; };
				}
			}
		}
		if(GetKeyState(0x4b)&0x80)   // K Agarrar magnetismo
    	{
    		
    		if(LadoRobo == 1)
    		{
    			if((xRobo >= 160 && xRobo <= 240) && yRobo == 560 && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 1;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
				else if((xRobo >= 280 && xRobo <= 340) && (yRobo == 420) && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 2;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
			}
			else if(LadoRobo == 0)
			{
				//if((xRobo >= 1165 && xRobo <= 1185) && (yRobo == 620) && AgarraMagnetismo == false)
				if((xRobo >= 360 && xRobo <= 420) && yRobo == 220 && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 3;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}
			}
    		//PiscaCaixa += 1;
		}
		if(GetKeyState(0x4c)&0x80)   // L Disparar o braço na direção
    	{
    		//PiscaCaixa += 1;
			/*xRobo = 100;
			yRobo = 560;*/
			xRobo = 900;
			yRobo = 620;
		}



		setvisualpage(pg);
	
	    delay(30);
	
	    fflush(stdin);
	    if (kbhit())
	      tecla = getch();   
	}
	
	closegraph();	

  	
}










void Tela6() {
	int pg = 1;
	char tecla = 0;
	bool andaDireita = false, andaEsquerda = false, MostraCaixa = true, pulaRobo = false, AgarraMagnetismo = false,
		 DesceEscada = false, SobeEscada = false, Caindo = false;
	int iRobo, i, iRoboPula;
	int LadoRobo; // Em direção a esquerda = 0, Em direção a direita = 1
	int PiscaCaixa = 0;
	int ELipse[6];
	int posXrobo = 100;
	int posYrobo = 100;
	int FPS;
	unsigned long long gt1, gt2;
	int PosMag1[4];
	int PosObs1[4];
	int PosObs2[4];
	int PosObs3[4];
	int posXimg;	
	int Min (int a, int b);
	int Max (int a, int b);
	int RoboAgarra = 0;
	int iRoboEscalaMag;
	int LadoMagnetismo = 1;
	int DescendoEscada = 0;
	int SubindoEscada = 0;
	int iAgarraMagnetismo;
	int nMagnetismo = 0;
	int nEscada = 0;
	int tamEscada2;
	unsigned char *Escada, *EscadaM;
	unsigned char *Escada2, *Escada2M;

  	cleardevice();

  	putimage(0, 0, Fundo[5], COPY_PUT); 	

	/*tamEscada = imagesize(0, 0, 45, 300);
  	tamEscada2 = imagesize(0, 0, 45, 700);
  	
	Escada = (unsigned char *)malloc(tamEscada);
  	EscadaM = (unsigned char *)malloc(tamEscada);
  	
  	Escada2 = (unsigned char *)malloc(tamEscada2);
  	Escada2M = (unsigned char *)malloc(tamEscada2);
  	
  	readimagefile(".\\imagens\\EscadaF5.bmp", 0, 0, 45, 300);
  	getimage(0, 0, 45, 300, Escada);
  	getimage(0, 0, 45, 300, EscadaM);
  	
  	readimagefile(".\\imagens\\EscadaF5D.bmp", 0, 0, 45, 700);
  	getimage(0, 0, 45, 700, Escada2);
  	getimage(0, 0, 45, 700, Escada2M);
  	
  	PreparaImg(tamEscada, Escada, EscadaM);
  	PreparaImg(tamEscada2, Escada2, Escada2M);*/
  	
  	
  	iRobo = 0;
  	xRobo = 100;
	yRobo = 560;
	posXimg = 0;
	LadoRobo = 1;
	iRoboPula = 0;
	iRoboEscalaMag = 0;
	
	/*xRobo = 500;
	yRobo = 100;*/

	while(tecla != ESC) {
		
		if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    /* Prepara o fundo */
	    cleardevice();
  		
		
		putimage(0, 0, Fundo[5], COPY_PUT);
		
		/*putimage(875, 400, EscadaM, AND_PUT);
		putimage(875, 400, Escada, OR_PUT);
		
		putimage(1220, 0, Escada2M, AND_PUT);
		putimage(1220, 0, Escada2, OR_PUT);*/
		
		/*PosObs3[0] = 1000;
		PosObs3[1] = ;
		PosObs3[2] = 800;
		PosObs3[3] = 500;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/

    	
    	
    	/*if(MostraCaixa)
    	{
    		//std::cout << PiscaCaixa << std::endl;
    		if(PiscaCaixa == 0){
    			putimage(300, 450, C, COPY_PUT);
			}
			else{
				if(PiscaCaixa % 2 == 0)
				{
					putimage(300, 450, C, COPY_PUT);
				}
				else{
					
				}
				PiscaCaixa++;
				//std::cout << "E" << std::endl;
				delay(50);
			}
			if(PiscaCaixa >= 10){ MostraCaixa = false; }
		}*/
		
    	//putimage(300, 450, C, COPY_PUT);
    	
    	//putimage(200, 485, CM, OR_PUT);
		
		putimage(300, 480, MagnetismoM, AND_PUT);
		putimage(300, 480, Magnetismo, OR_PUT);
		
		putimage(500, 280, MagnetismoM, AND_PUT);
		putimage(500, 280, Magnetismo, OR_PUT);
		
		/*putimage(1140, 500, MagnetismoM, AND_PUT);
		putimage(1140, 500, Magnetismo, OR_PUT);*/
		
		/*if((xRobo == 1090 || xRobo == 1085 || xRobo == 1080 ) && yRobo == 410)
		{
			std::cout << "Entrou aqui ASBDUIAH" << std::endl;
			DesceEscada = true;
			DescendoEscada == 1;
		}*/
		//DesceEscada = true;
		if(DesceEscada == true)
		{
			if(DescendoEscada == 1)
			{
				putimage(860, 420, EM[0], AND_PUT);
				putimage(860, 420, E[0], OR_PUT);
			}
			else if(DescendoEscada == 2)
			{
				putimage(860, 440, EM[1], AND_PUT);
				putimage(860, 440, E[1], OR_PUT);
			}
			else if(DescendoEscada == 3)
			{
				putimage(860, 460, EM[0], AND_PUT);
				putimage(860, 460, E[0], OR_PUT);
			}
			else if(DescendoEscada == 4)
			{
				putimage(860, 480, EM[1], AND_PUT);
				putimage(860, 480, E[1], OR_PUT);
			}
			else if(DescendoEscada == 5)
			{
				putimage(860, 500, EM[0], AND_PUT);
				putimage(860, 500, E[0], OR_PUT);
			}
			else if(DescendoEscada == 6)
			{
				putimage(860, 530, EM[1], AND_PUT);
				putimage(860, 530, E[1], OR_PUT);
			}
			else if(DescendoEscada == 7)
			{
				putimage(860, 560, EM[0], AND_PUT);
				putimage(860, 560, E[0], OR_PUT);
			}
			else if(DescendoEscada == 8)
			{
				putimage(860, 590, EM[1], AND_PUT);
				putimage(860, 590, E[1], OR_PUT);
			}
			else if(DescendoEscada == 9)
			{
				putimage(860, 610, EM[0], AND_PUT);
				putimage(860, 610, E[0], OR_PUT);
		 	
				
				DesceEscada = false;
				xRobo = 900;
				yRobo = 620;
			}
			if(DescendoEscada == 9){ 
				DescendoEscada = 0; 
			}
			else{
				DescendoEscada++;
			}			
			//std::cout << "Entrou Aqui" << std::endl;
			delay(100);
		}
		else if(SobeEscada == true)
		{
			//std::cout << "Entrou Aqui213212313" << std::endl;
			if(nEscada == 1)
			{
				if(SubindoEscada == 1)
				{
					putimage(860, 610, EM[0], AND_PUT);
					putimage(860, 610, E[0], OR_PUT);
				}
				else if(SubindoEscada == 2)
				{
					putimage(860, 590, EM[1], AND_PUT);
					putimage(860, 590, E[1], OR_PUT);
				}
				else if(SubindoEscada == 3)
				{
					putimage(860, 560, EM[0], AND_PUT);
					putimage(860, 560, E[0], OR_PUT);
				}
				else if(SubindoEscada == 4)
				{
					putimage(860, 530, EM[1], AND_PUT);
					putimage(860, 530, E[1], OR_PUT);
				}
				else if(SubindoEscada == 5)
				{
					putimage(860, 500, EM[0], AND_PUT);
					putimage(860, 500, E[0], OR_PUT);
				}
				else if(SubindoEscada == 6)
				{
					putimage(860, 480, EM[1], AND_PUT);
					putimage(860, 480, E[1], OR_PUT);
				}
				else if(SubindoEscada == 7)
				{
					putimage(860, 460, EM[0], AND_PUT);
					putimage(860, 460, E[0], OR_PUT);
				}
				else if(SubindoEscada == 8)
				{
					putimage(860, 440, EM[1], AND_PUT);
					putimage(860, 440, E[1], OR_PUT);
				}
				else if(SubindoEscada == 9)
				{
					putimage(860, 420, EM[0], AND_PUT);
					putimage(860, 420, E[0], OR_PUT);
			 	
					SubindoEscada = 0;
					
					SobeEscada = false;
					xRobo = 900;
					yRobo = 420;
				}
				SubindoEscada++;
			}
			else if(nEscada == 2)
			{
				if(SubindoEscada == 1)
				{
					putimage(1210, 620, EM[0], AND_PUT);
					putimage(1210, 620, E[0], OR_PUT);
				}
				else if(SubindoEscada == 2)
				{
					putimage(1210, 590, EM[1], AND_PUT);
					putimage(1210, 590, E[1], OR_PUT);
				}
				else if(SubindoEscada == 3)
				{
					putimage(1210, 560, EM[0], AND_PUT);
					putimage(1210, 560, E[0], OR_PUT);
				}
				else if(SubindoEscada == 4)
				{
					putimage(1210, 530, EM[1], AND_PUT);
					putimage(1210, 530, E[1], OR_PUT);
				}
				else if(SubindoEscada == 5)
				{
					putimage(1210, 510, EM[0], AND_PUT);
					putimage(1210, 510, E[0], OR_PUT);
				}
				else if(SubindoEscada == 6)
				{
					putimage(1210, 480, EM[1], AND_PUT);
					putimage(1210, 480, E[1], OR_PUT);
				}
				else if(SubindoEscada == 7)
				{
					putimage(1210, 450, EM[0], AND_PUT);
					putimage(1210, 450, E[0], OR_PUT);
				}
				else if(SubindoEscada == 8)
				{
					putimage(1210, 420, EM[1], AND_PUT);
					putimage(1210, 420, E[1], OR_PUT);
				}
				else if(SubindoEscada == 9)
				{
					putimage(1210, 390, EM[0], AND_PUT);
					putimage(1210, 390, E[0], OR_PUT);
				}
				else if(SubindoEscada == 10)
				{
					putimage(1210, 360, EM[1], AND_PUT);
					putimage(1210, 360, E[1], OR_PUT);
				}
				else if(SubindoEscada == 11)
				{
					putimage(1210, 330, EM[0], AND_PUT);
					putimage(1210, 330, E[0], OR_PUT);
				}
				else if(SubindoEscada == 12)
				{
					putimage(1210, 300, EM[1], AND_PUT);
					putimage(1210, 300, E[1], OR_PUT);
				}
				else if(SubindoEscada == 13)
				{
					putimage(1210, 270, EM[1], AND_PUT);
					putimage(1210, 270, E[1], OR_PUT);
				}
				else if(SubindoEscada == 14)
				{
					putimage(1210, 240, EM[1], AND_PUT);
					putimage(1210, 240, E[1], OR_PUT);
				}
				else if(SubindoEscada == 15)
				{
					putimage(1210, 210, EM[0], AND_PUT);
					putimage(1210, 210, E[0], OR_PUT);
			 	
					SubindoEscada = 0;
					
					SobeEscada = false;
					xRobo = 1160;
					yRobo = 200;
				}
				/*if(SubindoEscada == 15){ 
					SubindoEscada = 0; 
				}
				else{*/
					SubindoEscada++;
				//}
			}
			else if(nEscada == 3)
			{
				if(SubindoEscada == 1)
				{
					putimage(1210, 200, EM[0], AND_PUT);
					putimage(1210, 200, E[0], OR_PUT);
				}
				else if(SubindoEscada == 2)
				{
					putimage(1210, 180, EM[1], AND_PUT);
					putimage(1210, 180, E[1], OR_PUT);
				}
				else if(SubindoEscada == 3)
				{
					putimage(1210, 150, EM[0], AND_PUT);
					putimage(1210, 150, E[0], OR_PUT);
				}
				else if(SubindoEscada == 4)
				{
					putimage(1210, 120, EM[1], AND_PUT);
					putimage(1210, 120, E[1], OR_PUT);
				}
				else if(SubindoEscada == 5)
				{
					putimage(1210, 90, EM[0], AND_PUT);
					putimage(1210, 90, E[0], OR_PUT);
				}
				else if(SubindoEscada == 6)
				{
					putimage(1210, 60, EM[1], AND_PUT);
					putimage(1210, 60, E[1], OR_PUT);
				}
				else if(SubindoEscada == 7)
				{
					putimage(1210, 30, EM[0], AND_PUT);
					putimage(1210, 30, E[0], OR_PUT);
				}
				else if(SubindoEscada == 8)
				{
					putimage(1210, 10, EM[1], AND_PUT);
					putimage(1210, 10, E[1], OR_PUT);
				}
				else if(SubindoEscada == 9)
				{
					putimage(1210, -20, EM[0], AND_PUT);
					putimage(1210, -20, E[0], OR_PUT);
			 	
					SubindoEscada = 0;
					
					SobeEscada = false;
					xRobo = 1210;
					yRobo = -50;
					
					Tela6();
				}
				SubindoEscada++;
			}
			
			
			delay(100);
		}
		
		
    	//DesceEscada = true;
    	if(AgarraMagnetismo == false && DesceEscada == false && SobeEscada == false)
    	{
    		if(andaDireita == true)
	    	{
	    	
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, RM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, R[iRobo], OR_PUT);
				}
				xRobo += 20;
				
				
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				if(pulaRobo == true){
					delay(20);
				}
				else if(Caindo == true){
					delay(25);
				}
				else{
					delay(70);
				}
			}
			else if(andaEsquerda == true)
			{
				if(pulaRobo == false)
				{
					putimage(xRobo, yRobo, REM[iRobo], AND_PUT);
					putimage(xRobo, yRobo, RE[iRobo], OR_PUT);
				}
				if((xRobo - 10) <= 0 )
				{
					xRobo = -10;
				} 
				else{
					xRobo -= 20;
				}
				iRobo++;
				if(iRobo >= QtdRobos){
					iRobo = 0; }
				/*std::cout << xRobo << std::endl;
				std::cout << yRobo << std::endl;*/
				if(pulaRobo == true){
					delay(20);
				}
				else if(Caindo == true){
					delay(25);
				}
				else{
					delay(70);
				}
			}
			else
	    	{
	    		if(pulaRobo == false)
	    		{
	    			if(LadoRobo == 1)
		    		{
		    			putimage(xRobo, yRobo, RM[0], AND_PUT);
						putimage(xRobo, yRobo, R[0], OR_PUT);
					}
					else if(LadoRobo == 0)
					{
						putimage(xRobo, yRobo, REM[0], AND_PUT);
						putimage(xRobo, yRobo, RE[0], OR_PUT);
					}
				}
			}
			if(pulaRobo == true && iRoboPula >= 0)
			{
				/*for(i = 0; i < iRoboPula; i++)
				{*/
				if(iRoboPula == 1){
					sndPlaySound(".\\sons\\som_pulo.wav", SND_ASYNC);
				}
				if(LadoRobo == 1)
				{
					putimage(xRobo, yRobo, PUM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PU[iRoboPula - 1], OR_PUT);
				}
				else if(LadoRobo == 0)
				{
					putimage(xRobo, yRobo, PUEM[iRoboPula - 1], AND_PUT);
					putimage(xRobo, yRobo, PUE[iRoboPula - 1], OR_PUT);
				}
				
					//iRoboPula++;
				//}
				std::cout << "yRobo Ficou" << std::endl;
				std::cout << yRobo << std::endl;
				std::cout << xRobo << std::endl;
				if(yRobo < 0)
				{
					yRobo = 10;
				}
				else if(yRobo >= 0)
				{
					if(iRoboPula >= 5)
					{
						yRobo += 20;
					}
					else
					{
						if(not((xRobo >= 260 && xRobo <= 360) && (yRobo >= 520 && yRobo <= 520))
						)
						{
							yRobo -= 20;
						}
						//}
					}
					if((xRobo >= 50 && xRobo <= 360) && (yRobo > 560))
					{
						yRobo = 560;
					}
					
				}
				iRoboPula++;
				if(iRoboPula > QtdRobosPulando){
					iRoboPula = 0;
					pulaRobo = false; }
				
				delay(70);
			}
		}
		else if(AgarraMagnetismo == true && DesceEscada == false && SobeEscada == false)
		{
			if(LadoMagnetismo == 1)
			{
				if(nMagnetismo == 2)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(330, 420, MEM[0], AND_PUT);
						putimage(330, 420, ME[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(330, 420, MEM[1], AND_PUT);
						putimage(330, 420, ME[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(360, 370, MEM[2], AND_PUT);
						putimage(360, 370, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(380, 340, MEM[2], AND_PUT);
						putimage(380, 340, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(400, 320, MEM[3], AND_PUT);
						putimage(400, 320, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(430, 290, MEM[3], AND_PUT);
						putimage(430, 290, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(455, 275, MEM[4], AND_PUT);
						putimage(455, 275, ME[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 8)
					{
						putimage(460, 250, MEM[5], AND_PUT);
						putimage(460, 250, ME[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 9)
					{
						putimage(480, 220, MEM[6], AND_PUT);
						putimage(480, 220, ME[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 500;
						yRobo = 220;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
				else if(nMagnetismo == 1)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(190, 560, MEM[0], AND_PUT);
						putimage(190, 560, ME[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(190, 560, MEM[1], AND_PUT);
						putimage(190, 560, ME[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(220, 530, MEM[2], AND_PUT);
						putimage(220, 530, ME[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(240, 500, MEM[3], AND_PUT);
						putimage(240, 500, ME[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(255, 475, MEM[4], AND_PUT);
						putimage(255, 475, ME[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(260, 450, MEM[5], AND_PUT);
						putimage(260, 450, ME[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(290, 420, MEM[6], AND_PUT);
						putimage(290, 420, ME[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 300;
						yRobo = 420;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
			}
			else if(LadoMagnetismo == 0)
			{	
				
				if(nMagnetismo == 3)
				{
					if(iRoboEscalaMag == 1)
					{
						putimage(380, 220, MEIM[0], AND_PUT);
						putimage(380, 220, MEI[0], OR_PUT);
					}
					else if(iRoboEscalaMag == 2)
					{
						putimage(370, 210, MEIM[1], AND_PUT);
						putimage(370, 210, MEI[1], OR_PUT);
					}
					else if(iRoboEscalaMag == 3)
					{
						putimage(340, 180, MEIM[2], AND_PUT);
						putimage(340, 180, MEI[2], OR_PUT);
					}
					else if(iRoboEscalaMag == 4)
					{
						putimage(300, 160, MEIM[3], AND_PUT);
						putimage(300, 160, MEI[3], OR_PUT);
					}
					else if(iRoboEscalaMag == 5)
					{
						putimage(270, 135, MEIM[4], AND_PUT);
						putimage(270, 135, MEI[4], OR_PUT);
					}
					else if(iRoboEscalaMag == 6)
					{
						putimage(270, 110, MEIM[5], AND_PUT);
						putimage(270, 110, MEI[5], OR_PUT);
					}
					else if(iRoboEscalaMag == 7)
					{
						putimage(240, 80, MEIM[6], AND_PUT);
						putimage(240, 80, MEI[6], OR_PUT);
						
						AgarraMagnetismo = false;
						xRobo = 240;
						yRobo = 80;
					}
					iRoboEscalaMag++;
					iAgarraMagnetismo++;
					if (iAgarraMagnetismo > iRoboEscalaMag)
					{
						iAgarraMagnetismo = 0;
					}
					//Efeito Sonoro Magnetismo
					if(iAgarraMagnetismo == 1)
					{				
		    		    sndPlaySound(".\\sons\\magnetismo.wav", SND_ASYNC);	
					}
				}
				
			}
			delay(120);
		}
		
		Caindo = false;
		
		
		if(not((xRobo >= -10 && xRobo <= 260) && (yRobo == 560))
		&& not((xRobo >= 260 && xRobo <= 360) && (yRobo == 420))
		&& not((xRobo >= 480 && xRobo <= 660) && (yRobo == 220))
		&& not((xRobo >= 800 && xRobo <= 1100) && (yRobo == 420))
		&& not((xRobo >= 840 && xRobo <= 1220) && (yRobo == 620))
		&& not((xRobo >= 1160 && xRobo <= 1220 ) && yRobo == 200)
		)
		{
			if(pulaRobo == false && AgarraMagnetismo == false)
			{
				Caindo = true;
				yRobo += 10;
			}
		}
		
		
		/*xRobo = 785;
		yRobo = 320;*/
		
    	PosObs3[0] = 1180;
		PosObs3[1] = 280;
		PosObs3[2] = 1220;
		PosObs3[3] = 290;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);
		
		/*PosObs3[0] = 300;
		PosObs3[1] = 500;
		PosObs3[2] = 400;
		PosObs3[3] = 520;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		/*PosObs3[0] = 500;
		PosObs3[1] = 300;
		PosObs3[2] = 700;
		PosObs3[3] = 320;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
		
		/*PosObs3[0] = 860;
		PosObs3[1] = 700;
		PosObs3[2] = 1140;
		PosObs3[3] = 710;
		bar(PosObs3[0], PosObs3[1], PosObs3[2], PosObs3[3]);*/
    	
    	andaEsquerda = false;
    	if(GetKeyState(0x41)&0x80)  // A
		{
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			
			if(not(xRobo <= -10 && yRobo == 560)
			&& not((xRobo >= 260 && xRobo <= 280) && (yRobo >= 570))
			&& not((xRobo >= 360 && xRobo <= 370) && (yRobo >= 430 && yRobo <= 520))
			&& not((xRobo >= 860 && xRobo <= 870) && (yRobo >= 480 && yRobo <= 620))
			&& not((xRobo >= 1160 && xRobo <= 1170) && (yRobo >= 100 && yRobo <= 200))
			)
			{
				andaEsquerda = true;
			}
			LadoRobo = 0;
		}
		andaDireita = false;
    	if(GetKeyState(0x44)&0x80)     // D
		{
			//xRobo += 7;
			//xRobo += 10;
			std::cout << xRobo << std::endl;
			std::cout << yRobo << std::endl;
			if(xRobo >= 1280)
			{
				
				//Tela4();
			}
			if(not(xRobo == 260 && (yRobo >= 430 && yRobo <= 520))
			&& not((xRobo == 1080) && (yRobo >= 0 && yRobo <= 420))
			&& not((xRobo >= 1200 && xRobo <= 1200) && (yRobo >= 480 && yRobo <= 620))
			&& not((xRobo == 1200) && (yRobo >= 100 && yRobo <= 200))
			)
			{
				andaDireita = true;
			}
			
			LadoRobo = 1;
		}
    	if(GetKeyState(0x53)&0x80)   // S Agachar
    	{
    		//PiscaCaixa += 1;
    		if((xRobo == 860) && yRobo == 420)
			{
				DesceEscada = true;
				DescendoEscada == 1;
			}
		}
		//pulaRobo = false;
		if(GetKeyState(0x57)&0x80)   // W Pular
    	{
    		if(xRobo == 860 && yRobo == 620 && SobeEscada == false)
    		{
    			SobeEscada = true;
    			SubindoEscada = 1;
    			nEscada = 1;
			}
			else if(xRobo == 1200 && yRobo == 620 && SobeEscada == false)
			{
				SobeEscada = true;
    			SubindoEscada = 1;
    			nEscada = 2;
			}
			else if(xRobo == 1200 && yRobo == 200 && SobeEscada == false)
			{
				SobeEscada = true;
    			SubindoEscada = 1;
    			nEscada = 3;
			}
    		else{
    			if(SobeEscada == false && DesceEscada == false)
    			{
    				pulaRobo = true;
    				if(iRoboPula == 0){ iRoboPula = 1; };
				}
			}
		}
		if(GetKeyState(0x4b)&0x80)   // K Agarrar magnetismo
    	{
    		
    		if(LadoRobo == 1)
    		{
    			if((xRobo >= 160 && xRobo <= 240) && yRobo == 560 && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 1;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
				else if((xRobo >= 280 && xRobo <= 340) && (yRobo == 420) && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 2;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 1;
	    			iRoboEscalaMag = 1;
				}
			}
			else if(LadoRobo == 0)
			{
				//if((xRobo >= 1165 && xRobo <= 1185) && (yRobo == 620) && AgarraMagnetismo == false)
				/*if((xRobo >= 360 && xRobo <= 420) && yRobo == 220 && AgarraMagnetismo == false)
	    		{
	    			nMagnetismo = 3;
	    			AgarraMagnetismo = true;
	    			LadoMagnetismo = 0;
	    			iRoboEscalaMag = 1;
				}*/
			}
    		//PiscaCaixa += 1;
		}
		if(GetKeyState(0x4c)&0x80)   // L Disparar o braço na direção
    	{
    		//PiscaCaixa += 1;
			/*xRobo = 100;
			yRobo = 560;*/
			xRobo = 900;
			yRobo = 620;
		}



		setvisualpage(pg);
	
	    delay(30);
	
	    fflush(stdin);
	    if (kbhit())
	      tecla = getch();   
	}
	
	closegraph();	

  	
}



int Min (int a, int b) {
  if (a < b)
    return(a);
  else
    return(b);
}

int Max (int a, int b) {
    if (a > b)
    return(a);
  else
    return(b);
}

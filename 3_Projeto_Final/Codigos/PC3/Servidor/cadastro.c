#include<stdio.h>
#include <ctime>
#include <iostream>
#include <raspicam/raspicam_cv.h>
using namespace std;

int main(int arg, char *argv[]){

	FILE *escrita;
  // Escrevendo no arquivo
	escrita = fopen("lista.txt","a");

  if (escrita == NULL)
	{
		printf("Erro na abertura do arquivo");
		return 1;
	}
  fprintf(escrita," %s \n",argv[1]);
	fclose(escrita);
	printf("Os dados foram gravados com sucesso! \n");

// tirando foto
	time_t timer_begin,timer_end;
	raspicam::RaspiCam_Cv Camera;
	cv::Mat image;
	int nCount=100;
	//set camera params
	//Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
	//Open camera
	cout<<"Opening Camera..."<<endl;
	if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}
	//Start capture
	cout<<"Capturing "<<nCount<<" frames ...."<<endl;
	time ( &timer_begin );
	for ( int i=0; i<nCount; i++ ) {
		Camera.grab();
		Camera.retrieve ( image);
		if ( i%5==0 )  cout<<"\r captured "<<i<<" images"<<std::flush;
	}
	cout<<"Stop camera..."<<endl;
	Camera.release();
	//show time statistics
	time ( &timer_end ); /* get current time; same as: timer = time(NULL)  */
	double secondsElapsed = difftime ( timer_end,timer_begin );
	cout<< secondsElapsed<<" seconds for "<< nCount<<"  frames : FPS = "<<  ( float ) ( ( float ) ( nCount ) /secondsElapsed ) <<endl;
	//save image
	cv::imwrite(argv[1]".jpg",image);
	cout<<"Image saved at raspicam_cv_image.jpg"<<endl;


return 0;
}

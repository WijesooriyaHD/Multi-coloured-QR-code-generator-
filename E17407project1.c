#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *gethashstr(const char input[], int size);   //prototype function decleration
void piSquare(int bgcc);
void character(int ch,int bgcc);
void frame(int no);


int main(int argc,char *argv[]){   //decleration of command line argument(c.l.a)
        
	int flag=0; //assign variable flag to 0

	if(argc==3){  //check whether colour is given or not in the c.l.a

		for(int i=0;argv[2][i]!=0;i++){      //loop through argv[2](colour) and convert all letters in to lowercase
			argv[2][i]=tolower(argv[2][i]);
		}

		 flag=!(strcmp(argv[1],"-c"));   //check whether the flag of the c.l.a is -c or not ,if it is -c flag=1
	}



	if(((flag)&& argc==3)||argc==1){    //check whether the given c.l.a  is correct or not

		if(argc==1||(!(strcmp(argv[2],"black")))||!(strcmp(argv[2],"red")) || !(strcmp(argv[2],"green")) || !(strcmp(argv[2],"yellow")) || !(strcmp(argv[2],"blue")) || !(strcmp(argv[2],"magenta")) || !(strcmp(argv[2],"cyan"))){   //check whether the given colour is valid or not


			char input[121];               // decleration of array to store URL

		

			 printf("Enter URL: ");    //prompt user to enter URL
               		 scanf("%[^\n]%*c",input);     //get input from the user


			int inplen=strlen(input);          //length of the URL
			
			int bgcc;   // variable decleration bgcc-background colour code

			if(argc==1||(!(strcmp(argv[2],"black")))){                     //assigning bgcc(background colour code) according to the user input
				bgcc=40;
			}else{
				if(!(strcmp(argv[2],"red"))){
					bgcc=41;
				}else{
					if(!(strcmp(argv[2],"green"))){
						bgcc=42;
					}else{
						if(!(strcmp(argv[2],"yellow")) ){
							bgcc=43;
						}else{
							if(!(strcmp(argv[2],"blue"))){
								bgcc=44;
							}else{
								if(!(strcmp(argv[2],"magenta"))){
									bgcc=45;
								}else{
									bgcc=46;
								}
							}
						}
					}
				}
			}
				
	


			 if(3<inplen && inplen<120){     //chek the length of the input

				char *hashStr1;    //pointer to store an array
				 if(inplen<=20){      //check whether it is smaller qr version or not
                                    
				   hashStr1=gethashstr(input,25);    //invoke gethashstr function to get pointer ,25 -array size for smaller qr version

				   for(int v=0;v<20;v++){   //move curser down by 50
					   printf(" \n");
				   }

				    frame(20);          //print the basic frame on the terminal

				    printf("\033[19A\033[2C");   //move the curser
				    piSquare(bgcc);  // print position ientification square
	   			     
				     character(hashStr1[20],bgcc);   //print ch21,ch23
			     	     character(hashStr1[22],bgcc);

	     			     piSquare(bgcc);  //print position identification square

				     printf("\033[12C\033[18A");   //move curser
				    
				     character(hashStr1[16],bgcc);  //print ch17,ch19
				     character(hashStr1[18],bgcc);
				     printf("\033[6D");

				     character(hashStr1[21],bgcc);  //print ch22,ch24
				     character(hashStr1[23],bgcc);
				     printf("\033[6C\033[6A");
				
				     for(int a1=0;a1<13;a1=a1+4){
				    	 character(hashStr1[a1],bgcc);   //print ch1,ch5,ch9,ch13 in the correct positions
				     }
				     printf("\033[6C\033[18A");

				     character(hashStr1[17],bgcc);   //print ch18
				     character(hashStr1[19],bgcc);  //print ch20
				     for(int a1=1;a1<14;a1=a1+4){
				    	 character(hashStr1[a1],bgcc);  //print ch2,ch6,ch10,ch14 in the correct positions
				     }
				     printf("\033[6C\033[18A");

				     piSquare(bgcc);                   //print position identification square
                                     
				     for(int a1=2;a1<15;a1=a1+4){
				    	 character(hashStr1[a1],bgcc);    //print ch3,ch7,ch11,ch15 in the correct positions
				     }
				     printf("\033[6C\033[12A");

				     for(int a1=3;a1<16;a1=a1+4){      
					    character(hashStr1[a1],bgcc);  //print ch4,ch8.ch12,ch16 in the correct positions
				     }

				     printf("\n"); //move curser to new line
				     


				}else{     //code to print the larger QR version

					 hashStr1=gethashstr(input,133);   //invoke gethashstr function to get pointer , 133-array size for larger qr version
					 
					 for(int v=0;v<20;v++){   //move curser down by 50
                                           printf(" \n");
                                         }


					 frame(38);  //print the basic frame

					 printf("\033[37A\033[2C");   //move the curser
					 piSquare(bgcc);  // print position ientification square

					 for(int a2=116;a2<131;a2=a2+2){
						 character(hashStr1[a2],bgcc);  //print ch117,ch119,ch121,ch123,ch125,ch127,ch129,ch131 in the correct positions
				        
					 }
					 piSquare(bgcc);  // print position ientification square

					 printf("\033[12C\033[36A");
					 character(hashStr1[100],bgcc);   //print ch101,ch109
					 character(hashStr1[108],bgcc);

					 printf("\033[6D");
					 for(int a2=117;a2<132;a2=a2+2){
                                                 character(hashStr1[a2],bgcc);  //print ch118,ch1120,ch122,ch124,ch126,ch128,ch130,ch132 in the correct positions

                                         }
					 printf("\033[6C\033[24A");
					 for(int a2=0;a2<91;a2=a2+10){            //print ch1,ch11,ch21,ch31,ch41,ch51,ch61,ch71,ch81,ch91 in the correct positions

                                                 character(hashStr1[a2],bgcc);

                                         }

				
					 printf("\033[6C\033[36A");

					 character(hashStr1[101],bgcc);  //print ch 102
                                         character(hashStr1[109],bgcc);  //print ch110
					 for(int a2=1;a2<92;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(2,12,22,32,42,52,62,72,82,92) in the correct positions

                                         }

					 printf("\033[6C\033[36A"); //move curser toleft and up
					 character(hashStr1[102],bgcc);   //print ch103
                                         character(hashStr1[110],bgcc);  //print ch111
                                         for(int a2=2;a2<93;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(3,13,23,33,43,53,63,73,83,93) in the correct positions

                                         }
					 printf("\033[6C\033[36A");   //move curser to left and up
                                         character(hashStr1[103],bgcc);  //print ch104
                                         character(hashStr1[111],bgcc);  //print ch112
                                         for(int a2=3;a2<94;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(4,14,24,34,44,54,64,74,84,94) in the correct positions

                                         }

					 printf("\033[6C\033[36A");   //move curser to left and up
                                         character(hashStr1[104],bgcc);  //print ch105
                                         character(hashStr1[112],bgcc);  //print ch113
                                         for(int a2=4;a2<95;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(5,15,25,35,45,55,65,75,85,95)in the correct positions


                                         }

					 printf("\033[6C\033[36A");     //move curser to left and up
                                         character(hashStr1[105],bgcc); //print ch 106
                                         character(hashStr1[113],bgcc);  //print ch 114
                                         for(int a2=5;a2<96;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(6,16,26,36,46,56,76,86,96) in the correct positions


                                         }

					 printf("\033[6C\033[36A");  //move curser to left and up
                                         character(hashStr1[106],bgcc);  //print ch 107
                                         character(hashStr1[114],bgcc);  //print ch115
                                         for(int a2=6;a2<97;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(7,17,27,37,47,57,67,87,97)in the correct positions


                                         }

					 printf("\033[6C\033[36A"); //move curser to left and up
                                         character(hashStr1[107],bgcc);  //print ch 108
                                         character(hashStr1[115],bgcc);  //print ch116
                                         for(int a2=7;a2<98;a2=a2+10){
                                                 character(hashStr1[a2],bgcc); //print ch(8,18,28,38,48,58,68,78,88,98)in the correct positions


                                         }

					  printf("\033[6C\033[36A");  //move curser to left and up

					  piSquare(bgcc);  // print position ientification square

					 
                                         for(int a2=8;a2<99;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(9,19,29,39,49,59,69,79,89,99)in the correct positions


                                         }

					 printf("\033[6C\033[30A");  //move curser t left and up

					 for(int a2=9;a2<100;a2=a2+10){
                                                 character(hashStr1[a2],bgcc);  //print ch(10,20,30,40,50,60,70,80,90,100)in the correct positions


                                         }


					printf("\n"); //print new  line

				}
			 }else{
				if(inplen>=120){
					printf("String is too long. Not supported by available QR versions\n");          //prompt when the length of the input is not in the range
				}else{
					 printf("String is too short. Not supported by available QR versions\n");   
				}
			}




		}else{


			printf("Invalid argument for color.\n");  //prompt user that the given colour is not supported
			printf("usage :\n");
			printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
                        printf("%s -h for the help about the program\n",argv[0]);

		}
		
		
	}else{

		if(!strcmp(argv[1],"-h")&&(argc==2)){

	     	        printf("usage :\n");	                                    	//prompt the user about how to give input
			printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
	       	        printf("%s -h for the help about the program\n",argv[0]);

		}else{
		       	printf("Incorrect usage of arguments.\n");
                        printf("usage :\n");                                            //prompt the user about how to give input
                        printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
                        printf("%s -h for the help about the program\n",argv[0]);

		}


	}                                                

        
	return 0;
}


char    *gethashstr (const char input[],  int size){   //function to create hashed string

        static int array1[256]; //contains ascii codes
         static  char hashStr1[256];   //contain hashed str
	  int inplen=strlen(input);    //get the length of  the input
	
	 array1[0]=inplen+50;    //assign initial value to array1
	 int c1,c2,c3=0;
        for(c1=1;c1<(size-1);c1++){    //code to generate array1 which contains ascii codes
        	 for(c2=0;c2<inplen;c2++){

                 	 array1[c1]=input[c2]+c3;

                         c1++;
                       	if(c1>=(size-1)){
                        	 break;
                         }
                 }
               	 c3++;
                 c1--;
        }

                        //code to get the reversed array
	int c6=size-2;
       for(int c4=0;c4<(size-1);c4++){
      	 if(c4<=inplen){
             hashStr1[c4]=array1[c4];
	     
          }else{
             hashStr1[c4]=array1[c6];
	    
             c6--;
          }
     }
     
     return hashStr1;  //return hashsed string
}



void piSquare(int bgcc){          //function to print piSquare  (position identintification square) according to the colour ,given by the user
	
	int sqr[6][6]={{1,1,1,1,1,1},{1,0,0,0,0,1},{1,0,1,1,0,1},{1,0,1,1,0,1},{1,0,0,0,0,1},{1,1,1,1,1,1}};  //2D array decleration which contains the binary number pattern  of the piSquare
	for(int i=0;i<6;i++){         
		for(int j=0;j<6;j++){  //loop through the elements of the array
			if(sqr[i][j]==1){
				printf("\033[%dm  ",bgcc); //when elemnt is ==1,print a space with the given background colour
			
			}else{
				printf("\033[47m  ");   //when element is ==0,print a space with white background colour
			}

		}
		printf("\033[m"); //set default terminal colour
		printf("\033[B");  //move curser down by 1
                printf("\033[%dD",12);  //move curser left by 12
	}
	printf("\033[0m");  //set default terminal colour
}


void character(int ch,int bgcc){            //function to print the encoded pattern of one character

	int bc[10];  // decleration of an array ,bc -array to store 9 bit binary number
	int c7=8,re;       //c7- counter variable , re-remainder
  	if(ch>0){   
		while(ch>0){                                            
			re=ch%2;                           //code to convert a positive decimal number  in to 9bit binary number
			ch=ch/2;
			bc[c7]=re;
			c7--;
		}

		while(c7!=-1){
			bc[c7]=0;
			c7--;
		}
	}else{                       
	   					
						//code to convert a decimal  negative number  in to 9bit binary number....considering -127=129
		int count=128+ch;   
		int new=128+count;
		 while(new>0){                                            
                        re=new%2;               
                        new=new/2;
                        bc[c7]=re;
                        c7--;
                }

                while(c7!=-1){
                        bc[c7]=0;
                        c7--;
                }


	}

	int c10=0;  



	for(int c8=0;c8<3;c8++){  //code to print the encoded pattern of one character
		
              

		for(int c9=0;c9<3;c9++){
			
			if(bc[c10]==1){
				printf("\033[%dm  ",bgcc); //when elemnt is ==1,print a space with the given background colour
			
				
			}else{
				 printf("\033[47m  ");   //when element is ==0,print a space with white background colour
			        
                             
			}
			c10++;
		}
		
		printf("\033[m");  //set the defualt terminal colour

		printf("\033[B");	//move curser down by 1
		printf("\033[%dD",6);  //move curser left by 6
	}


	
}

		
void frame(int no){                    //function to print the basic frame-this prints a white colour filled square
	for(int c11=0;c11<no;c11++){
		for(int c12=0;c12<no;c12++){
			  printf("\033[47m  ");   //print a white colour space
		}
		 printf("\033[m");  //set default terminal colour
		 printf("\n");  //print new line
	}

	 printf("\033[m");   //set default terminal colour
	
 }

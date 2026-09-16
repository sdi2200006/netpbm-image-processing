#include <stdio.h>
#define ENCODED 0
 /*IF ENCODED=0,IT CHANGE THE COLOUR AND IF ENCODED=1,IT CHANGE THE TEXT FILE (BONUS)*/                  

int space (int ch){                                    /*CHECKS FOR SPACE*/
    while (ch==' ' || ch=='\n'|| ch=='\t' ){           /*READS AND PRINT SPACES*/
        putchar(ch);
        ch=getchar();
    }
    return ch;
}

int space2 (int ch){                                   /*CHECKS FOR SPACE */
    while (ch==' ' || ch=='\n'|| ch=='\t' ){           /*ONLY READS WHITE SPACES */
        ch=getchar();
    }
    return ch;
}

int checking(int ch){                                   /*ASCII -> NUMBERS*/
    int temp;
    temp=0;
    while (ch>='0' && ch<='9'){
        temp= (ch-'0')+ temp*10;
        ch=getchar();
    }
    if (ch==' ' || ch=='\n'|| ch=='\t'){
        return temp;
    }
    else{                                              /*BECAUSE IT CAN READ A LETTER OR =,-,_,&,(),# ...  AND THIS IS A ERROR*/
        return -1;
    }
}


int main(void){
    int red, green,blue, grey, ch2, max, height, width, temp,temp_width,i, n, err=0;
    int ch,count,pixels;
    if(ENCODED==0){
        ch=getchar();  
        if (ch=='P'){                                           
            putchar(ch);                                   /*PRINTS "P"*/
            ch2=getchar();                                 /*KEEP NUMBER FOR ORIGINAL COLOR*/
            if (ch2=='2'){                                 /*THE "IF" PRINT THE NUMBER WHICH SHOWS THE COLOUR OF FINAL IMAGE*/
                putchar('1');
            }
            else if (ch2=='3'){
                putchar('2');
            }
            else if (ch2=='5'){
                putchar('4');
            }
            else if (ch2=='6'){
                putchar('5');
            }
            else {
                printf("Input error!");
                return 1;
            }   
        }
        else {                                         /*IF THE FIRST CHAR IS NOT "P" IT'S A ERROR*/
            printf("Input error!");
            return 1;
        }
        ch=getchar();                                    /*READS NEXT CHAR*/
        ch=space(ch);                                      
        i=0;                                             /*AS A LOGIC VARIABLE*/
        while (ch=='#'){                                 /*CHECKS FOR COMMENTS AND AFTER CHECKS IF THEY EXIST AND ON THE NEXT LINE*/
            ch=getchar();
            while (ch!='\n'){                            /*CHECK IF LINE CHANGED*/
                ch=getchar();
            }
            if (i==0){                                   /*TO PRINT ONLY ONE LINE CHANGE*/
                putchar(ch);
                i=1;                                     /*CHANGE i=1 TO KNOW THAT IT HAS PRINTED A LINE CHANGE*/
            }
            ch=getchar();
        }           
        width=0;                                         /*COMPUT THE WIDTH*/
        if (ch>='0' && ch<='9'){
            while (ch>='0' && ch<='9'){
                putchar(ch);                             /*DUE TO THIS COMMAND I AM NOT USING THE "CHECKING" FUNCTION */
                width= (ch-'0')+ width*10;
                ch=getchar();
            }
        }
        else {                                          /*BECAUSE IT CAN READ A LETTER OR =,-,_,&,(),# ...  AND THIS IS A ERROR*/
            printf("input error");
            return 1;
        } 
        putchar(ch);
        ch=getchar();
        height=0;                                        /*COMPUT HEIGHT*/
        if (ch>='0' && ch<='9'){
            while (ch>='0' && ch<='9'){
                putchar(ch);                                  /*DUE TO THIS COMMAND I AM NOT USING THE "CHECKING" FUNCTION */
                height= (ch-'0')+ height*10;
                ch=getchar();
            }
        }
        else {                                           /*BECAUSE IT CAN READ A LETTER OR =,-,_,&,(),# ...  AND THIS IS A ERROR*/
            printf("input error");
            return 1;
        } 
        pixels=width*height;                             /*TOTAL OF PIXELS*/
        count=1;                                         /*SHOWS THE NEXT PIXEL */
        if (ch2!='1' && ch2!='4'){                       /*IF IT'S NOT BLACK-WHITE (1OR4) WAITS TO READ MAX FOR COLOR QUANTITY*/
            putchar(ch);
            ch=getchar();
            max=0;
            while (ch>='0' && ch<='9'){                  /*COMPUT THE MAX*/      
                max= (ch-'0')+ max*10;
                if (ch2=='3' || ch2=='6'){               /*BECAUSE OF THE "IF" STATEMENT I AM NOT USING THE "CHECKING" FUNCTION */
                    putchar(ch);                         /*WE NEED TO PRINT MAX WHEN THE FINAL IS GREY */
                }
                ch=getchar();
            }
            if (max==0){                           /* it means 2 things. 1) there wasn't repetition or 2) that max=0. both aren't right */
                printf ("input error");
                return 1;
            }
            if (ch2 == '3' || ch2 =='6')
                putchar('\n'); 
        }

            if (ch2=='2'){                          /*GREY -> WHITE-BLACK TEXT FILE*/
              n=0;                                     
              while (count<=pixels && ch!=EOF){     /*UNTIL THE FILE IS FINISHED OR UNTIL ALL PIXELS ARE FILLED */
                ch=getchar();
                ch=space(ch);                       /*CHECK FOR SPACES*/
                grey=checking(ch);                  /*COMPUT AMOUNT OF GRAY FOR CURRENT PIXEL*/
                if (grey>(max+1)/2) {              
                    printf("0 ");
                }
                else {
                    printf("1 ");
                }
                n++;                                 /*INCREASE N AT EACH REPETITION*/
                if (n%84==0)                         /*PRINTS NEXT LINE WHEN IT PRINTS 84 CHAR*/
                    printf("\n");
                count++;                             /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL AT EACH REPETITION*/
                if (grey==-1 || grey>max){ 
                    printf("input error");
                    return 1;
                }
            }
        }
        else if (ch2=='3'){                              /*COLOUR -> GREY TEXT FILE*/
            n=0;
            while (count<=pixels && ch!=EOF){            /*UNTIL THE FILE IS FINISHED OR UNTIL ALL PIXELS ARE FILLED*/
                ch=getchar();
                ch=space(ch);                            /*CHECK FOR SPACES*/
                red=checking(ch);                        /*READS THE AMOUNT OF RED COLOR*/
                ch=getchar();
                ch=space(ch);                            /*CHECK FOR SPACES*/
                green=checking(ch);                      /*READS THE AMOUNT OF GREEN COLOR*/
                ch=getchar();
                ch=space(ch);                            /*CHECK FOR SPACES*/
                blue=checking(ch);                       /*READS THE AMOUNT OF BLUE COLOR*/
                grey=(299*red+587*green+114*blue)/1000;  /*COMPUT THE AMOUNT OF GRAY*/
                printf("%d ",grey);
                n++;                                     /*INCREASE N AT EACH REPETITION*/
                count++;                                 /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL AT EACH REPETITION*/
                if (n%84==0)                             /*PRINTS NEXT LINE WHEN IT PRINTS 84 CHAR*/
                    printf("\n");
                if (red==-1 || blue==-1 || green==-1 || red>max || green>max || blue>max){   /*IT'S ERROR IF IN THE FILE THERE WAS A LETTER*/
                    printf("input error");
                    return 1;
                }
            }
        }
        else if (ch2=='5'){                              /*GRAY CONVERT -> BLACK-WHITE BINARY*/
            ch=getchar();
            if (width%8==0){                             /*IF IMAGE WIDTH IS A MULTIPLE OF 8*/           
                while (count<=pixels && ch!=EOF){        /*UNTIL THE FILE HAS ENDED OR UNTIL ALL PIXELS ARE FILLED*/                    
                    grey=0;
                    n=128;                               /*8TH BIT FROM BINARY TO DECIMAL IS MULTIPLYED BY 128*/
                    while (n!=0){                        /*UNTIL FINISHED ONE BYTE*/
                        if (ch>max){
                            printf("input error");
                            return 1;
                        }
                        if (ch>((max+1)/2)){
                            temp=0;
                        }
                        else {
                            temp=1;
                        }
                        grey= grey + temp*n;             /*COMPUT GREY*/
                        n/=2;                            /*EACH BIT RELATIVE TO THE PREVIOUS IS MULTIPLYED BY -1 TO THE POWER OF 2 (BINARY->DECIMAL)*/
                        ch=getchar();
                        count++;                         /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL*/
                    }
                    putchar(grey);
                }
            }
            else {                                      /*IF IMAGE WIDTH IS NOT A MULTIPLE OF 8*/
                while (count<=pixels && ch!=EOF){  
                    temp_width=width;                    /*EACH LINE WIDTH IS ASSIGNED TO "TEMP"  EACH TIME WE READ A NEW LINE AND IT WILL CHANGE TO SHOW HOW MANY CHARACTERS ARE LEFT TO READ ON THE NEW LINE*/
                    while (temp_width>0  && count<=pixels && ch!=EOF){   /*UNTIL THE LINE OR FILE HAVE ENDED OR UNTIL ALL PIXELS ARE FILLED*/
                        if (ch>max){
                            printf("input error");
                            return 1;
                        }
	                    n=128;                           /*8TH BIT FROM BINARY TO DECIMAL IS MULTIPLYED BY 128*/
                        grey=0;         
                        while (n!=0  &&  temp_width>0 ){ /*UNTIL THE LINE IS ENDED AND THE BYTE IS NOT FILLED*/
                            if (ch>((max+1)/2)){
                                temp=0;
                            }
                            else {
                                temp=1;
                            }
                            grey= grey + temp*n;
                            n/=2;                        /*EACH BIT RELATIVE TO THE PREVIOUS IS MULTIPLYED BY -1 TO THE POWER OF 2 (BINARY->DECIMAL)*/
                            ch=getchar();
                            count++;                     /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL*/
                            temp_width--;                /*I UPDATE IT ON EACH CHARACTER SO IT KNOWS HOW MANY CHARACTERS ARE ON EACH LINE*/
                        }  
                        if (n==0){                       /*FINISH 1 DIP SO PRINTING DIRECTLY*/
                            putchar(grey);
                        }
                        else{
                            while (n!=0 ){              /*THE LINE IS ENDED AND THE LAST BYTE SHOULD BE FILLED WITH 1*/
                                grey= grey + 1*n;
                                n/=2;
                            }
                            putchar(grey);
                        }
                    }   
                }
            }
        }
        else if (ch2=='6'){                               /*CONVERT COLOR-> GRAY BINARY*/
            red=getchar();
            if (red!=EOF && count<=pixels){               /*CHECKS IF THE FILE ENDED*/
                do{
                    green=getchar();
                    blue=getchar();
                    grey=(299*red+587*green+114*blue)/1000;
                    if (red>max || blue>max || green>max){          /*IT'S ERROR IF A COLOUR IS BIGGER THAN MAX*/
                        printf("input error");
                        return 1;
                    }
                    putchar(grey);
                    red=getchar();
                    count++;
                }while (count<=pixels && red!=EOF);                  /*UNTIL THE FILE IS FINISHED OR UNTIL ALL PIXELS ARE FILLED*/
            }
        }
        if (ch2=='3' || ch2=='2'){
            ch=space(ch);                       /*we should be sure that the others characters aren't \n,\t, ....*/
            if (ch!=EOF || count!=pixels){      /*IF THE FILE HAS'T ENDED OR THE PIXELS DOESH'T HAVE COMPLETED,IT'S A ERROR*/
                return -1;
            } 
        }
        else if (ch2=='5'){
            if (ch!=EOF || count!=pixels){
                return -1;
            }
        }
        else if (ch2=='6'){
            if (red!=EOF || count!=pixels){
                return -1;
            }
        }
        return 0;
    }


    else if (ENCODED==1){
        ch=getchar();  
        if (ch=='P'){                                           
            putchar(ch);                                   /*PRINTS "P"*/
            ch2=getchar();                                 /*KEEP NUMBER FOR ORIGINAL COLOR*/
	        if (ch2=='1'){                                 /*THE "IF" PRINT THE NUMBER WHICH SHOWS THE COLOUR OF FINAL IMAGE*/
                putchar('4');
            }
            else if (ch2=='2'){                         
                putchar('5');
            }
            else if (ch2=='3'){
                putchar('6');
            }
	        else if (ch2=='4'){
                 putchar('1');
            }
            else if (ch2=='5'){
                putchar('2');
            }
            else if (ch2=='6'){
                putchar('3');
            }
            else {
                printf("Input error!");
                return 1;
            }   
        }
        else {                                      /*IF THE FIRST CHAR IS NOT "P" IT'S A ERROR*/
            printf("Input error!");
            return 1;
        }
        ch=getchar();
        ch=space(ch);                                      
        i=0;                                        /*AS A LOGIC VARIABLE*/
        while (ch=='#'){                            /*CHECKS FOR COMMENTS AND AFTER CHECKS IF THEY EXIST AND ON THE NEXT LINE*/
            ch=getchar();
            while (ch!='\n'){                       /*CHECK IF LINE CHANGED*/
                ch=getchar();
            }
            if (i==0){                              /*TO PRINT ONLY ONE LINE CHANGE*/
                putchar(ch);
                i=1;                                /*CHANGE i=1 TO KNOW THAT IT HAS PRINTED A LINE CHANGE*/
            }
            ch=getchar();
        }           
        width=0;                                   /*COMPUT THE WIDTH*/
        if (ch>='0' && ch<='9'){
            while (ch>='0' && ch<='9'){
                putchar(ch);                       /*DUE TO THIS COMMAND I AM NOT USING THE "CHECKING" FUNCTION */
                width= (ch-'0')+ width*10;
                ch=getchar();
            }
        }
        else {                                    /*BECAUSE IT CAN READ A LETTER OR =,-,_,&,(),# ...  AND THIS IS A ERROR*/
            printf("input error");
            return 1;
        } 
        putchar(ch);
        ch=getchar();
        height=0;                                 /*COMPUT HEIGHT*/
        if (ch>='0' && ch<='9'){
            while (ch>='0' && ch<='9'){
                putchar(ch);                      /*DUE TO THIS COMMAND I AM NOT USING THE "CHECKING" FUNCTION */
                height= (ch-'0')+ height*10;
                ch=getchar();
            }
        }
        else {                                    /*BECAUSE IT CAN READ A LETTER OR =,-,_,&,(),# ...  AND THIS IS A ERROR*/
            printf("input error");
            return 1;
        } 
        if (ch2!='1' && ch2!='4'){                  /*IF IT'S NOT BLACK-WHITE (1OR4) WAITS TO READ MAX FOR COLOR QUANTITY*/
            ch=space(ch);
            max=checking(ch);                     /*COMPUT MAX*/
            printf("%d\n",max);                   /*PRINTS MAX AT THE FINAL PICTURE*/
            if (max == -1){                       /*IF THERE WASN A FALSE CHARACTER*/
 	            printf("input error"); 
                return 1;	 
            }
        }
        else{ 
            printf("\n");
        }
        pixels=width*height;                        /*TOTAL OF PIXELS*/
        count=1;                                    /*SHOWS THE NEXT PIXEL */
        if (ch2=='1'){  
            while (count<=pixels && ch!=EOF){  
                ch=space2(ch);
                temp_width=width;                                    /*EACH LINE WIDTH IS ASSIGNED TO "TEMP"  EACH TIME WE READ A NEW LINE AND IT WILL CHANGE TO SHOW HOW MANY CHARACTERS ARE LEFT TO READ ON THE NEW LINE*/
                while (temp_width>0  && count<=pixels && ch!=EOF){   /*UNTIL THE LINE OR FILE HAVE ENDED OR UNTIL ALL PIXELS ARE FILLED*/
	                n=128;                                           /*8TH BIT FROM BINARY TO DECIMAL IS MULTIPLYED BY 128*/
                    temp=0;     
                    while (n!=0  &&  temp_width>0 && ch!=EOF){       /*UNTIL THE LINE IS ENDED AND THE BYTE IS NOT FILLED*/
                        grey=checking(ch);                           /*COMPUT AMOUNT OF GRAY FOR CURRENT PIXEL*/
                        if (grey==1)
                            temp+=n;
                        else if (grey==0)
                            temp=temp;
                        else /*if (grey== -1)*/{              
        			        printf("input error");
        		            return 1;
                        } 
                        n/=2;                        /*EACH BIT RELATIVE TO THE PREVIOUS IS MULTIPLYED BY -1 TO THE POWER OF 2 (BINARY->DECIMAL)*/
                        ch=getchar();
    		            ch=space2(ch);               /*CHECK FOR SPACES*/     
                        count++;                     /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL*/
                        temp_width--;                /*I UPDATE IT ON EACH CHARACTER SO IT KNOWS HOW MANY CHARACTERS ARE ON EACH LINE*/
                    }  
                    if (n==0){                       /*FINISH 1 DIP SO PRINTING DIRECTLY*/
                        putchar(temp);
                    }
                    else{
                        while (n!=0 ){               /*THE LINE IS ENDED AND THE LAST BYTE SHOULD BE FILLED WITH 1*/
                            temp= temp + n;
                            n/=2;
                        }
                        putchar(temp);
                    }
                }   
            }   
        }
        else if (ch2=='2'){                         /*GREY  TEXT FILE -> GREY BINARY FILE*/
          	while (count<=pixels && ch!=EOF){       /*UNTIL THE FILE IS FINISHED OR UNTIL ALL PIXELS ARE FILLED */
           		ch=getchar();
        		ch=space2(ch);                      /*CHECK FOR SPACES*/
                grey=checking(ch);                  /*COMPUT AMOUNT OF GRAY FOR CURRENT PIXEL*/
            	count++;                            /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL*/
        		if (grey== -1 || grey>max){         /*IT'S ERROR IF IN THE FILE THERE WAS A LETTER OR COLOUR>MAX*/
        			printf("input error");
        			return 1;
                }
            	putchar(grey);
            }
        }
        else if (ch2=='3'){                            /*COLOUR TEXT FILE -> COLOUR BINARY FILE*/
            while (count<=pixels && ch!=EOF){          /*UNTIL THE FILE IS FINISHED OR UNTIL ALL PIXELS ARE FILLED*/
                ch=getchar();
            	ch=space2(ch);                         /*CHECK FOR SPACES*/
            	red=checking(ch);                      /*READS THE AMOUNT OF RED COLOR*/
            	ch=getchar();
            	ch=space2(ch);                         /*CHECK FOR SPACES*/
                green=checking(ch);                    /*READS THE AMOUNT OF GREEN COLOR*/
            	ch=getchar();
            	ch=space2(ch);                         /*CHECK FOR SPACES*/
            	blue=checking(ch);                     /*READS THE AMOUNT OF BLUE COLOR*/
            	count++;                               /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL*/
                if (red==-1 || blue==-1 || green==-1 || red>max || green>max || blue>max){    /*IT'S ERROR IF IN THE FILE THERE WAS A LETTER OR COLOUR>MAX*/
            		printf("input error");
            		return 1;
                }
                putchar(red);
                putchar(green);
                putchar(blue);
            }
        }
       else if(ch2=='4'){
            ch=getchar();                                /*READS THE FIRST BYTE*/
            if (width%8==0){                             /*IF IMAGE WIDTH IS A MULTIPLE OF 8*/           
                while (count<=pixels && ch!=EOF){        /*UNTIL THE FILE HAS ENDED OR UNTIL ALL PIXELS ARE FILLED*/                    
                    n=128;                               /*8TH BIT FROM BINARY TO DECIMAL IS MULTIPLYED BY 128*/
                    while (n!=0 && ch!=EOF){             /*UNTIL FINISHED ONE BYTE AND THE FILE END*/
                        temp=ch/n;                       
                        if (temp!=0 && temp!=1){
                            printf ("input error");
                            return 1;
                        }
                        printf("%3d  ",temp);
                        ch = ch -temp*n;
                        n/=2;                         /*EACH BIT RELATIVE TO THE PREVIOUS IS MULTIPLYED BY -1 TO THE POWER OF 2 (BINARY->DECIMAL)*/
                        count++;                      /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL*/
                    }
                    ch=getchar();                     /*READS THE NEXT ONE BYTE*/
                }
            }
            else {                                    /*IF IMAGE WIDTH IS NOT A MULTIPLE OF 8*/
                while (count<=pixels && ch!=EOF){  
                    temp_width=width;                 /*EACH LINE WIDTH IS ASSIGNED TO "TEMP"  EACH TIME WE READ A NEW LINE AND IT WILL CHANGE TO SHOW HOW MANY CHARACTERS ARE LEFT TO READ ON THE NEW LINE*/
                    while (temp_width>0  && count<=pixels && ch!=EOF){   /*UNTIL THE LINE OR FILE HAVE ENDED OR UNTIL ALL PIXELS ARE FILLED*/         
                       n=128;                                            /*8TH BIT FROM BINARY TO DECIMAL IS MULTIPLYED BY 128*/
                        while (n!=0  &&  temp_width>0 && ch!=EOF ){      /*UNTIL THE LINE AND FILE IS ENDED AND THE BYTE IS FILLED*/
                             temp=ch/n;
                             printf("%3d",temp);
                             if (temp!=0 && temp!=1){
                                printf ("input error");
                                return 1;
                            }
                             ch = ch -temp*n;
                             n/=2;                            /*EACH BIT RELATIVE TO THE PREVIOUS IS MULTIPLYED BY -1 TO THE POWER OF 2 (BINARY->DECIMAL)*/
                             count++;                         /*INCREASE BECAUSE IT SHOULD SHOW THE NEXT PIXEL*/
                             temp_width--;                    /*I UPDATE IT ON EACH CHARACTER SO IT KNOWS HOW MANY CHARACTERS ARE ON EACH LINE*/
                        }
                        while (n!=0){
                            printf("1 ");
                            n/=2;
                        }
                        
                        ch=getchar();
                    }   
                }
            }
       }
       else if (ch2=='5'){                                     /*GREY  BINARY -> GREY TEXT FILE*/   
        	while (count<=pixels && ch!=EOF){ 
            	ch=getchar();
                printf("%3d   ",ch);                           /*PRINTS GREY*/
                count++;
                if ((count-1)%84==0)
                   printf("\n");
             }
        }
        else if (ch2=='6'){                                   /*COLOR BINARY -> COLOR TEXT FILE*/
            red=getchar();
            if (red!=EOF && count<=pixels){
                do{
                    green=getchar();
                    blue=getchar();
                    if (red>max || blue>max || green>max){     /*IT'S ERROR IF A COLOUR IS BIGGER THAN MAX*/
                        printf("input error");
                        return 1;
                    }
                    printf("%3d   %3d   %3d   ", red,green,blue);   /*PRINTS RGB*/
                    red=getchar();                                   
                    count++;
                    if ((count-1)%84==0)
                        printf("\n");
                }while (count<=pixels && red!=EOF);     /*UNTIL THE FILE IS FINISHED OR UNTIL ALL PIXELS ARE FILLED*/
            }
        }
        if (ch2=='3' || ch2=='2' ||  ch2=='1' ){
            ch=space2(ch);                       /*we should be sure that the others characters aren't \n,\t, ....*/
            if (ch!=EOF || count!=pixels){      /*IF THE FILE HAS'T ENDED OR THE PIXELS DOESH'T HAVE COMPLETED,IT'S A ERROR*/
                return -1;
            } 
        }
        else if (ch2=='5' || ch2=='4'){
            if (ch!=EOF || count!=pixels){        /*IF THE FILE HAS'T ENDED OR THE PIXELS DOESH'T HAVE COMPLETED,IT'S A ERROR*/
                return -1;
            }
        }
        else if (ch2=='6'){
            if (red!=EOF || count!=pixels){       /*IF THE FILE HAS'T ENDED OR THE PIXELS DOESH'T HAVE COMPLETED,IT'S A ERROR*/
                return -1;
            }
        }
        return 0;
    }   
    else {
        printf("false ENCODED. ENCODED should be 0 (for normal) or 1 (for bonus).\n");
        return 1;
    }  
}
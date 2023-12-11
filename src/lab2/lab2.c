/*
  EECS461
  Lab 2
  Updated: March 17th, 2014 by Scott Kenyon
           July  4th, 2014 by GPCz
           2017-03-15 RMC
           2018-03    Paul Domanico
           2021-01-12  jfr
           2021-09-02  jfr
           2021-09-17  jfr
           2022-08-12  jfr
           2023-08-18  jfr
*/


 #include "eecs461.h"
 #include "S32K144.h"
 #include "gpio.h"
 #include "qd.h"


 int main(void){
   initEECS461();
   uint16_t counter = 0;
   int32_t total = 0;
   int i;
   float angle;
   int16_t angleInt;
   int section = 4; //Set to case you are testing

   /* Initialize EECS461, QD, GPDO */
   initQD();
   for (i = 0; i < 16; i++) {
     initGPDO(3, i);
   }


   while(1){
     switch(section){
     case 1://Read the counter

       counter = FTM2->CNT & FTM_CNT_COUNT_MASK;
       //4000 counts for 1 revolution

       break;

     case 2://Overflow and Underflow



       counter = FTM2->CNT & FTM_CNT_COUNT_MASK;
       for (i = 0; i < 16; i++) {
           writeGPIO(3, i, (counter >> i) & 0b1);
       }
             //8 revolutions to overflow from the center (a little over)
       break;

     case 3: //updateCounter and Faulty Casting
       total = updateCounter();
       for (i = 0; i < 16; i++) {
           writeGPIO(3, i, ((total >> 8) >> i) & 0b1);
       }


       break;

     case 4: //Angle Calculation
         angle = updateAngle();
         for (i = 0; i < 16; i++) {
             writeGPIO(3, i, ((int)angle >> i) & 0b1);
         }
       break;
     }
   }
 }

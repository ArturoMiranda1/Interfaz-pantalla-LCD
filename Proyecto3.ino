#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int control;
int control1;
int bandera;
int bandera1;
int bandera2;
int bandera3;
int bandera4;
int bandera5;

void setup() {

  lcd.begin(16, 2);  // Inicializar el LCD

  for (int positionCounter = 0; positionCounter < 10; positionCounter++){
      lcd.setCursor(13,0);
      lcd.print("Bienvenid@");
      lcd.scrollDisplayLeft();
      delay(400);
  } 
  delay(300); 
  lcd.clear();
  delay(1000);
  int boton;
  boton = analogRead(0);
  Screen2(); 
}

void loop() {
  
  int boton;
  boton = analogRead(0);
  while ((boton < 410 && boton > 408) && (bandera != 1) && (bandera5 != 1)){
    ScreenSi();
    control = 1;
    control1 = 0;
    boton = analogRead(0);
  }

  while ((boton < 1) && (bandera !=1) && (bandera5 != 1)){
    ScreenNo();
    control = 0;
    control1 = 1;
    boton = analogRead(0);
  }

  while (boton < 639 && (boton > 637) && (bandera4 != 1)){
    if (control == 1){
      Humedad();
      bandera = 1;
      boton = analogRead(0);
    }
    else if (control1 == 1){
      Salida();
    }
    else{
      boton = analogRead(0);
    }  
  }
  
  while ((boton < 410 && boton > 408) && (bandera = 1) && (bandera5 != 1) ){
    Bajo();
    bandera = 1;
    bandera2 = 1;
    bandera3 = 0;
    bandera4 = 1;
    boton = analogRead(0);
  } 

  while ((boton < 1) && (bandera = 1) && (bandera5 != 1)){
    Alto();
    bandera1 = 1;
    bandera2 = 0;
    bandera3 = 1;
    bandera4 = 1;
    boton = analogRead(0);
  }

  while ((boton < 639 && boton > 637) && (bandera4 = 1)){
    if (bandera2 == 1){
      FlujoB();
      bandera1 = 0;
      bandera = 0;
      control = 0;
      control1 = 0;
      bandera5 = 1;
      boton = analogRead(0);
    }
    else if (bandera3 == 1){
      FlujoA();
      bandera1 = 0;
      bandera = 0;
      control = 0;
      control1 = 0;
      bandera5 = 1;
      boton = analogRead(0);
    }
    else{
      boton = analogRead(0);
    }  
  }

}
void Screen2(){
  lcd.setCursor(1,0);
  lcd.print("Desea Iniciar?");
  lcd.setCursor(1,1);
  lcd.print("Si");   
  lcd.setCursor(6,1);
  lcd.print("No");
}

int ScreenNo(){
  lcd.setCursor(6,1);
  lcd.print(" "); 
  lcd.setCursor(7,1);
  lcd.print(" "); 
  lcd.setCursor(6,1);
  lcd.print("N"); 
  lcd.setCursor(7,1);
  lcd.print("o"); 
}

void ScreenSi(){
  lcd.setCursor(1,1);
  lcd.print(" "); 
  lcd.setCursor(2,1);
  lcd.print(" "); 
  lcd.setCursor(1,1);
  lcd.print("S"); 
  lcd.setCursor(2,1);
  lcd.print("i");
}

void Humedad(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("% De Humedad?");
  lcd.setCursor(3,1);
  lcd.print("Bajo");   
  lcd.setCursor(9,1);
  lcd.print("Alto");
}

void Bajo(){
  lcd.setCursor(3,1);
  lcd.print(" "); 
  lcd.setCursor(4,1);
  lcd.print(" "); 
  lcd.setCursor(5,1);
  lcd.print(" "); 
  lcd.setCursor(6,1);
  lcd.print(" "); 
  lcd.setCursor(3,1);
  lcd.print("B"); 
  lcd.setCursor(4,1);
  lcd.print("a"); 
  lcd.setCursor(5,1);
  lcd.print("j"); 
  lcd.setCursor(6,1);
  lcd.print("o"); 
}

void Alto(){
  lcd.setCursor(9,1);
  lcd.print(" "); 
  lcd.setCursor(10,1);
  lcd.print(" "); 
  lcd.setCursor(11,1);
  lcd.print(" "); 
  lcd.setCursor(12,1);
  lcd.print(" "); 
  lcd.setCursor(9,1);
  lcd.print("A"); 
  lcd.setCursor(10,1);
  lcd.print("l"); 
  lcd.setCursor(11,1);
  lcd.print("t"); 
  lcd.setCursor(12,1);
  lcd.print("o"); 
}

void FlujoB(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Flujo Bajo");
}

void FlujoA(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Flujo Alto");
}

void Salida(){
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Adios");
  exit(0);
}
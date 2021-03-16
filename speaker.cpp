#include <LiquidCrystal.h>
LiquidCrystal lcd(7);  //Pins où on va connecter l'écran (RS, E, D4, D5, D6, D7)

void setup() {
  lcd.begin(16, 2);   //on initialise l'écran
}

void loop() {
  //Message 1
  lcd.setCursor(0, 0);          //Place le pointeur sur la colonne 0, ligne 0
  lcd.write("essai 1:");      //écrit le message 
  lcd.setCursor(0, 1);         //Place le pointeur sur la colonne 0, ligne 1
  lcd.write("bonjour!");    //écrit le message
  delay(3500);                 //attente 3.5 secondes
  lcd.clear();                 //efface le message affiché

  //Message 2
  lcd.setCursor(3, 0);          //Place le pointeur sur la colonne 3, ligne 0
  lcd.write("essai 2:");       //écrit le message
  lcd.setCursor(2, 1);          //Place le pointeur sur la colonne 2, ligne 1
  lcd.write("Arduino et LCD");   //écrit le message
  delay(3500);                  //attente 3.5 secondes
  lcd.clear();                  //efface le message affiché
}

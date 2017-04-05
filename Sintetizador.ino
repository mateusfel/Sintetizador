#include <LiquidCrystal.h>

//Primeira oitava
#define C1 65
#define D1 73
#define E1 82
#define F1 87
#define G1 97
#define A1 110
#define B1 123

//Segunda oitava
#define C2 130
#define D2 146
#define E2 164
#define F2 174
#define G2 195
#define A2 220
#define B2 246

//Terceira oitava
#define C3 261
#define D3 293
#define E3 329
#define F3 349
#define G3 391
#define A3 440
#define B3 493

//Quarta oitava
#define C4 523
#define D4 587
#define E4 659
#define F4 698
#define G4 783
#define A4 880
#define B4 987

//Quinta oitava
#define C5 1046
#define D5 1174
#define Ds5 1244
#define E5 1318
#define F5 1396
#define G5 1567
#define A5 1760
#define B5 1975

//Sexta oitava
#define C6 2093
#define D6 2349
#define E6 2637
#define F6 2793
#define G6 3135
#define A6 3520
#define B6 3951

#define pino 10

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempo = 500; //em milisegundos (o tempo vale 1/4)

const int semibreve = 4*tempo;
const int minima = 2*tempo;
const int seminima = tempo;
const int colcheia = tempo/2;
const int semicolcheia = tempo/4;


const int notas[][2] = {{C5, seminima},
                           {C6, colcheia},
                           {B5, colcheia},
                           {G5, seminima},
                           {00, seminima},
                           
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {G5, seminima},
                           {00, seminima},
          
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {E5, seminima},
                           {00, seminima},

                           {D5, seminima},
                           {E5, colcheia},
                           {F5, colcheia},
                           {G5, seminima},
                           {00, seminima},
//////////////////////////////////////////////2
                           {C5, seminima},
                           {C6, colcheia},
                           {B5, colcheia},
                           {G5, seminima},
                           {00, seminima},
                           
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {G5, seminima},
                           {00, seminima},
          
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {E5, seminima},
                           {D5, colcheia},
                           {E5, colcheia},

                           {C5, seminima},
                           {00, seminima},
                           {00, minima},

                           {C5, seminima},
                           {C6, colcheia},
                           {B5, colcheia},
                           {G5, seminima},
                           {00, seminima},
/////////////////////////////////////////////3                           
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {G5, seminima},
                           {00, seminima},
          
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {E5, seminima},
                           {00, seminima},

                           {D5, seminima},
                           {E5, colcheia},
                           {F5, colcheia},
                           {G5, seminima},
                           {00, seminima},

                           {C5, seminima},
                           {C6, colcheia},
                           {B5, colcheia},
                           {G5, seminima},
                           {00, seminima},
                           
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {G5, seminima},
                           {00, seminima},
/////////////////////////////////////////////4
                           {A5, seminima},
                           {G5, colcheia},
                           {F5, colcheia},
                           {E5, seminima},
                           {D5, colcheia},
                           {E5, colcheia},

                           {C5, seminima},
                           {00, seminima},
                           {00, minima},

                           {G5, seminima},
                           {00, colcheia},
                           {E5, colcheia},
                           {C5, seminima},
                           {E5, seminima},

                           {A5, colcheia},
                           {G5, colcheia},
                           {A5, seminima},
                           {G5, seminima},
                           {00, seminima},

                           {A5, colcheia},
                           {G5, colcheia},
                           {A5, seminima},
                           {G5, seminima},
                           {00, seminima},
////////////////////////////////////////////5
                           {F5, seminima},
                           {Ds5, seminima},
                           {E5, seminima},
                           {00, seminima},

                           {G5, seminima},
                           {00, colcheia},
                           {E5, colcheia},
                           {G5, semicolcheia},
                           {00, semicolcheia},
                           {00, colcheia},
                           {E5, semicolcheia},
                           {00, semicolcheia},
                           {00, colcheia},

                           {A5, colcheia},
                           {G5, colcheia},
                           {A5, seminima},
                           {G5, seminima},
                           {00, seminima},

                           {A5, colcheia},
                           {G5, colcheia},
                           {A5, seminima},
                           {G5, seminima},
                           {C5, semicolcheia},
                           {00, semicolcheia},
                           {00, colcheia},

                           {-1, -1} //indica o fim da música
                           };

void setup() {
  // put your setup code here, to run once:
  pinMode(pino, OUTPUT);
  Serial.begin(250000);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sintetizador");
  lcd.setCursor(0, 1);
  lcd.print("F=");
}

void loop() {
  // put your main code here, to run repeatedly:
  static int i = 0;
  while(notas[i][0] != -1){
    Serial.println(notas[i][0]);
    lcd.setCursor(2, 1);
    lcd.print(notas[i][0]);
    lcd.print("Hz    ");
    tone(pino, notas[i][0], notas[i][1]);
    delay(notas[i][1]);
    noTone(pino);
    i++;
  }
  noTone(pino);
  i = 0;
}

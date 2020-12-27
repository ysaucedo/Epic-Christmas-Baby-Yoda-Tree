const int HI = HIGH;
const int LO = LOW;

const int salida1 = 3;
const int salida2 = 5;
const int salida3 = 6;

const int salida4 = 9;
const int salida5 = 10;
const int salida6 = 11;

const int salida7 = 8;
const int salida8 = 12;
const int salida9 = 13;

const int cascada = 7;
const int indirecta1 = 0;
const int indirecta2 = 1;
const int indirecta3 = A0;
const int indirecta4 = 2;

const int ciclos = 100;
const int ciclosApagado = 10;

const int ciclosApagadoDim = 50;
int cualCiclosApagadoVoyDim = 0;

int alternando = 1;
int cualCicloVoy = 1;
int cualCiclosApagadoVoy = 0;

int val = 0;
int aumentando = 1;

int repeticiones = 1;

int contadorCascada = 1;

int contadorIndirecta = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(salida1, OUTPUT);
  pinMode(salida2, OUTPUT);
  pinMode(salida3, OUTPUT);
  pinMode(salida4, OUTPUT);
  pinMode(salida5, OUTPUT);
  pinMode(salida6, OUTPUT);
  pinMode(salida7, OUTPUT);
  pinMode(salida8, OUTPUT);
  pinMode(salida9, OUTPUT);
  pinMode(cascada, OUTPUT);
  pinMode(indirecta1, OUTPUT);
  pinMode(indirecta2, OUTPUT);
  pinMode(indirecta3, OUTPUT);
  pinMode(indirecta4, OUTPUT);

  analogWrite(salida1, 0);
  analogWrite(salida2, 0);
  analogWrite(salida3, 0);
  analogWrite(salida4, 0);
  analogWrite(salida5, 0);
  analogWrite(salida6, 0);
  digitalWrite(salida7, LO);
  digitalWrite(salida8, LO);
  digitalWrite(salida9, LO);
  digitalWrite(cascada, LO);
  digitalWrite(indirecta1, LO);
  digitalWrite(indirecta2, LO);
  digitalWrite(indirecta3, LO);
  digitalWrite(indirecta4, LO);

}

void loop() {

  contadorCascada = contadorCascada + 1;
  if (contadorCascada < 70){
    digitalWrite(cascada, LOW);
  }
  if (contadorCascada > 70 && contadorCascada < 85){
    digitalWrite(cascada, HIGH);
  }
  if (contadorCascada > 85 && contadorCascada < 100){
    digitalWrite(cascada, LOW);
  }
  if (contadorCascada > 100 && contadorCascada < 115){
    digitalWrite(cascada, HIGH);
  }
  if (contadorCascada == 115){
    contadorCascada = 1;
  }

  //Programación indirecta verde
  contadorIndirecta = contadorIndirecta + 1;
  if (contadorIndirecta < 70) {
    digitalWrite(indirecta1, HIGH);
    digitalWrite(indirecta2, HIGH);
    digitalWrite(indirecta3, HIGH);
    digitalWrite(indirecta4, HIGH);
  }
  if (contadorIndirecta > 70 && contadorIndirecta < 90){
    digitalWrite(indirecta1, LOW);
  }
  if (contadorIndirecta > 90 && contadorIndirecta < 100){
    digitalWrite(indirecta1, HIGH);
    digitalWrite(indirecta2, LOW);
  }  
  if (contadorIndirecta > 100 && contadorIndirecta < 120){
    digitalWrite(indirecta2, HIGH);
    digitalWrite(indirecta3, LOW);
  }  
  if (contadorIndirecta > 120 && contadorIndirecta < 140){
    digitalWrite(indirecta3, HIGH);
    digitalWrite(indirecta4, LOW);
  }  
  if (contadorIndirecta == 140){
    contadorIndirecta = 1;
  }


  if (aumentando == 1 && val < 200){
    val = val + 1;
  }
  if (aumentando == 0 && val > 0){
    val = val -1;
  }
  if (val == 200){
    aumentando = 0;
  }
  if (val == 0){
    aumentando = 2;
  }
  if (aumentando == 2) {
    if (cualCiclosApagadoVoyDim < ciclosApagadoDim){
      cualCiclosApagadoVoyDim = cualCiclosApagadoVoyDim + 1;
    }else{
      if (repeticiones == 3){
        flashea();
        repeticiones = 0;
      }
      cualCiclosApagadoVoyDim = 0;
      aumentando = 1;
      repeticiones = repeticiones + 1;
    }

  }
  
  analogWrite(salida1, val);
  analogWrite(salida2, val);
  analogWrite(salida3, val);
  analogWrite(salida4, val);
  analogWrite(salida5, val);
  analogWrite(salida6, val);
  
  delay(15);

  if (alternando == 1) {
    if (cualCicloVoy <  ciclos){
      digitalWrite(salida7, HI);
      digitalWrite(salida8, LO);
      digitalWrite(salida9, LO);
      cualCicloVoy = cualCicloVoy + 1;
    } else {
      alternando = 2;
      cualCicloVoy = 1;
    }
  }

  if (alternando == 2) {
    if (cualCicloVoy <  ciclos){
      digitalWrite(salida7, LO);
      digitalWrite(salida8, HI);
      digitalWrite(salida9, LO);
      cualCicloVoy = cualCicloVoy + 1;
    } else {
      //me voy a negativo para que el siguiente ciclo dure más
      alternando = 3;
      cualCicloVoy = -200;
    }
  }
  
  if (alternando == 3) {
    if (cualCicloVoy <  ciclos){
      digitalWrite(salida7, LO);
      digitalWrite(salida8, LO);
      digitalWrite(salida9, HI);
      cualCicloVoy = cualCicloVoy + 1;
    }else{
      digitalWrite(salida7, LO);
      digitalWrite(salida8, LO);
      digitalWrite(salida9, LO);
      alternando = 4;
      cualCicloVoy = 1;
    }
  }
  if (alternando == 4) {
    if (cualCiclosApagadoVoy < ciclosApagado) {
      cualCiclosApagadoVoy = cualCiclosApagadoVoy + 1;
    }else {
      cualCiclosApagadoVoy = 0;
      alternando = 1;
    }
  }
  
  //secuencia1();
}

void flashea(){
  digitalWrite(indirecta1, HIGH);
  digitalWrite(indirecta2, HIGH);
  digitalWrite(indirecta3, HIGH);
  digitalWrite(indirecta4, HIGH);

  digitalWrite(salida7, LO);
  digitalWrite(salida8, LO);
  digitalWrite(salida9, HI);
  digitalWrite(cascada, LOW);
  
  int repeticiones = 8;
  int enCualVoy = 1;
  while (enCualVoy < repeticiones){
    for (int espada=1;espada<=6;espada++){
      analogWrite(salida1, 0);
      analogWrite(salida2, 0);
      analogWrite(salida3, 0);
      analogWrite(salida4, 0);
      analogWrite(salida5, 0);
      analogWrite(salida6, 0);
      if (espada == 1){
        analogWrite(salida1, 200);
      }else if (espada == 2){
        analogWrite(salida1, 0);
        analogWrite(salida2, 200);
      }else if (espada == 3){
        analogWrite(salida2, 0);
        analogWrite(salida3, 200);
      }else if (espada == 4){
        analogWrite(salida3, 0);
        analogWrite(salida4, 200);
      }else if (espada == 5){
        analogWrite(salida4, 0);
        analogWrite(salida5, 200);
      }else if (espada == 6){
        analogWrite(salida5, 0);
        analogWrite(salida6, 200);
      }
      //Flashea luz indirecta
      if (espada%2 == 0) {
        digitalWrite(indirecta1, HIGH);
        digitalWrite(indirecta2, HIGH);
        digitalWrite(indirecta3, HIGH);
        digitalWrite(indirecta4, HIGH);
      }else{
        digitalWrite(indirecta1, LOW);
        digitalWrite(indirecta2, LOW);
        digitalWrite(indirecta3, LOW);
        digitalWrite(indirecta4, LOW);      
      }
        
      delay(100);
    }
    enCualVoy = enCualVoy + 1;
  }
  digitalWrite(indirecta1, HIGH);
  digitalWrite(indirecta2, HIGH);
  digitalWrite(indirecta3, HIGH);
  digitalWrite(indirecta4, HIGH); 
}

void secuencia1(){
  digitalWrite(salida1, HI);
  digitalWrite(salida2, HI);
  delay(750);
  digitalWrite(salida3, HI);
  digitalWrite(salida4, HI);
  delay(350);
  digitalWrite(salida1, LO);
  digitalWrite(salida2, LO);  
  delay(750);
  digitalWrite(salida5, HI);
  digitalWrite(salida6, HI);
  delay(350);  
  digitalWrite(salida3, LO);
  digitalWrite(salida4, LO);  
  delay(350);
  digitalWrite(salida5, LO);
  digitalWrite(salida6, LO);   
  digitalWrite(salida7, HI);
  delay(500);
  digitalWrite(salida7, LO);
  delay(350);  
  digitalWrite(salida7, HI);
  delay(350);    
  digitalWrite(salida7, LO);
  delay(350);    
  digitalWrite(salida7, HI);
  digitalWrite(salida1, HI);
  digitalWrite(salida2, HI);
  delay(350);    
  digitalWrite(salida7, LO);
}

void prendeUnaEnUna(){
  prende(salida1);
  prende(salida2);
  prende(salida3);
  prende(salida4);
  prende(salida5);
  prende(salida6);
  prende(salida7);
}

void prende(int salida) {
  
  digitalWrite(salida, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(2000);               // wait for a second
  digitalWrite(salida, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}

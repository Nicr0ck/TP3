#define Boton 2
#define PotRojo A0
#define PotVerde A1
#define PotAzul A2
#define LEDR 9
#define LEDA 10
#define LEDV 11

int estadoBoton = 0;
bool configuracionCompletada = false;
int diezsegundos = 10000;
void setup() {
  pinMode(Boton, INPUT);
  pinMode(PotRojo, INPUT);
  pinMode(PotVerde, INPUT);
  pinMode(PotAzul, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDV, OUTPUT);
  pinMode(LEDA, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  while (digitalRead(Boton) == HIGH) {
  }
  Serial.println("Tiene 10 s para configurar el color del led....");

  delay(diezsegundos);
  int valorRojo = analogRead(PotRojo) / 4;
  int valorVerde = analogRead(PotVerde) / 4;
  int valorAzul = analogRead(PotAzul) / 4;

  Serial.print("El led esta usando esta configuración de colores RGB: (");
  Serial.print(valorRojo);
  Serial.print("; ");
  Serial.print(valorVerde);
  Serial.print("; ");
  Serial.print(valorAzul);
  Serial.println(")");
  analogWrite(LEDR, valorRojo);
  analogWrite(LEDV, valorVerde);
  analogWrite(LEDA, valorAzul);



  while (digitalRead(Boton) == LOW) {

  }
  configuracionCompletada = false;
}

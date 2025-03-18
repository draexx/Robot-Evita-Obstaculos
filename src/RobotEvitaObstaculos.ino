// Definición de pines
const int trigPin = 2;      // Pin Trig del HC-SR04
const int echoPin = 3;      // Pin Echo del HC-SR04
const int enA = 9;          // Pin PWM para controlar la velocidad del Motor A
const int in1 = 4;          // Control de dirección del Motor A
const int in2 = 5;          // Control de dirección del Motor A
const int enB = 10;         // Pin PWM para controlar la velocidad del Motor B
const int in3 = 6;          // Control de dirección del Motor B
const int in4 = 7;          // Control de dirección del Motor B

// Velocidades de los motores (0-255)
const int velocidadAvance = 150;  // Velocidad normal al avanzar
const int velocidadLenta = 80;    // Velocidad reducida al acercarse a un obstáculo
const int velocidadGiro = 100;    // Velocidad al girar

// Distancias de detección
const int distanciaGiro = 10;     // Distancia a la que el robot debe girar (en cm)
const int distanciaAlerta = 20;   // Distancia a la que el robot reduce la velocidad (en cm)

void setup() {
  // Inicialización de pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600);  // Iniciar comunicación serial para depuración
  randomSeed(analogRead(0));  // Inicializar la semilla aleatoria
}

void loop() {
  // Medir la distancia
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convertir a centímetros

  Serial.print("Distancia: ");
  Serial.println(distance);

  // Lógica de movimiento
  if (distance < distanciaGiro) {
    // Obstáculo detectado a menos de 20 cm, girar aleatoriamente
    evitarObstaculo();
  } else if (distance < distanciaAlerta) {
    // Obstáculo detectado a menos de 30 cm, reducir velocidad
    avanzar(velocidadLenta);
  } else {
    // No hay obstáculo, avanzar a velocidad normal
    avanzar(velocidadAvance);
  }
}

void avanzar(int velocidad) {
  // Mover ambos motores hacia adelante con velocidad controlada
  analogWrite(enA, velocidad);  // Velocidad Motor A
  analogWrite(enB, velocidad);  // Velocidad Motor B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void evitarObstaculo() {
  // Retroceder ligeramente antes de girar
  retroceder();
  delay(500);  // Tiempo para retroceder

  // Girar aleatoriamente a la izquierda o derecha
  int direccionGiro = random(2);  // Generar 0 o 1 aleatoriamente
  if (direccionGiro == 0) {
    girarIzquierda();  // Girar a la izquierda
  } else {
    girarDerecha();    // Girar a la derecha
  }
}

void retroceder() {
  // Mover ambos motores hacia atrás
  analogWrite(enA, velocidadGiro);  // Velocidad Motor A
  analogWrite(enB, velocidadGiro);  // Velocidad Motor B
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void girarDerecha() {
  // Girar a la derecha: Motor A avanza, Motor B retrocede
  analogWrite(enA, velocidadGiro);  // Velocidad Motor A
  analogWrite(enB, velocidadGiro);  // Velocidad Motor B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(400);  // Tiempo de giro, ajustar según sea necesario
}

void girarIzquierda() {
  // Girar a la izquierda: Motor A retrocede, Motor B avanza
  analogWrite(enA, velocidadGiro);  // Velocidad Motor A
  analogWrite(enB, velocidadGiro);  // Velocidad Motor B
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(400);  // Tiempo de giro, ajustar según sea necesario
}
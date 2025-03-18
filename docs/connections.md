# Conexiones del Proyecto

Este documento describe las conexiones necesarias para montar el robot que evita obstáculos utilizando un sensor de ultrasonidos HC-SR04 y un puente H L298N.

---

## Componentes Requeridos
1. **Microcontrolador:** Arduino Uno o similar.
2. **Sensor de Ultrasonidos:** HC-SR04.
3. **Puente H:** L298N.
4. **Motores DC:** 2 motores con reductora (motoreductores).
5. **Batería:** Pack de baterías o fuente de alimentación (7-12V).
6. **Cables y Conectores:** Para realizar las conexiones.

---

## Diagrama de Conexiones

![Diagrama de Conexiones](diagrama_conexiones.png)

---

## Conexiones Detalladas

### 1. Sensor HC-SR04
| Pin HC-SR04 | Pin Arduino |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| Trig        | D2          |
| Echo        | D3          |

### 2. Puente H L298N
| Pin L298N   | Pin Arduino | Descripción                     |
|-------------|-------------|---------------------------------|
| VCC         | 5V          | Alimentación lógica del L298N   |
| GND         | GND         | Tierra común                   |
| IN1         | D4          | Control de dirección Motor A    |
| IN2         | D5          | Control de dirección Motor A    |
| IN3         | D6          | Control de dirección Motor B    |
| IN4         | D7          | Control de dirección Motor B    |
| ENA         | D9          | Control de velocidad Motor A (PWM) |
| ENB         | D10         | Control de velocidad Motor B (PWM) |
| OUT1        | Motor A (+)  | Terminal positivo del Motor A   |
| OUT2        | Motor A (-)  | Terminal negativo del Motor A   |
| OUT3        | Motor B (+)  | Terminal positivo del Motor B   |
| OUT4        | Motor B (-)  | Terminal negativo del Motor B   |
| 12V         | Batería (+)  | Alimentación de los motores (7-12V) |
| GND         | Batería (-)  | Tierra de la batería            |

### 3. Alimentación
- Conecta el positivo de la batería al pin `12V` del L298N.
- Conecta el negativo de la batería al pin `GND` del L298N y al `GND` del Arduino.

---

## Notas Adicionales
1. **Polaridad de los Motores:** Asegúrate de conectar los terminales de los motores correctamente. Si el motor gira en la dirección equivocada, intercambia los cables `OUT1` y `OUT2` (para el Motor A) o `OUT3` y `OUT4` (para el Motor B).
2. **PWM:** Los pines `ENA` y `ENB` controlan la velocidad de los motores mediante PWM. Asegúrate de usar pines PWM en el Arduino (D9 y D10).
3. **Batería:** Usa una batería con suficiente capacidad para alimentar los motores y el Arduino. Un pack de baterías de 9V o 12V es recomendable.

---

## Diagrama de Conexiones Visual

Si no tienes una imagen del diagrama, puedes crear una usando herramientas como [Fritzing](https://fritzing.org/) o [Tinkercad](https://www.tinkercad.com/). Guarda la imagen en la carpeta `docs/` como `diagrama_conexiones.png`.

---

¡Con estas conexiones, tu robot estará listo para evitar obstáculos! 🚀🤖
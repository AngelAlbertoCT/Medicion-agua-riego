# Sistema de Riego Automatizado con IoT

Este proyecto implementa un sistema de riego automatizado utilizando Internet de las Cosas (IoT) para medir la humedad del suelo en las plantas y la cantidad de agua en los depósitos. El objetivo es optimizar el riego de las plantas para garantizar un crecimiento saludable, evitando el desperdicio de agua.

## Componentes del Proyecto

- **Sensor de Humedad del Suelo:** Mide la humedad en la tierra donde están plantadas las flores o cultivos.
- **Sensor de Ultrasonidos:** Mide el nivel de agua en los depósitos, proporcionando información sobre la disponibilidad de agua para el riego.
- **Microcontrolador ESP8266:** Recopila datos de los sensores y los envía a un servidor a través de una conexión WiFi.
- **Servidor Web:** Recibe los datos del ESP8266 y procesa las peticiones de control del sistema.
- **Actuadores (LEDs):** Indican visualmente el estado del sistema de riego. Se pueden cambiar los actuadores según las necesidades de cada persona o proyecto

## Funcionamiento del Proyecto

1. **Medición de la Humedad del Suelo:** El sensor de humedad del suelo mide la humedad en la tierra. Si es baja, indica que las plantas necesitan ser regadas.
2. **Medición del Nivel de Agua en los Depósitos:** El sensor de ultrasonidos mide el nivel de agua en los depósitos. Si hay suficiente agua, el sistema está listo para regar las plantas.
3. **Control del Riego:** Si la humedad del suelo es baja y hay suficiente agua en los depósitos, el sistema activa el riego mediante el encendido de un LED indicador. Una vez que la humedad del suelo alcanza un nivel adecuado, el riego se detiene y el LED se apaga.
4. **Comunicación con el Servidor:** Los datos de humedad del suelo y nivel de agua se envían al servidor a través de una conexión WiFi y HTTP.
5. **Visualización y Control Remoto:** El servidor web permite visualizar el estado del sistema y controlar manualmente el riego desde cualquier dispositivo con conexión a Internet.

## Beneficios del Proyecto

- **Ahorro de Agua:** El riego se activa solo cuando es necesario, reduciendo el desperdicio de agua.
- **Optimización del Crecimiento de las Plantas:** Las plantas reciben la cantidad adecuada de agua en el momento adecuado, promoviendo un crecimiento saludable.
- **Automatización y Comodidad:** El sistema elimina la necesidad de supervisión manual constante, proporcionando una solución automatizada y conveniente para el riego de plantas.

Con este proyecto, se demuestra cómo la tecnología IoT puede mejorar la eficiencia y sostenibilidad en el cuidado de las plantas, ofreciendo un enfoque inteligente y automatizado para el riego.

---

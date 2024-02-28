#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "Vivo-Internet-F653";
const char* password = "9BA8F7A7";
WiFiUDP udp;

void setup() {
  Serial.begin(115200);

  // Conectar à rede Wi-Fi
  Serial.printf("Conectando a %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado");
  
  // Começar a escutar na porta especificada
  udp.begin(44404);
  Serial.printf("Escutando na porta UDP %d\n", 44404);
}

void loop() {
  // Se houver dados disponíveis para leitura
  int packetSize = udp.parsePacket();
  if (packetSize) {
    // Lendo o pacote
    char packetBuffer[255];
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    Serial.printf("Mensagem recebida: %s\n", packetBuffer);
  }
  delay(10);
}

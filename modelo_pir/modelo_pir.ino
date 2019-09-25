int pin_pir = 2;
int tempo_sem_movimemento_segundo;
int tempo_sem_movimemento_minuto;
bool ar_ligado;
int val = 0;

void setup() {
    pinMode(pin_pir, INPUT);
    Serial.begin(9600);
}
void loop() {
    val = digitalRead(pin_pir);
    if (val == HIGH) { //Movimento detectado 
        if (ar_ligado == false) {
            //ligar arcondicionado
            Serial.println("Ligando arcondicionado");
            ar_ligado = true;
        }
        tempo_sem_movimemento_segundo = 0;
        tempo_sem_movimemento_minuto = 0;

    } else { //Sem movimento
        tempo_sem_movimemento_segundo++;
    }

    if (tempo_sem_movimemento_segundo == 60) {
        tempo_sem_movimemento_minuto++;
        tempo_sem_movimemento_segundo = 0;
    }

    //if(tempo_sem_movimemento_minuto == 30){
    if (tempo_sem_movimemento_segundo == 5) {
        //deligar ar-condicionado
        if (ar_ligado == true) {
            //ligar arcondicionado

            Serial.println("Desligando Arcondicionado");

            ar_ligado = false;
        }

        tempo_sem_movimemento_minuto++;
        tempo_sem_movimemento_segundo = 0;
    }
    Serial.println(tempo_sem_movimemento_segundo);
    if (ar_ligado == true) {

        Serial.println("Ligado");
    } else {
        Serial.println("Desligado");
    }

    delay(1000);

}

//Komentari ne uticu na velicinu koda na arduinu, ne brini, ovde sam stavio bukv sve da bi ukontao sta radi sta
//Duzina imena isto ne utice na memoriju zauzetu tkd ostavi da mogu da razumem sta se desava kada ti pises
//Za pinove UVEK koristi const jer trosi programsku memoriju umesto RAM-a, koji nam je holy grail jer ga ima samo 2kb
//Ako u kom slucaju zatreba programskog mesta, sto verovatno hoce, izbrisacemo sve sa serial bibliotekom jer zauzima oko 1.5kb programskog prostora(od 32kb)
//Stagod mislis da je bitno da znam, dodaj u komentare
const int stepZ = 4;   // Pin za stepovanje
const int dirZ = 7;    // Pin za smer, napred nazad i to
const int stepA = 12;
const int dirA = 13;
const int enablePin = 8; // Ovo samo jumpujemo

void setup() {
  Serial.begin(9600);
  
  //Outputiranje, ovaj deo ne diraj jer logicno, svaki pin mora biti output, osim ako menjas koji drajver hoces gde, koristim Z i A jer mi samo ti rade trenutno na mom cnc shieldu
  pinMode(stepZ, OUTPUT);
  pinMode(dirZ, OUTPUT);
  pinMode(stepA, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  // Ovo pali ceo cnc shield, ne diraj, jer ces se posle pitati sto ne radi
  digitalWrite(enablePin, LOW); 
}

void loop() {
  Serial.println("Radi");
  Move(1, 2000); //Prva stvar je smer, 1 znaci da je high i ide napred, 0 je low i ide unazad, ne znam da li ce nam biti korisno ali bolje nego da pravimo dve funkcije
  
  delay(1000); // Proizvoljno, ovo ostavljam samo zato sto ne zelimo tokom testiranja da nam radi svo vreme jer moze da pregori motor, to ne zelimo jer onda sve ode u k
}

void Move(byte smer, unsigned long durationMs) {
  digitalWrite(dirZ, smer); 
  digitalWrite(dirA, smer);
  
  for(int i=0; i<durationMs; i++){
    digitalWrite(stepZ, HIGH);
    digitalWrite(stepA, HIGH);
    
    delayMicroseconds(1000); // Ako nam u bilo kom slucaju treba da kontrolisemo brzinu, ovo cemo da menjamo
    
    digitalWrite(stepZ, LOW);
    digitalWrite(stepA, LOW);
    
    delayMicroseconds(1000);
  }
}
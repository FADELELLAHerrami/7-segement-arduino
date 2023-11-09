// Broches pour chaque segment (a, b, c, d, e, f, g, dp)
const int segments[] = {0,1,2,3,4,5,6};

void setup() {
  for (int i = 0; i <= 6; i++) {
    pinMode(segments[i], OUTPUT);
  }
}

void loop() {
  // Afficher le chiffre 0
  for(int i=0 ; i<=9;i++){
    displayDigit(i);
    delay(1000); // Attendre 1 seconde    
  }
  
}

void displayDigit(int digit) {
  // Tableau de segments pour les chiffres 0-9 (inversé pour un afficheur à anode commune)
  byte digitSegments[10] = {
    B0111111,  // 0
    B0110000,  // 1
    B1011011,  // 2
    B1001111,  // 3
    B1100110,  // 4
    B1101101,  // 5
    B1111101,  // 6
    B0000111,  // 7
    B1111111,  // 8
    B1101111,  // 9
    
  };

  for (int i = 0; i < 8; i++) {
    digitalWrite(segments[i], !bitRead(digitSegments[digit], i)); // Inverser la valeur (LOW pour activer les segments)
  }
}

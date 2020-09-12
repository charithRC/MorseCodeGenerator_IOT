 const char letters[36] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

 const String morse[26] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
"-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};
const char dash = '-';


char text[20]={'p','r','o','g','r','a','m'};
const int led = 4;
const int buzzer = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  digitalWrite(led,LOW);  //to avoid run time errors
  digitalWrite(buzzer,HIGH);

  for(int i=0; i<strlen(text) ;i++){
    for(int j=0;j<strlen(letters);j++){
      if(text[i] == letters[j]){
         Serial.println(morse[j]);
         Serial.println(letters[j]);

         
          String n = morse[j];
          int len = n.length();
         
          char char_array[len+1];
          strcpy(char_array, morse[j].c_str()); 
          for (int k = 0; k < len; k++) {
            Serial.print("char = " );
            Serial.println(char_array[k]);

            //code to glow led and to buzz
            if(char_array[k] == dash){
              digitalWrite(led,HIGH);
              digitalWrite(buzzer,LOW);
              
              delay(400);           //600 micro secs for -
              digitalWrite(led,LOW);
              digitalWrite(buzzer,HIGH); 
            }else{
              digitalWrite(led,HIGH);
              digitalWrite(buzzer,LOW);
             
              delay(200);           //600 micro secs for .
              digitalWrite(led,LOW);
              digitalWrite(buzzer,HIGH); 

              
              }delay(500);//gap between morse letters 

                   }     
          }

       }
    }delay (100000);
    

}

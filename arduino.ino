// make an array to save Sev Seg pin configuration of numbers
String serialBit;

int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9
                                       
//function header
void Num_Write(int);

void setup() 
{ 
    Serial.begin(9600);
  // set pin modes
    for(int i =2;i<9;i++)
    {
        pinMode(i,OUTPUT);
    } 
}

void loop() 
{
  
  
  if(Serial.available()>0)
  {
      serialBit = Serial.readStringUntil('\n');
  }

  if(serialBit=="0")Num_Write(serialBit);
  else if(serialBit=="2")Num_Write(serialBit);
  else if(serialBit=="3")Num_Write(serialBit);
  else if(serialBit=="4")Num_Write(serialBit);
  else Num_Write(serialBit);
  
}

// this functions writes values to the sev seg pins  
void Num_Write(int number) 
{
  int pin= 2;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[number][j]);
   pin++;
  }
}

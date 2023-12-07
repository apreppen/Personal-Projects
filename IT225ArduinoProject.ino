#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int upPin = 10;
int downPin = 9;
int leftPin = 8;
int rightPin = 7;

int goRight = digitalRead(rightPin);
int goLeft = digitalRead(leftPin);
int goUp = digitalRead(upPin);
int goDown = digitalRead(downPin);

int vert = 0;
int horz = 0;

int oldVert = 0;
int oldHorz = 1;


byte player[8] = 
{
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte block[8]
{
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
};

bool blockT = false;

int blockHorz = 0;
int blockVert = 0; 

int bOldHorz = 0;
int bOldVer = 0;

int block2Horz = 0;
int block2Ver = 0;

int block3Horz = 0;
int block3Ver = 0;

int block4Horz = 0;
int block4Ver = 0;

int block5Horz = 0;
int block5Ver = 0;

int block6Horz = 0;
int block6Ver = 0;

//delay before blocks are created, how long they will blink for 
 int blockDelay = 100;
 int blockTimer = 1000;
int blink = 3;

bool isPlaying = false; 
bool didStart = false;
bool first = false;
bool blinking = true;

//tried to make it so if block was on player it would blink between block and player model, for some reason really messed up the game 
void blocks(char block)
{
  delay (blockTimer);
 if (goLeft == HIGH || goRight == HIGH || goUp == HIGH || goDown == HIGH)
  {
    blinking = true;
    blockT = false;
   blockHorz = random(0,15);
blockVert = random(0,2);


  for (int i = 0; i < blink + 1; i++)
{
  delay(500);
lcd.setCursor(blockHorz, blockVert);
lcd.write(byte(1));
delay(500);
lcd.setCursor(blockHorz, blockVert);
lcd.print(" ");
i++;
}
blinking = false;
blockT = true;
lcd.setCursor(blockHorz, blockVert);
lcd.write(byte(1));
  


//block 2
if (blockTimer <= 800)
{

block2Horz = random(0,15);
block2Ver = random(0,2);

if ((blockHorz == block2Horz && blockVert == block2Ver) || (blockHorz == block3Horz && blockVert == block3Ver)|| 
(blockHorz == block4Horz && blockVert == block4Ver) || (blockHorz == block5Horz && blockVert == block5Ver))
{
  block2Horz = random(0,15);
block2Ver = random(0,2);
}
blinking = true;
blockT = false;
// if (block2Horz != horz && block2Ver != vert)
// {
for (int i = 0; i < blink + 1; i++)
{
  delay(500);
lcd.setCursor(block2Horz, block2Ver);
lcd.write(byte(1));
delay(500);
lcd.setCursor(block2Horz, block2Ver);
lcd.print(" ");
i++;
}
blinking = false;
blockT = true;
lcd.setCursor(block2Horz, block2Ver);
lcd.write(byte(1));
}


//block 3 always on last player position


if (blockTimer <= 650)
{
  block3Horz = horz;
  block3Ver = vert; 

if ((block3Horz == blockHorz && block3Ver == blockVert) || (block3Horz == block2Horz && block3Ver == block2Ver)|| 
(block3Horz == block4Horz && block3Ver == block4Ver) || (block3Horz == block5Horz && block3Ver == block5Ver))
{
  block3Horz = random(0,15);
block3Ver = random(0,2);
}

blinking = true; 
blockT = false;

for (int i = 0; i < blink + 1; i++)
{
  delay(500);
lcd.setCursor(block3Horz, block3Ver);
lcd.write(byte(1));
delay(500);
lcd.setCursor(block3Horz, block3Ver);
lcd.write(byte(0));
i++;
}
blinking = false;
blockT = true; 
lcd.setCursor(block3Horz, block3Ver);
lcd.write(byte(1));
}


//block4
if (blockTimer <= 500)
{
  block4Horz = random(0,15);
  block4Ver = vert; 

if ((block4Horz == blockHorz && block4Ver == blockVert) || (block4Horz == block2Horz && block4Ver == block2Ver)|| 
(block4Horz == block3Horz && block4Ver == block3Ver) || (block4Horz == block5Horz && block4Ver == block5Ver))
{
  block4Horz = random(0,15);
block4Ver = random(0,2);
}
blinking = true; 
blockT = false; 

  for (int i = 0; i < blink + 1; i++)
{
  delay(500);
lcd.setCursor(block4Horz, block4Ver);
lcd.write(byte(1));
delay(500);
lcd.setCursor(block4Horz, block4Ver);
lcd.print(" ");
i++;
}
blinking = false;
blockT = true; 
lcd.setCursor(block4Horz, block4Ver);
lcd.write(byte(1));
}


//block 5
if (blockTimer <= 400)
{
  block5Horz = horz;
  block5Ver = random(0,2);

if ((block5Horz == blockHorz && block5Ver == blockVert) || (block5Horz == block2Horz && block5Ver == block2Ver)|| 
(block5Horz == block3Horz && block5Ver == block3Ver) || (block5Horz == block4Horz && block5Ver == block4Ver))
{
  block5Horz = random(0,15);
block5Ver = random(0,2);
}

blinking = true;
blockT = false; 
  for (int i = 0; i < blink + 1; i++)
{
  delay(500);
lcd.setCursor(block5Horz, block5Ver);
lcd.write(byte(1));
delay(500);
lcd.setCursor(block5Horz, block5Ver);
lcd.print(" ");
i++;
}
blinking = false;
blockT = true; 
lcd.setCursor(block5Horz, block5Ver);
lcd.write(byte(1));
}


  }
  else
  {
      lcd.setCursor(blockHorz, blockVert);
    lcd.write(byte(1));
    playerMove();
  }
}















//Try to make it so player can move away from block especially with block 3 being on player
//seems like it works
void blockClear()
{
delay(500);
lcd.setCursor(blockHorz, blockVert);
lcd.print(" ");
lcd.setCursor(block2Horz, block2Ver);
lcd.print(" ");
lcd.setCursor(block3Horz, block3Ver);
lcd.print(" ");
lcd.setCursor(block4Horz, block4Ver);
lcd.print(" ");
lcd.setCursor(block5Horz, block5Ver);
lcd.print(" ");
blockT = false; 
}


void playerMove()
{
 
 

goRight = digitalRead(rightPin);
goLeft = digitalRead(leftPin);
goUp = digitalRead(upPin);
goDown = digitalRead(downPin);

if (goRight == LOW)
{

  lcd.setCursor(oldHorz,oldVert);
  lcd.print(" ");
  if (horz + 1 > 15)
  {
    horz = 0;
  lcd.setCursor(0,vert);
   lcd.write(byte(0));
  }
  else
  {
   horz = horz + 1;
   lcd.setCursor(horz,vert);
   lcd.write(byte(0));
  }
}

 if (goLeft == LOW)
{

  lcd.setCursor(oldHorz,oldVert);
  lcd.print(" ");
  
  if (horz == 0)
  {
    horz = 15;
  lcd.setCursor(15,vert);
   lcd.write(byte(0));
  }

  else
  {
   horz = horz - 1;
   lcd.setCursor(horz,vert);
   lcd.write(byte(0));
  }
}

 if (goUp == LOW)
{

  lcd.setCursor(oldHorz,oldVert);
  lcd.print(" ");
  if (vert == 1)
  {
    vert = 0;
  lcd.setCursor(horz,0);
   lcd.write(byte(0));
  }
  else
  {
   vert = 1;
   lcd.setCursor(horz,vert);
   lcd.write(byte(0));
  }
}

 if (goDown == LOW)
{

  lcd.setCursor(oldHorz,oldVert);
  lcd.print(" ");
  if (vert == 0)
  {
    vert = 1;
  lcd.setCursor(horz,1);
   lcd.write(byte(0));
  }
  else
  {
   vert = 0;
   lcd.setCursor(horz,vert);
   lcd.write(byte(0));
  }
}

oldHorz = horz;
oldVert = vert;
}


void start()
{
  if ( digitalRead(rightPin) == LOW ||  digitalRead(leftPin) == LOW || digitalRead(upPin) == LOW || digitalRead(downPin) == LOW && didStart == false)
  {
    lcd.setCursor(0,0);
  lcd.print("                     ");
  isPlaying = true; 
     didStart = true;




 for (int i = 0; i < 16; i++)
 {
   for(int j = 0; j < 2; j++)
   { 
    delay(50);
     lcd.setCursor(i, j);;
     lcd.write(byte(1));
     lcd.setCursor(bOldHorz, bOldVer);
     lcd.print(" ");
     bOldHorz = i;
     bOldVer = j;
   }
 }

 lcd.setCursor(15, 1);
     lcd.print(" ");

  
 
 for (int i = 0; i < 16; i++)
 {
   for(int j = 0; j < 2; j++)
   { 
    delay(50);
     lcd.setCursor(i, j);;
     lcd.write(byte(0));
     lcd.setCursor(oldHorz, oldVert);
     lcd.print(" ");
     oldHorz = i;
     oldVert = j;
   }
      
 }

 lcd.setCursor(15, 1);
     lcd.print(" ");
  

  }

else
  lcd.setCursor(0,0);
  lcd.write("Press any button");
 
}



void setup() {
  // put your setup code here, to run once:
//initialize LCD for # of rows/columns
lcd.begin(16,2);
lcd.createChar(0, player);
lcd.createChar(1, block);
lcd.setCursor(horz,vert);
lcd.write(byte(0));


pinMode(upPin, INPUT_PULLUP);  
pinMode(downPin, INPUT_PULLUP);  
pinMode(leftPin, INPUT_PULLUP);  
pinMode(rightPin, INPUT_PULLUP);  



}




void loop() {
  // put your main code here, to run repeatedly:
   

start();
//weird issue where can't get player model to be written until player moves 
  while (isPlaying && didStart)
  {
    
  // if (first = false)
  //   {
  //   lcd.setCursor(horz, vert);
  //   lcd.write(byte(0));
  //   first = true;
  //   }
//delay (blockTimer);

if (goLeft == HIGH || goRight == HIGH || goUp == HIGH || goDown == HIGH )
{
  lcd.setCursor(horz, vert);
  lcd.write(byte(0));
  first = false; 
}



blocks(byte(1));

playerMove();



 if(horz == blockHorz && vert == blockVert && blinking == false && blockT == true)
 {

   isPlaying = false; 
   didStart = false;
   first = false;
   blink = 3; 
  blockTimer = 1000;
    horz = 0;
   vert = 0;

   //trying to remove lingering hitboxes: 
   int blockHorz = 100;
int blockVert = 100; 

int block2Horz = 100;
int block2Ver = 100;

int block3Horz = 100;
int block3Ver = 100;

int block4Horz = 100;
int block4Ver = 100;

int block5Horz = 100;
int block5Ver = 100;
 }



else if(horz == block2Horz && vert == block2Ver && blinking == false && blockT == true)
 {

   isPlaying = false; 
   didStart = false;
   first = false;
   blink = 3; 
  blockTimer = 1000;
   

horz = 0;
vert = 0; 
   //trying to remove lingering hitboxes: 
    blockHorz = 100;
 blockVert = 100; 

 block2Horz = 100;
 block2Ver = 100;

 block3Horz = 100;
 block3Ver = 100;

 block4Horz = 100;
 block4Ver = 100;

 block5Horz = 100;
 block5Ver = 100;
 }



else if (horz == block3Horz && vert == block3Ver && blinking == false&& blockT == true)
{
isPlaying = false; 
   didStart = false;
   first = false;
   blink = 3; 
   blockTimer = 1000;


   horz = 0;
vert = 0; 
   //trying to remove lingering hitboxes: 
    blockHorz = 100;
 blockVert = 100; 

 block2Horz = 100;
 block2Ver = 100;

 block3Horz = 100;
 block3Ver = 100;

 block4Horz = 100;
 block4Ver = 100;

 block5Horz = 100;
 block5Ver = 100;
}

else if (horz == block4Horz && vert == block4Ver && blinking == false&& blockT == true)
{
  isPlaying = false; 
   didStart = false;
   first = false;
   blink = 3; 
   blockTimer = 1000;
    

  horz = 0;
vert = 0; 
   //trying to remove lingering hitboxes: 
    blockHorz = 100;
 blockVert = 100; 

 block2Horz = 100;
 block2Ver = 100;

 block3Horz = 100;
 block3Ver = 100;

 block4Horz = 100;
 block4Ver = 100;

 block5Horz = 100;
 block5Ver = 100;
}

else if (horz == block5Horz && vert == block5Ver && blinking == false && blockT == true)
{
  isPlaying = false; 
   didStart = false;
   first = false;
   blink = 3; 
   blockTimer = 1000;

   horz = 0;
   vert = 0; 
   //trying to remove lingering hitboxes: 
    blockHorz = 100;
 blockVert = 100; 

 block2Horz = 100;
 block2Ver = 100;

 block3Horz = 100;
 block3Ver = 100;

 block4Horz = 100;
 block4Ver = 100;

 block5Horz = 100;
 block5Ver = 100;
}

blockClear();


if (blockTimer >= 300)
{
  blockTimer = blockTimer - 25;
}

}
}







 

# Labor 04

Signal-slot mechanizmusra [példa](https://doc.qt.io/qt-5/signalsandslots.html). 

## Feladatok

1. Készítsünk egy nyomógomb (```QPushButton```) osztályt, mely csak a jobb egérgomb klikkre reagál (például nyisson meg egy felugró ablakot, amelyben kiírja, hogy "Jobb klikk"). Teszteljük a működését.
 
2. Definiáljunk egy bankszámla osztályt mely implementálja az egyenleg kezelését. Definiáljunk egy eseményt mely akkor jön létre, ha az egyenleg meghalad egy küszöbértéket (pl. 1 000 000). Egy ciklusban, véletlenszerűen módosítgassuk az egyenleget (pénzletevés, pénzfelvevés az egyenleg határain belül). Implementáljuk egy ANAF osztályt mely feliratkozik a bankszámla eseményére, és ez bekövetkezésekor kiírja, hogy „Hoppá!”.

3. Hozzunk létre két osztályt: "MagicSlider" és "RewardBagDisplayer". Az előző tartalmazzon egy ```QSlider```t, az utóbbi pedig egy ```QLCDNumber```t és ebből hozzunk majd létre többet is. A ```RewardBagDisplayer``` példányainkat iratkozassuk fel a slider ```QSlider::valueChanged``` eseményére. Amennyiben az kiváltódik, nézzük meg, hogy egyenlő-e a szám a displayer konstruktorában generált véletlen számmal (használjuk a ```QRandomGenerator::bounded``` függvényt a határérték generálására). Ha egyenlő, akkor állítsuk be ezt a számot a displayer értékének, majd 2 másodperc múlva zárjuk be az ablakot.

4. (**Plusz pontra**) Implementálunk egy két személy által egymás ellen játszható (vagyis _local multiplayer_) [tic-tac-toe](https://hu.wikipedia.org/wiki/Tic-tac-toe) játékot (_kéthetes határidő, laboron be kell majd mutatni_). 

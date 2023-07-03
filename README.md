# Store Handling AI Project
This repository was created in order to develop an AI-based algorithm, which will be learned to handle a simple model of storage with deliveries and shipments. 
## AI methods
+ evolutionary algorithms
+ single layer perceptron
## Programming languages
+ C++
+ Java
## Założenia projektowe
+ 1. Algorytm oparty na algenach, którego populacja to zbiór agentów będących SLP
+ 2. Magazyn z obsługą dostaw i wysyłek
+ 3. C++ do ewolucji, Java do wizualizacji
+ 4. Architektura osobnika:
  + dwuwymiarowa macierz wag, jeden wymiar to agenci, drugi to parametry sieci neuronowych
+ 5. Architektura sieci:
  + wejście (rozmiar n):
    + x
    + y
    + NN x
    + NN y
    + kolor niesionego pudełka przez NN agenta
    + pozycje najbliższych pudełek (po jednym w każdym kolorze)
    + po jednym wejściu na każdy kolor pudełka trzymanego
    + [-1, 1] czy w strefie rozładunku są jeszcze pudełka
    + zamówienie: 3 flagi odpowiadające na pytanie czy pudełko danego koloru jest jeszcze potrzebne
  + wartstwa ukryta ma rozmiar (n+k)/2	
  + wyjście (rozmiar k):
    + v_x
    + v_y
    + GRAB
    + SMELL
+ 6. Nagroda za szybki rozładunek
+ 7. Nagroda za czas realizacji zamówień
+ 8. Krzyżowanie:
  + rysunek
  + dwójka rodziców -> dwójka dzieci
  + dziecko jest mocno podobne do jednego z rodziców (?)
  + krzyżowanie odbywa się poprzez wymianę "pakietów" wejść (cech skorelowanych jak np. x i y), a nie losowych zestawów cech
  + wagi spomiędzy warstwy ukrytej i wyjściowej są dziedziczone w zależności od tego z jakiego neuronu warstwy ukrytej wychodzą. Jeśli neuron ten, znaczącą część informacji otrzymuje z wag przesyłających modyfikowane w trakcie krzyżowania cechy, to taka waga również zostaje odziedziczona po osobniku, od którego zachodzi dziedziczenie.
+ 9. Mutacja

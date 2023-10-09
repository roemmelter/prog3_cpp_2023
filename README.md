# PROG3 Lab 01
Autor: Prof. Dr.-Ing. Enrico Schröder - enrico.schroeder@th-nuernberg.de

**Willkommen zur ersten Übung zur Veranstaltung PROG3 / Teil B!**

### Übersicht
Im Laufe des Semesters werden Sie ein kleines Spiel in C++ schreiben (als Beispiel dient *Asteroids* - Sie können jedoch auch ein anderes Spiel entwickeln) und dabei die wichtigsten Konzepte von Objektorientiertem Programmieren und C++ praktisch kennenlernen und anwenden.

![](screenshot_asteroids.png)

Wir fangen jedoch langsam an. In diesem ersten Lab sollen Sie sich mit der Entwicklungsumgebung und den dazugehörigen Tools vertraut machen. Sie werden ihr erstes simples C++ Programm schreiben und (manuell) kompilieren. Als nächstes werden Sie mithilfe von [raylib](https://www.raylib.com) bzw. [raylib-cpp](https://github.com/RobLoach/raylib-cpp) Ihr erstes graphisches Programm in C++ schreiben, welches Ihren Spiel-Hintergrund anzeigt. Am Ende werden Sie sich Gedanken machen, welche logische Architektur ihr Spiel benötigt und diese als C++ Klassen implementieren.


### Vorraussetzungen
Die Übungen sind so konzipiert, dass sie prinzipiell auf jedem System bearbeitet werden können. Es wird jedoch **wärmstens** empfohlen, Linux oder macOS zu verwenden. Nutzen Sie ggf. als Windows-Nutzer die Virtuelle Maschine aus vorigen Veranstaltungen. 

Als Entwicklungsumgebung kommt [Visual Studio Code (vscode)](https://code.visualstudio.com) zum Einsatz. Stellen Sie sicher, dass Sie vscode auf Ihrem System installiert haben und ausführen können.

### Abgaben
Um eine Übung erfolgreich zu bestehen, fertigen Sie ein Protokoll an und geben es (möglichst zeitnah) ab. In den einzelnen Aufgaben ist genauer genannt, was ins Protokoll hinein muss. Generell sollen Sie jedoch folgendes Dokumentieren:
* Was haben Sie gelernt?
* Was hat funktioniert?
* Was hat nicht funktioniert?
* Was haben Sie probiert?

# Aufgabe 00
Schreiben und kompilieren Sie ihr erstes C++ Programm, das einfach "Hello Media Engineers" auf der Konsole ausgibt.  

#### Aufgabe 00_a
Stellen Sie sicher, dass sie über einen installierten C++ Compiler (üblicherweise *gcc* bzw. *g++* auf Linux bzw. *clang* auf macOS) verfügen. Sie sollten bereits über eine funktionierende Installation aus vorhergehenden Lehrveranstaltungen verfügen...
####  Aufabe 00_b
Im Ordner `00_HelloMediaEngineers` finden Sie eine leere C++ Datei *main.cpp*. Implementieren Sie, analog zur Vorlesung, ein simples Programm, das "Hello Media Engineers" auf der Konsole ausgibt.

Kompilieren Sie dieses Programm über die Kommandozeile und führen Sie es aus! Notieren Sie die benötigten Schritte im Protokoll.

# Aufgabe 01
Schreiben und kompilieren Sie ein C++ Programm, welches ein graphisches Fenster öffnet und dort den Hintergrund Ihres Spiels anzeigt.

Hierfür sind ein paar weitere Schritte nötig. Wir verwenden [raylib](https://www.raylib.com) bzw. [raylib-cpp](https://github.com/RobLoach/raylib-cpp) für Grafikausgabe. Dies ist eine s.g. *Dependency (Abhängigkeit)*, d.h. ein externes Codemodul, welches wir in unser Projekt inkludieren müssen. Vielleicht ist Ihnen das aus anderen Sprachen wie z.B. *Java (packages)* oder *Python (modules)* bereits bekannt. Da C++ eine kompilierte Sprache ist, gestaltet sich der Umgang mit externen Abhängigkeiten etwas komplizierter. Aber keine Angst, auch hier verwenden einige Tools, die uns das Leben einfacher machen: [Conan](https://conan.io) und [Cmake](https://cmake.org).

#### Aufgabe 01_a
Stellen Sie sicher, dass Sie sowohl Conan als auch Cmake auf Ihrem System installiert haben.

Die Installation hängt von Ihrem System ab. Sollen Sie Linux verwenden, sollte es beide Programme über den Paketmanager Ihrer Linuxdistribution geben. Ansonsten hier der Link auf die offiziellen Dokumentationen:
* Conan: https://conan.io/downloads
* Cmake: https://cmake.org/download

Führen Sie folgendes Kommando in einem Terminal aus (egal aus welchem Ordner):
> conan profile detect --force

Sie sollte in etwa folgende Ausgabe erhalten:
```
conan profile detect --force
detect_api: Found apple-clang 15.0
detect_api: apple-clang>=13, using the major as version

Detected profile:
...
Saving detected profile to /Users/eschroeder/.conan2/profiles/default
```
#### Aufgabe 01_b
Im Ordner ```01_Asteroids``` finden Sie das Gerüst für ihr zukünftiges Spiel! 
Stellen Sie sicher, dass Sie diese (noch leere) Gerüst, welches *raylib* als Abhängigkeit verwendet, mittels Conan und Cmake kompilieren können. 

Laden Sie dazu als erstes die vscode-Erweiterung [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) herunter.

Führen Sie nun folgende Kommandos im Terminal aus (aus dem Wurzelverzeichnis dieses Repositories, also *PROG3_Ueb_Asteroids_Lab01*):
> conan install . --output-folder=build/Release --build=missing

> cd build/Release && cmake ../.. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

Nun sollten Sie das Programm mittels des Befehls 

>cmake --build .

kompilieren können. Alternativ können Sie auch die Taste F7 drücken oder den entsprechenden *Build* Button in der Fußzeile von vscode betätigen.

#### Aufgabe 01_c
Nutzen Sie raylib-cpp, um ein leeres Fenster mit dem Hintergrundbild Ihres Spiels anzuzeigen.

Finden Sie heraus, wie das geht, indem Sie die Dokumentation von raylib-cpp konsultieren: https://github.com/RobLoach/raylib-cpp

Erweitern Sie die Datei ```01_Asteroids/src/main.cpp``` um die entsprechenden Funktionsaufrufe, sodass das Programm in etwa so aussieht:

![](screenshot_background.png)

Notieren Sie die wichtigsten Zeilen Ihres Programms im Protokoll!

Ein kleiner Hinweis zu raylib: Dies ist eigentlich eine C-Bibliothek. Wir verwenden aber die Sprache C++ und wollen objektorierten Code schreiben. Daher nutzen wir *raylib-cpp*, s.g. *C++ Bindings*. Diese machen die C Bibliothek nativ aus C++ heraus nutzbar (mit Klassen und Vererbung und allem drum und dran). Die Dokumentation von raylib-cpp ist nicht vollständig (da sie ja nur die Funktionen von raylib etwas "schöner" in C++ macht und man doppelte Dokumentation unbedingt vermeiden will). Sie werden daher im Laufe der Übungen öfters die Dokumentation von der Standardversion von raylib nutzen und selbständig die entsprechenden C++ Funktionsaufrufe herausfinden müssen (das ist aber meist sehr einfach!). 

# Aufgabe 02
Im Zentrum von objektorientierter Programmierung steht das *Objekt*, welches logisch zusammenhängende Daten, Zustände und Funktionalität kapselt. Überlegen Sie, welche *Objekte* es in Ihrem Spiel geben könnte und was diese tun bzw. welche Daten sie verwalten. 

Notieren Sie dies in Ihrem Protokoll!

Implementieren Sie ein oder zwei der wichtigsten Objekte als C++-Klassen mit dazugehörigen Daten und Methoden. Schreiben Sie Ihre main.cpp Datei so um, dass dort Instanzen des/der Objekt(e) erstellt werden und ggf. Methoden sinnvoll aufgerufen werden, um sie z.B. im Spielefenster anzuzeigen. 

Fügen Sie die wichtigsten Code-Schnipsel in ihr Protokoll hinzu!
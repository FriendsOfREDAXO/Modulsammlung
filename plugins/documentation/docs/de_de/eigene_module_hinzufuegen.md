# Eigene Module hinzufügen

Eigene Module können **supereinfach** der Sammlung hinzugefügt werden!

**Pflicht**

1. im Ordner `modulsammlung/lib/module/` einen Ordner mit dem gewünschten Namen anlegen
2. mindestens die Dateien `info.inc`,`config.inc`,`input.inc` und `output.inc` anlegen
3. in der `info.inc` bitte kurz eintragen (in HTML) welche Funktionen und Vorraussetzungen das Modul hat. Hier ist auch der Platz für den Hinweis auf Besonderheiten des Moduls.
4. `config.inc` füllen (Modulname / Status)
5. den Modul Input Code in der Datei `input.inc` speichern
6. den Modul Output Code in der Datei `output.inc` speichern
7. fertig.

**Kür**

In der Modulübersicht kann nützlicher (S)CSS Code dargestellt werden. Sofern das gewünscht ist bitte eine Datei mit dem Namen `styles_scss.inc` bzw. `styles_css.inc` anlegen und dort den (S)CSS Code eintragen. Das Addon erkennt automatisch ob die Datei vorhanden ist und bindet diese ein.

Mit der gleichen Vorgehensweise können bei der Modulinstallation Templates (`template.inc`) und Medianmanager Typen / Effekte angelegt werden (`mediamanager.inc`).
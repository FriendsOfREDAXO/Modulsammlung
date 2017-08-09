# Modulsammlung

Ziel des Addons *Modulsammlung* ist es einfach einige Module für REDAXO 5.x installieren zu können um eine Basis für die eigene Weiterentwicklung zu schaffen. Die Module können, sollen und müssen teilweise nach der Installation individuell angepasst werden.

Das Frontend (S)CSS wird entweder nicht oder nur reduziert mitgeliefert (es wird nicht mit dem Modul installiert.) :-)

Da es keinen Updateprozess vorhandener Module gibt (ist auch nicht geplant) kann das Addon nach der Installation der gewünschten Module eigentlich wieder gelöscht werden um zu verhindern, dass evtl. irgendein Anwender wild Module installiert die noch konfiguriert werden müssten.

[Eigene Module](#eigenemodule) können natürlich einfach hinzugefügt werden.


## Wie benutze ich das Addon?

### Module installieren

Nach der Installtion ist unter dem Punkt "Modulsammlung" die Auswahl der Module erreichbar.

* Durch Klick auf "Modul installieren" kann das gewünschte Modul installiert werden.
* Der Name des Moduls welches installiert wird kann vorher in dem Textfeld individuell angepasst werden.
* Bereits installierte Module werden nicht gelöscht oder überschrieben.
* Wird ein Modul mehrfach installiert wird es auch mehrfach (mit einer anderen ID) angelegt.

### Weitere Infos zu einem Modul

- Durch Klick auf das Datenbank Icon links neben der Modulbezeichnung wird der Modulcode dargestellt.
- Hinter dem Button "Info" verbirgt sich eine kurze Beschreibung des Moduls
- Sofern es einen Button "Styles" gibt werden hier beispielhafte (oder benötigte) (S)CSS Angaben bereitgestellt.


<a name="eigenemodule"></a>
## Eigene Module hinzufügen

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

**Superkür**

Jetzt fehlt nur noch ein Eintrag in die Doku und ein PR auf GitHub siehe [Verbesserungen einbringen](#verbesserungen)


## Wie kann ich mitmachen?

Ohne die Mithilfe vieler gäbe es dieses Addon bzw. die meisten der enthaltenen Module nicht.
Mach mit. *Sei cool!*

Selbstversändlich freuen wir uns wenn Du [Wünsche äussers / Fehler meldest](#wuensche_fehler) oder direkt [Verbesserungen einbringst](#verbesserungen). Noch größer ist die Freude aller wenn Du [eigene Module hinzufügst](#eigenemodule) :-)

<a name="wuensche_fehler"></a>
### Wünsche äussern / Fehler melden

Solltest Du einen Wunsch für ein bestimmtes Modul haben oder einen Fehler in einem Modul (oder in dem Addon) gefunden habe ist der beste Weg ein [ISSUES](https://github.com/FriendsOfREDAXO/REX5-Modulsammlung/issues) auf GitHub zu schreiben.

<a name="verbesserungen"></a>
### Verbesserungen einbringen

Hast Du ein Modul verbessert oder einen Fehler gefixt kannst du gerne einen Pull Request auf GitHub starten [Info](https://github.com/FriendsOfREDAXO/Info).

Gerne diskutieren wir auch Live in unserem [Redaxo Slack Channel](http://www.redaxo.org/slack/).
